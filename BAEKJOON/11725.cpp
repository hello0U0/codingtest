//11725 Ʈ��
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�� ����� �θ��带 ��ȯ�ϴ� �Լ�
vector<int> cal(const int& n, const vector<vector<int>> &tree) {
	vector<int> result(n + 1, -1);	//1�� ~ n���� ��带 ���(result[0]�� ������)
	vector<bool> visited(n + 1, false);	//Ư�� ��带 �湮�ߴ��� üũ
	queue<int> q;			//�湮�� ����
	q.push(1);				//��Ʈ��� 1�� �湮�� ��
	while (!q.empty()) {
		int node = q.front();	//�湮�� ��带 ť���� ������
		q.pop();
		visited[node] = true;	//�ش� ��忡 �湮����
		for (int i = 0; i < tree[node].size(); i++) {		//�ش� ���� ����� ��� ��忡 ����
			int nextnode = tree[node][i];		//����� ���
			if (visited[nextnode]) continue;	//����� ��尡 �̹� �湮��(�θ�Ǵ� ������) ���� �н�
			result[nextnode] = node;			//�ƴ϶�� �ڽĳ���̹Ƿ� ����� ����� �θ� �ش� ���� ����
			q.push(nextnode);					//�ڽĳ��(����� ���)�� �湮�Ѵ�.
		}
	}
	return result;
}

int main() {
	int n;			//��� ��
	cin >> n;
	vector<vector<int>> tree(n + 1, vector<int>(0));		//Ư�� ���� ����� ������ ����
	//�Է�
	for (int i = 0; i < n - 1; i++) {			//n-1���� ����
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);					//a - b �����
		tree[b].push_back(a);					//b - a �����
	}
	//���
	vector<int> result = cal(n, tree);			
	//���
	for (int i = 2; i <= n; i++) cout << result[i] << "\n";
}