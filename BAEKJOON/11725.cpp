//11725 트리
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//각 노드의 부모노드를 반환하는 함수
vector<int> cal(const int& n, const vector<vector<int>> &tree) {
	vector<int> result(n + 1, -1);	//1번 ~ n번의 노드를 사용(result[0]은 사용안함)
	vector<bool> visited(n + 1, false);	//특정 노드를 방문했는지 체크
	queue<int> q;			//방문할 노드들
	q.push(1);				//루트노드 1을 방문할 것
	while (!q.empty()) {
		int node = q.front();	//방문한 노드를 큐에서 꺼낸다
		q.pop();
		visited[node] = true;	//해당 노드에 방문했음
		for (int i = 0; i < tree[node].size(); i++) {		//해당 노드와 연결된 모든 노드에 대해
			int nextnode = tree[node][i];		//연결된 노드
			if (visited[nextnode]) continue;	//연결된 노드가 이미 방문한(부모또는 상위의) 노드면 패스
			result[nextnode] = node;			//아니라면 자식노드이므로 연결된 노드의 부모를 해당 노드로 설정
			q.push(nextnode);					//자식노드(연결된 노드)를 방문한다.
		}
	}
	return result;
}

int main() {
	int n;			//노드 수
	cin >> n;
	vector<vector<int>> tree(n + 1, vector<int>(0));		//특정 노드와 연결된 노드들의 집합
	//입력
	for (int i = 0; i < n - 1; i++) {			//n-1개의 간선
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);					//a - b 연결됨
		tree[b].push_back(a);					//b - a 연결됨
	}
	//계산
	vector<int> result = cal(n, tree);			
	//출력
	for (int i = 2; i <= n; i++) cout << result[i] << "\n";
}