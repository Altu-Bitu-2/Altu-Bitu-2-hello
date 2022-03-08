#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;	//���� [a,b]
	vector<int> arr(20);
	for (int i = 0; i < 20; i++) arr[i] = i+1;	//{1,2,3......,19,20}

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;	//1-20 ������ ���� �Է�
		a--;			//�迭�� 0-19�̹Ƿ� 1�� ����
		b--;

		int mid = (a + b) / 2;		//a~b �߰���
		// a ~ b���� �� �߰����� �������� ��Ī������ ��ȯ 
		for (int j = 0; j <= mid-a; j++) swap(arr[a + j], arr[b - j]);
	}

	for (int i = 0; i < 20; i++) cout << arr[i]<<" ";
	return 0;
}