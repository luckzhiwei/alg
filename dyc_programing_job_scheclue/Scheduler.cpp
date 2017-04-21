//
// Created by 廖志伟 on 2017/4/16.
//

#include "Scheduler.h"
#include <algorithm>

void Scheduler::addJob(Job job) {
    this->jobs.push_back(job);
}

int Scheduler::getMax(int p1, int p2) {
    return p1 > p2 ? p1 : p2;
}

int Scheduler::startSechulde() {
    sort(this->jobs.begin(), this->jobs.end(), [](const Job &job1, const Job &job2) {
        return job1.deadLineTime < job2.deadLineTime;
    });
    int size = this->jobs.size();
    int dMax = this->jobs[size - 1].deadLineTime;
    vector<vector<int>> table;
    table.resize(dMax + 1);

    for (int i = 0; i < dMax + 1; i++) {
        table[i].resize(size + 1, 0);
    }
    for (int i = 1; i <= dMax; i++) {
        for (int j = 1; j <= size; j++) {
            if (i < this->jobs[j - 1].timeToDo) {
                table[i][j] = table[i][j - 1];
            } else {
                int index = i - this->jobs[j - 1].timeToDo;
                int p = this->jobs[j - 1].effetive;
                table[i][j] = this->getMax(table[index][j - 1] + p,
                                           table[i][j - 1]);
            }
        }
    }
    return table[dMax][size];

}