#include <iostream>
#include <deque>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 10866
문제 이름 : 덱
문제 설명 :
*/

deque <int> dq;
int n;
int main()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.find("push_back") == 0) {
			long long num;
			cin >> num;
			dq.push_back(num);
		}
		else if (s.find("push_front") == 0) {
			long long num;
			cin >> num;
			dq.push_front(num);
		}
		else if (s.find("pop_front") == 0) {
			if (dq.empty()) cout << "-1" << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (s.find("pop_back") == 0) {
			if (dq.empty()) cout << "-1" << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (s.find("size") == 0) {
			cout << dq.size() << "\n";
		}
		else if (s.find("empty") == 0) {
			if (dq.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (s.find("front") == 0) {
			if (dq.empty()) cout << "-1" << "\n";
			else cout << dq.front() << "\n";
		}
		else if (s.find("back") == 0) {
			if (dq.empty()) cout << "-1" << "\n";
			else cout << dq.back() << "\n";
		}

	}


}
/*

*/

