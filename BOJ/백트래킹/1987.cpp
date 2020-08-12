#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int R, C;
char d[21][21];
int result = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1, 1,0,0};
int al[26] = { 0 };

void back_tr(int x, int y, int cnt) {
		result = max(result, cnt);

	for (int k = 0; k < 4; k++) {
		int rx = x + dx[k];
		int ry = y + dy[k];
		if (rx >=1 && rx <= R && ry <=C && ry >=1) {
			
			int t = (int)d[rx][ry] - 65;//A가 65부터
			if (al[t] > 0) continue;

			al[t]++;
			back_tr(rx, ry, cnt + 1);
			// 같으면 그냥 리턴하고 다르면 재귀한다.
			al[t]--; // 원래대로 되돌려놓는다.
		}
		
	}

}

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> d[i][j];
		}
	}
	al[(int)d[1][1] - 65]++;
	back_tr(1, 1, 1);
	cout << result << endl;

}