#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>


using namespace  std;

///func getting vec mof str each str represents following val by space
/// each represents job id, job time and next job
/// if next job is 0 end of job
/// func should disp total time of job

std::vector<int> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    if (result.size() == 3) {
        /// assuming each str represents a number
        return vector<int>{stoi(result[0]), stoi(result[1]), stoi(result[2])};
    }

    return vector<int> {};
}

void findJobId(vector<vector<int>> &vec, int target) {
    for (auto &v : vec) {
        if (v[0] == target) {
            v[0] = INT_MIN;
            return;
        }
    }
    std::cerr << "Target job not found " << target << endl;
}

void solution (const vector<string> &a) {
    // key = job.id ...  value = {time, next.job.id}
    std::unordered_map<int, pair<int, int>> mapJob;
    vector<vector<int>> parsed;

    // inserting into b
    for (const auto &el : a) {
        vector<int> vec = split(el, ' ');
        //cout << "D" << vec[0] << " " << vec[1] << " " << vec[2] << endl;
        parsed.push_back(vec);

        if (vec.empty()) {
            continue;
        }

        mapJob[vec[0]] = pair{vec[1], vec[2]};

    }

    for (const auto &el : parsed) {
        // cout << "B" << el[0] << " " << el[1] << " " << el[2] << endl;
        if (el[0] == INT_MIN) {
            continue;
        }

        vector<int> job;

        int totalTime = 0;

        if (el[2] == 0) {
            totalTime += el[1];
            job.push_back(el[0]);
            cout << "job id's: ";
            for (const auto &j : job) {
                cout << j << " ";
            }
            cout << "Total time: " << totalTime << endl;
        }
        else {
            int currentJob = el[0];
            while (currentJob != 0) {
                auto found = mapJob.find(currentJob);
                if (found != mapJob.end()) {
                    job.push_back(currentJob);
                    totalTime += found->second.first;
                    findJobId(parsed, currentJob);
                    currentJob = found->second.second;
                }
                else {
                    std::cerr << "job id unexpected error, job id not found" << std::endl;
                }
            }

            cout << "job id's: ";
            for (const auto &j : job) {
                cout << j << " ";
            }
            cout << "Total time: " << totalTime << endl;
        }
    }

}


vector<int> pareser (const string &a) {
    vector<string> vec;
    string c;
    for (int i =0; i < a.size(); i ++) {
        if (a[i] == ' ') {
            vec.push_back(c);
            c = "";
        }
        else {
            c += a[i];
        }
    }

    if (vec.size() == 3) {
        /// assuming each str represents a number
        return vector<int>{stoi(vec[0]), stoi(vec[1]), stoi(vec[2])};
    }

    return vector<int> {};
}


int main() {

    vector<string> a = {"1 10 3",
                        "2 20 0",
                        "3 15 0",
                        "4 18 0"};

    solution(a);

    return 0;
}
