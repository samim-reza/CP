#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> clubs(n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        cin >> clubs[i][0] >> clubs[i][1] >> clubs[i][2]; // start, end, id
    }
    
    // Sort by end time
    sort(clubs.begin(), clubs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    vector<int> selected;
    int last_end = -1;
    
    for (int i = 0; i < n; i++) {
        if (clubs[i][0] >= last_end) {
            selected.push_back(clubs[i][2]);
            last_end = clubs[i][1];
        }
    }
    
    cout << selected.size() << endl;
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i];
        if (i < selected.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}