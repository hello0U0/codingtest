//11047 ����0
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;		//���� ����, ���ϰ��� �ϴ� ��ġ
	cin >> n >> k;
	vector<int> cost(n);		//������ ��ġ
	for (int i = n - 1; i >= 0; i--) {		//������ ��ġ�� ������������ ����
		cin >> cost[i];
	}
	int costi = 0, sum = 0;
	while (k > 0) {
		sum += k / cost[costi];	//����� ū �ͺ��� �ִ�� �ֱ�
		k %= cost[costi];		//���� ���
		costi++;
	}
	cout << sum;
	return 0;
}