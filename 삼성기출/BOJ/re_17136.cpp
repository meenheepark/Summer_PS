#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

/*
백준
문제번호 : 17136
문제설명 : 색종이 붙이기.. 백트래킹 종류
브루트포스? 무조건 왼쪽부터 하면 안됨..  가로로 최대크기 구하고.. 그거부터 덮을수 있는지 보고 안되면 작은거.
*/

int a[11][11];
int p[6] = {0,5,5,5,5,5}; // 색종이.

int result;
int ans;
//1인 칸이 나오면 그게 색종이 최대크기 몇까지 되는지. 

void dfs(int x, int y) { // x,y좌표에서 시작.

    if (y == 10) { // 다음줄
        dfs(x + 1, 0);
        return;
    }

    if (x == 10) {
        //다돌았다.
        result = min(result, ans);
        return;
    }

    if (a[x][y] == 0) {
        dfs(x, y + 1); // 그냥 다음칸 확인
        return;
    }

    for (int k = 5; k >=1; k--) { // 색종이 길이는 최대 5
        bool check = true;
        if (p[k] > 0 && x + k <= 10 && y + k <= 10) { // 그 종이 크기가 남아있어야 함.

            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                        if (a[i + x][j + y] == 0) {
                            check = false;
                            break;
                        }
                }
                if (check == false) break;
            }

            if (check == false) { // 중간에 나왔다.
                continue;
            }
            p[k]--;
            ans++;
            //0으로 만들어주기.
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    a[i + x][j + y] = 0;
                }
            }
            dfs(x, y + k);
            // 돌리고 다시 원래대로
            p[k]++;
            ans--;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    a[i + x][j + y] = 1;
                }
            }
        }
    }


}

int main()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    result = 987654321;
    dfs(0, 0);
    if (result == 987654321) cout << -1 << endl;
    else cout << result << endl;
}