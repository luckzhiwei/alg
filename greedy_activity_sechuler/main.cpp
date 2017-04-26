#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Activity {
public:

    Activity(int s, int e) : startTime(s), endTime(e) {};
    int startTime;
    int endTime;
};

int getMax(int i, int j) {
    return i > j ? i : j;
}

vector<Activity> init() {
    vector<Activity> activities;
    activities.push_back(Activity(1, 4));
    activities.push_back(Activity(3, 5));
    activities.push_back(Activity(0, 6));
    activities.push_back(Activity(5, 7));
    activities.push_back(Activity(3, 8));
    activities.push_back(Activity(5, 9));
    activities.push_back(Activity(6, 10));
    activities.push_back(Activity(8, 11));
    activities.push_back(Activity(8, 12));
    activities.push_back(Activity(2, 13));
    activities.push_back(Activity(12, 14));
    return activities;
}

void dpSolution(vector<Activity> activities) {
    vector<vector<int>> table;
    set<int> numbers;
    sort(activities.begin(), activities.end(), [](const Activity &a1, const Activity &a2) {
        return a1.endTime < a2.endTime;
    });
    int size = activities.size();
    int maxEndTime = activities[size - 1].endTime;

    table.resize(maxEndTime + 1);
    for (int i = 0; i < maxEndTime + 1; i++) {
        table[i].resize(size + 1);
    }
    for (int i = 1; i < maxEndTime + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            if (i < activities[j - 1].endTime) {
                table[i][j] = table[i][j - 1];
            } else {
                if (table[activities[j - 1].startTime][j - 1] + 1 > table[i][j - 1]) {
                    numbers.insert(j - 1);
                    table[i][j] = table[activities[j - 1].startTime][j - 1] + 1;
                } else {
                    table[i][j] = table[i][j - 1];
                }
            }
        }
    }
    cout << "dp solution" << endl;
    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << activities[*it].startTime;
        cout << "\t ";
        cout << activities[*it].endTime;
        cout << "\n";
    }
}

void greedySolution(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), [](const Activity &a1, const Activity &a2) {
        return a1.endTime < a2.endTime;
    });
    vector<Activity> choosedActivities;

    choosedActivities.push_back(activities[0]);
    int e = choosedActivities[0].endTime;
    for (int i = 1; i < activities.size(); i++) {
        if (e <= activities[i].startTime) {
            e = activities[i].endTime;
            choosedActivities.push_back(activities[i]);
        }
    }

    for (vector<Activity>::iterator it = choosedActivities.begin(); it != choosedActivities.end(); it++) {
        cout << it->startTime;
        cout << "\t ";
        cout << it->endTime;
        cout << "\n";
    }
    return;
}

int main() {
    vector<Activity> activities = init();
    cout << "greedy alg" << endl;
    greedySolution(activities);
    dpSolution(activities);
    return 0;
}