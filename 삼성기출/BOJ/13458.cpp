#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

/*
백준
문제번호 : 13458
문제설명 : 
그리디인듯 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.
*/
long long N, B, C;
vector <long long> a;
int result = 987654321;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long num;
         cin >> num; 
         a.push_back(num);
    }
    cin >> B >> C;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long stu = a[i];
        stu -= B;
        sum++;
        //stu를 자릿수?만큼 나눠서.C의 배수중 가장 큰것으로 빼기.
        if (stu > 0) {
            if (stu % C == 0) sum += (stu / C);
            else sum += (stu / C) + 1;
        }
    }
    cout << sum << endl;
}
