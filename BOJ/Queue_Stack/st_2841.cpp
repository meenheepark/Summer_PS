#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/*
백준
문제번호 : 2841
문제설명 : 높은게 들어오면 높은것을 그냥 누르고, 작은게 들어오면 높은것들을 떼고 작은것.
            줄을 바꿀때에는 상관 없음. 그냥 줄마다 스택을따로..
*/
int n, p;
stack <int> st[7];

int main()
{
    cin >> n >> p;
    int line = 0; // 현재 줄
    int cnt = 0;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> line >> k;
        if (st[line].empty()) {
            st[line].push(k);
            cnt++; 
        }
        else {
            if (st[line].top() < k) {
                st[line].push(k);
                cnt++; 
            }
            else if (st[line].top() > k) {
                while (!st[line].empty() && st[line].top() > k) {
                    st[line].pop();
                    cnt++; 
                }
                if (st[line].empty()) {
                    st[line].push(k);
                    cnt++;
                }
                else if (!st[line].empty() && st[line].top() < k) {
                    st[line].push(k);
                    cnt++; 
                }
            }
        }
    }

    cout << cnt << endl;
}
