#include <iostream>
#include<string>
#include <stack>

int solution(std::string s)
{
 std::stack<char> caStack;
    for(int i = 0; i < s.length(); i++){
        // 스택이 비어있거나, 현재 문자와 같은 문자가 아니라면 푸시
        if(caStack.empty() || caStack.top() != s[i]) {
            caStack.push(s[i]);
        }
        else {
            // 현재 문자와 스택의 가장 최근 문자가 같으면 팝
         caStack.pop();   
        }
        
    }
    return caStack.empty();
}
