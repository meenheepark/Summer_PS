#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

int N, M, R, C, L;
int d[51][51];
int visited[51][51];
int result = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

/*
SWEA
문제번호 : 1953
bfs
출력해야 할 정답은 탈주범이 위치할 수 있는 장소의 개수
*/

void bfs(int x, int y){
    
    queue <pair<int, int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    
    while(!q.empty()){
        int rx = q.front().first;
        int ry = q.front().second;
        q.pop();
        if(visited[rx][ry] == L) continue; // 종료조건
         // 0이면 갈 수 없음.
        int ax, ay;
                if(d[rx][ry] == 1){ // 상하좌우
                    	ax = rx + -1;
                        ay = ry; // 상.
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 5 || d[ax][ay] == 6)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                        ax = rx + 1;
                        ay = ry; //하
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 4 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                     	ax = rx ;
                        ay = ry - 1; //좌
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 4 || d[ax][ay] == 5)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                    	 ax = rx;
                        ay = ry + 1; //우
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 6 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                }
                else if(d[rx][ry] == 2){ // 상하
						ax = rx -1;
                        ay = ry; // 상.
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 &&  (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 5 || d[ax][ay] == 6)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                    ax = rx + 1;
                     ay = ry; // 하
                    if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0  && (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 4 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                    }
                    
                }
                else if(d[rx][ry] == 3){ // 좌우
					    ax = rx ;
                        ay = ry-1; //좌.
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 4 || d[ax][ay] == 5)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                    ax = rx;
                    ay = ry+1; // 우
                    if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 6 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                    }
                }
                else if(d[rx][ry] == 4){ // 상우
					   ax = rx -1;
                        ay = ry;
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0  &&  (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 5 || d[ax][ay] == 6)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                       ax = rx;
                       ay = ry+1;
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 6 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                   
                }
                else if(d[rx][ry] == 5){ // 하우 
 						ax = rx+1 ;
                        ay = ry;
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0  && (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 4 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                    ax = rx;
                    ay = ry+1; // 우
                    if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 6 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                    }
                }
                else if(d[rx][ry] == 6){ // 하좌
					ax = rx+1 ;
                        ay = ry;
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0  && (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 4 || d[ax][ay] == 7)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                     ax = rx;
                     ay = ry-1;
                    if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 4 || d[ax][ay] == 5)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                    }
                }
                else if(d[rx][ry] == 7){ // 상좌
						 ax = rx-1 ;
                         ay = ry;
                        if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0  &&  (d[ax][ay] == 1 || d[ax][ay] == 2 || d[ax][ay] == 5 || d[ax][ay] == 6)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                        }
                    
                    ax = rx;
                    ay = ry-1;
                    if(ax >= 0 && ax < N && ay >= 0 && ay < M && visited[ax][ay] == 0 && (d[ax][ay] == 1 || d[ax][ay] == 3 || d[ax][ay] == 4 || d[ax][ay] == 5)){
                        	visited[ax][ay] = visited[rx][ry] + 1;
                        	q.push(make_pair(ax, ay));
                    }
                }
    
    }
    return;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 0;
        memset(visited, 0, sizeof(visited));
        cin >> N  >> M >> R >> C >> L ;
        
       	for(int i = 0; i < N ; i++){
        	for(int j = 0 ;  j < M ; j++) cin >> d[i][j];
        }
        
		bfs(R, C);
        
        for(int i = 0; i < N ; i++){
        	for(int j = 0 ;  j < M ; j++){
            	if(visited[i][j] > 0) result++;
            }
        }
        
        cout <<"#" << test_case << " "<<result << endl;
        result = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}