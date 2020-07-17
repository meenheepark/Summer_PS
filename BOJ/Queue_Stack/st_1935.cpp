#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 1935
문제 이름 : 후위 표기식 2
문제 설명 : 스택사용법 .. 간과한점. top보다 우선순위가 높아야 푸쉬한다...
*/
int n;
string ss;
vector <char> ans;
stack <double> st;
int a[101];
int main()
{
    cin >> n;
	cin >> ss;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = 0;
    //나뉠때가.. 내생각엔 우선순위가 차이가 생길때 * -> -
    for (int i = 0; i < ss.size(); i++) {
        if ('A' <= ss[i] && ss[i] <= 'Z') {
            st.push(a[ss[i] - 'A']);
        }
        //operator(연산자)

        else {
            double q = st.top();
            st.pop();
            double r = st.top();
            st.pop();

            switch (ss[i]) {
            case '*': {
                st.push(q * r); 
                break; 
            }
            case '/': {
                st.push(r/q);
                break;
            }
            case '+': {
                st.push(q + r);
                break;
            }
            case '-': {
                st.push(r - q);
                break;
            }
            }
        }
    }
    double result = st.top();
    cout << fixed;
    cout.precision(2);
    cout << result << "\n";
    return 0;

}
/*

*/

