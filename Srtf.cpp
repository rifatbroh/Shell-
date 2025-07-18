/*
    MD Rifat 
    
    country Bangladesh
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> arrivalTime(n), burstTime(n);
    vector<int> completionTime(n), turnaroundTime(n), waitingTime(n);
    vector<int> remainingBurstTime(n), isCompleted(n, 0);

    // Input arrival and burst times
    cout << "Enter the arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> arrivalTime[i];
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> burstTime[i];
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0, completed = 0;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    while (completed < n) {
        int minRemainingTime = INT_MAX;
        int nextProcess = -1;

        for (int i = 0; i < n; ++i) {
            if (arrivalTime[i] <= currentTime && !isCompleted[i] &&
                remainingBurstTime[i] < minRemainingTime) {
                minRemainingTime = remainingBurstTime[i];
                nextProcess = i;
            }
        }

        if (nextProcess == -1) {
            currentTime++;
        } else {
            remainingBurstTime[nextProcess]--;
            currentTime++;

            if (remainingBurstTime[nextProcess] == 0) {
                isCompleted[nextProcess] = 1;
                completed++;
                completionTime[nextProcess] = currentTime;

                turnaroundTime[nextProcess] = completionTime[nextProcess] - arrivalTime[nextProcess];
                waitingTime[nextProcess] = turnaroundTime[nextProcess] - burstTime[nextProcess];

                totalWaitingTime += waitingTime[nextProcess];
                totalTurnaroundTime += turnaroundTime[nextProcess];
            }
        }
    }

    // Output result
    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t"
             << completionTime[i] << "\t\t" << turnaroundTime[i] << "\t\t"
             << waitingTime[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n << "\n";
    cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << "\n";

    return 0;
}
