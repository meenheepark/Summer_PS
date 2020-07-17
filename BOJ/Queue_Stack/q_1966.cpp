#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 1966
문제 이름 : 프린터 큐
문제 설명 :  
*/

queue <int> q;
int t, n, m; // m은 위치
int pri[101];
int a[101]; // 프린트 순서 적음.
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		int key;
		for (int j = 0; j < 101; j++) {
			pri[j] = -1; // 우선순위 저장 배열 초기화
		}
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			q.push(num);
			pri[j] = num;
			if (j == m) {
				key = num;
			}
		}
		int k_cnt = 0;
		for (int j = 0; j < n; j++) {
			if (key == pri[j]) {
				k_cnt++;
			}
		}
		int p_cnt = 0;
		while (!q.empty()) {
			int check = 0;
			int f = q.front();
			//cout << f;
			for (int j = 0; j < n; j++) {
				if (f < pri[j]) {
					q.pop();
					q.push(f);
					check = 1;
					break;
				}
			}
			if (check == 0) { // 큰게 없으면 팝
				if (q.front() == key) {
					k_cnt--;
				}
				for (int j = 0; j < n; j++) {
					if (f == pri[j]) {
						pri[j] = -1;
						break;
					}
				}
				q.pop();
				p_cnt++;
			}
			if (k_cnt == 0) {
				cout << p_cnt << endl;
				break;
			}
		}
		
	}

}
/*

*/

