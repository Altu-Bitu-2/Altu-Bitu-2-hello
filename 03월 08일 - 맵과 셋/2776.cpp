#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		unordered_map<int, int> note1;
		//��ø 1 �Է�
		cin >> n;
		while (n--) {
			cin >> m;
			note1[m] = 1;
		}
		//��ø 2 �Է� �� ���
		cin >> n;
		while (n--) {
			cin >> m;
			cout << note1[m] << '\n';
		}
	}
	return 0;
}