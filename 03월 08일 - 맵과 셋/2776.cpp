#include<iostream>
#include<set>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int n,m;
		set<int> note;
		set<int>::iterator iter;
		//��ø 1 �Է�
		cin >> n;
		while(n--) {
			cin >> m;
			note.insert(m);
		}
		//��ø 2 �Է� �� ���
		cin >> n;
		while(n--) {
			cin >> m;
			set<int>::iterator iter = note.find(m);
			cout << (iter != note.end()) << '\n';
		}
	}
	return 0;
}