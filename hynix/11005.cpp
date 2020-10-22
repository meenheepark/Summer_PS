#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

long long N;
int B;

int main() {
	cin >> N >> B;
	int tmp = N;
	vector <int> v;
	int idx = 0;
	while (tmp != 0) {
		int k = tmp % B;
		tmp /= B;
		v.push_back(k);
		idx++;
	}
	for (int i = idx-1; i >= 0; i--) {
		if (v[i] < 10) {
			cout << v[i];
		}
		else {
			char t = v[i] + 55;
			cout << t;
		}
	}
	cout << endl;
}
