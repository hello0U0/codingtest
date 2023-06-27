//1717 ������ ǥ��
#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;			//�θ��尡 �������� ���� Ȥ�� ������ ����� ����� ���� ����
//�θ��带 ã�� �Լ�
int findParent(int x) {			
	if (parent[x] < 0) return x;				//������ �ڽŰ� �ڽĳ���� ���̹Ƿ� �ڱ� �ڽ��� ��ȯ
	return parent[x] = findParent(parent[x]);	//�ƴϸ� �θ��带 ��ȯ�Ѵ�. �θ��尡 �ٲ���� �� �����Ƿ� �� �θ��� �θ� �ٽ� ã�ƺ���.
}
//�������� �ϴ� �Լ�
void unionInput(int x, int y) {			//x, y�� ��忡 ����		
	int px = findParent(x);				//px�� x�� �θ���
	int py = findParent(y);				//py�� y�� �θ���

	if (px == py) return;				//���� ����(���� �θ�)�� ��
	if (parent[px] < parent[py]) {		//px ������ ��� ���� �� ������(�����̹Ƿ� ���ڰ� �� ����) px���տ� py�� ����
		parent[px] += parent[py];		//px ��忡 py��� ���� ���ϰ�
		parent[py] = px;				//py ����� �θ� px�� ����
	}
	else {								//py ������ ��� ���� �� ������ py���տ� px������ ����
		parent[py] += parent[px];
		parent[px] = py;
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//�Է�
	int n, m;
	cin >> n >> m;
	parent.resize(n + 1, -1);		//0���� ������� �ʰ� 1~n���� ���, ���ڰ� �ڽ��� ������ �θ��� �ʱ�ȭ
	//�Է� �� ���
	while (m--) {
		int x, a, b;
		cin >> x >> a >> b;			
		if (!x) {					//x�� 0�̸�
			unionInput(a, b);		//a,b������ ��ģ��.
			continue;
		}//x�� 1�̶�� a�� b�� �θ� ã�Ƽ� ���� �θ�� YES�� �ƴϸ� NO�� ��ȯ
		if (findParent(a) == findParent(b)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}