#include <string>
#include <vector>
#include <stack>

int solution(std::vector<std::vector<int>> board, std::vector<int> moves) {
    // 보드 열 크기 만큼 스택 생성
    std::stack<int> lanes[board[0].size()];
    // 순회
    for(int i = board.size() - 1; i >= 0; i--){
        for(int j = 0; j < board[0].size(); j++){
            // 블럭이 있으면 해당열을 스택에 푸시
            if(board[i][j]){
                lanes[j].push(board[i][j]);
            }
        }    
    }
    
    // 보드판에서 꺼낸 인형을 보관한 스택 선언
    std::stack<int> bucket;
    int answer = 0;
    
    for(int m : moves){
        if(lanes[m-1].size()){
            int doll = lanes[m - 1].top();
            lanes[m-1].pop();
            if(bucket.size() && bucket.top() == doll) {
                bucket.pop();
                answer = answer + 2;
            } else{
                bucket.push(doll);
            }
        }
        
    }
    return answer;
}                   
