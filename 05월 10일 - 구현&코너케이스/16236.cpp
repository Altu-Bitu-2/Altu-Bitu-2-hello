//16236 �Ʊ� ���
#include<iostream>
#include<queue>
#include<cmath>
#include<tuple>
using namespace std;
typedef pair<int, int> ci;
typedef tuple<int, int, int> ti;

int bfs(const int& n, vector<vector<int>>& field, ti& babyshark) {
	vector<ci> dir = { {-1,0},{0,-1},{0,1},{1,0} };			//�����¿� ���⺤��
	vector<vector<bool>> visited(n, vector<bool>(n, 0));	//�湮 ���
	priority_queue<ti, vector<ti>, greater<>> find;			//�ð��� ��������, row�� ��������, col�� �������� ���� ����Ѵ�.
	int shark = get<0>(babyshark), x = get<1>(babyshark), y = get<2>(babyshark);
	int now = 0;											//����⸦ �Ա����� �̵��� ��
	int cnt = 0;
	//�ʱ�ȭ. �Ʊ��� ��ġ���� Ž��	
	find.push({ now,x,y });
	while (!find.empty()) {
		now = get<0>(find.top());
		x = get<1>(find.top());
		y = get<2>(find.top());
		find.pop();
		if (visited[x][y] == 1) continue;
		visited[x][y] = 1;
		//���� �� �ִ� ������ ����⸦ �԰� ������.
		if (field[x][y] > 0 && field[x][y] < shark) {
			cnt = now;
			field[x][y] = 0;
			babyshark = { shark, x,y };
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nowx = x + dir[i].first;
			int nowy = y + dir[i].second;
			//���� ���̸� �Ѿ��.�̹� �湮������ �Ѿ��.
			if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= n || visited[nowx][nowy] == 1) continue;
			//ū ������ �� ������ ����������.
			if (field[nowx][nowy] > shark) continue;
			//���� �������� �����ų� �� ĭ�̶�� ��������.
			find.push({ now + 1,nowx,nowy });
		}
		now = 0;
	}
	return cnt;
}

int countFish(const int& n, vector<vector<int>>& field, ti& babyshark) {
	int ans = 0;		//�̵��� �ð�
	int eat = 0;		//���� ������
	while (true) {
		//����⸦ �Ա� ���� �̵��� �ð��� ���Ѵ�. 0�̸� ���� ����Ⱑ ���ٴ� ��
		int cnt = bfs(n, field, babyshark);
		if (cnt == 0) break;
		ans += cnt;
		eat++;
		//���� ����� ���� ��� ������� ���ٸ� ��� ����� Ű���.
		if (get<0>(babyshark) == eat) {
			get<0>(babyshark)++;
			eat = 0;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n));		//�ʵ�
	ti babyshark;							//�Ʊ��� ��ġ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j] == 9) {			//9�� �Ʊ�� �ǹ�,
				babyshark = { 2,i,j };		//�Ʊ����� ũ��, ��ġ�� ���
				field[i][j] = 0;
			}
		}
	}

	cout << countFish(n, field, babyshark);
}