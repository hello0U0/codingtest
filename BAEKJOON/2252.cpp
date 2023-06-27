//2252 �ټ����
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> cal(const int &n,vector<vector<int>> &graph, vector<int> &indegree) {
	vector<int> result;		//���
	queue<int> q;			//�湮�� ���

	for (int i = 1; i <= n; i++) {		//���������� ���� ��带 ť�� �߰�
		if (!indegree[i]) q.push(i);
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {		//���� ��带 ������������ ���� �ִ� �͵鿡 ����
			int next_node = graph[node][i];
			//���� ������ node�� ���� ���������� �ϳ� �پ���.���������� ���� ��带 ť�� �߰�
			if (!(--indegree[next_node])) q.push(next_node);	
		}
	}
	return result;
}

int main() {
	int n, m;	// 1<=n<=32000), 1<=M<=100000
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(0));	// out ����Ʈ
	vector<int> indegree(n + 1, 0);	//in ����
	while (m--) {
		int a, b;	//�л���ȣ Ű ���� a < b
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