//15686 ġŲ ���
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef vector<pair<int, int>> vi;
int MAX = 13000;	//������ �Ÿ��� �ִ밪���� ũ�� ����


int bruteforce(vi &house,vi &chicken,int m) {
	size_t chickensize = chicken.size();
	size_t housesize = house.size();

	//�� - ġŲ�� ���� �Ÿ� ���ϱ�
	vector<vector<int>> dicthc(housesize, vector<int>(chickensize));	//��1 - ġŲ��1 �Ÿ�, ��1 - ġŲ��2 �Ÿ�.......
																		//��2 - ġŲ��1 �Ÿ�, ��2 - ġŲ��2 �Ÿ�.......
	for (int h = 0; h < housesize; h++) {	
		for (int c = 0; c < chickensize; c++) {	
			dicthc[h][c] = abs(house[h].first - chicken[c].first) + abs(house[h].second - chicken[c].second);
		}
	}

	//ġŲ�� �� m���� ġŲ���� ������ ������� ����
	vector<bool> openc(chickensize, 0);			//ġŲ�� � ����	
	for (int i = 1; i <=m; i++) {	//���������� m�ڸ��� 1(�)���� ����
		openc[chickensize-i] = 1;
	}

	//������ ġŲ�Ÿ��� ���� ���� ��� ã��
	int answer = MAX;
	do {	//������ ��� ��쿡 ���� ���
		int sum = 0;		//���� ġŲ������ ��� �� �ּҰŸ�
		for (int h = 0; h < housesize; h++) {	//��� ���� ���ؼ�
			int mindict = MAX;		//���� ġŲ���� �ּҰŸ�
			for (int c = 0; c < chickensize; c++) {	//��� ġŲ���� ����
				if (!openc[c]) continue;			//� ���ϸ� �н�
				//�ּҰ��� ã�´�.
				mindict = min(mindict, dicthc[h][c]);
			}
			//�� ���� �ּҰŸ��� ���Ѵ�.
			sum += mindict;		
		}
		//������ ġŲ�Ÿ��� �ּҰ� ������Ʈ
		answer = min(sum, answer);
	} while (next_permutation(openc.begin(), openc.end()));	//������ ���
	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;
	vi house;		//�� ��ǥ
	vi chicken;		//ġŲ�� ��ǥ	
	for (int i = 0; i < n; i++) {		//i,j��ǥ
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;	
			if (x == 1) house.push_back({ i,j });		//���� ��ġ ����
			else if (x == 2) chicken.push_back({ i,j });//ġŲ���� ��ġ ����
		}
	}
	//���
	int answer = bruteforce(house,chicken,m);
	cout << answer;
	return 0;
}