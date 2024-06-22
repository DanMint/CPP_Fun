#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// recive const vector of ints and return new vector sorted via usage of bubble sort
void copyVec(const vector<int> &vec, vector<int> &cVec) {
    for (int i : vec) {
       cVec.push_back(i);
    }
}

vector<int> ascendingBubbleSort(const vector<int> &vec) {
    vector<int> answer;

    copyVec(vec, answer);


    for (int i = 0; i < answer.size(); i ++) {
        for (int j = 0; j < (answer.size() - 1 - i); j ++) {
            if (answer[j] > answer[j + 1]) {
                int temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }

    return answer;

}

vector<int> reverseVec(vector<int> &vec) {
    vector<int> cVec;

    for (int i = vec.size() - 1; i >=0; i --) {
        cVec.push_back(vec[i]);
    }

    return cVec;
}

vector<int> descendingBubbleSort(const vector<int> &vec) {
    vector<int> answer;

    copyVec(vec, answer);


    for (int i = 0; i < answer.size(); i ++) {
        for (int j = 0; j < (answer.size() - 1 - i); j ++) {
            if (answer[j] < answer[j + 1]) {
                int temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }

    return answer;
}

void compareVectors (const vector<int> &answer, const vector<int> &expected) {
    assert(answer.size() == expected.size());

    for (int i = 0; i < answer.size(); i ++) {
        assert(answer[i] == expected[i]);
    }
}

void showVec (const vector<int> &vec) {
    for (const auto &el : vec) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {

    /// normal bubble sort test cases
    vector<int> testCase = {1, 2, 3, 4, 5, 6, 7};
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
    vector<int> answer = ascendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {7, 6, 5, 4, 3, 2, 1};
    expected = {1, 2, 3, 4, 5, 6, 7};
    answer = ascendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {6, 1, 9, 3, 2, 10, 2};
    expected = {1, 2, 2, 3, 6, 9, 10};
    answer = ascendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {8, 1, 0, 20, 50, -5, -90};
    expected = {-90, -5, 0, 1, 8 ,20, 50};
    answer = ascendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    expected = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    answer = ascendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {-1, -9, -3, -2, -7, -4};
    expected = {-9, -7, -4, -3, -2, -1};
    answer = ascendingBubbleSort(testCase);
    compareVectors(answer, expected);


    /// descending bubble sort
    testCase = {1, 2, 3, 4, 5, 6, 7};
    expected = {7, 6, 5, 4, 3, 2, 1};
    answer = descendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {7, 6, 5, 4, 3, 2, 1};
    expected = {7, 6, 5, 4, 3, 2, 1};
    answer = descendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {6, 1, 9, 3, 2, 10, 2};
    expected = {10, 9, 6, 3, 2, 2, 1};
    answer = descendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {8, 1, 0, 20, 50, -5, -90};
    expected = {50, 20, 8, 1, 0 , -5, -90};
    answer = descendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    expected = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    answer = descendingBubbleSort(testCase);
    compareVectors(answer, expected);

    testCase = {-1, -9, -3, -2, -7, -4};
    expected = {-1, -2, -3, -4, -7, -9};
    answer = descendingBubbleSort(testCase);
    compareVectors(answer, expected);

    return 0;
}
