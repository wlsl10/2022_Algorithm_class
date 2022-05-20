#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//노드 개수 
int NUMBER = 6;
//무한
int INFINITE = 10000000;

//edge에 대한 정보
vector<pair<int, int>> a[7];
//최단거리//최소비용
int d[7];

void dijkstra(int start) {
	//자기자신으로 가는 비용은 0
	d[start] = 0;
	//힙구조//가까운 순서대로 처리하기 위해 큐 사용
	//priority_queue는 큰 값이 앞에 옴
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first;
		//짧은 게 먼저 올 수 있도록 (pair의 second인 거리를) 음수화
		int distance = -pq.top().second;
		pq.pop();
		//최단 거리가 아니면 넘어감
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			//선택된 노드의 인접 노드
			int next = a[current][i].first;
			//선택된 노드를 거쳐 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].second;
			//기존 최소 비용보다 더 적으면 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				//거리는 음수화 해서 넣어주기
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	//선택한 노드와 연결되지 않은 노드의 비용은 무한으로 설정
	for (int i = 1; i <= NUMBER; i++) {
		d[i] = INFINITE;
	}

	//그래프 초기화
	//1번 노드에서 2번 노드로 가는 비용 5
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

	//결과 출력//각 노드의 최소비용 출력됨
	for (int i = 1; i <= NUMBER; i++) {
		//cout << d[i];
		printf("%d ", d[i]);
	}
}