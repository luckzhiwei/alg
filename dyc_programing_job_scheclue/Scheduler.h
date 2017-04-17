//
// Created by 廖志伟 on 2017/4/16.
//

#ifndef DYC_PROGRAMING_JOB_SCHECLUE_JOB_H
#define DYC_PROGRAMING_JOB_SCHECLUE_JOB_H

#include <iostream>
#include <vector>

using namespace std;

class Job {
public:
    Job() {};

    Job(int t, int d, int p) : timeToDo(t), deadLineTime(d), effetive(p) {};
    int timeToDo;
    int deadLineTime;
    int effetive;
};

class Scheduler {
public:
    Scheduler() {};

    void addJob(Job job);

    int startSechulde();

private:
    vector<Job> jobs;
    int getMax(int p1,int p2);
};


#endif //DYC_PROGRAMING_JOB_SCHECLUE_JOB_H
