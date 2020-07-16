#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 12865
문제 이름 : 평범한 배낭
문제 설명 :  가치의 최댓값 k 무게까지만 해서 v의 합이 최대가되는것.
점화식 -  
무게의 합이 k이전으로 되는 것 중에 가치 합이 최대인것..

*/

long long n, k;
long long w[101], v[101];
long long dp[101][100001]; // 팩토리얼 값 저장.
//n번째에서 시작해서 최대를 구해야함..


int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i]; 
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) { // j무게까지의 최대구하기
			dp[i][j] = dp[i-1][j]; // 안더하고넘어감
			if (j - w[i] >= 0) { //더할수있으면
				dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]); // 더한것과 안더한것중 최대
			}
		}
	}


	cout << dp[n][k] << endl;

}
/*

*/

