//2437 ����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n + 1);
	num[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	//���� ������ �����Ѵ�.
	sort(num.begin(), num.end());
	// n��° ���ڴ� ���� ���ڹ迭���� +n��° ���� ���� �Ͱ� ����.
	// 1�� -> 1�� -> 1
	// 2�� -> 0+2�� 1��+2��	 -> 1,2(,3)���� ����
	// 3�� -> 0+3�� 1��+3�� 2��+3�� 1��+2��+3�� (0+3���� 1��+2��+1���� ũ�� �ȵȴ�.) ->������ ���� ���ϱ� ������ ���� ������� ���� �����̴�.
	// ������ ���ڵ��� ������ �����̾���Ѵ�.(�׷��� �� ���ڰ� �Ȼ����.)
	int endnum = 0;
	
	for (int i = 1; i <= n; i++) {
		if (num[i] > endnum + 1) {
			break;
		}
		endnum += num[i];
	}
	cout << endnum + 1;
	return 0;
}