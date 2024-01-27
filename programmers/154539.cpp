#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> biggest;
    for (int i = numbers.size()-1; i >= 0; i--) {
        while (!biggest.empty() && biggest.top() <= numbers[i]) {
            biggest.pop();  
        }
        if (biggest.size() == 0) {
            answer.push_back(-1);
        } else {
            answer.push_back(biggest.top());
        }
        biggest.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}