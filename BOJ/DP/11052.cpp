#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 11052
문제 이름 : 카드구매하기.
문제 설명 :  
*/

int n,k;
long long dp[1001]; // [idx], [몇개] 써서 넘길지
long long cost[1001];
int main()
{
	cin >> n;
	for (int i = 1; i <= n ; i++) { 
		cin >> dp[i];
	}

	for (int i = 1; i <= n; i++) {// 갯수가 적고 비싸거나 갯수가 많고 비싸거나
		cost[i] = dp[i];
		for (int j = 1; j <= i; j++) {
			if (cost[i] < cost[i - j] + dp[j]) {
				cost[i] = cost[i - j] + dp[j];
			}
		}
	}

	cout << cost[n] << endl;

}
/*

*/

