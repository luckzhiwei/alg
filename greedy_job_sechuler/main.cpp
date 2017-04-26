#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Job {
public:
    Job(int d, int w, int id) : d(d), w(w), id(id) {};
    int d;
    int w;
    int id;
};

bool isInDedepend(vector<Job> &jobs) {
    sort(jobs.begin(), jobs.end(), [](const Job &job1, const Job &job2) {
        return job1.d < job2.d;
    });
    int i = 0;
    for (vector<Job>::iterator it1 = jobs.begin(); it1 != jobs.end(); it1++) {
        i++;
        if (i > it1->d) {
            return false;
        }
    }
    return true;
}

vector<Job> startScheule(vector<Job> &jobs) {
    vector<Job> scheduedJobs;
    sort(jobs.begin(), jobs.end(), [](const Job &job1, const Job &job2) {
        return job1.w > job2.w;
    });
    for (vector<Job>::iterator it = jobs.begin(); it != jobs.end(); it++) {
        scheduedJobs.push_back(*(it));
        if (!isInDedepend(scheduedJobs)) {
            scheduedJobs.erase(it);
        }
    }
    for (vector<Job>::iterator it = scheduedJobs.begin(); it != scheduedJobs.end(); it++) {
        cout << it->id << "\t" << it->w << endl;
    }
}


int main() {

    vector<Job> jobs;
    jobs.push_back(Job(4, 70, 1));
    jobs.push_back(Job(2, 60, 2));
    jobs.push_back(Job(1, 30, 5));
    jobs.push_back(Job(4, 50, 3));
    jobs.push_back(Job(4, 20, 6));
    jobs.push_back(Job(6, 10, 7));
    jobs.push_back(Job(3, 40, 4));
    startScheule(jobs);
    return 0;
}