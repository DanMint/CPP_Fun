#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;

/// vector vector recieve every vertor has a jobid, jobtime and nextJob (if next job is 0 no job and non zero means there is a next job)
/// returns vector with job id and total time )

struct StoredJob {
    int initialJobId = 0;
    int totalTime = 0;
    int nextJobId = 0;
    bool used = false;

    StoredJob(int initialJobId, int totalTime, int nextJobId) {
        this->initialJobId = initialJobId;
        this->totalTime = totalTime;
        this->nextJobId = nextJobId;
    }

};


vector<vector<int>> jobCompletion (const vector<vector<int>> &jobs) {

    if (jobs.empty()) {
        return {};
    }

    if (jobs[0].empty()) {
        return {{}};
    }


    vector<vector<int>> chains;
    unordered_map<int, StoredJob*> jobsHash;

    for (const auto &el : jobs) {
        auto *newJob = new StoredJob(el[0], el[1], el[2]);
        jobsHash[el[0]] = newJob;
    }

    for (auto &job : jobsHash) {
        if (job.second->used) {
            continue;
        }
        int nextJob = job.second->nextJobId;
        while (nextJob != 0) {
            auto findNext = jobsHash.find(nextJob);
            if (findNext->second->used) {
                break;
            }
            nextJob = findNext->second->nextJobId;
            job.second->totalTime += findNext->second->totalTime;
            findNext->second->used = true;
        }
    }

    for (const auto &el : jobsHash) {
        if (el.second->used) {
            delete(el.second);
            continue;
        }
        chains.push_back({el.second->initialJobId, el.second->totalTime});
        delete(el.second);

    }

    return chains;
}

void test (const vector<vector<int>> &expected, const vector<vector<int>> &output) {
    assert(expected.size() == output.size());

    for (int i = 0; i < expected.size(); i ++) {
        bool found = false;
        for (int j = 0; j < output.size(); j ++) {
            assert(expected[i].size() == expected[j].size());
            if (expected[i].empty()){
                found = true;
                break;
            }
            if (expected[i][0] == output[j][0]) {
                found = true;
                assert(expected[i][1] == output[j][1]);
                break;
            }
        }
        assert(found);
    }

    cout << "Test has been passed" << endl;

}

int main() {

    vector<vector<int>> jobs0 = {};
    vector<vector<int>> expected0 = {};
    vector<vector<int>> output0 = jobCompletion(jobs0);
    test(expected0, output0);


    vector<vector<int>> jobs1 = {{}};
    vector<vector<int>> expected1 = {{}};
    vector<vector<int>> output1 = jobCompletion(jobs1);
    test(expected1, output1);


    vector<vector<int>> jobs2 = {{1, 2, 0}, {2, 4, 0}, {6, 8, 0}, {10, 80, 0}};
    vector<vector<int>> expected2 = {{1, 2}, {2, 4}, {6, 8}, {10, 80}};
    vector<vector<int>> output2 = jobCompletion(jobs2);
    test(expected2, output2);


    vector<vector<int>> jobs3 = {{1, 2, 10}, {2, 4, 0}, {6, 8, 0}, {10, 80, 2}};
    vector<vector<int>> expected3 = {{1, 86}, {6, 8}};
    vector<vector<int>> output3 = jobCompletion(jobs3);
    test(expected3, output3);

    vector<vector<int>> jobs4 = {{1, 2, 10}, {2, 4, 0}, {6, 8, 0}, {10, 80, 2}, {3, 10, 6}};
    vector<vector<int>> expected4 = {{1, 86}, {3, 18}};
    vector<vector<int>> output4 = jobCompletion(jobs4);
    test(expected4, output4);




    return 0;
}
