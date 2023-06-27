//1976 ���డ��
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
	
	int n, m, x;						//���� �� n, ���� ��ȹ ���� �� m
	cin >> n >> m;						
	parent.resize(n + 1, -1);			//0���� ������� �ʰ� 1~n���� ���, ���ڰ� �ڽ��� ������ �θ��� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {					//1 ~ n������ ���ÿ� ����
		for (int j = 1; j <= n; j++) {				//1 ~ n������ ���ð�
			cin >> x;								//1�̸� ���� 0�̸� ������� ����
			if (i < j && x) unionInput(i, j);		//i-j ����� j-i���� �ι� ǥ���ϱ� ������ i<j�϶��� ���.
		}											//x�� 1�� �����̸� i�� j�� ��ģ��.
	}
	bool yes = true;				//�����ȹ�� �������� üũ
	int root;						//�����ȹ�� ��Ʈ���
	cin >> x;						//ù ���ø� root���� ����
	root = findParent(x);			
	while(--m) {					//�տ��� �ϳ� �Է��� �޾ұ� ������ m�� ���� ���� ���δ�.
		cin >> x;
		x = findParent(x);			//�����ȹ ������ �θ� ã�´�.
		if (root != x) {			//��Ʈ���� ����Ǿ����� ������(�θ� �ٸ���)
			yes = false;			//�����ȹ�� ����
			break;					//�����ȹ�� �ѹ��� �Ǵ��ϱ� ������ NO�� �������� �� ������ �Է��� �ȹ޾Ƶ� ������.
		}
	}
	if (yes) cout << "YES";			//������ �����ϸ� YES �ƴϸ� NO ���
	else cout << "NO";
	return 0;
}