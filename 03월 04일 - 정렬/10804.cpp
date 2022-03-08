#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;	//���� [a,b]
	vector<int> arr(21);
	for (int i = 1; i < 21; i++) arr[i] = i;	//{X, 1,2,3......,19,20}

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;	//1-20 ������ ���� �Է�
		int mid = (a + b) / 2;		//a~b �߰���
		// a ~ b���� �� �߰����� �������� ��Ī������ ��ȯ 
		for (int j = 0; j <= mid - a; j++) {
			swap(arr[a + j], arr[b - j]);
		}
	}

	for (int i = 1; i < 21; i++) cout << arr[i] << " ";
	return 0;
}