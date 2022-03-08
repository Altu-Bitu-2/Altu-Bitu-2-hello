#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int calNum(string s, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (isdigit(s[i]) > 0) count += s[i] - '0';
	}
	return count;
}
bool cmp(const string a, string b) {
	int a_size = a.size(), b_size = b.size();
	//A�� B�� ���̰� �ٸ��ٸ�, ª�� ���� ���� �´�
	if (a_size != b_size)	return a_size < b_size;
	//A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� �ͺ��� �´�
	int b_count = calNum(b, b_size);
	int a_count = calNum(a, a_size);
	if (b_count != a_count) return b_count > a_count;

	if (a > b) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}