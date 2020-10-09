#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
//시뮬레이션, 완탐

int N, K, ans;
int min_num = 987654321;
vector <string> v;
vector <int> num_v;

string turn(string s) { // 회전 함수
    string tmp = "";
    tmp += s[s.size() - 1];
    for (int i = 1; i < s.size(); i++) {
        tmp += s[i - 1];
    }
    return tmp;
}

void add(string s) { // N/4 씩 자르고 모든 경우의수 벡터에 추가하는 함수
    for (int i = 0; i < s.size(); i+=N/4) {
        string k= "";
        for (int j = 0; j < N / 4; j++) {
            k += s[i + j];
        }
        int check = 0;
        for (int r = 0; r < v.size(); r++) {
            if (v[r] == k) {
                check = 1;
                break;
            }
        }
        if(check == 0) v.push_back(k);
    }
}

void change(vector <string> v) { // 16진수를 10진수로 바꾼 후 K번째 값 찾기
    for (int i = 0; i < v.size(); i++) {
        int k = 1;
        int num = 0;
        
        for (int j = N/4 - 1; j >= 0 ; j--) {
            if (v[i][j] == 'A') {
                num += k * 10;
            }
            else if (v[i][j] == 'B') {
                num += k * 11;
            }
            else if (v[i][j] == 'C') {
                num += k * 12;
            }
            else if (v[i][j] == 'D') {
                num += k * 13;
            }
            else if (v[i][j] == 'E') {
                num += k * 14;
            }
            else if (v[i][j] == 'F') {
                num += k * 15;
            }
            else {
                int t = v[i][j]-'0';
                num += k * t;
            }
            k *= 16;
        }
        num_v.push_back(num);
    }
    sort(num_v.begin(), num_v.end(), greater<int>());
    ans = num_v[K - 1];
    return;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
         ans = 0;
        cin >> N >> K;
        string s;
        cin >> s;
        //vector <string> v;
        //벡터 초기화
        int size = s.size();
        for (int i = 0; i < N / 4; i++) {
            s = turn(s);
            add(s);
        }
        change(v);

        cout << "#" << test_case << " " << ans << endl;
        v.clear();
        num_v.clear();
    }

}
