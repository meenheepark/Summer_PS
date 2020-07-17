#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 10845
문제 이름 : 큐
문제 설명 :  
*/

queue <int> q;
int n;
int main()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.find("push") == 0) {
			long long num;
			cin >> num;
			q.push(num);
		}
		else if (s.find("pop") == 0) {
			if (q.empty()) cout << "-1" << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s.find("size") == 0) {
			cout << q.size() << "\n";
		}
		else if (s.find("empty") == 0) {
			if (q.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (s.find("front") == 0) {
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.front() << "\n";
		}
		else if (s.find("back") == 0) {
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.back() << "\n";
		}
	
	}


}
/*

*/

