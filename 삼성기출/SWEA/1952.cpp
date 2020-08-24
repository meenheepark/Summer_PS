#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int result = 987654321;
int cost[4]; // 요금
int day[13];

/*
SWEA
문제번호 : 1952
브루트포스 혹은 그리디
*/

void dfs(int month, int sum){
    
    if(month > 12){
     	result = min(result, sum);
    	return;
    }
    
    for(int  i = 0 ; i < 4 ; i++){ // 하고가거나 안하고가거나?
    	if(i == 0){ // 1일
        		dfs(month + 1, sum + cost[0]*day[month]);
        }
        else if(i == 1){ // 1달
        	  dfs(month + 1, sum + cost[1]);
        }
        else if(i == 2){ // 세달
        	dfs(month + 3, sum + cost[2]);
        }
        else{ // 1년
            dfs(month + 12, sum + cost[3]);
        }
    }
	
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 987654321;
        cin >> cost[0] >> cost[1]>> cost[2]>> cost[3];
       	for(int i = 1; i <= 12 ; i++) cin >> day[i];
        
        dfs(1, 0);	
        
        cout <<"#" << test_case << " " <<result << endl;
        result = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}