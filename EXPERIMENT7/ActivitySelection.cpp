//Write a program to solve the Activity Selection problem using the Greedy approach. 
 //NAME = SUHEL CHOUDHARY
 //ROLL NO = 25/DA/059
//                                                                EXPERIMENT 7
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

// Sort activities according to finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start time and finish time of each activity:\n";

    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

   
    sort(activities.begin(), activities.end(), compare);

    cout << "\nSelected Activities:\n";

    
    int lastFinish = activities[0].finish;

    cout << "(" << activities[0].start << ", "
         << activities[0].finish << ")" << endl;

    
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", "
                 << activities[i].finish << ")" << endl;

            lastFinish = activities[i].finish;
        }
    }

    return 0;
}

