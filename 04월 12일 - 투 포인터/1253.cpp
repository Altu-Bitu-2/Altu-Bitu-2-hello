﻿//1253 좋다
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int>& num, int left, int right, int idx) {
    //양 끝부터 시작해서 범위를 좁혀나간다.
    while (left < right) {
        //선택된 두 수는 표적이 아니어야한다.
        if (left == idx) {
            left++;
            continue;
        }
        if (right == idx) {
            right--;
            continue;
        }
        //선택된 두 수의 합으로 표현이 되면 좋은 수다.
        if (num[left] + num[right] == num[idx]) {
            return true;
        }//두 수의 합이 더 크다면 큰 수를 줄인다.
        if (num[left] + num[right] > num[idx]) {
            right--;
        }//두 수의 합이 더 작다면 작은 수를 높인다.
        else {
            left++;
        }
    }
    return false;
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0;

    //입력
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.end());       //수를 정렬한다.
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i)) { //좋은 수면 체크
            ans++;
        }
    }

    //출력
    cout << ans;
    return 0;
}