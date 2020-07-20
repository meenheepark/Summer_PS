#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 9012
문제 이름 : 괄호
문제 설명 : 
   */
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		stack <char> st;
		bool check = true;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') {
				st.push(s[j]); 
			}
			else if(s[j] == ')'){
				if (!st.empty()) {
					st.pop();
				}
				else if(st.empty()) check = false;
			}
		}
		
		if(st.empty() && check == true)cout << "YES" << endl;
		else if (check == false || !st.empty()) cout << "NO" << endl;
	}
}
/*

*/

