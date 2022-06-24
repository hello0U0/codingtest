//1931 회의실 배정
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;

int main() {
	int n;
	cin >> n;
	vector<ci> meeting(n);			//회의목록(끝시간, 시작시간)으로 저장
	for (int i = 0; i < n;i++) {	//끝이 빠를수록 다음 시작시간이 빠른 회의를 잡을 수 있다.
		int start,end;
		cin >> start >> end;
		meeting[i] = { end,start };
	}
	sort(meeting.begin(), meeting.end());	//끝시간이 빠를수록, 시작시간이 빠를수록 정렬
	vector<ci> room;				//회의 수, 방의 회의가 마지막으로 끝나는 시간
	for (int i = 0; i < n; i++) {
		auto [end, start] = meeting[i];
		bool isok = false;					//회의가 기존 방으로 들어갔는지 체크
		for (int j = 0; j < room.size(); j++) {		//전체 방에 대해
			if (start >= room[j].second) {		//시작시간에 방이 비어있다면
				isok = true;				//기존방으로
				room[j].second = end;		//방에 다음 회의 끝 시간을 기록
				room[j].first++;			//현재까지 방을 쓴 회의 수
				break;
			}
		}
		if (!isok) {					//기존방에 들어갈 수 없다면
			room.push_back({ 1,end });	//새로운 방으로
		}
	}
	sort(room.begin(), room.end(), greater<>());		//회의 수가 가장 많은 것을 탐색
	cout << room[0].first;
}