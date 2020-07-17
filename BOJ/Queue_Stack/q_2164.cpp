#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 2164
문제 이름 : 카드2
문제 설명 :  
*/

queue <int> q;
long long n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		q.pop(); // 맨위의 카드 버린다.
		long long num = q.front();
		q.pop();
		q.push(num);
	}
	cout << q.front() << endl;

}
/*

*/

