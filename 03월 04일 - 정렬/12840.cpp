#include<iostream>

int main() {
	int h, m, s, q, t, c, clock;
	cin >> h >> m >> s >> q;
	//�ʴ��� �ð����� ����
	clock = h * 3600 + m * 60 + s;

	for (int i = 0; i < q; i++) {
		cin>>t;
		if (t == 3) {	//�ð� ���
			h = clock / 3600;
			m = (clock % 3600) / 60;
			s = clock % 60;
			cout << h << " " << m << " " << s << "\n";
		}
		else {
			cin >> c;
			//�ð��� ���̳� �ڷ� ������
			if (t == 2) clock -= c;	
			else clock += c;
			//24�ð�(0~86400)�� ���̷� ���� ���߱�
			if (clock >= 86400 || clock <= -86400)clock %= 86400;
			if (clock < 0) clock += 86400;
		}
	}

	return 0;
}