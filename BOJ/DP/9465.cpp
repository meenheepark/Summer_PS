#include <iostream>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 9465
문제 이름 : 스티커
문제 설명 :
*/
int t, n, m;
int sti[2][100001];
int d[100001][3]; // 떼졌는지상태검사.

int check(int i, int status) { // staus가 0이면 이전에안떼짐, 1이면 위에떼짐 2이면 아래떼짐
	if (i == n) return 0;
	if (d[i][status] != -1) return d[i][status];

	int result = check(i + 1, 0);
	if (status != 1) {
		result = max(result, check(i + 1, 1) + sti[0][i]);
	}
	if (status != 2) {
		result = max(result, check(i + 1, 2) + sti[1][i]);
	}
	d[i][status] = result;
	return result;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int result = 0;
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < n; j++) {
				cin >> sti[k][j];
			}
		}
		for (int k = 0; k < n; k++)
			for (int j = 0; j < 3; j++)
				d[k][j] = -1;
		int result2 = check(0, 0);

		cout << result2 << endl;
	}

}
/*

*/

