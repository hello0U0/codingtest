//2231 ������
#include<iostream>
using namespace std;

//n�� ���ڸ� �� ���� ���
int countN(int n) {
	int cnt = 0;
	while (n > 0) {
		n /= 10;
		cnt++;
	}
	return cnt;
}
//n�� �����ڸ� ��ȯ, �����ڰ� ������ 0�� ��ȯ
int calNum(int n, int start) {
	int num;		//������
	for (num = start; num < n; num++) {		//start���� �����ؼ�
		int sum = num;		//num�� ������
		int nownum = num;
		while (nownum > 0) {		//num�� ��ü �ڸ�����
			sum += nownum % 10;		//���Ѵ�
			nownum /= 10;
		}
		if (sum == n) break;		//�� ���� n�� ������ ��
	}
	if (num == n) num = 0;		//�����ڸ� ��ã������ 0
	return num;
}
int main() {
	int n;
	cin >> n;
	//n�� �ڸ����� ����� ���ϱ�
	int cnt = countN(n);
	//�ڸ����� 10�̸��� ���̱� ������ n - 10*(�ڸ� ����)������ ���� ���� �� �� ����.
	int start = n - 10 * cnt;
	//������ ���ϱ�
	int ans = calNum(n, start);
	cout << ans;
	return 0;
}