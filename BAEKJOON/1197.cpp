//1197 �ּ� ���д� Ʈ��
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;			//�θ��尡 �������� ���� Ȥ�� ������ ����� ����� ���� ����
//�θ��带 ã�� �Լ�
int findParent(int x) {
	if (parent[x] < 0) return x;				//������ �ڽŰ� �ڽĳ���� ���̹Ƿ� �ڱ� �ڽ��� ��ȯ
	return parent[x] = findParent(parent[x]);	//�ƴϸ� �θ��带 ��ȯ�Ѵ�. �θ��尡 �ٲ���� �� �����Ƿ� �� �θ��� �θ� �ٽ� ã�ƺ���.
}
//�������� �ϴ� �Լ�. ��ġ�⸦ �ߴ��� ���ߴ����� ��ȯ
bool unionInput(int x, int y) {			//x, y�� ��忡 ����		
	int px = findParent(x);				//px�� x�� �θ���
	int py = findParent(y);				//py�� y�� �θ���

	if (px == py) return false;	//���� ����(���� �θ�)�� ��
	if (parent[px] < parent[py]) {		//px ������ ��� ���� �� ������(�����̹Ƿ� ���ڰ� �� ����) px���տ� py�� ����
		parent[px] += parent[py];		//px ��忡 py��� ���� ���ϰ�
		parent[py] = px;				//py ����� �θ� px�� ����-
	}
	else {								//py ������ ��� ���� �� ������ py���տ� px������ ����
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

//�ּҽ���Ʈ��
int cal(const int &v,const vector<tp> &edge) {
	int count = 0, sum = 0;			//������ ���� ��, ����ġ ��
	for (auto [w, n1, n2] : edge) {	//w=�� ���� ����ġ, n1,n2�� ������ �糡��
		if (!unionInput(n1, n2)) continue;   // ����Ŭ�� ����� ��� �ش簣���� �������� ����
		sum += w;		//������ ������ ����ġ�� ���ϰ�
		count++;		//������ ���� �� ����
		if (count == v - 1) {    // �ʿ��� ������ ��� ã�� ���
			return sum;		//����ġ ���� ��ȯ
		}
	}
	return 0;		//������ �� ã�� �������� �������� ���� ������ �ִٴ� ���̹Ƿ� 0 ��ȯ
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