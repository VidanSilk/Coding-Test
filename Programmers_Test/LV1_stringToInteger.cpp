#include <string>
#include <vector>
#include <algorithm>

int solution(std::string s) {
   
    int answer = 0;
    int checkSum = 0;
    
    if(s[0] == '-'){
        checkSum = 1;
        answer = stoi(s.substr(1));
    }
    else if(s[0] == '+'){
        answer = stoi(s.substr(1));
    }
    else{
        answer = stoi(s);
    }
    if(checkSum == 1){
        answer *= -1;
    }
    
    return answer;
}
