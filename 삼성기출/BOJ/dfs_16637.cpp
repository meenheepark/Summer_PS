#include <iostream>
#include <algorithm>
#include <string.h>
#include<climits>
using namespace std;

int N;
string s;
int result = 0;

int cal(int a, int b, char op) {
	int ans = a;
	switch (op)
	{
		case '*': ans *= b; break;
		case '+': ans += b; break;
		case '-': ans -= b; break;
	}
	return ans;
}

void DFS(int idx, int sum) {

	if (idx > N-1) {
		result = max(result, sum);
		return;
	}

	char op = (idx == 0) ? '+' : s[idx - 1]; // 처음이면 그냥 플러스 아니면 이전거에다가 붙이기
	//묶는다
	if (idx + 2 < N) { // 다음거
		int b = cal(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		DFS(idx + 4, cal(sum, b, op));
	}
	//안묶는다
	DFS(idx + 2, cal(sum, s[idx]-'0', op));
}

int main() {
	cin >> N >>  s;
	result = INT_MIN; // 이게없으면 안됨
	DFS(0, 0);
	cout << result <<endl;
}