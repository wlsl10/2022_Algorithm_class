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

//ť ���� �Լ�
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