#include <iostream>
#include <algorithm>
#include <vector>

// Structure to represent a job
struct Job {
    char id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profits in descending order
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find the maximum deadline among the jobs
int findMaxDeadline(const std::vector<Job>& jobs) {
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline > maxDeadline) {
            maxDeadline = job.deadline;
        }
    }
    return maxDeadline;
}

// Function to perform job scheduling using Greedy algorithm
void jobScheduling(const std::vector<Job>& jobs) {
    std::vector<Job> sortedJobs = jobs;
    std::sort(sortedJobs.begin(), sortedJobs.end(), compareJobs);

    int maxDeadline = findMaxDeadline(sortedJobs);
    std::vector<char> result(maxDeadline, 0);
    int totalProfit = 0;

    // Perform the greedy job scheduling
    for (const auto& job : sortedJobs) {
        int deadline = job.deadline - 1;
        while (deadline >= 0) {
            if (result[deadline] == 0) {
                result[deadline] = job.id;
                totalProfit += job.profit;
                break;
            }
            deadline--;
        }
    }a

    // Print the selected jobs and total profit
    std::cout << "Selected Jobs: ";
    for (char jobID : result) {
        if (jobID != 0) {
            std::cout << jobID << " ";
        }
    }
    std::cout << "\nTotal Profit: " << totalProfit << std::endl;
}

int main() {
    std::vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    std::cout << "Job Scheduling Result:\n";
    jobScheduling(jobs);

    return 0;
}
