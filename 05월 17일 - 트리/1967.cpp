//1967 Ʈ���� ����
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
    int pos = node, len = 0; //������ �����ϴ� ��� �� �ϳ�, �� �������� �Ÿ�
    for (int i = 0; i < graph[node].size(); i++) {//���� ����� ��� ��忡 ����
        int next_node = graph[node][i].first;   //���� ���
        if (next_node == parent) {     //���� ��尡 �θ�� �Ѿ��.
            continue;
        }

        ci dfs_search = dfs(next_node, node, graph); //�ڽ� ��忡 ���� dfs Ž��
        if (graph[node][i].second + dfs_search.second > len) { //���� �Ÿ����� ��ٸ� ����
            len = graph[node][i].second + dfs_search.second;
            pos = dfs_search.first;     //�ش� �Ÿ��� ���
        }
    }
    return { pos, len };    //���� �� �Ÿ��� ���, ����Ž��
}

/**
 * [Ʈ���� ����]
 *
 * 1. ������ �̷�� �� ���� ��� ���� ���
 * 2. ������ �� ��忡�� ���� �ָ� �ִ� ���(���� ���)�� ������ �̷�� ��� �� �ϳ�
 * 3. ������ �̷�� ��忡�� ���� �ָ� �ִ� ���� ������ �̷�� �ٸ� ���
 *
 * �θ�->�ڽ��� ���⸸ �����ϸ� ���� ��忡�� �ٸ� ���� ���� Ž���� �� �����Ƿ� ������ �׷����� ����
 */

int main() {
    int n, p, c, w;

    //�Է�
    cin >> n;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    for (int i = 1; i < n; i++) { //������ �׷����� �����
        cin >> p >> c >> w;
        graph[p].push_back({ c, w });   // p->c ����ġ w
        graph[c].push_back({ p, w });   // c->p ����ġ w
    }

    //����
    ci first_node = dfs(1, -1, graph); //������ �����ϴ� ��� �ϳ� ã��
    ci second_node = dfs(first_node.first, -1, graph); //������ �����ϴ� �ٸ� ��� ã��

    //���
    cout << second_node.second;
    return 0;
}