#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
/*
백준
문제 번호 : 10265
문제 이름 : MT
문제 설명 : 끝까지 파고들어서 걔까지 합친게 num보다 적으면 넣고 아니면 말고
텀프로젝트같은문제...
   */

int n, num;
vector <int> v; 
int visited[1001];
int check[1001]; // 버스타는것에 포함이 되었는지 아닌지.
int d[1001];
int cnt = 0;


void dfs(int x) {
	if (visited[x] != 0) return;

	visited[x] = 1;
	cnt++;
	if (visited[d[x]] == 1) { // 끝까지 갔다, 그 묶음 갯수를 세야한다.
		return;
	}
	else dfs(d[x]);

}

int main()
{
	
	cin >> n >> num;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	int result = 0;
	for (int i = 1; i <= n; i++) { // 시작점.
		int sum = 0;
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = i; j <= n; j++) {
			if (!visited[j]) {
				dfs(j);//cout << cnt << "i,j" << i << j << endl;
				if (cnt > num) break;
				if(sum + cnt <= num) sum += cnt;
				result = max(result, sum);
				cnt = 0;
				 
			}
		}
	}
	cout << result << endl;
}
/*

*/

