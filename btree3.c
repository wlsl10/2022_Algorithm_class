#include <stdio.h>
#include <stdlib.h>
//time 함수 포함 라이브러리//난수 생성 
#include <time.h>

#define TRUE 1  
#define FALSE 0

//minimum degree t
#define DEGREE 5//testcase1
//#define DEGREE 7//testcase2
//#define DEGREE 9//testcase3

//노드 구조체 생성
typedef struct node
{
	int key[2 * DEGREE - 1];//key는 2t-1
	struct node* child[2 * DEGREE];
	int leaf;
	int n;//length
}
node;

//BTree 구조체 생성
typedef struct B_Tree
{
	node* root;
}B_Tree;


void B_Tree_Create(B_Tree* T);//BTree 생성
void B_Tree_Insert(B_Tree* T, int k);//BTree에 값 삽입
void B_Tree_Insert_Nonfull(node* x, int k);
void B_Tree_Split_Child(node* x, int i);
void B_Tree_Display(B_Tree* T);//BTree 출력
void B_Tree_Display2(node* x, int h);
void B_Tree_Delete(B_Tree* T, int k);//BTree의 값 삭제
void B_Tree_Delete2(node* x, int k);
int Find_Successor(node* x);
int Find_Predecessor(node* x);


int main()
{
	//시간 측정 및 난수 생성을 위한 코드
	srand(time(NULL));
	//시간 단위는 ms
	clock_t start, end;
	double result;

	//BTree 생성할 공간 동적할당하고 트리 생성
	B_Tree* T = malloc(sizeof(B_Tree));
	B_Tree_Create(T);

	//시간 측정 시작
	start = clock();

	//0~9999까지의 데이터를 1000개 삽입
	for (int i = 0; i < 1000; i++) {
		B_Tree_Insert(T, rand() % 10000);
	}
	//생략해도 되는 코드지만 제대로 되는지 확인 
	B_Tree_Display(T);

	//0~9999까지의 데이터를 500개 삽입
	for (int i = 0; i < 500; i++) {
		B_Tree_Delete(T, rand() % 10000);
	}
	//생략해도 되는 코드지만 제대로 되는지 확인 
	B_Tree_Display(T);
	
	//시간 측정 종료
	end = clock();

	result = (double)(end - start);//실행시간
	printf("실행시간: %f", result);

	//동적할당 받은 공간 반납
	free(T);
}

void B_Tree_Create(B_Tree* T)
{
	node* x = malloc(sizeof(node));
	//메모리 할당 실패
	if (x == NULL) {
		printf("메모리 할당에 실패했습니다.");
		return;
	}
	x->leaf = TRUE;
	x->n = 0;
	T->root = x;
}

void B_Tree_Insert(B_Tree* T, int k)
{
	node* r = T->root;
	if (r->n == 2 * DEGREE - 1)
	{
		node* s = malloc(sizeof(node));
		//메모리 할당 실패
		if (s == NULL) {
			printf("메모리 할당에 실패했습니다.");
			return;
		}
		T->root = s;
		s->leaf = FALSE;
		s->n = 0;
		s->child[0] = r;
		B_Tree_Split_Child(s, 0);
		B_Tree_Insert_Nonfull(s, k);
	}
	else
	{
		B_Tree_Insert_Nonfull(r, k);
	}
}

void B_Tree_Insert_Nonfull(node* x, int k)
{
	int i = x->n;
	if (x->leaf)
	{
		i--;
		while (i >= 0 && k < x->key[i])
		{
			x->key[i + 1] = x->key[i];
			i--;
		}
		x->key[i + 1] = k;
		x->n = x->n + 1;
	}
	else {
		while (i >= 1 && k < x->key[i - 1])
		{
			i--;
		}
		if ((x->child[i])->n == 2 * DEGREE - 1)
		{
			B_Tree_Split_Child(x, i);
			if (k > x->key[i]) {
				i++;
			}
		}
		B_Tree_Insert_Nonfull(x->child[i], k);
	}
}


void B_Tree_Split_Child(node* x, int i)
{
	node* z = malloc(sizeof(node));
	//메모리 할당 실패
	if (z == NULL)
	{
		printf("메모리 할당에 실패했습니다.");
		return;
	}
	node* y = x->child[i]; // 0 <= i
	z->leaf = y->leaf;
	z->n = DEGREE - 1;
	for (int j = 0; j < DEGREE - 1; j++)
	{
		z->key[j] = y->key[j + DEGREE];
	}
	if (y->leaf == FALSE)
	{
		for (int j = 0; j < DEGREE; j++)
		{
			z->child[j] = y->child[j + DEGREE];
		}
	}
	y->n = DEGREE - 1;
	for (int j = x->n; j > i; j--)
	{
		x->child[j + 1] = x->child[j];
	}
	x->child[i + 1] = z;
	for (int j = x->n - 1; j > i - 1; j--)
	{
		x->key[j + 1] = x->key[j];
	}
	x->key[i] = y->key[DEGREE - 1];
	x->n = x->n + 1;
}

void B_Tree_Display(B_Tree* T)
{
	node* r = T->root;
	B_Tree_Display2(r, 1);
}

void B_Tree_Display2(node* x, int h)
{
	printf("%d : ", h);
	for (int i = 0; i < x->n; i++)
	{
		printf("%d ", x->key[i]);
	}
	printf("\n");
	if (x->leaf == 0)
	{
		for (int i = 0; i < x->n + 1; i++)
		{
			B_Tree_Display2(x->child[i], h + 1);
		}
	}
}

void B_Tree_Delete(B_Tree* T, int k)
{
	node* r = T->root;
	int i = r->n - 1;
	if (r->leaf == 1)
	{
		while (i >= 0 && r->key[i] > k)
		{
			i--;
		}
		if (i >= 0 && r->key[i] == k) {
			for (int j = i + 1; j < r->n; j++)
			{
				r->key[j - 1] = r->key[j];
			}
			r->n--;
			printf("데이터 삭제를 성공했습니다.\n");
		}
		else {
			printf("데이터가 없습니다.");
		}
		return;
	}
	else {
		if (r->n > 1) {
			B_Tree_Delete2(r, k);
		}
		else {
			node* left_c = r->child[0];
			node* right_c = r->child[1];
			if (left_c->n == DEGREE - 1 && right_c->n == DEGREE - 1) {
				left_c->key[DEGREE - 1] = r->key[0];
				for (int j = 0; j < DEGREE - 1; j++) {
					left_c->key[DEGREE + j] = right_c->key[j];
				}
				if (left_c->leaf == FALSE) {
					for (int j = 0; j < DEGREE; j++) {
						left_c->child[DEGREE + j] = right_c->child[j];
					}
				}
				left_c->n = DEGREE * 2 - 1;
				free(right_c);
				T->root = left_c;
				free(r);
				B_Tree_Delete2(left_c, k);
			}
			else {
				B_Tree_Delete2(r, k);
			}
		}
	}
}

void B_Tree_Delete2(node* x, int k) {
	int i = x->n;
	while (i > 0 && x->key[i - 1] >= k) {
		i--;
	}
	if (i < x->n && x->key[i] == k) {
		if (x->leaf == 1) {
			for (int j = i; j < x->n - 1; j++) {
				x->key[j] = x->key[j + 1];
			}
			x->n--;
			return;
		}
		else {
			node* left_c = x->child[i];
			node* right_c = x->child[i + 1];
			if (left_c->n > DEGREE - 1) {
				int pre_k = Find_Predecessor(left_c);
				x->key[i] = pre_k;
				B_Tree_Delete2(left_c, pre_k);
			}
			else if (right_c->n > DEGREE - 1) {
				int su_k = Find_Successor(right_c);
				x->key[i] = su_k;
				B_Tree_Delete2(right_c, su_k);
			}
			else {
				left_c->key[DEGREE - 1] = k;
				for (int j = 0; j < DEGREE - 1; j++)
				{
					left_c->key[DEGREE + j] = right_c->key[j];
				}
				for (int j = 0; j < DEGREE; j++) {
					left_c->child[DEGREE + j] = right_c->child[j];
				}
				left_c->n = 2 * DEGREE - 1;
				for (int j = i; j < x->n - 1; j++) {
					x->key[j] = x->key[j + 1];
				}
				for (int j = i + 1; j < x->n; j++) {
					x->child[j] = x->child[j + 1];
				}
				x->n--;
				free(right_c);
				B_Tree_Delete2(left_c, k);
			}
		}
	}
	
	return;
}

//데이터 삭제 시 오른쪽 자식 노드의 값을 삭제하고, 키와 바꾸기 위한 코드
int Find_Predecessor(node* x) {
	while (x->leaf == 0) {
		x = x->child[x->n];
	}
	return x->key[x->n - 1];
}

//데이터 삭제 시 왼쪽 자식 노드의 값을 삭제하고, 키와 바꾸기 위한 코드
int Find_Successor(node* x) {
	while (x->leaf == 0) {
		x = x->child[0];
	}
	return x->key[0];
}