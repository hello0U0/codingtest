//11047 동전0
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;		//동전 종류, 구하고자 하는 가치
	cin >> n >> k;
	vector<int> cost(n);		//동전의 가치
	for (int i = n - 1; i >= 0; i--) {		//동전의 가치를 내림차순으로 저장
		cin >> cost[i];
	}
	int costi = 0, sum = 0;
	while (k > 0) {
		sum += k / cost[costi];	//비용이 큰 것부터 최대로 넣기
		k %= cost[costi];		//남은 비용
		costi++;
	}
	cout << sum;
	return 0;
}