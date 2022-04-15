#include <stdio.h>
//rand, srand �Լ� ���� ���̺귯��
#include <stdlib.h>
//time �Լ� ���� ���̺귯��
#include <time.h>
//��� ����//NUMBER���� ���� data�� ���� ���� �ð� ��
//100 500 1000 5000 10000���� ����
#define NUMBER 100
//0���� (MAX_RAND-1)������ ���� ����
#define MAX_RAND 100

//��ȯ����
void exchangeSort(int n, int arr[]) {//�迭 �Ű������� �ޱ�
	int i, j, tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j]) {//�迭 arr ������������ ����
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


int main() {
	//���� �����ϴ� �迭 array ����
	int array[NUMBER];

	srand(time(NULL));//���� �ʱ�ȭ//�Ź� �ٸ� seed �� ����
	for (int i = 0; i < NUMBER; i++)//NUMBER�� �ݺ�
	{
		array[i] = rand() % MAX_RAND;//0~(MAX_RAND-1)������ ���� ������ array �迭 ���ҷ� ����
	}

	clock_t start, end;
	double result;

	//start = clock();//�ð� ���� ����
	start = (double)clock();

	exchangeSort(NUMBER, array);

	//end = clock();//�ð� ���� ��
	end = (double)clock();//�ð� ���� ��

	//���� ms
	//result = (double)(end - start);//����ð�
	result = end - start;//����ð�
	printf("%f", result);

	return 0;
}