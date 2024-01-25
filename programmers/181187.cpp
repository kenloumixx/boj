#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<long long, long long> calculate_points(long long r);

int main() {
    int r1, r2;
    cin >> r1 >> r2;
    long long answer = 0;
    int max_r = max(r1, r2);
    int min_r = min(r1, r2);
    pair<long long, long long> points_max = calculate_points((long long)max_r);
    pair<long long, long long> points_min = calculate_points((long long)(min_r));
    return 0;
}

pair<long long, long long> calculate_points(long long r) {
    // 4분면 
    long long num_points = 0;
    long long num_rim_points = 0;
    for (long long x = 0; x < r; x++) {
        double y = sqrt(pow(r, 2) - pow(x, 2));
        num_points += int(y); 
        if (y == int(y)) {
            num_rim_points++;
        }
    }
    return make_pair((num_points) * 4, (num_rim_points) * 4);
}


// 조건 0 : 한 사분면 위의 점들만 구하기 
// 조건 1 : 유클리디안 거리가 r1, r2 사이 
// 조건 2 : x, y 좌표 전부 정수 