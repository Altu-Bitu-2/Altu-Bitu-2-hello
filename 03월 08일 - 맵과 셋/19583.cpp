#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string start_time, end_time, close_time;
	int count = 0;
	map<string, int> name_check;

	cin >> start_time >> end_time >> close_time;
	while (!cin.eof()) {
		string time, name;
		cin >> time >> name;
		//�������� ä��ģ �л��� map�� ���
		if (time <= start_time) {
			name_check[name] = 0;
		}// ��ȸ�� ���� ������ ��Ʈ���� ����Ǳ�������
		else if (time >= end_time && time <= close_time) {
			// ä���ϸ� map�� ��ϵǾ�������쿡�� üũ
			if (name_check.find(name) != name_check.end()) {
				name_check[name] = 1;
			}
		}
	}//map���� üũ�� ����鸸 ���
	for (auto iter : name_check) {
		if (iter.second ) count++;
	}

	cout << count;
	return 0;
}