#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		unordered_set<int> note1;
		//��ø 1 �Է�
		cin >> n;
		while (n--) {
			cin >> m;
			note1.insert(m);
		}
		//��ø 2 �Է� �� ���
		cin >> n;
		while (n--) {
			cin >> m;
			cout << (note1.find(m) != note1.end()) << '\n';
		}
	}
	return 0;
}