#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> numbers(1000001);
    for (int i = 0; i * i <= 1000000; i++) {
        numbers[i * i] = 1;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (!numbers[i]) {
            for (int j = 1; j * j + i <= 1000000; j++) {
                numbers[i + j * j] = 1;
            }
        }
    }

    int num_test;
    cin >> num_test;

    for (int i = 0; i < num_test; i++) {
        int test;
        cin >> test;
        if (numbers[test] == 0) {
            cout << "cubelover" << '\n';
        } else {
            cout << "koosaga" << '\n';
        }
    }
    return 0;
}