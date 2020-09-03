#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, i = 0;
    string tmp(name.length(), 'A');
    while(true){
        tmp[i] = name[i];
        if(name[i] - 'A' > 'Z' + 1 - name[i]){
            answer += 'Z' + 1 - name[i];
        }
        else answer += name[i] - 'A';
        
        if(tmp == name) break;
        
        for(int move = 1 ; move < name.length(); move++){
            if(name[(i+move)%name.length()] != tmp[(i+move)%name.length()]){ // 오른쪽으로
                answer += move;
                i = (i+move)%name.length(); // 바뀐인덱스
                break;
            }
            else if(name[(i+name.length() - move)%name.length()] != tmp[(i+name.length() - move)%name.length()]){
                i = (i+name.length() - move)%name.length();
                answer += move;
                break;
            }
        }
    }
    return answer;
}
