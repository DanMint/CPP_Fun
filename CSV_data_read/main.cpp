#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>


int main() {
    std::ifstream file("data.csv");  // Replace "data.csv" with your CSV file path
    std::vector<std::vector<int>> data;

    if (file.is_open()) {
        std::string line;
        bool firstLine = true;
        while (std::getline(file, line)) {
            if (firstLine) {
                firstLine = false;
                continue;
            }
            std::vector<int> row;
            std::stringstream ss(line);
            std::string cell;

            bool firstLine = true;

            while (std::getline(ss, cell, ',')) {
                int value = stoi(cell);
                row.push_back(value);
            }

            data.push_back(row);
        }

        file.close();

//        /// Print the data
//        for (const auto& row : data) {
//            for (int value : row) {
//                std::cout << value << " ";
//            }
//            std::cout << std::endl;
//        }
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }

    std::unordered_map<int, std::pair<int, int>> lookUp; /// here we put all the works to find them. key: job_id, value: time, continuation
    std::unordered_map<int, bool> used; /// here we check if a certin process is used, key: job_id, value: bool (used or not)

    for (const auto &el : data) {
        lookUp[el[0]] = std::make_pair(el[1], el[2]);
        used[el[0]] = false;
    }

    std::vector<std::vector<std::vector<int>>> chains;

    /// here we arise an error b/c jobs are unique an 2 diffrent jobs CANNOT access the same next job
    bool error = false;

    for (const auto &el : data) {
        std::vector<std::vector<int>> chain;
        int currentJob = el[0];
        int timeTaken = el[1];
        int nextJob = el[2];

        if (used[currentJob])
            continue;
        else
            used[currentJob] = true;

        while (true) {
            if (used[nextJob]) {
                error = true;
                break;
            }

            chain.push_back({currentJob, timeTaken, nextJob});

            used[currentJob] = true;

            if (nextJob == 0)
                break;

            else {
                currentJob = nextJob;
                timeTaken = lookUp[currentJob].first;
                nextJob = lookUp[currentJob].second;
            }
        }

        if (error) {
            std::cout << "Wrong input data" << std::endl;
            break;
        }

        chains.push_back(chain);
    }

    if (error)
        return 0;

    std::cout << "----------------- Chains -----------------" << std::endl;

    bool zero = false;

    for (const auto &el : chains) {
        for (const auto &elo : el) {
            for (const auto &temp : elo) {
                std::cout  << temp << " ";
                if (temp == 0)
                    zero = true;
            }
            if (zero) {
                zero = false;
                continue;
            }

            std::cout << "->" << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "----------------- Work Average -----------------" << std::endl;

    int timeSum = 0;

    for (const auto& row : data) {
        for (int value : row) {
           timeSum += value;
        }
    }

    std::cout << timeSum / data.size() << std::endl;

    return 0;
}
