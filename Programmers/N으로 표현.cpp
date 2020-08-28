#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 987654321;

void dfs(int N, int number,int cur, int cnt){
    if(cnt >= 9) return; // 범위넘음
    if(cur == number){
         answer = min(answer, cnt);   
    }
    
    int tmp = 0 ;
    for(int i = 0 ; i + cnt < 9 ; i++){ // 몇자릿수까지 곱하느냐
        tmp = tmp * 10 + N; // N,  NN, NNN...
        dfs(N, number, cur + tmp, cnt + i + 1);
        dfs(N, number, cur - tmp, cnt + i + 1);
        dfs(N, number, cur / tmp, cnt + i + 1);
        dfs(N, number, cur * tmp, cnt + i + 1);
    }
}


int solution(int N, int number) {
    dfs(N, number, 0,0);
    if(answer > 8) answer = -1;
    return answer;
}
