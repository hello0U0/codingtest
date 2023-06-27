//14502 ������
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//���̷��� Ȯ��
void virus(vector<vector<int>>& field, int n, int m) {
	queue<pair<int, int>> q;	//���� ���̷����� ���� ��� ���
	//���ʷ� ���̷����� �ִ� ���� ã��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == 2) {		//���̷�����
				q.push({ i,j });		//ť�� ����
				field[i][j] = 0;		//ť ����� ���Ǹ� ���� ��ĭ���� �ٲٱ�
			}
		}
	}
	//���̷��� Ȯ��
	vector<int> dirtx = { -1,0,0,1 };	//�����¿� x��ǥ
	vector<int> dirty = { 0,-1,1,0 };	//�����¿� y��ǥ
	while (!q.empty()) {			//ť�� ������� ������ ����
		auto [x, y] = q.front();
		q.pop();
		if (field[x][y] != 0) continue;		//��ĭ�� �ƴϸ� �Ѿ��
		field[x][y] = 2;					//��ĭ�� ���̷����� Ȯ���
		for (int i = 0; i < 4; i++) {		//���̷����� �����¿쿡 ����
			int nowx = x + dirtx[i];
			int nowy = y + dirty[i];
			//�ʵ� ���� ���̸� �Ѿ��
			if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= m) continue;	
			if (field[nowx][nowy] == 0) {	//��ĭ�̸�(���̷��� Ȯ�� �����̸�)
				q.push({ nowx,nowy });		//ť�� ����
			}
		}
	}
	return;
}

int bruteforce(vector<vector<int>>& field, int n, int m, vector<pair<int, int>>& blank) {
	size_t blanksize = blank.size();
	vector<bool> use(blanksize, 0);		//���� ��ġ�ϴ��� ����
	//����� �� �ʱ�ȭ
	for (int i = 0; i <3; i++) use[i] = 1;
	sort(use.begin(), use.end());
	//������ ��� ����� ���� ���� �ִ밪�� ã�´�.
	int answer = 0;
	do {
		vector<vector<int>> nowfield = field;
		//���� �����.
		for (int i = 0; i < blanksize; i++) {
			if (use[i]) {
				nowfield[blank[i].first][blank[i].second] = 1;
			}
		}
		//���̷��� Ȯ��
		virus(nowfield, n, m);
		//���� ���� ���
		int nowans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (nowfield[i][j] == 0) nowans++;
			}
		}
		//�ִ밪 ã��
		answer = max(answer, nowans);
	} while (next_permutation(use.begin(), use.end()));

	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m));	//�ʵ�
	vector<pair<int, int>> blank;		//��ĭ��ǥ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 0) blank.push_back({ i,j });	//��ĭ��ġ ����
		}
	}
	int answer = bruteforce(field,n,m,blank);
	cout << answer;
	return 0;
}