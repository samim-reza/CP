#include <bits/stdc++.h>
using namespace std;

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
};

//round robin cpu scheduling
void findCompletionTime(Process proc[], int n, int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = proc[i].burstTime;
    }
    int t = 0;
    while (1) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    proc[i].completionTime = t;
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true) {
            break;
        }
    }
}

void findTurnAroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
    }
}

void findWaitingTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
    }
}

void findResponseTime(Process proc[], int n, int quantum) {
    proc[0].responseTime = 0;
    for (int i = 1; i < n; i++) {
        proc[i].responseTime = proc[i-1].responseTime + quantum;
    }
}

int main()
{
    int n, total_wt = 0, total_tat = 0, total_rt = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process proc[n];
    cout << "Enter the process ID, arrival time, burst time of each process:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> proc[i].processID >> proc[i].arrivalTime >> proc[i].burstTime;
    }
    int quantum;
    cout << "Enter the quantum time: ";
    cin >> quantum;
    findCompletionTime(proc, n, quantum);
    findTurnAroundTime(proc, n);
    findWaitingTime(proc, n);
    findResponseTime(proc, n, quantum);
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n";
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waitingTime;
        total_tat += proc[i].turnaroundTime;
        total_rt += proc[i].responseTime;
        cout << proc[i].processID << "\t\t" << proc[i].arrivalTime << "\t\t" << proc[i].burstTime << "\t\t" << proc[i].completionTime << "\t\t" << proc[i].turnaroundTime << "\t\t" << proc[i].waitingTime << "\t\t" << proc[i].responseTime << endl;
    }
    cout << "Average waiting time: " << (float)total_wt / n << endl;
    cout << "Average turnaround time: " << (float)total_tat / n << endl;
    cout << "Average response time: " << (float)total_rt / n << endl;
}

// 1 0 10                         
// 2 0 13
// 3 0 7
// 4 0 15
// 5 0 6
// 6 0 10