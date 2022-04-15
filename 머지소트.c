//잘 정렬 되었는지 확인하기 위한 출력 코드 주석처리

#include <stdio.h>
//rand, srand 함수 포함 라이브러리
#include <stdlib.h>
//time 함수 포함 라이브러리
#include <time.h>
//상수 생성//NUMBER개의 난수 data에 대해 실행 시간 비교
//100 500 1000 5000 10000으로 변경
#define NUMBER 5000
//0부터 (MAX_RAND-1)까지의 난수 생성
#define MAX_RAND 10000

void merge(int a[], int start, int mid, int end) {
	int b[NUMBER];//merge sort는 임시저장공간 필요

	int i = start;
	int j = mid + 1;
	int k = 0;

	//왼쪽과 오른쪽 집합을 정렬된 상태로 배열 b에 저장
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];

	}
	//왼쪽 집합에 옮겨지지 않은 게 남아있을 때 b에 옮김
	while (i <= mid) {
		b[k++] = a[i++];
	}
	//오른쪽 집합에 옮겨지지 않은 게 있을 때 b에 옮김
	while (j <= end) {
		b[k++] = a[j++];
	}
	k--;

	//정렬된 것을 저장한 배열 b의 값을 a에 옮김
	while (k >= 0) {
		a[start + k] = b[k];
		k--;
	}
}

void mergeSort(int a[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
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

	mergeSort(array, 0, NUMBER - 1);


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