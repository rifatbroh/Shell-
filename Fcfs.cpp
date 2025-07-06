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

    vector<int> processID(n), burstTime(n), arrivalTime(n);
    vector<int> completionTime(n), turnaroundTime(n), waitingTime(n);
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Input arrival time and burst time for each process
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        processID[i] = i + 1;
        cout << "P" << processID[i] << ":\n";
        
        cout << "Arrival Time: ";
        cin >> arrivalTime[i];
        cout << "Burst Time: ";
        cin >> burstTime[i];
    }

    // Sort processes by Arrival Time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1]) {
                swap(arrivalTime[j], arrivalTime[j + 1]);
                swap(burstTime[j], burstTime[j + 1]);
                swap(processID[j], processID[j + 1]);
            }
        }
    }

    // Calculate Completion Time, Turnaround Time, Waiting Time
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }
        completionTime[i] = currentTime + burstTime[i];
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];

        currentTime = completionTime[i];

        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Display process details
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processID[i] << "\t" 
             << arrivalTime[i] << "\t\t" 
             << burstTime[i] << "\t\t" 
             << completionTime[i] << "\t\t" 
             << turnaroundTime[i] << "\t\t" 
             << waitingTime[i] << "\n";
    }

    // Display averages
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n << "\n";
    cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << "\n";

    return 0;
}
