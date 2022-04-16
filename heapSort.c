//�� ���� �Ǿ����� Ȯ���ϱ� ���� ��� �ڵ� �ּ�ó��

#include <stdio.h>
//rand, srand �Լ� ���� ���̺귯��
#include <stdlib.h>
//time �Լ� ���� ���̺귯��
#include <time.h>
//��� ����//NUMBER���� ���� data�� ���� ���� �ð� ��
//100 500 1000 5000 10000���� ����
#define NUMBER 100
//0���� (MAX_RAND-1)������ ���� ����
#define MAX_RAND 10000

//heapSort
void swap(int* arr, int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

//�θ��� Ȯ��
void node_swap(int* arr, int i)
{
	int parent_node = (i - 1) / 2;//�θ� ��� �ּ�

	//root�� �����ϰų� �θ��庸�� ������ ���� 
	if (i == 0 || arr[i] < arr[parent_node])
		return;

	//�θ��尡 �ڽĳ�庸�� ������ �ٲ��ְ� �ݺ� ���� 
	if (arr[i] > arr[parent_node])
	{
		swap(arr, i, parent_node);
		node_swap(arr, parent_node);
	}
}

void heapSort(int* arr, int size)
{
	//��Ʈ�� ����//�ִ� ��
	for (int i = 1; i < size; i++)
		node_swap(arr, i);
	swap(arr, 0, size - 1);	//ó���� ������ �ٲ���

	//����//�ڽĳ�尡 �ִ� �θ��常
	for (int size_t = size - 1; size_t > 1; size_t--)
	{
		//�ڽĳ�尡 �ִ� �θ��常 Ȯ��
		for (int i = 0, child = i * 2 + 1; i < size_t / 2; i++)
		{
			//�ڽĳ�尡 �ΰ��� ���ؼ� ū �� ����
			if (child + 1 < size_t && arr[child] < arr[child + 1])
				child++;

			//�ڽĳ�尡 �θ��庸�� ũ�� �ٲ��ְ� �θ��� Ȯ��
			if (arr[i] < arr[child])
			{
				swap(arr, i, child);
				node_swap(arr, i);
			}
		}
		swap(arr, 0, size_t - 1);//������ ���� �ٲ���
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

	//end = (double)clock();//�ð� ���� ��
	end = clock();//�ð� ���� ��

	//printf("\n");
	//printf("\n");
	//���� ms
	//result = end - start;//����ð�
	result = (double)(end - start);//����ð�
	printf("%f", result);

	return 0;
}