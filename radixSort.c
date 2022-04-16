//잘 정렬 되었는지 확인하기 위한 출력 코드 주석처리

#include <stdio.h>
//rand, srand 함수 포함 라이브러리
#include <stdlib.h>
//time 함수 포함 라이브러리
#include <time.h>
//상수 생성//NUMBER개의 난수 data에 대해 실행 시간 비교
//100 500 1000 5000 10000으로 변경
#define NUMBER 100
//0부터 (MAX_RAND-1)까지의 난수 생성
#define MAX_RAND 10000

//큐 관련 함수
int queue[NUMBER];
int start, end = 0;

int put(int k) {
	if ((end + 1) % NUMBER == start) {
		//printf("OVER FLOW!\n\n");
		return -1;
	}
	else {
		queue[end] = k;
		end = ++end % NUMBER;
		return 1;
	}
}

int get() {
	int k;
	if (start == end) {
		//printf("UNDER FLOW!\n\n");
		return -1;
	}
	else {
		k = queue[start];
		start = ++start % NUMBER;
		return k;
	}
}

//radixSort
void radixSort(int array[], int size) {
	int max = array[0];
	int digit = 0;
	int factor = 1;
	for (int i = 1; i < size; i++) {
		if (max < array[i]) max = array[i];
	}
	for (int i = max; i > 0; i /= 10) {
		digit++;
	}

	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < 10; j++) { // 0~9
			for (int k = 0; k < size; k++) {
				if ((array[k] / factor) % 10 == j) {
					put(array[k]);
				}
			}
		}
		factor *= 10;
		for (int i = start; i != end; i++) {
			array[i] = get();
		}
		start = end = 0;
	}
}

int main() {
	int array[NUMBER];

	srand(time(NULL));
	for (int i = 0; i < NUMBER; i++)
	{
		array[i] = rand() % MAX_RAND;
		//printf("%d ", array[i]);
	}

	clock_t start, end;
	double result;

	//start = (double)clock();
	start = clock();

	radixSort(array, NUMBER);

	//printf("\n");
	//printf("\n");
	/*
	for (int i = 0; i < NUMBER; i++)
	{
		printf("%d ", array[i]);
	}
	*/

	//end = (double)clock();//시간 측정 끝
	end = clock();//시간 측정 끝

	//printf("\n");
	//printf("\n");
	//단위 ms
	//result = end - start;//실행시간
	result = (double)(end - start);//실행시간
	printf("%f", result);

	return 0;
}