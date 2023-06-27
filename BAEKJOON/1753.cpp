//1753 �ִܰ��
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;
int INF = 3e6 + 1;
vector<int> dijkstra(const int &vn, const vector<vector<ci>> &graph, const int &start) {
	vector<int> result(vn + 1, INF);		//�� ���������� �ִܰŸ�. �������� �ʱ�ȭ
	priority_queue<ci,vector<ci>,greater<>> node;			// �Ÿ��� ���� �ͺ��� ����ϱ����� ť
	result[start] = 0;		//���������� �ڱ��ڽ��̹Ƿ� �ִܰŸ� 0
	node.push({ 0,start });	//�湮�� ���������� �Ÿ�, �湮�� ����

	while (!node.empty()) {
		int nowweight = node.top().first;				//ť���� �湮�� ��带 ������
		int nownode = node.top().second;
		node.pop();
		if (result[nownode] < nowweight) continue;		//������ ����� �Ÿ��� �� ��� �н�

		for (int i = 0; i < graph[nownode].size(); i++) {	//���� ������ ����� ��� ������ ����
			int nextnode = graph[nownode][i].first;			//���� ����
			int nextweight = nowweight+ graph[nownode][i].second;	//���� ������ ���� ���� �������� ���� ��ΰ�
			if (nextweight < result[nextnode]) {			//���������� ������ ��ΰ� �� ª����
				result[nextnode] = nextweight;				//���簪���� ����
				node.push({ nextweight,nextnode });			//���� ��带 �湮�� �� 
			}
		}
	}
	return result;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//�Է�
	int vn, en, k;			//���� ��, ���� ��, ������
	cin >> vn >> en;
	cin >> k;
	vector<vector<ci>> graph(vn + 1, vector<ci>(0));		//�׷���
	while(en--) {
		int u, v, w;			// u -> v �� ������ ����ġ�� w��.
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });		//�׷����� ����
	}
	//���
	vector<int> result = dijkstra(vn,graph,k);	
	//���
	for (int i = 1; i <= vn; i++) {
		if (result[i] >= INF) cout << "INF" << '\n';
		else cout << result[i] << '\n';
	}
}