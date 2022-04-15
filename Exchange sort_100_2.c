#include <stdio.h>
//rand, srand 함수 포함 라이브러리
#include <stdlib.h>
//time 함수 포함 라이브러리
#include <time.h>
//상수 생성//NUMBER개의 난수 data에 대해 실행 시간 비교
//100 500 1000 5000 10000으로 변경
#define NUMBER 100
//0부터 (MAX_RAND-1)까지의 난수 생성
#define MAX_RAND 100

//교환정렬
void exchangeSort(int n, int arr[]) {//배열 매개변수로 받기
	int i, j, tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j]) {//배열 arr 오름차순으로 정렬
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


int main() {
	//난수 저장하는 배열 array 생성
	int array[NUMBER];

	srand(time(NULL));//난수 초기화//매번 다른 seed 값 생성
	for (int i = 0; i < NUMBER; i++)//NUMBER번 반복
	{
		array[i] = rand() % MAX_RAND;//0~(MAX_RAND-1)사이의 난수 생성해 array 배열 원소로 대입
	}

	clock_t start, end;
	double result;

	//start = clock();//시간 측정 시작
	start = (double)clock();

	exchangeSort(NUMBER, array);

	//end = clock();//시간 측정 끝
	end = (double)clock();//시간 측정 끝

	//단위 ms
	//result = (double)(end - start);//실행시간
	result = end - start;//실행시간
	printf("%f", result);

	return 0;
}