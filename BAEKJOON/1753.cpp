//1753 최단경로
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;
int INF = 3e6 + 1;
vector<int> dijkstra(const int &vn, const vector<vector<ci>> &graph, const int &start) {
	vector<int> result(vn + 1, INF);		//각 정점까지의 최단거리. 무한으로 초기화
	priority_queue<ci,vector<ci>,greater<>> node;			// 거리가 작은 것부터 계산하기위한 큐
	result[start] = 0;		//시작지점은 자기자신이므로 최단거리 0
	node.push({ 0,start });	//방문할 정점까지의 거리, 방문할 정점

	while (!node.empty()) {
		int nowweight = node.top().first;				//큐에서 방문할 노드를 꺼낸다
		int nownode = node.top().second;
		node.pop();
		if (result[nownode] < nowweight) continue;		//기존에 저장된 거리가 더 길면 패스

		for (int i = 0; i < graph[nownode].size(); i++) {	//현재 정점에 연결되 모든 정점에 대해
			int nextnode = graph[nownode][i].first;			//다음 정점
			int nextweight = nowweight+ graph[nownode][i].second;	//현재 정점을 지나 다음 정점으로 가는 경로값
			if (nextweight < result[nextnode]) {			//현재정점을 지나는 경로가 더 짧으면
				result[nextnode] = nextweight;				//현재값으로 갱신
				node.push({ nextweight,nextnode });			//다음 노드를 방문할 것 
			}
		}
	}
	return result;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//입력
	int vn, en, k;			//정점 수, 간선 수, 시작점
	cin >> vn >> en;
	cin >> k;
	vector<vector<ci>> graph(vn + 1, vector<ci>(0));		//그래프
	while(en--) {
		int u, v, w;			// u -> v 인 간선의 가중치는 w다.
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });		//그래프에 저장
	}
	//계산
	vector<int> result = dijkstra(vn,graph,k);	
	//출력
	for (int i = 1; i <= vn; i++) {
		if (result[i] >= INF) cout << "INF" << '\n';
		else cout << result[i] << '\n';
	}
}