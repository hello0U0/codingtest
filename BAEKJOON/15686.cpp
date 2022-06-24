//15686 치킨 배달
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef vector<pair<int, int>> vi;
int MAX = 13000;	//도시의 거리를 최대값보다 크게 설정


int bruteforce(vi &house,vi &chicken,int m) {
	size_t chickensize = chicken.size();
	size_t housesize = house.size();

	//집 - 치킨집 사이 거리 구하기
	vector<vector<int>> dicthc(housesize, vector<int>(chickensize));	//집1 - 치킨집1 거리, 집1 - 치킨집2 거리.......
																		//집2 - 치킨집1 거리, 집2 - 치킨집2 거리.......
	for (int h = 0; h < housesize; h++) {	
		for (int c = 0; c < chickensize; c++) {	
			dicthc[h][c] = abs(house[h].first - chicken[c].first) + abs(house[h].second - chicken[c].second);
		}
	}

	//치킨집 중 m개의 치킨집을 선택해 운영중으로 세팅
	vector<bool> openc(chickensize, 0);			//치킨집 운영 여부	
	for (int i = 1; i <=m; i++) {	//끝에서부터 m자리를 1(운영)으로 세팅
		openc[chickensize-i] = 1;
	}

	//도시의 치킨거리가 가장 작은 경우 찾기
	int answer = MAX;
	do {	//가능한 모든 경우에 대해 계산
		int sum = 0;		//현재 치킨집들을 운영할 때 최소거리
		for (int h = 0; h < housesize; h++) {	//모든 집에 대해서
			int mindict = MAX;		//집과 치킨집의 최소거리
			for (int c = 0; c < chickensize; c++) {	//모든 치킨집에 대해
				if (!openc[c]) continue;			//운영 안하면 패스
				//최소값을 찾는다.
				mindict = min(mindict, dicthc[h][c]);
			}
			//각 집의 최소거리를 더한다.
			sum += mindict;		
		}
		//도시의 치킨거리의 최소값 업데이트
		answer = min(sum, answer);
	} while (next_permutation(openc.begin(), openc.end()));	//순열로 계산
	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;
	vi house;		//집 좌표
	vi chicken;		//치킨집 좌표	
	for (int i = 0; i < n; i++) {		//i,j좌표
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;	
			if (x == 1) house.push_back({ i,j });		//집의 위치 저장
			else if (x == 2) chicken.push_back({ i,j });//치킨집의 위치 저장
		}
	}
	//계산
	int answer = bruteforce(house,chicken,m);
	cout << answer;
	return 0;
}