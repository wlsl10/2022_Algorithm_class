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

void quickSort(int* a, int start, int end) {
	if (start >= end) {//���Ұ� 1���� ���
		return;
	}
	int key = start; //pivot ��
	int i = start + 1; //���� ��
	int j = end; //���� ���� ��
	int temp; //�ӽú���

	while (i <= j) {//i>j�϶����� �ݺ�
		while (a[i] <= a[key]) {//Ű ������ ū���� ���������� 
			i++;  //���������� �̵�
		}
		while (a[j] >= a[key] && j > start) {//Ű ������ �������� ����������//j�� start���ٴ� Ŀ����
			j--;  //�������� �̵�
		}
		if (i > j) {//���� i>j(������ ����)�� Ű ���� ��ü
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

	quickSort(array, 0, NUMBER - 1);

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