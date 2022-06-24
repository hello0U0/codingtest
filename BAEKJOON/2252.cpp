//2252 줄세우기
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> cal(const int &n,vector<vector<int>> &graph, vector<int> &indegree) {
	vector<int> result;		//결과
	queue<int> q;			//방문할 노드

	for (int i = 1; i <= n; i++) {		//진입조건이 없는 노드를 큐에 추가
		if (!indegree[i]) q.push(i);
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {		//현재 노드를 진입조건으로 갖고 있는 것들에 대해
			int next_node = graph[node][i];
			//진입 조건이 node인 곳은 진입조건이 하나 줄어든다.진입조건이 없는 노드를 큐에 추가
			if (!(--indegree[next_node])) q.push(next_node);	
		}
	}
	return result;
}

int main() {
	int n, m;	// 1<=n<=32000), 1<=M<=100000
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(0));	// out 리스트
	vector<int> indegree(n + 1, 0);	//in 개수
	while (m--) {
		int a, b;	//학생번호 키 순서 a < b
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	vector<int> result = cal(n, graph,indegree);
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	return 0;
}