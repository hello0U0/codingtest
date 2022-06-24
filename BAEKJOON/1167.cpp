//1167 트리의 지름
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
	int goal = node, len = 0;	//node에서 가장 먼 거리의 노드와 그 길이

	for (int i = 0; i < graph[node].size(); i++) {		//노드와 연결도니 모든 노드에 대해
		int next = graph[node][i].first;			//연결된 다음노드
		int weight = graph[node][i].second;			//다음 노드까지의 거리
		if (next == parent) continue;				//부모(parent -> node를 이미 계산했으므로)면 패프

		auto [next_dfs, next_dfs_weight] = dfs(next, node, graph);	//다음 노드부터 리프노드까지의 길이 중 가장 긴 것
		if (weight + next_dfs_weight > len) {			//다음 노드까지의 거리 + 다음노드에서 리프노드까지의 거리가 가장 긴 것으로 업데이트
			len = weight + next_dfs_weight;
			goal = next_dfs;
		}
	}
	return { goal,len };
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int v;		//정점 수 v
	cin >> v;
	vector<vector<ci>> graph(v + 1, vector<ci>(0));	//무방향 그래프 graph

	while (v--) {		//모든 정점에 대해
		int node;		//현재 노드
		cin >> node;
		int next, weight;		//다음 노드, 가중치
		while (1) {
			cin >> next;
			if (next == -1) break;	//-1이 입력되면 끝
			cin >> weight;
			graph[node].push_back({ next,weight });	// node -> next의 가중치 wegiht
		}
	}

	ci goal = dfs(1, -1, graph);		//임의로 1번 노드에서 가장 긴 노드 찾기
	goal = dfs(goal.first, -1, graph);	//위의 결과노드로부터 가장 긴 노드 찾기
	cout << goal.second;
	return 0;
}