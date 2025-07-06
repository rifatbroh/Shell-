/*
    MD Rifat

    Country: Bangladesh
    Program: Non-Preemptive SJF in C++
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> processID(n), burstTime(n), arrivalTime(n);
    vector<int> waitingTime(n), turnaroundTime(n), completionTime(n);
    vector<bool> isCompleted(n, false);

    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Input process info
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; ++i) {
        processID[i] = i + 1;
        cout << "P" << processID[i] << ":\n";
        cout << "Arrival Time: ";
        cin >> arrivalTime[i];
        cout << "Burst Time: ";
        cin >> burstTime[i];
    }

    // Sort by arrival time, then burst time
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arrivalTime[j] > arrivalTime[j + 1] ||
                (arrivalTime[j] == arrivalTime[j + 1] && burstTime[j] > burstTime[j + 1])) {
                swap(arrivalTime[j], arrivalTime[j + 1]);
                swap(burstTime[j], burstTime[j + 1]);
                swap(processID[j], processID[j + 1]);
            }
        }
    }

    int currentTime = 0, completed = 0;

    while (completed < n) {
        int minBurst = INT_MAX;
        int nextProcess = -1;

        // Find the next shortest job that has arrived
        for (int i = 0; i < n; ++i) {
            if (arrivalTime[i] <= currentTime && !isCompleted[i] && burstTime[i] < minBurst) {
                minBurst = burstTime[i];
                nextProcess = i;
            }
        }

        if (nextProcess == -1) {
            currentTime++;
        } else {
            currentTime += burstTime[nextProcess];
            completionTime[nextProcess] = currentTime;
            turnaroundTime[nextProcess] = completionTime[nextProcess] - arrivalTime[nextProcess];
            waitingTime[nextProcess] = turnaroundTime[nextProcess] - burstTime[nextProcess];

            totalWaitingTime += waitingTime[nextProcess];
            totalTurnaroundTime += turnaroundTime[nextProcess];
            isCompleted[nextProcess] = true;
            completed++;
        }
    }

    // Output results
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << processID[i] << "\t"
             << arrivalTime[i] << "\t\t"
             << burstTime[i] << "\t\t"
             << completionTime[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << endl;

    return 0;
}
