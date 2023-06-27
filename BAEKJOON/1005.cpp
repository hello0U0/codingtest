//1005 ARM Craft
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int cal(const int &n,const int &w, vector<vector<int>> &graph, vector<int> &indegree,vector<int> &time) {
	vector<int> result(n + 1, 0);		//���, �� �ǹ��� ���µ� �ʿ��� �ּҽð�
	queue<int> q;			//�湮�� ���

	for (int i = 1; i <= n; i++) {		
		result[i] = time[i];			//�ڱ��ڽŵ��� �������Ѵ�.
		if (!indegree[i]) q.push(i);	//���������� ���� ��带 ť�� �߰�
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {		//���� ��带 ������������ ���� �ִ� �͵鿡 ����
			int next_node = graph[node][i];
			result[next_node] = max(result[next_node], result[node] + time[next_node]);
			//���� ������ node�� ���� ���������� �ϳ� �پ���.���������� ���� ��带 ť�� �߰�
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