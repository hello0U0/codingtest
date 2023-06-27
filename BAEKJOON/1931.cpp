//1931 ȸ�ǽ� ����
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;

int main() {
	int n;
	cin >> n;
	vector<ci> meeting(n);			//ȸ�Ǹ��(���ð�, ���۽ð�)���� ����
	for (int i = 0; i < n;i++) {	//���� �������� ���� ���۽ð��� ���� ȸ�Ǹ� ���� �� �ִ�.
		int start,end;
		cin >> start >> end;
		meeting[i] = { end,start };
	}
	sort(meeting.begin(), meeting.end());	//���ð��� ��������, ���۽ð��� �������� ����
	vector<ci> room;				//ȸ�� ��, ���� ȸ�ǰ� ���������� ������ �ð�
	for (int i = 0; i < n; i++) {
		auto [end, start] = meeting[i];
		bool isok = false;					//ȸ�ǰ� ���� ������ ������ üũ
		for (int j = 0; j < room.size(); j++) {		//��ü �濡 ����
			if (start >= room[j].second) {		//���۽ð��� ���� ����ִٸ�
				isok = true;				//����������
				room[j].second = end;		//�濡 ���� ȸ�� �� �ð��� ���
				room[j].first++;			//������� ���� �� ȸ�� ��
				break;
			}
		}
		if (!isok) {					//�����濡 �� �� ���ٸ�
			room.push_back({ 1,end });	//���ο� ������
		}
	}
	sort(room.begin(), room.end(), greater<>());		//ȸ�� ���� ���� ���� ���� Ž��
	cout << room[0].first;
}