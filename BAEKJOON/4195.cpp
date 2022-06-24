//4195 친구 네트워크
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> parent;			//부모노드가 무엇인지 저장 혹은 음수로 연결된 노드의 수를 저장
//부모노드를 찾는 함수
int findParent(int x) {
	if (parent[x] < 0) return x;				//음수면 자신과 자식노드의 수이므로 자기 자신을 반환
	return parent[x] = findParent(parent[x]);	//아니면 부모노드를 반환한다. 부모노드가 바뀌었을 수 있으므로 내 부모의 부모를 다시 찾아본다.
}
//합집합을 하는 함수. 그리고 집합의 노드 수를 반환
int unionInput(int x, int y) {			//x, y두 노드에 대해		
	int px = findParent(x);				//px는 x의 부모노드
	int py = findParent(y);				//py는 y의 부모노드

	if (px == py) return parent[px];	//같은 집합(같은 부모)면 끝
	if (parent[px] < parent[py]) {		//px 집합의 노드 수가 더 많으면(음수이므로 숫자가 더 적음) px집합에 py가 편입
		parent[px] += parent[py];		//px 노드에 py노드 수를 더하고
		parent[py] = px;				//py 노드의 부모를 px로 설정
		return parent[px];
	}
	else {								//py 집합의 노드 수가 더 많으면 py집합에 px집합이 편입
		parent[py] += parent[px];
		parent[px] = py;
		return parent[py];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t;		//testcase t
	cin >> t;
	while (t--) {
		int f;		//친구관계수
		cin >> f;	
		int namemap_i = 1;		//이름에 맵핑할 번호
		map<string, int> namemap;
		parent.resize(1, -1);	//0번은 안쓸 것이므로 0번 하나 넣어두기
		while (f--) {
			string a, b;
			cin >> a >> b;		
			if (!namemap[a]) {	//이름이 처음 등장하면 번호를 부여
				namemap[a] = namemap_i++;
				parent.push_back(-1);	//부모노드를 넣을 장소도 만들기
			}
			if (!namemap[b]) {		//b에 대해서도 똑같이 진행
				namemap[b] = namemap_i++;
				parent.push_back(-1);
			}
			int ai = namemap[a];	//ai는 a에 매핑된 번호
			int bi = namemap[b];	//bi는 b에 매핑된 번호
			cout << -unionInput(ai, bi) << '\n';	//노드 수(친구 네트워크의 사람 수)를 출력
		}
	}

	return 0;
}