#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct applicant {
	int inter;  //���ͺ�����
	int doc;	//��������
};

bool cmp(const applicant& a, const applicant& b) {
	return a.doc < b.doc;
}
int main() {
	int t;	//�׽�Ʈ���̽� �Է�
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;	//n �Է�
		vector<applicant> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i].doc >> arr[i].inter;
		}

		//�������� �������� ����
		sort(arr.begin(), arr.end(), cmp);
		
		int min_inter = 1000000;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].inter < min_inter) {
				min_inter = arr[i].inter;
				count++;
			}
		}
		cout << count << endl;
		vector<applicant> arr2(0);
		arr.swap(arr2);
	}
	return 0;
}