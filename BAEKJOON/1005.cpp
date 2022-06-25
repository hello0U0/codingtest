//1005 ARM Craft
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int cal(const int &n,const int &w, vector<vector<int>> &graph, vector<int> &indegree,vector<int> &time) {
	vector<int> result(n + 1, 0);		//결과, 각 건물을 짓는데 필요한 최소시간
	queue<int> q;			//방문할 노드

	for (int i = 1; i <= n; i++) {		
		result[i] = time[i];			//자기자신들은 만들어야한다.
		if (!indegree[i]) q.push(i);	//진입조건이 없는 노드를 큐에 추가
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {		//현재 노드를 진입조건으로 갖고 있는 것들에 대해
			int next_node = graph[node][i];
			result[next_node] = max(result[next_node], result[node] + time[next_node]);
			//진입 조건이 node인 곳은 진입조건이 하나 줄어든다.진입조건이 없는 노드를 큐에 추가
			if (!(--indegree[next_node])) {
				q.push(next_node);
			}
		}
	}
	return result[w];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, k, x, y, w;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> time(n + 1);
		vector<vector<int>> graph(n + 1, vector<int>(0));
		vector<int> indegree(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}
		while (k--) {
			cin >> x >> y;
			graph[x].push_back(y);
			indegree[y]++;
		}
		cin >> w;
		int result = cal(n, w, graph, indegree, time);
		cout << result << '\n';
	}
}