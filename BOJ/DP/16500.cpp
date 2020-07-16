#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 16500
문제 이름 : 문자열판별
문제 설명 :  가치의 최댓값 k 무게까지만 해서 v의 합이 최대가되는것.
점화식 -  
무게의 합이 k이전으로 되는 것 중에 가치 합이 최대인것..

*/

string s;
int n;
int dp[101]; // 마지막 알파벳을 저장하는 방법으로하여 bottom up하는게나을듯
//n번째에서 시작해서 최대를 구해야함..
string a[101];
int t[101]; // 맞으면 1로 바꾸기

int main()
{
	cin >> s;
	cin >> n;
	int check = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; // 한단어씩 입력.
	}
	dp[s.length()] = 1; // 맨마지막에 1을 찍음.
	 // 뒤에서부터 탐색해서 남은것으로 만들수있는지를 담는 배열 dp
	for (int i = s.length()-1; i >=0 ; i--) { 
		for (int j = 0; j <= n; j++) { // 단어하나씩 비교해보기
			if (s.find(a[j], i) == i && dp[i + a[j].length()] == 1) {
				// 단어하나와. s에서 그위치에서부터 찾았을때 거기가 시작이 맞고, 
				// 그위치에서 단어길이만큼까지했을때가 한단어로 꽉 차면 그위치에 단어를 박아줌.
				// 한단어가 다른단어에 부분적으로 포함되더라도 성립함
				dp[i] = 1;
				break;
			}
			else {
				dp[i] = 0; // 그게아니면 0으로 냅둠
			}
		}
	}


	cout << dp[0] << endl;

}
/*

*/

