//2607 ����� �ܾ�
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

//�ܾ��� ���ĺ� �������� ��ȯ
map<char, int> calAlpha(const string &s) {
	map<char, int> alpha;
	for (int i = 0; i < s.size(); i++) alpha[s[i]]++;
	return alpha;
}

int cal(const string& s, map<char,int> &first_alpha) {
	int ans = 0;	//�ϳ����� -1, �ϳ� �ֱ� 1, �ٲٱ� 3
	map<char, int> now_alpha = calAlpha(s);
	for (char i = 'A'; i <= 'Z'; i++) {
		int nowdiff = first_alpha[i] - now_alpha[i];	//���ĺ� i�� ������
		if (nowdiff == 0) continue;						//���̰� ������ �Ѿ��
		//2���̻� ���̳��� ������� ����, �ٲٱ� �Ұ��� ��
		if (abs(nowdiff) != 1 || (ans != 0 && nowdiff + ans != 0)) return 0;
		ans = (ans == 0 ? nowdiff : 3);		//�ϳ� ����� -1, �ϳ� �ֱ�� 1, �ٲٱ�� 2
	}
	return 1;
}

int main() {
	int n, ans = 0;
	string s;
	cin >> n;
	//ù��° �ܾ�
	cin >> s;
	map<char, int> first_alpha = calAlpha(s);
	while (--n) {
		cin >> s;
		ans += cal(s, first_alpha);
	}
	cout << ans;
}