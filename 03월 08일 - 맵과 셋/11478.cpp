#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	string s, now;
	set<string> spart;

	cin >> s;
	int s_size = s.size();
	for (int i = 0; i < s_size; i++) {
		now.clear();
		//i��°���� �ѱ��ھ� �߰��Ͽ� set�� �ִ´�.
		for (int j = i; j < s_size; j++) {
			now += s[j];
			spart.insert(now);
		}
	}
	cout << spart.size();
}