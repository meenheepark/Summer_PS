#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 1725
문제 이름 : 히스토그램
문제 설명 : 완전탐색으로는 풀수없음 범위너무커서 시간초과날것... 스택으로 시간 줄인다.
   스택 탑보다 높이가 높으면 푸쉬하고, 스택탑보다 낮으면 팝하면서 계산하고 나중에 푸쉬. 탑이 가장 높은값으로 유지되게
   이전막대보다 현재막대가 더 작을때가 직사각형최대일때임
   */
long long n;
long long v[1000002];
stack <int> st; // 마지막 인덱스
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    long long result = 0;
    st.push(0);
    for (int i = 1; i <= n + 1; i++) {
        while (!st.empty() && v[st.top()] > v[i]) { // 더작은애가들어오면 팝해줘여함
            long long height = v[st.top()];
            st.pop();
            long long width = i - st.top() - 1;
            result = max(result, height * width);
        }
        st.push(i);
    }
    cout << result;
}
/*

*/

