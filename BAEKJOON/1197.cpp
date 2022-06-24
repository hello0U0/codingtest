//1197 최소 스패닝 트리
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;			//부모노드가 무엇인지 저장 혹은 음수로 연결된 노드의 수를 저장
//부모노드를 찾는 함수
int findParent(int x) {
	if (parent[x] < 0) return x;				//음수면 자신과 자식노드의 수이므로 자기 자신을 반환
	return parent[x] = findParent(parent[x]);	//아니면 부모노드를 반환한다. 부모노드가 바뀌었을 수 있으므로 내 부모의 부모를 다시 찾아본다.
}
//합집합을 하는 함수. 합치기를 했는지 안했는지를 반환
bool unionInput(int x, int y) {			//x, y두 노드에 대해		
	int px = findParent(x);				//px는 x의 부모노드
	int py = findParent(y);				//py는 y의 부모노드

	if (px == py) return false;	//같은 집합(같은 부모)면 끝
	if (parent[px] < parent[py]) {		//px 집합의 노드 수가 더 많으면(음수이므로 숫자가 더 적음) px집합에 py가 편입
		parent[px] += parent[py];		//px 노드에 py노드 수를 더하고
		parent[py] = px;				//py 노드의 부모를 px로 설정-
	}
	else {								//py 집합의 노드 수가 더 많으면 py집합에 px집합이 편입
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

//최소신장트리
int cal(const int &v,const vector<tp> &edge) {
	int count = 0, sum = 0;			//선택한 간선 수, 가중치 합
	for (auto [w, n1, n2] : edge) {	//w=는 간선 가중치, n1,n2는 간선의 양끝점
		if (!unionInput(n1, n2)) continue;   // 사이클이 생기는 경우 해당간선은 선택하지 않음
		sum += w;		//선택한 간선의 가중치를 더하고
		count++;		//선택한 간선 수 증가
		if (count == v - 1) {    // 필요한 간선을 모두 찾은 경우
			return sum;		//가중치 합을 반환
		}
	}
	return 0;		//간선을 다 찾지 못했으면 연결하지 못한 노드들이 있다는 것이므로 0 반환
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int v, e;
	cin >> v >> e;
	vector<tp> edge;
	parent.resize(v + 1, -1);
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c,a,b });
	}
	sort(edge.begin(), edge.end());
	cout << cal(v, edge);
	return 0;
}