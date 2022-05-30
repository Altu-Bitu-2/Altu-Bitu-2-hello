//4195 ģ�� ��Ʈ��ũ
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string, string> parent;

//�ش� ����� ��Ʈ��� ã��
string findParent(string node) {
	if (parent[node].empty()) {	//ó�� �����ϸ�
		parent[node] = "-1";		//�ʱ�ȭ
		return node;
	}
	if (parent[node][0]=='-') {	//������� ������ ��Ʈ
		return node;
	}
	return parent[node] = findParent(parent[node]);
}
void unionInput(string x, string y) {
	string xp = findParent(x);
	string yp = findParent(y);
	//�̹� ���� �����̸� ��
	if (xp == yp) return;
	int ixp = stoi(parent[xp]);
	int iyp = stoi(parent[yp]);
	int sum = ixp + iyp;
	//xp�� �ڽ��� �� ������ xp ������ yp�� ����.
	if (ixp<iyp) {
		parent[xp] = to_string(sum);
		parent[yp] = xp;
	}//�ƴϸ� yp������ xp�� ����.
	else {
		parent[yp] = to_string(sum);
		parent[xp] = yp;
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		parent.clear();
		int f;
		cin >> f;
		while(f--) {
			string a;
			string b;
			cin >> a >> b;
			unionInput(a, b);
			int ans = stoi(parent[findParent(a)]);
			cout << -ans<<"\n";
		}
	}
	return 0;
}