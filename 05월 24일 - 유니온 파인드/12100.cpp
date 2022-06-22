//12100 2048
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
//�ִ� �� ���
int findMaxNum(const vector<vector<int>>& field, const int& n) {
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_num = max(max_num, field[i][j]);
		}
	}
	return max_num;
}
//��ǥ�� �ʵ� ���� �ȿ� �ִ��� üũ
bool check(const int &now, const int &n) {
	if (now < 0 || now >= n) return false;
	return true;
}
//���� �ø���
void goUp(vector<vector<int>> &field,const int &n) {
	//�� ���� ��ü�� ����
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = 0;	//�о��� �� �ٴ� ���� ��
		int nextx = 1;	//�о��� �� �ٴ� �Ʒ��� ��
		//�� ���� ��ġ�� ���
		while (check(nextx, n)) {	//�ε��� ���� ������ ���. next�� ������ prev���� �ռ���.
			if (field[nextx][i] == 0) {	//next���� ������ next�� ����
				nextx++;
				continue;
			}
			if (field[prevx][i] == 0) {	//prev���� ������ prev�� ����
				prevx++;
				continue;
			}
			if (prevx == nextx) {	//prev�� next�� ������ next�� ����
				nextx++;
				continue;
			}//prev�� next�� �ڸ��� �ִ�.
			//�ٸ��� prev ����, next���� �ٽ� üũ
			if (field[prevx][i] != field[nextx][i]) {
				result.push(field[prevx][i]);
				prevx = nextx;
				nextx++;
			}
			else {//��ĥ �� ������ ��ġ�� �� ����, �� ������Ϻ��� �ٽ� üũ
				result.push(field[prevx][i] + field[nextx][i]);
				prevx = nextx + 1;
				nextx += 2;
			}
		}
		//prev���� �����ϸ� prev�� ����
		if (check(prevx,n) && field[prevx][i] > 0) result.push(field[prevx][i]);

		//field�� ����
		int xi = 0;
		while (!result.empty()) {
			field[xi++][i] = result.front();
			result.pop();
		}
		while (xi < n) {
			field[xi++][i] = 0;
		}
	}
	return;
}
//�Ʒ��� ������
void goDown(vector<vector<int>>& field, const int& n) {
	//�� �Ʒ��� ��ü�� ����
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = n-1;	//�о��� �� �ٴ� �Ʒ��� ��
		int nextx = n-2;	//�о��� �� �ٴ� ���� ��
		//�� ���� ��ġ�� ���
		while (check(nextx, n)) {	//�ε��� ���� ������ ���. next�� ������ prev���� �ռ���.
			if (field[nextx][i] == 0) {	//next���� ������ next�� ����ĭ����
				nextx--;
				continue;
			}
			if (field[prevx][i] == 0) {	//prev���� ������ prev�� ����ĭ����
				prevx--;
				continue;
			}
			if (prevx == nextx) {	//prev�� next�� ������ next�� ����ĭ����
				nextx--;
				continue;
			}//prev�� next�� ���� �ִ�.
			//�ٸ��� prev ����, next���� �ٽ� üũ
			if (field[prevx][i] != field[nextx][i]) {
				result.push(field[prevx][i]);
				prevx = nextx;
				nextx--;
			}
			else {//��ĥ �� ������ ��ġ�� �� ����, �� ������Ϻ��� �ٽ� üũ
				result.push(field[prevx][i] + field[nextx][i]);
				prevx = nextx - 1;
				nextx -= 2;
			}
		}
		//prev���� �����ϸ� prev�� ����
		if (check(prevx, n) && field[prevx][i] > 0) result.push(field[prevx][i]);

		//field�� ����
		int xi = n-1;
		while (!result.empty()) {
			field[xi--][i] = result.front();
			result.pop();
		}
		while (xi >= 0) {
			field[xi--][i] = 0;

		}
	}
	return;
}
//�������� �б�
void goLeft(vector<vector<int>>& field, const int& n) {
	//�� ���� ��ü�� ����
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = 0;	//�о��� �� �ٴ� ����
		int nextx = 1;	//�о��� �� �ٴ� ������ ��
		//�� ���� ��ġ�� ���
		while (check(nextx, n)) {	//�ε��� ���� ������ ���. next�� ������ prev���� �ռ���.
			if (field[i][nextx] == 0) {	//next���� ������ next�� ����
				nextx++;
				continue;
			}
			if (field[i][prevx] == 0) {	//prev���� ������ prev�� ����
				prevx++;
				continue;
			}
			if (prevx == nextx) {	//prev�� next�� ������ next�� ����
				nextx++;
				continue;
			}//prev�� next�� �ڸ��� �ִ�.
			//�ٸ��� prev ����, next���� �ٽ� üũ
			if (field[i][prevx] != field[i][nextx]) {
				result.push(field[i][prevx]);
				prevx = nextx;
				nextx++;
			}
			else {//��ĥ �� ������ ��ġ�� �� ����, �� ������Ϻ��� �ٽ� üũ
				result.push(field[i][prevx] + field[i][nextx]);
				prevx = nextx + 1;
				nextx += 2;
			}
		}
		//prev���� �����ϸ� prev�� ����
		if (check(prevx, n) && field[i][prevx] > 0) result.push(field[i][prevx]);

		//field�� ����
		int yi = 0;
		while (!result.empty()) {
			field[i][yi++] = result.front();
			result.pop();
		}
		while (yi < n) {
			field[i][yi++] = 0;
		}
	}
	return;
}
//���������� �б�
void goRight(vector<vector<int>>& field, const int& n) {
	//������ �� ��ü�� ����
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = n-1;	//�о��� �� �ٴ� ������ �ε���
		int nextx = n-2;	//�о��� �� �ٴ� ���� �ε���
		//�� ���� ��ġ�� ���
		while (check(nextx, n)) {	//�ε��� ���� ������ ���. next�� ������ prev���� �ռ���.
			if (field[i][nextx] == 0) {	//next���� ������ next�� ����
				nextx--;
				continue;
			}
			if (field[i][prevx] == 0) {	//prev���� ������ prev�� ����
				prevx--;
				continue;
			}
			if (prevx == nextx) {	//prev�� next�� ������ next�� ����
				nextx--;
				continue;
			}//prev�� next�� �ڸ��� �ִ�.
			//�ٸ��� prev ����, next���� �ٽ� üũ
			if (field[i][prevx] != field[i][nextx]) {
				result.push(field[i][prevx]);
				prevx = nextx;
				nextx--;
			}
			else {//��ĥ �� ������ ��ġ�� �� ����, �� ������Ϻ��� �ٽ� üũ
				result.push(field[i][prevx] + field[i][nextx]);
				prevx = nextx - 1;
				nextx -= 2;
			}
		}
		//prev���� �����ϸ� prev�� ����
		if (check(prevx, n) && field[i][prevx] > 0) result.push(field[i][prevx]);

		//field�� ����
		int yi = n-1;
		while (!result.empty()) {
			field[i][yi--] = result.front();
			result.pop();
		}
		while (yi >= 0) {
			field[i][yi--] = 0;
		}
	}
	return;
}
//2048 ���
int cal2048(int time,int dir, vector<vector<int>> field, const int &n) {
	int max_num = 0;
	//ó�� ���
	if (time == 0) {
		for (int i = 0; i < 4; i++) {
			int now = cal2048(time + 1, i, field, n);
			max_num = max(now, max_num);
		}
		return max_num;
	}
	//�̵� ���
	if (dir == 0) goUp(field, n);
	else if (dir == 1) goDown(field, n);
	else if (dir == 2) goLeft(field, n);
	else goRight(field, n);
	//5�� ���ϸ� ��
	if (time == 5) {
		//�ִ� �� ���
		max_num=findMaxNum(field, n);
		return max_num;
	}
	//�ƴϸ� ���� ���
	for (int i = 0; i < 4; i++) {
		int now = cal2048(time + 1, i, field, n);
		max_num = max(now, max_num);
	}
	return max_num;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
	cout<<cal2048(0, 0, field, n);
	return 0;
}