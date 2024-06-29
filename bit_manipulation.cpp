#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/// we get inger we return string that represents bit map of interger + test case
string removeZero(const string &bitRep) {
    string answer;
    bool found = false;

    for (const auto &el : bitRep) {
        if (el == '1' && !found) {
            found = true;
        }

        if (found) {
            answer.push_back(el);
        }
    }

    if (!found) {
        answer.push_back('0');
    }

    return answer;
}

string bitMap(const int val) {
    string answer(sizeof(val) * 8, '0');
    int intShift = 1;

    for (int i = 0; i < sizeof(val) * 8; i ++) {
         if ((val & intShift) == intShift) {
             answer[(sizeof(val) * 8) - i - 1] = '1';
         }
         else {
             answer[(sizeof(val) * 8) - i - 1] = '0';
         }

         intShift = intShift << 1;
    }

    return removeZero(answer);
}

int main() {


    vector<pair<int, string>> testInt = {{0, "0"},
                                         {1, "1"},
                                         {2, "10"},
                                         {3, "11"},
                                         {4, "100"},
                                         {5, "101"},
                                         {6, "110"},
                                         {7, "111"},
                                         {8, "1000"},
                                         {9, "1001"},
                                         {10, "1010"},
                                         {11, "1011"}};

    for (const auto &test : testInt) {
        string output = bitMap(test.first);
        cout << output << endl;
        assert(output == test.second);
    }

    return 0;
}
