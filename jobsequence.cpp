#include <bits/stdc++.h>
using namespace std;

// Define the job structure
struct Job {
    char id;     // Job ID
    int deadline; // Job deadline
    int profit;   // Job profit
};

// Global array to store jobs
Job jobs[1000]; // Assuming a maximum of 1000 jobs
int n;          // Number of jobs

// Comparator function to sort jobs in descending order of profit
bool jobComparator(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit sequence of jobs
void jobScheduling() {
    // Sort the jobs in descending order of profit
    sort(jobs, jobs + n, jobComparator);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Create a slot array to keep track of free time slots
    vector<bool> slot(maxDeadline + 1, false);//slot intize

    vector<char> jobSequence(maxDeadline + 1, '\0');//job sequce intize

    int totalProfit = 0;

    // Assign jobs to free slots
    for (int i = 0; i < n; i++) {//0 time no work
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {//check bewtwen the max deline and current deadline the small i will put it
            if (slot[j]==false) {//empty slot

                jobSequence[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                slot[j] = true;
                break;//1->2 empty put break.but 1->2 fill 0->1 empty put break
            }
        }
    }

    // Print the result
    cout << "Maximum profit sequence of jobs: ";
    for (int i = 1; i <=maxDeadline; i++) {//as 0 time o workd so 1
        if (jobSequence[i] != '\0') {
            cout << jobSequence[i] << " ";
        }
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    cout << "Enter the number of jobs: ";
    cin >> n;

    cout << "Enter job details (ID Deadline Profit):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobScheduling();
    return 0;
}
