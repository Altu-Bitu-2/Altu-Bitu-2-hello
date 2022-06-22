//1043 ������
#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
int findParent(int node) {
	if (parent[node] < 0) return node;
	return parent[node] = findParent(parent[node]);
}
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) return;
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	parent.assign(n + 1, -1);
	int t;
	//������ �ƴ� �׷�
	cin >> t;
	int first = 0;				//������ �ƴ��� ��ǥ
	if (t > 0) cin >> first;
	while (--t>0) {
		int x;
		cin >> x;
		unionInput(first, x);
	}
	vector<vector<int>> party(m);
	//��Ƽ�׷� �� ������ �ƴ� �׷��� �ִ��� Ȯ��
	for (int i = 0; i < m;i++) {
		cin >> t;
		party[i].resize(t);
		for (int j = 0; j < t;j++) {			//��Ƽ������ ����
			cin >> party[i][j];
			unionInput(party[i][0], party[i][j]);
		}
	}
	int count = m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (findParent(party[i][j]) == findParent(first)) {
				count--;
				break;
			}
		}
	}
	cout << count;
	return 0;
}