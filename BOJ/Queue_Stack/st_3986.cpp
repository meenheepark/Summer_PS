#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/*
백준
문제번호 : 3986
문제설명 : 한줄에 한단어, 같은게 들어오면 팝하자
*/
int n;

int main()
{
    cin >> n;
    int cnt = 0;
    string s;
    for (int i = 0; i < n; i++) {
        stack <char> st;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (st.empty()) { st.push(s[j]); }
            else {
                if (st.top() == s[j]) st.pop();
                else st.push(s[j]);
            }
        }
        if (st.empty()) { 
            cnt++; }
    }

    cout << cnt << endl;
}
