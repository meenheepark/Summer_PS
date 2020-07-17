#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 1918
문제 이름 : 후위 표기식
문제 설명 : 스택사용법 .. 간과한점. top보다 우선순위가 높아야 푸쉬한다...
*/

string ss;
vector <char> ans;
stack <char> s;

int main()
{
	cin >> ss;
	for (int i = 0; i < ss.size(); i++) {
        if ('A' <= ss[i] && ss[i] <= 'Z')

            ans.push_back(ss[i]);

        //operator(연산자)

        else

        {

            switch (ss[i])

            {

            case '(':

                s.push(ss[i]);

                break;

            case '*':

            case '/':

                //우선순위 제일 높으므로 같은 기호들 pop

                while (!s.empty() && (s.top() == '*' || s.top() == '/'))

                {

                    ans.push_back(s.top());

                    s.pop();

                }

                s.push(ss[i]);

                break;

            case '+':

            case '-':

                //우선순위 같거나 높은 기호들 pop

                while (!s.empty() && s.top() != '(')

                {

                    ans.push_back(s.top());

                    s.pop();

                }

                s.push(ss[i]);

                break;

            case ')':

                //'('가 나올 때까지 다 pop

                while (!s.empty() && s.top() != '(')

                {

                    ans.push_back(s.top());

                    s.pop();

                }

                //'(' pop

                s.pop();

                break;

            }

        }

	}

    while (!s.empty())

    {

        ans.push_back(s.top());

        s.pop();

    }


	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}

}
/*

*/

