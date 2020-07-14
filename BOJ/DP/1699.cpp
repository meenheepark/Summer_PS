#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 1699
문제 이름 : 제곱수의 합.
문제 설명 :  
*/

int n,k;
long long dp[100001]; // [idx], [몇개] 써서 넘길지
int main()
{
	cin >> n;
	for (int i = 1; i <= n ; i++) { // n부터 해서 내려감.
		dp[i] = i; // 1로만 채워졌을때 최대갯수는 i
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1; // i에서 j제곱을 빼내어 제곱수로 하는게 더 작으면 바꿔준다.
			}
		}
	}
	cout << dp[n] << endl;

}
/*

*/

