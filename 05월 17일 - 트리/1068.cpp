//1068 Ʈ��
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//�־��� ������ ������ ���� ���� ����� ��
int eraseLeafCnt(int node, int& erase_node) {
    if (node == erase_node) {   //���� ��尡 (�κ�Ʈ����) ��Ʈ���� Ʈ���� ����.
        return 0;
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {    //���� ��尡 (�κ�Ʈ����)��Ʈ ����̰ų�, ��Ʈ�� ������ �ڽ��� ���� ����
        return 1;   //(�κ�Ʈ����)��Ʈ��� �ϳ��� ���´�.
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {   //���� ����� ��� �ڽĵ鿡 ����
        cnt += eraseLeafCnt(tree[node][i], erase_node);    //����� ������ ���� ���� �����Ѵ�. ��������� ������ üũ�Ѵ�. 
    }
    return cnt; //��������� ������ ��ȯ�Ѵ�.
}

/**
 * [Ʈ��]
 *
 * ���� ���� ��� ������ ���� dfs Ž������ ����� ������ ������ �� �̻� Ž������ �ʰ� 0�� ����
 *
 * !����! ����� ������ �ش� �θ� ����� ������ �ڽ� ��忴�� ���, �ش� ������ ����� �θ� ��尡 ���� ��尡 �ż� ������ 1 �������� ����
 * !����! ��Ʈ ��尡 �׻� 0�� �ƴ��� ����
 */

int main() {
    int n, par, root, erase_node;

    //�Է�
    cin >> n;
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        cin >> par;
        if (par == -1) {    //-1�̸� ��Ʈ
            root = i;   //��Ʈ��尪�� ����
            continue;
        }
        tree[par].push_back(i); //�θ��� par�� �ڽĳ�� i�� �ִ�.
    }
    cin >> erase_node;  

    //���� & ���
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}