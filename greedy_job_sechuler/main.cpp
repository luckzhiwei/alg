#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Activity {
public:

    Activity(int s, int e) : startTime(s), endTime(e) {};
    int startTime;
    int endTime;
};

int main() {

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
    return 0;
}