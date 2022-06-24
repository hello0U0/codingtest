//1766 ¹®Á¦Áý
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> cal(const int &n, vector<int> &indegree, vector<vector<int>> &graph) {
	vector<int> result;
	priority_queue<int,vector<int>,greater<>> q;
	int time = 0;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		while (!q.empty()) {
			int node = q.top();
			q.pop();
			result.push_back(node);
			for (int i = 0; i < graph[node].size(); i++){
				int next_node = graph[node][i];
				if (!(--indegree[next_node])) q.push(next_node);
			}
		}
	}
	return result;
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(0));
	vector<int> indegree(n + 1, 0);
	while (m--) {
		cin >> a >> b;
		indegree[b]++;
		graph[a].push_back(b);
	}
	vector<int> result = cal(n, indegree, graph);
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	return 0;
}