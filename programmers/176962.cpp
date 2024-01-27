#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), [](vector<string> data1, vector<string> data2){
        return (data1[1] < data2[1]);   // start 순으로 정렬
    });
    
    stack<vector<string>> remainder_stack;
    vector<string> complete;
    for (int i = 0; i < plans.size()-1; i++) {
        vector<string> plan = plans[i];
        int h = stoi(plan[1].substr(0, 2));
        int m = stoi(plan[1].substr(3, 2));
        int plan_time = h * 60 + m + stoi(plan[2]);  // 전체시간 - 다음 과제 start 시간 
        
        vector<string> next_plan = plans[i+1];
        int next_h = stoi(next_plan[1].substr(0, 2));
        int next_m = stoi(next_plan[1].substr(3, 2));
        int next_start = next_h * 60 + next_m;
        int time_diff = next_start - plan_time;
        if (time_diff >= 0) {
            complete.push_back(plan[0]);
            while (!remainder_stack.empty() && time_diff >= 0 && stoi(remainder_stack.top()[1]) <= time_diff) {
                // 만약 쌓여있던 과제 끝내면 complete로 보내고 
                complete.push_back(remainder_stack.top()[0]);
                time_diff -= stoi(remainder_stack.top()[1]);
                remainder_stack.pop();
            }
            // 못끝내면 줄어든 만큼 계산 후 complete로 보내기
            if (!remainder_stack.empty()) {
            remainder_stack.top()[1] = to_string(stoi(remainder_stack.top()[1]) - time_diff);
            }
        } else {  // 얘도.. stack으로 보내기 
            remainder_stack.push({plan[0], to_string(-time_diff)});
        }
    }
    complete.push_back(plans[plans.size()-1][0]);
    
    // 여기서부터 stack에 쌓인 애들 하나씩 complete에 넣기 
    while (!remainder_stack.empty()) {
        complete.push_back(remainder_stack.top()[0]);
        remainder_stack.pop();
    }
    return complete;
}

// 테스트 4
// 입력값 〉 [["a", "09:00", "10"], ["b", "09:10", "10"], ["c", "09:15", "10"], ["d", "09:30", "10"], ["e", "09:35", "10"]] ["a", "c", "b", "e", "d"]
// 기댓값 〉 ["a", "c", "b", "e", "d"]
// 실행 결과 〉 실행한 결괏값 ["a","c","b","d","e"]이 기댓값 ["a","c","b","e","d"]과 다릅니다.