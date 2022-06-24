//14502 연구소
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//바이러스 확산
void virus(vector<vector<int>>& field, int n, int m) {
	queue<pair<int, int>> q;	//새로 바이러스가 생긴 장소 목록
	//최초로 바이러스가 있던 지점 찾기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == 2) {		//바이러스면
				q.push({ i,j });		//큐에 저장
				field[i][j] = 0;		//큐 계산의 편의를 위해 빈칸으로 바꾸기
			}
		}
	}
	//바이러스 확산
	vector<int> dirtx = { -1,0,0,1 };	//상하좌우 x좌표
	vector<int> dirty = { 0,-1,1,0 };	//상하좌우 y좌표
	while (!q.empty()) {			//큐가 비어있지 않으면 진행
		auto [x, y] = q.front();
		q.pop();
		if (field[x][y] != 0) continue;		//빈칸이 아니면 넘어가기
		field[x][y] = 2;					//빈칸에 바이러스가 확산됨
		for (int i = 0; i < 4; i++) {		//바이러스의 상하좌우에 대해
			int nowx = x + dirtx[i];
			int nowy = y + dirty[i];
			//필드 범위 밖이면 넘어가기
			if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= m) continue;	
			if (field[nowx][nowy] == 0) {	//빈칸이면(바이러스 확산 가능이면)
				q.push({ nowx,nowy });		//큐에 저장
			}
		}
	}
	return;
}

int bruteforce(vector<vector<int>>& field, int n, int m, vector<pair<int, int>>& blank) {
	size_t blanksize = blank.size();
	vector<bool> use(blanksize, 0);		//벽을 설치하는지 저장
	//사용할 벽 초기화
	for (int i = 0; i <3; i++) use[i] = 1;
	sort(use.begin(), use.end());
	//가능한 모든 경우의 수에 대해 최대값을 찾는다.
	int answer = 0;
	do {
		vector<vector<int>> nowfield = field;
		//벽을 세운다.
		for (int i = 0; i < blanksize; i++) {
			if (use[i]) {
				nowfield[blank[i].first][blank[i].second] = 1;
			}
		}
		//바이러스 확산
		virus(nowfield, n, m);
		//남은 구역 계산
		int nowans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (nowfield[i][j] == 0) nowans++;
			}
		}
		//최대값 찾기
		answer = max(answer, nowans);
	} while (next_permutation(use.begin(), use.end()));

	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m));	//필드
	vector<pair<int, int>> blank;		//빈칸좌표목록
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 0) blank.push_back({ i,j });	//빈칸위치 저장
		}
	}
	int answer = bruteforce(field,n,m,blank);
	cout << answer;
	return 0;
}