//1167 Ʈ���� ����
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
	int goal = node, len = 0;	//node���� ���� �� �Ÿ��� ���� �� ����

	for (int i = 0; i < graph[node].size(); i++) {		//���� ���ᵵ�� ��� ��忡 ����
		int next = graph[node][i].first;			//����� �������
		int weight = graph[node][i].second;			//���� �������� �Ÿ�
		if (next == parent) continue;				//�θ�(parent -> node�� �̹� ��������Ƿ�)�� ����

		auto [next_dfs, next_dfs_weight] = dfs(next, node, graph);	//���� ������ ������������ ���� �� ���� �� ��
		if (weight + next_dfs_weight > len) {			//���� �������� �Ÿ� + ������忡�� ������������ �Ÿ��� ���� �� ������ ������Ʈ
			len = weight + next_dfs_weight;
			goal = next_dfs;
		}
	}
	return { goal,len };
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int v;		//���� �� v
	cin >> v;
	vector<vector<ci>> graph(v + 1, vector<ci>(0));	//������ �׷��� graph

	while (v--) {		//��� ������ ����
		int node;		//���� ���
		cin >> node;
		int next, weight;		//���� ���, ����ġ
		while (1) {
			cin >> next;
			if (next == -1) break;	//-1�� �ԷµǸ� ��
			cin >> weight;
			graph[node].push_back({ next,weight });	// node -> next�� ����ġ wegiht
		}
	}

	ci goal = dfs(1, -1, graph);		//���Ƿ� 1�� ��忡�� ���� �� ��� ã��
	goal = dfs(goal.first, -1, graph);	//���� ������κ��� ���� �� ��� ã��
	cout << goal.second;
	return 0;
}