//�� ���� �Ǿ����� Ȯ���ϱ� ���� ��� �ڵ� �ּ�ó��

#include <stdio.h>
//rand, srand �Լ� ���� ���̺귯��
#include <stdlib.h>
//time �Լ� ���� ���̺귯��
#include <time.h>
//��� ����//NUMBER���� ���� data�� ���� ���� �ð� ��
//100 500 1000 5000 10000���� ����
#define NUMBER 5000
//0���� (MAX_RAND-1)������ ���� ����
#define MAX_RAND 10000

void merge(int a[], int start, int mid, int end) {
	int b[NUMBER];//merge sort�� �ӽ�������� �ʿ�

	int i = start;
	int j = mid + 1;
	int k = 0;

	//���ʰ� ������ ������ ���ĵ� ���·� �迭 b�� ����
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];

	}
	//���� ���տ� �Ű����� ���� �� �������� �� b�� �ű�
	while (i <= mid) {
		b[k++] = a[i++];
	}
	//������ ���տ� �Ű����� ���� �� ���� �� b�� �ű�
	while (j <= end) {
		b[k++] = a[j++];
	}
	k--;

	//���ĵ� ���� ������ �迭 b�� ���� a�� �ű�
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
	//���� �����ϴ� �迭 array ����
	int array[NUMBER];

	srand(time(NULL));//���� �ʱ�ȭ//�Ź� �ٸ� seed �� ����
	for (int i = 0; i < NUMBER; i++)//NUMBER�� �ݺ�
	{
		array[i] = rand() % MAX_RAND;//0~(MAX_RAND-1)������ ���� ������ array �迭 ���ҷ� ����
		//printf("%d ", array[i]);
	}

	clock_t start, end;
	double result;

	start = (double)clock();//�ð� ���� ����

	mergeSort(array, 0, NUMBER - 1);


	//printf("\n");
	//printf("\n");
	/*
	for (int i = 0; i < NUMBER; i++)
	{
		printf("%d ", array[i]);
	}
	*/

	end = (double)clock();//�ð� ���� ��

	//printf("\n");
	//printf("\n");
	//���� ms
	result = end - start;//����ð�
	printf("%f", result);

	return 0;
}