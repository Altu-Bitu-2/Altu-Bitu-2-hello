#include<iostream>
#include<set>
using namespace std;

int main() {
	string s;
	set<string> spart;
	cin >> s;
	int s_size = s.size();
	
	for (int i = 1; i < s_size; i++) {	//s ��ü ���ڿ��� �ϳ��ۿ� �����Ƿ� ��꿡�� ����
		//s���� i ������ �κм����� set�� ����
		for (int j = 0; j <= s_size-i; j++) {
			spart.insert(s.substr(j, i));
		}
	}

	cout << spart.size() + 1;
}