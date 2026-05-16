#include <string>
#include <vector>
#include <algorithm>

// 수포자 패턴 분석
// 1 - 12345
// 2- 21232425.... 212
// 3 - 3311224455... 331122

std::vector<int> solution(std::vector<int> answers) {
    //수포자들의 패턴 정리 
    std::vector<int> student1 {1,2,3,4,5};
    std::vector<int> student2 {2,1,2,3,2,4,2,5};
    std::vector<int> student3 {3,3,1,1,2,2,4,4,5,5};
    
    // 가장 많이 문제를 맞힌 걸 저장할 백터
    std::vector<int> answer;
    
    // 수포자들이 맞힌 문제 개수를 저장할 벡터
    std::vector<int> matchCount(3);
    
    // 실제 정답과 수포자들의 패턴을 비교해서 맞힌 개수 
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == student1[i % student1.size()]){
            matchCount[0]++;
        }
        if(answers[i] == student2[i % student2.size()]){
            matchCount[1]++;
        }
        if(answers[i] == student3[i % student3.size()]){
            matchCount[2]++;
        }
    }
    // 가장 많이 맞힌 수포자가 얻은 점수
    int maxScore = *std::max_element(matchCount.begin(), matchCount.end());
    
    // 가장 많이 맞힌 수포자의 번호 저장
    for(int i = 0; i < 3; i++){
        if(matchCount[i] == maxScore){
            answer.push_back(i+1);
        }
        
    }
    
    return answer;
}
