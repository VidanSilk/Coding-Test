#include<string>
#include <iostream>
#include<stack>

bool solution(std::string s)
{
    bool answer = true;
    std::stack<char> myStack;
    for(auto it : s){
        if(it == '('){
            myStack.emplace(it);
        }
        else {
            if(true == myStack.empty()){
                return false;
            }
            else{
                myStack.pop();       
            }
        }
    }
        
    return myStack.empty();
}
