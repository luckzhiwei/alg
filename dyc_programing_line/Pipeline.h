//
// Created by 廖志伟 on 2017/4/12.
//

#ifndef DYC_PROGRAMING_LINE_PIPELINE_H
#define DYC_PROGRAMING_LINE_PIPELINE_H

#include <vector>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Node{
public:
     Node(){}
     Node(int asTime,int nextNodeTime) : assemblyTime(asTime), toNextNodeTime(nextNodeTime){};
     int assemblyTime;
     int toNextNodeTime;
};


class Pipeline {
public:
    Pipeline(int len,int startTime1,int startTime2);
    void findPath();
    void setInfo(int id,const vector<pair<int,int>> & map);
    void outputLine();
private:
    vector<Node> mPipeline1;
    vector<int> mCostPipeline1;
    vector<int> mCostPipeline2;
    vector<int> path1;
    vector<int> path2;
    vector<Node> mPipelien2;
    int mStartTime1;
    int mStartTime2;
    int mLen;
};



#endif //DYC_PROGRAMING_LINE_PIPELINE_H
