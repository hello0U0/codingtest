//1976 여행가자
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
	
	int n, m, x;						//도시 수 n, 여행 계획 도시 수 m
	cin >> n >> m;						
	parent.resize(n + 1, -1);			//0번은 사용하지 않고 1~n번을 사용, 각자가 자신의 집합의 부모라고 초기화
	for (int i = 1; i <= n; i++) {					//1 ~ n까지의 도시에 대해
		for (int j = 1; j <= n; j++) {				//1 ~ n까지의 도시가
			cin >> x;								//1이면 연결 0이면 연결되지 않음
			if (i < j && x) unionInput(i, j);		//i-j 연결과 j-i연결 두번 표현하기 때문에 i<j일때만 계산.
		}											//x가 1로 연결이면 i와 j를 합친다.
	}
	bool yes = true;				//여행계획이 가능한지 체크
	int root;						//여행계획의 루트노드
	cin >> x;						//첫 도시를 root노드로 설정
	root = findParent(x);			
	while(--m) {					//앞에서 하나 입력을 받았기 때문에 m의 수를 먼저 줄인다.
		cin >> x;
		x = findParent(x);			//여행계획 도시의 부모를 찾는다.
		if (root != x) {			//루트노드와 연결되어있지 않으면(부모가 다르면)
			yes = false;			//여행계획은 실패
			break;					//여행계획을 한번만 판단하기 때문에 NO인 순간부터 그 다음은 입력을 안받아도 괜찮다.
		}
	}
	if (yes) cout << "YES";			//여행이 가능하면 YES 아니면 NO 출력
	else cout << "NO";
	return 0;
}