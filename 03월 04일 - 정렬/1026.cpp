#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n,min=0;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	//a�� ��������, b�� ������������ �����Ͽ� ���Ѵ�.
	sort(a.begin(), a.end(),greater<>());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) min += a[i] * b[i];
	
	cout << min;
}