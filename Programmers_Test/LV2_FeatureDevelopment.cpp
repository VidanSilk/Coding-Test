#include <string>
#include <vector>
#include <cmath>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) {
    std::vector<int> answer;
    int n = progresses.size();
    std::vector<int> days_left(n);
    
    // 작업별로 완료까지 남은 일 수 계산
    for(int i = 0; i < n; i++){
        days_left[i] = std::ceil((100.0 -progresses[i]) / speeds[i]);
    }
    
    // 배포할 작업수 
    int count = 0;
    // 가장 늦게 배포할 작업의 최대 기한
    int max_day = days_left[0];
    
    for(int i = 0; i < n; i++){
        if(days_left[i] <= max_day){
            count++;
        }
        else{
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];   
        }
    }
    answer.push_back(count); // 마지막으로 카운트 된 작업들을 함께 배포 
    return answer;
}
