//12865 평범한 배낭
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int caldp(vector<pair<int,int>> &bags,int n,int k) {
	int answer;
	vector<int> dp(k + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= bags[i].first; j--) {
			dp[j] = max(dp[j - bags[i].first] + bags[i].second, dp[j]);
		}
	}

	return dp[k];
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> bags(n+1); //{무게, 가치}
	for (int i = 1; i <= n; i++) {
		cin >> bags[i].first >> bags[i].second;
	}
	int answer = caldp(bags,n,k);
	cout << answer;
	return 0;
}