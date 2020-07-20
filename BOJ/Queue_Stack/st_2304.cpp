#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2304
문제 이름 : 창고다각형
문제 설명 : 창고 주인은 창고 다각형의 면적이 가장 작은 창고를 만들기를 원한다.
   */
int n, l , h;
int a[1001];
stack <int> st;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		a[l] = h;
	}
	int sum = 0;
	st.push(0); // 없을수도
	for (int i = 0; i < 1001; i++) {
		//if(a[i] != 0 && a[st.top()] < a[i]) st.push(i);
		if (a[i] != 0 && a[st.top()] < a[i]) {
			int width = i - st.top();
			int height = a[st.top()];
			int n = width * height;
			sum += n;
			st.pop();
			st.push(i);
		}
	}
	// st.top에는 가장 높은애것만 있음. 거꾸로 가서 top에있는데까지 최대

	int k =  st.top();
	stack <int> st;
	st.push(1000);
	for (int i = 1000; i > k - 1; i--) {
		//if(a[i] != 0 && a[st.top()] < a[i]) st.push(i);
		if (a[i] != 0 && a[st.top()] < a[i]) {
			int width = st.top() - (i);
			int height = a[st.top()];
			int n = width * height;
			sum += n;
			//cout << i << " " << n << endl;
			st.pop();
			st.push(i);
		}
	}
	int k2 = st.top();

	int r = k2 + 1 - k;
	int b = max(a[k2], a[k]);
	sum += r * b;

	cout << sum;
}
/*

*/

