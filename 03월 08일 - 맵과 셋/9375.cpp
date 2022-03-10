#include<iostream>
#include<map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, match = 1;
		cin >> n;

		//n=0�̸� 0��� �� �Ѿ��
		if (n == 0) {
			cout << "0\n";
			continue;
		}//�� �̸� ���� �Է¹ޱ�
		map<string, int> name_kind;
		while(n--) {
			string name, kind;
			cin >> name >> kind;
		//������ �� ���� �����ϱ�
			name_kind[kind]++;
		}
		//�� ������ �� ���� +1�� ���Ѵ�.(���Դ°ͱ��� ���)
		for (auto iter:name_kind) {
			match *= (iter.second + 1);
		}
		//�˸��� ��� ����
		match--;

		cout << match << '\n';
	}
}