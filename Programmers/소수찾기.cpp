#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool *prime;
//
void eratos(int num){
    prime = new bool[num+1];
    prime[0] = false;
    prime[1] = false; 
    for(int i = 2 ; i <= num ;i++){
        prime[i] = true; // 아닌것만 false
    }
    
    for(int i = 2 ; i*i <= num ; i++){
        if(prime[i] == true){
            for(int j = i+i ; j <= num; j+=i){
                prime[j] = false;
            }//소수의 배수는 다 false로   
        }
    }
    
}

bool isinclude(int num, string numbers){
    string k = to_string(num);
    for(int i = 0 ; i < k.size() ; i++){
        bool check = false;
        for(int j = 0 ; j <= numbers.size(); j++){
            if(numbers[j] == k[i]){
                check = true;
                numbers[j] = ' ';
                break;
            }
        }
        if(check == false) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>()); // 내림차순 정렬
    int num = stoi(numbers);
    eratos(num);
    
    for(int i = 0 ; i <= num; i++){
        if(prime[i] && isinclude(i, numbers)){
            answer++;
        }
    }
    
    return answer;
}
