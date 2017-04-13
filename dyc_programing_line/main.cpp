#include <iostream>

#include "Pipeline.h"

int main() {

    Pipeline pipeline(6,2,4);
    vector<pair<int,int>> line1;
    line1.push_back(pair<int,int>(7,2));
    line1.push_back(pair<int,int>(9,3));
    line1.push_back(pair<int,int>(3,1));
    line1.push_back(pair<int,int>(4,3));
    line1.push_back(pair<int,int>(8,4));
    line1.push_back(pair<int,int>(4,3));
    vector<pair<int,int>> line2;
    line2.push_back(pair<int,int>(8,2));
    line2.push_back(pair<int,int>(5,1));
    line2.push_back(pair<int,int>(6,2));
    line2.push_back(pair<int,int>(4,2));
    line2.push_back(pair<int,int>(5,1));
    line2.push_back(pair<int,int>(7,2));
    pipeline.setInfo(1,line1);
    pipeline.setInfo(2,line2);
    pipeline.findPath();
    pipeline.outputLine();
    return 0;
}