#include <iostream>
#include "Scheduler.h"

int main() {
    Scheduler scheduler;
    scheduler.addJob(Job(3, 4, 4));
    scheduler.addJob(Job(4, 5, 3));
    scheduler.addJob(Job(2, 7, 1));
    scheduler.addJob(Job(1, 8, 1));
    int pBest = scheduler.startSechulde();
    cout << "the best effective is" << pBest << endl;
    return 0;
}