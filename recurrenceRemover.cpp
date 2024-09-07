#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;



vector<int> remover(const vector<int> &values, const int &repeatedAmount) {
    vector<int> answer;
    unordered_map<int, int> recurrence;

    for (const auto &el : values) {
        if (recurrence[el] > 0) {
            recurrence[el] += 1;
        }
        else {
            recurrence[el] = 1;
        }
    }

    for (const auto val : values) {
        if (recurrence[val] <= repeatedAmount) {
            answer.push_back(val);
        }
    }

    return answer;
}

struct tester {
    vector<int> test;
    vector<int> expected;
    int recurrenceAmount;
};

int main() {

    vector<tester> tests = {
            {{1, 2, 2, 2, 2, 3, 4},{1, 3, 4}, 3},
            {{4, 4, 4, 4, 4,4 }, {}, 1},
            {{1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, 1},
            {{1,1,2,2,3,3,3,4,4,5,5,6,6}, {1,1,2,2,4,4,5,5,6,6}, 2},
            {{1,2,3,4,5}, {}, 0},
            {{6, 6, 5, 5, 2, 2, 3, 3, 1, 1}, {6, 6, 5, 5, 2, 2, 3, 3, 1, 1}, 2},
            {{1, 2, 3, 1, 2, 3, 5}, {5}, 1}
    };

    for (const auto &test : tests) {
        auto result = remover(test.test, test.recurrenceAmount);
        assert(test.expected.size() == result.size());
        for (int i = 0; i < result.size(); i ++) {
            assert(result[i] == test.expected[i]);
        }
    }

    cout << "Successfully passed all the test" << endl;

    return 0;
}
