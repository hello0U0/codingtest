//3665 ��������
#include<iostream>
#include<queue>
using namespace std;

//���� ������ �л� ����� ��ȯ
vector<int> topologicalSort(const int &n,const vector<vector<int>> &graph, vector<int> &parentcnt){
	vector<int> result;					//������
	queue<int> q;
	//ó���� q�� ���� ���� ã�´�.
	for (int i = 1; i <= n; i++) {		//��ü ��忡 ����
		if (parentcnt[i]) continue;	//������ 0�� �ƴϸ� �н�
		parentcnt[i]--;					//�������� q�� ���� ���������ϱ� ���� q�� ������ ������ ����
		q.push(i);						//������ 0�� ��带 q�� �ֱ�
	}
	
	while (!q.empty()) {	//q�� �� ������
		size_t qsize = q.size();		//���� q�� ������=������ �� �� ���� ����
		if (qsize > 1) {	//ť�� �� �������� �����񱳰� �ȵǱ⶧���� 
			for (int i = 0; i < qsize; i++) {		//�� ����ŭ 0�� ����(0='?'��� ����)
				result.push_back(0);		
			}
		}
		else {				//q�� ��尡 �ϳ��ۿ� ������ ���� ����
			result.push_back(q.front());
		}
		while(qsize--) {	//ť�� ��忡 ����
			int now = q.front();	//������
			q.pop();
			for (int i = 0; i < graph[now].size(); i++) {	//������� ����� ���鿡 ����
				int next = graph[now][i];
				if (parentcnt[next] <= 0) {	//�̹� ť�� ���ٸ� ����Ŭ�� �߻��ϱ� ������ ��
					result.clear();
					return result;
				}
				parentcnt[next]--;		//���� ����� ������ �ϳ� �����
			}
		}
		//�ٽ� ��ü�� ���� ������ 0�� ��带 ã�´�.
		for (int i = 1; i <= n; i++) {		//��ü ��忡 ����
			if (parentcnt[i]) continue;	//������ 0�� �ƴϸ� �н�
			parentcnt[i]--;					//�������� q�� ���� ���������ϱ� ���� q�� ������ ������ ����
			q.push(i);						//������ 0�� ��带 q�� �ֱ�
		}
	}
	if (result.size() != n) {	//������ ������ ���� ���� n���� �ƴ϶�� ��
		result.clear();			//Ʈ���� �Ϻθ� ������ ����̴�.
		return result;
	}
	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, ti, m, a, b;
	cin >> t;		//testcase t;
	while (t--) {
		cin >> n;
		vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
		vector<vector<int>> graph(n + 1, vector<int>(0));
		vector<int> prevrank(n + 1);
		vector<int> parentcnt(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> prevrank[i];
		}
		for (int n1 = 1; n1 < n; n1++) {		
			int now = prevrank[n1];		//now�� n1�� ��
			for (int n2 = n1+1; n2 <= n; n2++) {		//n1���� ����� ���� n2�� ����
				int next = prevrank[n2];	//next�� n2�� ��
				visited[now][next] = true;		//n1�� �� -> n2�� ��
			}
		}
		cin >> m;
		while (m--) {		//���� ������ �� �� a,b�� �־�����
			cin >> a >> b;
			visited[a][b] = !visited[a][b];		//������ ������ �ݴ�� �����´�. ex) a->b ���ٸ� b->a��
			visited[b][a] = !visited[b][a];		// visited[a][b]=true, visiited[b][a]=false�� visited[a][b]=false,visited[b][a]=true��
		}
		for (int i = 1; i <= n; i++) {			//��ü ���迡 ����
			for (int j = 1; j <= n; j++) {
				if (visited[i][j]) {	//i->j��
					graph[i].push_back(j);		//i->j�� ǥ��
					parentcnt[j]++;		//j�� ���� ���� �þ��.
				}
			}
		}
		//���
		vector<int> nowrank = topologicalSort(n, graph, parentcnt);
		//���
		if (nowrank.empty()) cout << "IMPOSSIBLE\n";
		else {
			for (int i = 0; i < nowrank.size(); i++) {
				int now = nowrank[i];
				if (!now) cout << "? ";		//0�� ?�� �ǹ�
				else cout << now << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}