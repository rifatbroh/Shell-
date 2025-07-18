/*
    MD Rifat 
    
    country Bangladesh
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int n, m;
    int Allocation[MAX_PROCESSES][MAX_RESOURCES];
    int Max[MAX_PROCESSES][MAX_RESOURCES];
    int Need[MAX_PROCESSES][MAX_RESOURCES];
    int Available[MAX_RESOURCES];
    bool Finish[MAX_PROCESSES] = {false};
    int SafeSequence[MAX_PROCESSES];

    // Input number of processes and resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resource types: ";
    cin >> m;

    // Input Allocation matrix
    cout << "\nEnter Allocation Matrix (" << n << " x " << m << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> Allocation[i][j];

    // Input Max matrix
    cout << "\nEnter Max Matrix (" << n << " x " << m << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> Max[i][j];
            if (Allocation[i][j] > Max[i][j]) {
                cout << "Error: Allocation > Max at P" << i << " R" << j << "\n";
                return -1;
            }
        }
    }

    // Input Available resources
    cout << "\nEnter Available Resources (" << m << "):\n";
    for (int i = 0; i < m; ++i)
        cin >> Available[i];

    // Calculate Need matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            Need[i][j] = Max[i][j] - Allocation[i][j];

    // Deadlock detection logic
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!Finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; ++j) {
                    if (Need[i][j] > Available[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; ++j)
                        Available[j] += Allocation[i][j];

                    SafeSequence[count++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    // Output result
    if (count == n) {
        cout << "\nSystem is in a SAFE state.\nSafe Sequence: ";
        for (int i = 0; i < n; ++i)
            cout << "P" << SafeSequence[i] << " ";
        cout << "\n";
    } else {
        cout << "\nDeadlock detected! Processes involved: ";
        for (int i = 0; i < n; ++i)
            if (!Finish[i])
                cout << "P" << i << " ";
        cout << "\n";
    }

    return 0;
}
