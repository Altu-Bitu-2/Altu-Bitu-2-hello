//5639 ���� �˻� Ʈ��
#include <iostream>

using namespace std;

struct node_info {      
    int data;           //��
    node_info* left;    
    node_info* right;
};

node_info* makeTree(node_info* node, int data) {
    if (node == NULL) { //�̹� ��尡 ���Ե� ��ġ
        node = new node_info(); //���� �Ҵ�
        node->data = data;
        node->left = node->right = NULL; //�������� �������
    }
    else if (node->data > data) {      //���� ������ 
        node->left = makeTree(node->left, data);    //�������� ����
    }
    else if (node->data < data) {   //���� ũ��
        node->right = makeTree(node->right, data);  //���������� ����
    }
    return node;
}

//���� ��ȸ
void postorder(node_info* node) {
    if (node == NULL) {         //����� ���� ������ ��
        return;
    }
    postorder(node->left);      //���� ���
    postorder(node->right);     //������ ���
    cout << node->data << '\n'; // �θ� ���
}

/**
 * �ʰ� �� PPT �� BST ��� ���� ���� ����
 *
 * [���� �˻� Ʈ��]
 *
 * 1. �����ͷ� ����, ������ ����Ʈ���� ����Ű�� ����ü ����
 * 2. NULL ���� ������ ���ǿ� ���� ���� �Ǵ� ���������� �̵�
 * 3. ��尡 �� ��ġ�� ã���� �����Ҵ� �� ��� �����
 * 4. �ϼ��� Ʈ���� ���� ��ȸ
 */

int main() {
    int input;

    //�Է� & ����
    node_info* root = NULL;    //Ʈ��   
    while (cin >> input) {
        root = makeTree(root, input);   //Ʈ���� ���� ����
    }

    //�ⷰ
    postorder(root);
    return 0;
}