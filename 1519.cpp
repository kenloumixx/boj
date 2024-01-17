#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_NUMBER 1000001

using namespace std;

bool exist(vector<int>& subset_i, int sub_int_i);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int game_num;
    cin >> game_num;

    vector<pair<int, int>> game_number(MAX_NUMBER);

    for (int i = 0; i < 10; i++) {
        game_number[i].first = 0;
        game_number[i].second = -1;
    }

    for (int i = 10; i <= MAX_NUMBER; i++) {
        string str_i = to_string(i);
        vector<int> subset_i;
        for (int j = 0; j < str_i.length(); j++) {              // 시작점
            for (int k = 1; j + k <= str_i.length(); k++) {     // 갯수
                string sub_str_i = str_i.substr(j, k);
                int sub_int_i = stoi(sub_str_i);
                if (!exist(subset_i, sub_int_i) && sub_int_i != 0 && sub_int_i != i) {
                    subset_i.push_back(stoi(sub_str_i));
                }
            }
        }
        sort(subset_i.begin(), subset_i.end());
        for (int subnum : subset_i) {
            if (game_number[i-subnum].first == 0) {
                game_number[i].first = 1;
                game_number[i].second = subnum;
                break;
            }
        }
        if (game_number[i].first != 1) {
            game_number[i].second = -1;
        }
    }
    cout << game_number[game_num].second << '\n';
    
    return 0;
} 

bool exist(vector<int>& subset_i, int sub_int_i) {
    auto it = find(subset_i.begin(), subset_i.end(), sub_int_i);
    if (it == subset_i.end()) {
        return false;
    }
    return true;
}


// 게임 판에 어떤 자연수 N이 쓰여 있을 때, 두 명의 플레이어가 턴을 번갈아가면서 이 게임을 하려고 한다.

// 매 턴이 돌아올때마다, 플레이어는 현재 게임 판에 쓰여 있는 수의 진 부분 문자열인 양의 정수 M을 고를 수 있다. 그리고 나서 원래 수에서 M을 뺀다. 진 부분 문자열이란 자기 자신을 제외한 모든 연속된 부분 문자열을 말한다.

// 예를 들어, 현재 게임 판에 2309가 써있을 때, 플레이어는 2, 3, 9, 23, 30, 230, 309를 고를 수 있다. 2를 고르면, 현재 게임 판에 쓰여 있는 수는 2307이 되고, 3은 2306, ..............., 309는 2000이 된다.

// 만약에 플레이어가 부분 문자열을 고를 수 없게되면, 게임에서 지게된다.

// 입력으로 현재 게임 판에 쓰여 있는 수 N이 주어졌을 때, 플레이어 1(첫 턴을 가지는 플레이어)이 이기기 위해서 골라야 하는 수를 출력하는 프로그램을 작성하시오. 만약 여러 가지 경우가 있다면, 가장 작은 것을 출력하고, 이길 수 없다면 -1을 출력한다.

// 1. 한자리수는 전부 0 
// 2. subset은 매번 만들기 (각 idx에서 +idx 늘려가면서 end까지) -> 6 * 10^6. 
// 3. subset을 ordered set으로.  
// 4. 매 i 마다 i의 subset 구하고, 각 sub_i를 뺐을 때 1 말고 0이 나올 때까지 확인. -> 최소를 뺀다. - 최소를 출력