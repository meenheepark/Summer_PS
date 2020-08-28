#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){ // 최대 공약수
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a; // 최대공약수가 리턴됨.(나눌수 있는 최대수)
}
int LCM(int a, int b){ // 최소공배수
    return a * b / GCD(a, b);
}
int solution(vector<int> arr) {
    int answer = 0;
    int lcm = 1;
    for(int i = 0; i < arr.size(); i++){
        lcm = LCM(lcm, arr[i]);
    }
    answer = lcm;
    return answer;
}
