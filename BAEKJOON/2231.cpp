//2231 분해합
#include<iostream>
using namespace std;

//n이 몇자리 수 인지 계산
int countN(int n) {
	int cnt = 0;
	while (n > 0) {
		n /= 10;
		cnt++;
	}
	return cnt;
}
//n의 생성자를 반환, 생성자가 없으면 0을 반환
int calNum(int n, int start) {
	int num;		//생성자
	for (num = start; num < n; num++) {		//start부터 시작해서
		int sum = num;		//num의 분해합
		int nownum = num;
		while (nownum > 0) {		//num의 전체 자리수를
			sum += nownum % 10;		//더한다
			nownum /= 10;
		}
		if (sum == n) break;		//그 값이 n과 같으면 끝
	}
	if (num == n) num = 0;		//생성자를 못찾았으면 0
	return num;
}
int main() {
	int n;
	cin >> n;
	//n의 자리수는 몇개인지 구하기
	int cnt = countN(n);
	//자리수는 10미만의 수이기 때문에 n - 10*(자리 개수)이하의 수는 답이 될 수 없다.
	int start = n - 10 * cnt;
	//생성자 구하기
	int ans = calNum(n, start);
	cout << ans;
	return 0;
}