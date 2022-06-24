//4386 별자리 만들기
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef tuple<double, int, int> ti;		//거리, 별1, 별2

vector<int> parent;			//별의 부모노드

//부모를 반환
int findParent(int x) {
	if (parent[x] < 0) return x;		//음수면 자신이 부모
	return parent[x] = findParent(parent[x]);	//아니면 부모내 부모의 부모를 찾아서 나의 부모로 설정 및 반환
}
//합칠 수 있으면 합치고 합쳤는지를 반환
bool unionInput(int a, int b) {	
	int pa = findParent(a);		//a의 부모
	int pb = findParent(b);		//b의 부모
	if (pa == pb) return false;	//같은 집합이면 합치지 않음
	if (parent[pa] < parent[pb]) {		//(음수로 표시한) 자식 수가 많은 것에
		parent[pa] += parent[pb];		//자식들을 주고
		parent[pb] = pa;				//부모를 설정
	}
	else {
		parent[pb] += parent[pa];
		parent[pa] = pb;
	}
	return true;		//합침
}


int main() {
	int n;		//별의 수
	cin >> n;

	vector<pair<double, double>> stars(n);		//별의 위치를 저장
	for (int i = 0; i < n;i++){
		cin >> stars[i].first >> stars[i].second;
	}

	vector<ti> graph;				//거리, 별1 번호 1, 별 2번호
	for (int i = 0; i < n; i++) {				//모든 두 별에 대하여
		for (int j = i + 1; j < n; j++) {
			double w = pow((stars[i].first - stars[j].first), 2) + pow((stars[i].second - stars[j].second), 2);
			w = sqrt(w);			//거리 구하기
			graph.push_back({ w,i,j });		//거리와 별 번호 저장
		}
	}

	double result = 0;			//정답
	parent.resize(n, -1);		//별의 개수만큼 부모벡터 설정
	int cnte = 0;				//선택한 간선 수
	sort(graph.begin(), graph.end());		//오름차순으로 정렬
	for (int i = 0; i < graph.size(); i++) {	//거리가 작은 별부터
		auto [w, n1, n2] = graph[i];		//가중치, 거리, 별1 번호 1, 별 2번호
		if (cnte >= n - 1) break;			//간선 수 n-1개를 채웠으면 끝
		if (unionInput(n1, n2)) {			//합쳤다면
			cnte++;							//간선 수 증가
			result += w;					//거리 더하기
		}
	}

	cout << fixed;		//소수점 2째자리까지 출력
	cout.precision(2);
	cout << result;
	return 0;
}