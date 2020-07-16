#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 11055
문제 이름 : 가장 큰 증가부분수열
문제 설명 :  첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.
점화식 -  
*/

int n;
int a[1001];
int dp[1001]; //증가이기때문에 마지막값도 저장을 해줘야하고 dp에는 가

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}

	for (int i = 0; i < n; i++) { //i에서 시작.
		dp[i] = a[i]; // 처음포함되면
		for (int j = 0; j < i ; j++) { // 해당위치에서 합의 최대. 마지막값도 저장해둬야댐
			if (dp[i] < dp[j] + a[i] && a[j] < a[i]) {
				dp[i] = dp[j] + a[i];
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}

	cout << result << endl;

}
/*

*/

