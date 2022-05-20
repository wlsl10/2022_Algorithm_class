#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//��� ���� 
int NUMBER = 6;
//����
int INFINITE = 10000000;

//edge�� ���� ����
vector<pair<int, int>> a[7];
//�ִܰŸ�//�ּҺ��
int d[7];

void dijkstra(int start) {
	//�ڱ��ڽ����� ���� ����� 0
	d[start] = 0;
	//������//����� ������� ó���ϱ� ���� ť ���
	//priority_queue�� ū ���� �տ� ��
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first;
		//ª�� �� ���� �� �� �ֵ��� (pair�� second�� �Ÿ���) ����ȭ
		int distance = -pq.top().second;
		pq.pop();
		//�ִ� �Ÿ��� �ƴϸ� �Ѿ
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			//���õ� ����� ���� ���
			int next = a[current][i].first;
			//���õ� ��带 ���� ���� ���� ���� ���
			int nextDistance = distance + a[current][i].second;
			//���� �ּ� ��뺸�� �� ������ ��ü
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				//�Ÿ��� ����ȭ �ؼ� �־��ֱ�
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	//������ ���� ������� ���� ����� ����� �������� ����
	for (int i = 1; i <= NUMBER; i++) {
		d[i] = INFINITE;
	}

	//�׷��� �ʱ�ȭ
	//1�� ��忡�� 2�� ���� ���� ��� 5
	a[1].push_back(make_pair(2, 5));
	a[1].push_back(make_pair(4, 2));
	a[1].push_back(make_pair(5, 4));

	a[2].push_back(make_pair(1, 5));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 3));

	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 4));
	a[3].push_back(make_pair(6, 2));

	a[4].push_back(make_pair(1, 2));
	a[4].push_back(make_pair(2, 3));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(1, 4));
	a[5].push_back(make_pair(3, 4));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 2));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	//��� ���//�� ����� �ּҺ�� ��µ�
	for (int i = 1; i <= NUMBER; i++) {
		//cout << d[i];
		printf("%d ", d[i]);
	}
}