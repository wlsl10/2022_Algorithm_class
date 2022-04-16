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

//heapSort
void swap(int* arr, int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

//부모노드 확인
void node_swap(int* arr, int i)
{
	int parent_node = (i - 1) / 2;//부모 노드 주소

	//root에 도달하거나 부모노드보다 작으면 리턴 
	if (i == 0 || arr[i] < arr[parent_node])
		return;

	//부모노드가 자식노드보다 작으면 바꿔주고 반복 수행 
	if (arr[i] > arr[parent_node])
	{
		swap(arr, i, parent_node);
		node_swap(arr, parent_node);
	}
}

void heapSort(int* arr, int size)
{
	//힙트리 생성//최대 힙
	for (int i = 1; i < size; i++)
		node_swap(arr, i);
	swap(arr, 0, size - 1);	//처음과 마지막 바꿔줌

	//정렬//자식노드가 있는 부모노드만
	for (int size_t = size - 1; size_t > 1; size_t--)
	{
		//자식노드가 있는 부모노드만 확인
		for (int i = 0, child = i * 2 + 1; i < size_t / 2; i++)
		{
			//자식노드가 두개면 비교해서 큰 값 지정
			if (child + 1 < size_t && arr[child] < arr[child + 1])
				child++;

			//자식노드가 부모노드보다 크면 바꿔주고 부모노드 확인
			if (arr[i] < arr[child])
			{
				swap(arr, i, child);
				node_swap(arr, i);
			}
		}
		swap(arr, 0, size_t - 1);//마지막 값과 바꿔줌
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

	heapSort(array, NUMBER);

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