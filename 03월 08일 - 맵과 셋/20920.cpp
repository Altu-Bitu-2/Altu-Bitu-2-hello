#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.size() != b.first.size())return a.first.size() > b.first.size();
	return a.first < b.first;
}

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> voca_count;	//�ܾ�� �� �ܾ ������ Ƚ��
	vector<pair<string, int>> voca;			//�ܾ���
	while (n--) {
		string s;
		cin >> s;
		//m���� ���� ���̴� �Ѿ��.
		if (s.size() < m) continue;
		//�ܾ�� �ܾ ���� ������ �����Ѵ�.
		voca_count[s]++;
	}
	//�ܾ��忡 �����Ѵ�.
	for (auto iter : voca_count) {
		voca.push_back(pair<string, int>(iter.first, iter.second));
	}
	//�ܾ����� �����Ѵ�.
	sort(voca.begin(), voca.end(), cmp);

	for (auto iter : voca) {
		cout << iter.first << '\n';
	}
}