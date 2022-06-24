//1717 집합의 표현
#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;			//부모노드가 무엇인지 저장 혹은 음수로 연결된 노드의 수를 저장
//부모노드를 찾는 함수
int findParent(int x) {			
	if (parent[x] < 0) return x;				//음수면 자신과 자식노드의 수이므로 자기 자신을 반환
	return parent[x] = findParent(parent[x]);	//아니면 부모노드를 반환한다. 부모노드가 바뀌었을 수 있으므로 내 부모의 부모를 다시 찾아본다.
}
//합집합을 하는 함수
void unionInput(int x, int y) {			//x, y두 노드에 대해		
	int px = findParent(x);				//px는 x의 부모노드
	int py = findParent(y);				//py는 y의 부모노드

	if (px == py) return;				//같은 집합(같은 부모)면 끝
	if (parent[px] < parent[py]) {		//px 집합의 노드 수가 더 많으면(음수이므로 숫자가 더 적음) px집합에 py가 편입
		parent[px] += parent[py];		//px 노드에 py노드 수를 더하고
		parent[py] = px;				//py 노드의 부모를 px로 설정
	}
	else {								//py 집합의 노드 수가 더 많으면 py집합에 px집합이 편입
		parent[py] += parent[px];
		parent[px] = py;
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//입력
	int n, m;
	cin >> n >> m;
	parent.resize(n + 1, -1);		//0번은 사용하지 않고 1~n번을 사용, 각자가 자신의 집합의 부모라고 초기화
	//입력 및 계산
	while (m--) {
		int x, a, b;
		cin >> x >> a >> b;			
		if (!x) {					//x가 0이면
			unionInput(a, b);		//a,b집합을 합친다.
			continue;
		}//x가 1이라면 a와 b의 부모를 찾아서 같은 부모면 YES를 아니면 NO를 반환
		if (findParent(a) == findParent(b)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}