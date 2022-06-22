//16114 ȭ��ǥ ������
#include<iostream>
#include<string>
using namespace std;
const string INFINITE = "INFINITE";
const string ERROR = "ERROR";

string cal(int& x, int& n) {
	if (n == 1) {		//n==1�̸� ���� ���� ������
		x = -x;
		n = 0;
	}
	if (n % 2) return ERROR;		//n�� ¦����������(�Ѱ��� �׳� ���� ��ȣ)
	if (x > 0 && n == 0) return INFINITE;	//x�� ����� n�� 0�̸� ����
	n /= 2;		//-�� 2���� -1�̹Ƿ� -�� n���� -n/2
	x -= n;		//������ ���� ���ȴ�.
	if (x <= 0) return "0";		//x�� 0�Ǵ� ������ ������ 0
	int ans = x / n;	//x/n�������� while�� True
	if (x % n) ans++;	//x%n�� ������ x/n�� ����ϰ� ���
	return to_string(ans);
}
int main() {
	int x, n;
	cin >> x >> n;
	
	cout << cal(x, n);
}