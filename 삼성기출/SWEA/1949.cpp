#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int N, K;
int result = 0;
int d[9][9];
int visited[9][9];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

/*
SWEA
문제번호 : 1949
*/

void dfs(int x, int y, int cnt){
    //visited[x][y] =1 ;
	for(int i = 0 ; i < 4 ; i++){
    	int rx = x+dx[i];
        int ry = y+dy[i];
        if(rx >= 0  && rx < N && ry >= 0 && ry < N  && visited[rx][ry] == 0){
        	if(d[x][y] > d[rx][ry]){
               visited[rx][ry] = 1 ;
            	dfs(rx, ry, cnt+1); // 백트래킹
                visited[rx][ry] = 0;
            }
        }
    } // 네방향 다 봤는데 없다.
    
    result = max(result, cnt);
    //visited[x][y] =1 ;
    return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> K;
        int h = -1;
        vector <pair<int, int>> v;
        memset(d, 0, sizeof(d)); // 초기화
        
			for(int i = 0 ; i < N ; i++){
            	for(int j = 0 ; j <  N ; j++){
                	cin >> d[i][j];
                    h = max(h, d[i][j]);
                }
            }
        
        for(int i = 0 ; i < N ; i++){
            	for(int j = 0 ; j <  N ; j++){
                	if(h == d[i][j]) v.push_back(make_pair(i, j));
                }
        }
        
        for(int k = 1 ; k <= K ; k++){ // k는 깎는 높이. 최대 5
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j  < N ; j++){
                    	d[i][j] -= k;
                        for(int r = 0 ; r < v.size() ; r++){
                        	dfs(v[r].first, v[r].second, 1);
                        	memset(visited, 0, sizeof(visited));
                        }
                    	d[i][j] += k;
                }	
            }	
        }
	
        cout <<"#" << test_case << " " <<result << endl;
        result = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}