﻿//2798 블랙잭
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> card;
vector<int> mycard;
int m;

int calSum(const int can) {
	int sum = 0;
	//카드 3장을 뽑았으면 합을 구한다.
	if (mycard.size() >= 3) {
		for (int i = 0; i < 3; i++) sum += mycard[i];
		return sum;
	}

	for (int i = can; i < card.size(); i++) {
		//카드를 한장 뽑는다.
		mycard.push_back(card[i]);
		//다음 카드를 뽑거나 합을 구한다.
		int nowsum = calSum(i + 1);
		mycard.pop_back();
		//m과의 차이가 적은 합을 구한다.
		if (m - nowsum < 0) continue;
		if (m - nowsum < m - sum) sum = nowsum;
	}
	return sum;
}

int main() {
	int n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		card.push_back(x);
	}
	cout << calSum(0);
}