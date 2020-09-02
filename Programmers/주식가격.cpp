#include <string>
#include <vector>
#include <stack>
using namespace std;
//새로 나온것이 기존것보다 작으면 무언가를 해주어야한다.
//스택에 쌓다가 작은게 나오면
// 숫자가 구분이 안되니까 인덱스로 푸쉬해준다.
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack <int> st;
    for(int i = 0 ; i < prices.size() ; i++){
        while(!st.empty() && prices[st.top()] > prices[i]){
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
        while(!st.empty()){
            answer[st.top()] = prices.size() - st.top() - 1;
            st.pop();
        }
    return answer;
}
