#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string N;
int B;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> B;
	long long ans = 0;
	int tmp = 1;
	for (int i = N.size() - 1; i >= 0; i--) {
		if (N[i] >= '0' && N[i] <= '9') {
			int k = (int)N[i] - '0';
			k *= tmp;
			ans += k;
			//cout << "1  " << ans << endl;
		}
		else {
			int k = ((int)N[i] - 55);
			k*= tmp;
			ans += k;
			//cout << "2  " << ans << endl;
		}
		tmp *= B;
	}
	cout << ans << endl;
}
