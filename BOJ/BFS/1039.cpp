#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*
백준
문제번호 : 1039
문제설명 : 
*/


//바뀐 수와, 갯수 for문 두번..
int main()
{
    ios_base::sync_with_stdio(0);
    string N;int K;
    cin.tie(0);

    cin >> N >> K;


    queue <string> q;
    q.push(N);
    for (int r = 0; r < K; r++) { // k번 한다
        int size = q.size();
        set <string> found;
        for (int l = 0; l < size; l++) {
            string x = q.front();
            q.pop();

            if (found.count(x)) continue; // 이미 한것이라면.
            found.insert(x);

            for (int i = 0; i < x.size()-1; i++) {
                for (int j = i+1; j < x.size() ; j++) {
                    if (i > 0 || x[j] != '0') { // 바꾼수의 맨 앞이 0으로 시작하면 안되니깐
                        swap(x[i], x[j]);
                        q.push(x);
                        swap(x[i], x[j]);
                    }
                }
            }
        }
    }
    string result = "0";
    while (!q.empty()) {
        result = max(result, q.front());
        q.pop();
    }
    if (result[0] == '0') cout << -1 << endl;
    else cout << result << endl;
}
