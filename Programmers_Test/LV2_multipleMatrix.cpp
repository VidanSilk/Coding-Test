#include <string>
#include <vector>


std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr1, 
                                       std::vector<std::vector<int>> arr2) {
    
    // 최종 행렬의 곱의 결과를 저장할 백터 
    std::vector<std::vector<int>> answer;
    
    //  arr1과 arr2의 행렬 곱을 저장할 벡터 
    answer.assign(arr1.size(), std::vector<int>(arr2[1].size(),0));
    for(int i = 0; i < arr1.size(); i++){
        for(int j =0; j < arr2[1].size(); j++){
            for(int k =0; k < arr2.size(); k++){
                answer[i][j] += arr1[i][k] * arr2[k][j]; // 두 행렬의 곱 수행
            }
        }
        
    }
    return answer;
}
