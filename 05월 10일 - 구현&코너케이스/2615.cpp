//2615 ����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 19;

//�������� üũ
vector<pair<int, int>> calWin(const vector<vector<int>>& field, const int &x, const int &y) {
	vector<pair<int, int>> ans;		//������ ��ġ�� ����, ���ʿ� �ִ� ���� ���� �����ϹǷ� ����� ���Ǹ� ���� {y,x}����� ����
	vector<pair<int, int>> direct = { {0,1},{1,0},{1,-1},{1,1} };	//������, �Ʒ�, ���� �Ʒ� �밢��, ������ �Ʒ� �밢�� üũ

	for (int i = 0; i < direct.size(); i++) {
		ans.push_back({ y,x });
		int nowx = x, nowy = y;
		//üũ�Ϸ��� ������ �ݴ���⿡ ���� ���� ������ �н�(�������� �ƴϹǷ� �Ѿ��.)
		int prevx = nowx - direct[i].first, prevy = nowy - direct[i].second;
		if (prevx >= 0 && prevx < MAX && prevy >= 0 && prevy < MAX && field[prevx][prevy] == field[x][y]) {
			ans.clear();
			continue;
		}
		while (true) {
			nowx += direct[i].first;
			nowy += direct[i].second;
			//������ ����ų� ���� ���� �ƴϸ� ���߱�
			if (nowx < 0 || nowx >= MAX || nowy < 0 || nowy >= MAX || field[nowx][nowy] != field[x][y]) break;
			ans.push_back({ nowy,nowx });
		}
		if (ans.size() == 5) break;
		//�ٵϵ� ������ �� �ټ����� �ƴϸ� ����
		ans.clear();
	}
	return ans;
}

vector<int> cal(vector<vector<int>>& field) {
	vector<int> ans;
	vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (field[i][j] == 0) continue;		//�� ���̸� �н�
			vector<pair<int, int>> nowans = calWin(field, i, j);
			if (nowans.empty()) continue;		//���� ������ �Ѿ��
			//�̰����� ���� ����, ���� ������ ������ ����ϰ� ������.(�迭�� 0�����ͽ����ϱ� ������ 1�� ���Ѵ�.)
			pair<int, int> min_xy = *min_element(nowans.begin(), nowans.end());
			ans.push_back(field[i][j]);
			ans.push_back(min_xy.second + 1);
			ans.push_back(min_xy.first + 1);
			break;
		}
		if (!ans.empty()) break;
	}
	return ans;
}

int main() {
	vector<vector<int>> field(MAX, vector<int>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) cin >> field[i][j];
	}
	//���
	vector<int> ans = cal(field);
	//���
	if (ans.empty()) cout << 0;
	else cout << ans[0] << '\n' << ans[1] << " " << ans[2];
}