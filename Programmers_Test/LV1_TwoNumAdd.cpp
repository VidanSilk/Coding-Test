#include <string>
#include <vector>
#include <set>

std::vector<int> solution(std::vector<int> numbers) {
    
    std::set<int> sum;
    
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i+1; j <numbers.size(); j++){
            sum.insert(numbers[i] + numbers[j]);
        }
    }
     std::vector<int> answer(sum.begin(), sum.end());
    return answer;
}
