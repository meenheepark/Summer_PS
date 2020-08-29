#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;


int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    vector<vector<int>> ans(size, vector<int>(size));
    
    ans[0][0] = triangle[0][0];
    for(int i = 1 ; i < triangle.size() ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0){
                ans[i][0] = ans[i-1][0] + triangle[i][0];
            }
            else if( i == j){
                ans[i][j] = ans[i-1][j-1] + triangle[i][j];
            }
            else{
                ans[i][j] = max(ans[i-1][j-1], ans[i-1][j]) + triangle[i][j];
            }
            
            if(i == triangle.size()-1){ // 마지막층
                answer = max(answer, ans[i][j]);
            }
        }
    }
    return answer;
}
