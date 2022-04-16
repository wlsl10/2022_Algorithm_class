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

void quickSort(int* a, int start, int end) {
	if (start >= end) {//원소가 1개인 경우
		return;
	}
	int key = start; //pivot 값
	int i = start + 1; //시작 값
	int j = end; //뒤의 시작 값
	int temp; //임시변수

	while (i <= j) {//i>j일때까지 반복
		while (a[i] <= a[key]) {//키 값보다 큰값을 만날때까지 
			i++;  //오른쪽으로 이동
		}
		while (a[j] >= a[key] && j > start) {//키 값보다 작은값을 만날때까지//j가 start보다는 커야함
			j--;  //왼쪽으로 이동
		}
		if (i > j) {//현재 i>j(엇갈린 상태)면 키 값과 교체
			temp = a[j];
			a[j] = a[key];
			a[key] = temp;
		}
		else {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	quickSort(a, start, j - 1);
	quickSort(a, j + 1, end);
}

int main() {
	//난수 저장하는 배열 array 생성
	int array[NUMBER];

	srand(time(NULL));//난수 초기화//매번 다른 seed 값 생성
	for (int i = 0; i < NUMBER; i++)//NUMBER번 반복
	{
		array[i] = rand() % MAX_RAND;//0~(MAX_RAND-1)사이의 난수 생성해 array 배열 원소로 대입
		//printf("%d ", array[i]);
	}

	clock_t start, end;
	double result;

	start = (double)clock();//시간 측정 시작

	quickSort(array, 0, NUMBER - 1);

	//printf("\n");
	//printf("\n");
	/*
	for (int i = 0; i < NUMBER; i++)
	{
		printf("%d ", array[i]);
	}
	*/

	end = (double)clock();//시간 측정 끝

	//printf("\n");
	//printf("\n");
	//단위 ms
	result = end - start;//실행시간
	printf("%f", result);

	return 0;
}