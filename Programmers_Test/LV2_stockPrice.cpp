#include <string>
#include <vector>
#include <stack>


std::vector<int> solution(std::vector<int> prices) {
    std::vector<int> answer (prices.size());
    std::stack<int> myStack;
    
    int numPrice = prices.size();
    
    for(int i = 0; i < numPrice; i++) {
        while(!myStack.empty() && prices[myStack.top()] > prices[i]) {
            answer[myStack.top()] = i - myStack.top();
            myStack.pop();
        }
        myStack.push(i);
    }
   
    while(!myStack.empty()) {
        answer[myStack.top()] = numPrice - myStack.top() -1;
        myStack.pop();
    }
    return answer;
}
