#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 11727
문제 이름 : 2xn타일 2
문제 설명 :  
*/

int n;
long long dp[1001];
int main()
{
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] +  2*dp[i - 2]) % 10007;
	}
	cout << (dp[n]) % 10007;
}
/*

*/

