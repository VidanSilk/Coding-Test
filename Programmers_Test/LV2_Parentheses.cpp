#include <string>
#include <vector>
#include <stack> 
#include <unordered_map>

std::unordered_map<char, char> checkPair = {
    {')','('},
    {']','['}, 
    {'}','{'}    
};

// argument로 받은 문자열 기준으로 괄호의 짝이 맞는지 체크 해주는 함수 정의
bool isValid(std::string &s, int start){
    std::stack<char> charStack;
    unsigned int sz = s.size();
    
    //문자열 순회
    for(int i =0; i<sz; i++){
        char ch = s[(start + i) % sz];
        // ch가 닫힌 경우
        if(checkPair.count(ch)){
            // 스택이 비었거나 top 원소가 ch와 짝이 맞는 열린 괄호가 아니라면?
            if(charStack.empty() || charStack.top() != checkPair[ch]){
                return false;
            }
            // ch와 짝이 맞는 열린 괄호라면 해당 열린 괄호 제거
            charStack.pop();
        }else {
            charStack.push(ch); //열린 괄호면 스택에 넣기
        }
    }
    return charStack.empty();
}

int solution(std::string s) {
    int answer = 0;
    int n = s.size();
    // 문자열 순회
    for(int i = 0; i< n; i++){
        answer += isValid(s,i);
    }
    return answer;
}
