#include<stdio.h>

int main() {
	int h, m, s, q, t, c, clock;
	scanf_s("%d %d %d %d", &h, &m, &s, &q);
	//�ʴ��� �ð����� ����
	clock = h * 3600 + m * 60 + s;

	for (int i = 0; i < q; i++) {
		scanf_s("%d", &t);
		if (t == 3) {	//�ð� ���
			h = clock / 3600;
			m = (clock % 3600) / 60;
			s = clock % 60;
			printf("%d %d %d\n", h, m, s);
		}
		else {
			scanf_s("%d", &c);
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