#include<iostream>
#include<map>
using namespace std;

int main() {
	int n;
	string s;
	map<string, int> ext_count;		//Ȯ���� - ���� ����
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;

		//���ϸ��� Ȯ���ڸ� ����
		size_t dot_i = s.find(".");
		s = s.substr(dot_i + 1, s.size());
		//������ �޾����� �ش� Ȯ���� ���� ����, ���ο�� Ȯ���� ���� �ʱ�ȭ
		ext_count[s]++;
	}
	for (auto iter : ext_count) {
		cout << iter.first << " " << iter.second << '\n';
	}
}