#include <bits/stdc++.h>
using namespace std;

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int priority;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
};

void findCompletionTime(Process proc[], int n) {
    proc[0].completionTime = proc[0].burstTime;;
    for (int i = 1; i < n; i++) {
        proc[i].completionTime = proc[i-1].completionTime + proc[i].burstTime;
    }
}


void findTurnAroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
    }
}

void findWaitingTime(Process proc[], int n) {
    proc[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
    }
}

void findResponseTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].responseTime = proc[i].waitingTime;
    }
}

bool comparison(Process a, Process b) {
    return a.priority < b.priority;
}

void selectionSort(Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (proc[j].priority < proc[minIndex].priority) {
                minIndex = j;
            }
        }
        swap(proc[minIndex], proc[i]);
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process proc[n];
    int total_wt = 0, total_tat = 0, total_rt = 0;
    cout << "Enter the process ID, arrival time, burst time, and priority of each process:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> proc[i].processID >> proc[i].arrivalTime >> proc[i].burstTime >> proc[i].priority;
    }

    //sort(proc, proc + n, comparison);
    selectionSort(proc, n);

    findCompletionTime(proc, n);
    findTurnAroundTime(proc, n);
    findWaitingTime(proc, n);
    findResponseTime(proc, n);

    cout << "Priority\tProcess ID\tArrival Time\tBurst Time\tCompletion\tTurnaround Time\tWaiting Time\tResponse time" << endl;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waitingTime;
        total_tat += proc[i].turnaroundTime;
        total_rt += proc[i].responseTime;
        cout <<proc[i].priority<<"\t\t"<< "P" << proc[i].processID << "\t\t" << proc[i].arrivalTime << "\t\t" << proc[i].burstTime << "\t\t" << proc[i].completionTime<< "\t\t" << proc[i].turnaroundTime  << "\t\t" << proc[i].waitingTime << "\t\t" << proc[i].responseTime  << endl;
    }
    cout << "Average waiting time: " << (float)total_wt / n << endl;
    cout << "Average turnaround time: " << (float)total_tat / n << endl;
    cout << "Average response time: " << (float)total_rt / n << endl;
}
// 1 0 10 4                          
// 2 0 13 1
// 3 0 7 3
// 4 0 15 2
// 5 0 6 3
// 6 0 10 4