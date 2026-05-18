#include <string>
#include <vector>
#include <queue>


std::string solution(std::vector<std::string> cards1, 
                     std::vector<std::string> cards2, 
                     std::vector<std::string> goal) 
{
    std::queue<std::string> c1, c2, g;
    
    // 카드의 goal를 큐로 표현하기
    for(const std::string& s : cards1) c1.push(s);
    for(const std::string& s : cards2) c2.push(s);
    for(const std::string& s : goal) g.push(s);
    
    // 단어 배열을 앞부터 순회
    while(!g.empty()){
        //c1의 현재 문자열과 g의 현재 문자열이 일치한다면? 제거
        if(!c1.empty() && c1.front() == g.front()) {
            c1.pop();
            g.pop();
        }
        // c2의 현재 문자열과 g의 현재문자열이 일치한다면?제거 
        else if(!c2.empty() && c2.front() == g.front()) {
             c2.pop();
             g.pop();
            
        }
        else{
            // 일치는 카드가 없으면 반복문 빠져나가기
            break;
        }
        
    }
 
    return g.empty() ? "Yes" : "No";
}
