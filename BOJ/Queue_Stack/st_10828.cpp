#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 10828
문제 이름 : 스택
문제 설명 : 
   */
stack <int> st; // 마지막 인덱스
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
			st.push(num);
		}
		else if (s.find("pop") == 0) {
			if (st.empty()) cout << "-1" << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (s.find("size") == 0) {
			cout << st.size() << "\n";
		}
		else if (s.find("empty") == 0) {
			if (st.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (s.find("top") == 0) {
			if (st.empty()) cout << "-1" << "\n";
			else cout << st.top() << "\n";
		}
	}
}
/*

*/

