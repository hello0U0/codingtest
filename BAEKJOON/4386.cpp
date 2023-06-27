//4386 ���ڸ� �����
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef tuple<double, int, int> ti;		//�Ÿ�, ��1, ��2

vector<int> parent;			//���� �θ���

//�θ� ��ȯ
int findParent(int x) {
	if (parent[x] < 0) return x;		//������ �ڽ��� �θ�
	return parent[x] = findParent(parent[x]);	//�ƴϸ� �θ� �θ��� �θ� ã�Ƽ� ���� �θ�� ���� �� ��ȯ
}
//��ĥ �� ������ ��ġ�� ���ƴ����� ��ȯ
bool unionInput(int a, int b) {	
	int pa = findParent(a);		//a�� �θ�
	int pb = findParent(b);		//b�� �θ�
	if (pa == pb) return false;	//���� �����̸� ��ġ�� ����
	if (parent[pa] < parent[pb]) {		//(������ ǥ����) �ڽ� ���� ���� �Ϳ�
		parent[pa] += parent[pb];		//�ڽĵ��� �ְ�
		parent[pb] = pa;				//�θ� ����
	}
	else {
		parent[pb] += parent[pa];
		parent[pa] = pb;
	}
	return true;		//��ħ
}


int main() {
	int n;		//���� ��
	cin >> n;

	vector<pair<double, double>> stars(n);		//���� ��ġ�� ����
	for (int i = 0; i < n;i++){
		cin >> stars[i].first >> stars[i].second;
	}

	vector<ti> graph;				//�Ÿ�, ��1 ��ȣ 1, �� 2��ȣ
	for (int i = 0; i < n; i++) {				//��� �� ���� ���Ͽ�
		for (int j = i + 1; j < n; j++) {
			double w = pow((stars[i].first - stars[j].first), 2) + pow((stars[i].second - stars[j].second), 2);
			w = sqrt(w);			//�Ÿ� ���ϱ�
			graph.push_back({ w,i,j });		//�Ÿ��� �� ��ȣ ����
		}
	}

	double result = 0;			//����
	parent.resize(n, -1);		//���� ������ŭ �θ��� ����
	int cnte = 0;				//������ ���� ��
	sort(graph.begin(), graph.end());		//������������ ����
	for (int i = 0; i < graph.size(); i++) {	//�Ÿ��� ���� ������
		auto [w, n1, n2] = graph[i];		//����ġ, �Ÿ�, ��1 ��ȣ 1, �� 2��ȣ
		if (cnte >= n - 1) break;			//���� �� n-1���� ä������ ��
		if (unionInput(n1, n2)) {			//���ƴٸ�
			cnte++;							//���� �� ����
			result += w;					//�Ÿ� ���ϱ�
		}
	}

	cout << fixed;		//�Ҽ��� 2°�ڸ����� ���
	cout.precision(2);
	cout << result;
	return 0;
}