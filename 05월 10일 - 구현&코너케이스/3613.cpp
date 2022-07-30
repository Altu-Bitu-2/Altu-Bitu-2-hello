//3613 Java vs C++
#include<iostream>
using namespace std;
const int diff = 'a' - 'A';

string cal(const string& s) {
	string ans;
	int kind = 0;	// 1 : java, 2 : c++
	//�ҹ��ڷ� �������� ������ ��
	if (s[0] < 'a' || s[0]>'z') {
		ans = "Error!";
		return ans;
	}
	int max_size = s.size();
	for (int i = 0; i < max_size; i++) {
		//�빮�ڰ� ������ �ڹٴ�
		if (s[i] >= 'A' && s[i] <= 'Z') {
			//������ �ȸ����� ����
			if (kind == 2) {
				ans = "Error!";
				return ans;
			}
			kind = 1;
			ans.push_back('_');
			ans.push_back(s[i] + diff);
		}//����ٰ� ������ C++�̴�.
		else if (s[i] == '_') {
			//������ �ȸ����� ����
			i++;
			if (kind == 1 || i >= max_size||s[i] < 'a' || s[i] > 'z') {
				ans = "Error!";
				return ans;
			}
			kind = 2;
			ans.push_back(s[i] - diff);
		}//�ҹ��ڸ� �״�� �ֱ�
		else ans.push_back(s[i]);
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	cout << cal(s);
	return 0;
}