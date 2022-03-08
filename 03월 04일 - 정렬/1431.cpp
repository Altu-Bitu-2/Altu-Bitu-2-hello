#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const string a, string b) {
	int a_size = a.size(), b_size = b.size();
	//A�� B�� ���̰� �ٸ��ٸ�, ª�� ���� ���� �´�
	if (a_size != b_size)	return a_size < b_size;
	//A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� �ͺ��� �´�
	int a_count = 0, b_count = 0;
	for (int i = 0; i < a_size; i++) if (a[i] >= '0' && a[i] <= '9') a_count += a[i] - '0';
	for (int i = 0; i < b_size; i++) if (b[i] >= '0' && b[i] <= '9') b_count += b[i] - '0';
	if (a_count != b_count) return a_count < b_count;

	if(a.compare(b)>0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(),cmp);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}