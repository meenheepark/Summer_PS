#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector <pair<char, int>> al;
vector <char> result;

//암호는 서로 다른 L개의 알파벳 소문자들로 구성되며
//최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다.
// 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것

void back_tr(int idx, int ja_cnt, int mo_cnt, string s) {
	if (s.size() == L && mo_cnt >= 1 && ja_cnt >= 2) {
		cout << s << endl;
		return;
	}

	//if (cnt == C) return;
	// 추가를 하거나 안하거나...1 
	for (int i = idx; i < C; i++) {
		if (al[i].second == 0) { // 모음이면,
			back_tr(i + 1, ja_cnt, mo_cnt + 1, s + al[i].first);
		}
		else { // 자음이면
			back_tr(i + 1, ja_cnt + 1, mo_cnt, s + al[i].first);
		}
	}
}


int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char s;
		cin >> s;
		if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') al.push_back(make_pair(s, 0));
		else al.push_back(make_pair(s, 1)); // 1이면 자음.
	}
	sort(al.begin(), al.end());

	back_tr(0, 0, 0, "");
}