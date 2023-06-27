//4195 ģ�� ��Ʈ��ũ
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> parent;			//�θ��尡 �������� ���� Ȥ�� ������ ����� ����� ���� ����
//�θ��带 ã�� �Լ�
int findParent(int x) {
	if (parent[x] < 0) return x;				//������ �ڽŰ� �ڽĳ���� ���̹Ƿ� �ڱ� �ڽ��� ��ȯ
	return parent[x] = findParent(parent[x]);	//�ƴϸ� �θ��带 ��ȯ�Ѵ�. �θ��尡 �ٲ���� �� �����Ƿ� �� �θ��� �θ� �ٽ� ã�ƺ���.
}
//�������� �ϴ� �Լ�. �׸��� ������ ��� ���� ��ȯ
int unionInput(int x, int y) {			//x, y�� ��忡 ����		
	int px = findParent(x);				//px�� x�� �θ���
	int py = findParent(y);				//py�� y�� �θ���

	if (px == py) return parent[px];	//���� ����(���� �θ�)�� ��
	if (parent[px] < parent[py]) {		//px ������ ��� ���� �� ������(�����̹Ƿ� ���ڰ� �� ����) px���տ� py�� ����
		parent[px] += parent[py];		//px ��忡 py��� ���� ���ϰ�
		parent[py] = px;				//py ����� �θ� px�� ����
		return parent[px];
	}
	else {								//py ������ ��� ���� �� ������ py���տ� px������ ����
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
		int f;		//ģ�������
		cin >> f;	
		int namemap_i = 1;		//�̸��� ������ ��ȣ
		map<string, int> namemap;
		parent.resize(1, -1);	//0���� �Ⱦ� ���̹Ƿ� 0�� �ϳ� �־�α�
		while (f--) {
			string a, b;
			cin >> a >> b;		
			if (!namemap[a]) {	//�̸��� ó�� �����ϸ� ��ȣ�� �ο�
				namemap[a] = namemap_i++;
				parent.push_back(-1);	//�θ��带 ���� ��ҵ� �����
			}
			if (!namemap[b]) {		//b�� ���ؼ��� �Ȱ��� ����
				namemap[b] = namemap_i++;
				parent.push_back(-1);
			}
			int ai = namemap[a];	//ai�� a�� ���ε� ��ȣ
			int bi = namemap[b];	//bi�� b�� ���ε� ��ȣ
			cout << -unionInput(ai, bi) << '\n';	//��� ��(ģ�� ��Ʈ��ũ�� ��� ��)�� ���
		}
	}

	return 0;
}