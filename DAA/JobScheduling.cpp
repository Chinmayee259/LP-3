#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job{
    public:  // variables are private by default, so main() cannot directly access

        char id;
        int deadline;
        int profit;
};

// Sort jobs by decreasing profit
bool compare(Job a, Job b){
    return a.profit > b.profit;
}

// Function for Job Sequencing
void jobSequencing(vector<Job> jobs){
    // Sort jobs according to profit
    sort(jobs.begin(), jobs.end(), compare);    // O(nlogn)

    // Find max deadline
    int maxDeadline = 0;
    int totalProfit = 0;

    for(int i = 0; i < jobs.size(); i++){    // O(n)
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Create time slots
    vector<char> slots(maxDeadline + 1, '-');

    // Schedule jobs

    for(int i = 0; i < jobs.size(); i++){ //O(n * d)
        // Start from deadline and move backward
        for(int j = jobs[i].deadline; j >= 1; j--){
            if(slots[j] == '-'){
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    // Display Scheduled Jobs
    cout << "\n Scheduled Jobs \n";
    for(int i = 0; i < slots.size(); i++){
        if(slots[i] != '-'){
            cout <<"Slot "<< i << ": Job " << slots[i] << endl;
        }
    }

    cout << "\nMaximum Profit : " << totalProfit << endl;

}


// Main
int main(){
    int n;
    cout << "Enter number of jobs : ";
    cin >> n;

    vector<Job> jobs(n); // Job is the class that we created ourselves.

    cout << "Enter Job ID, Deadline and Profit : \n";

    for(int i = 0; i < n; i++){
        cin >> jobs[i].id;
        cin >> jobs[i].deadline;
        cin >> jobs[i].profit;
    }

    // Call FUNCTION
    jobSequencing(jobs);

    return 0;
}

// Compilation
// g++ JobScheduling.cpp -o JobScheduling 

// Run
// JobScheduling

// TC - O(nlogn + (n*d))
// nlogn - sorting
// n - finding max deadline
// n * d - scheduling jobs