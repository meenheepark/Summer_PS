#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬
    
    for(int i = 0 ; i < size ; i++){
        if(answer >= citations[i]) break;
        answer++;
    }
    
    return answer;
