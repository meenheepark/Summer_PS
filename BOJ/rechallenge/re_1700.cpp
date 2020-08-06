#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

/*
문제번호 : 1700
문제 설명:플러그를 빼는 횟수를 최소화
*/

int N, K;
int plug[101];
int sch[101];

int main() {
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> sch[i];
	}
	int result = 0;
	for (int i = 0; i < K; i++) { // 이번에 꽂을 전자기기
		// 꽂혀있는지 확인
		bool ok = false;
		for (int j = 0; j < N; j++) {
			if (plug[j] == sch[i]) {
				ok = true;
				break;
			}
		}
		if (ok) continue;

		// 아직 플러그가 다 안참. 빈거 확인.
		for (int j = 0; j < N; j++) {
			if (!plug[j]) {
				plug[j] = sch[i];
				ok = true;
				break;
			}
		}

		if (ok) continue;
		//빈것이 없으면 가장 오래 안쓸것이나앞으로 안쓸거를 빼고 꽂는다 
		int p_idx = -1; int d_idx = -1;
		for (int j = 0; j < N; j++) {
			int next = 0;
			for (int r = i + 1; r < K; r++) {
				if (plug[j] == sch[r]) { break; } // 꽂혀있고 앞으로 쓸것이다.
				next++; // 지금으로부텨 몇번째 뒤에 꽂을것인지.
			}

			if (next > d_idx) { // 결국엔 가장 나중인애가 될거임. 안쓰면 next가 맥시멈
				p_idx = j;// 이 플러그에 꽂혀있는 애.
				d_idx = next; // 몇번째 뒤
			}
		}
		plug[p_idx] = sch[i];
		//cout << i << endl;
		result++;
	}

	cout << result << endl;
}