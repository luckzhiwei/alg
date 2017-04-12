//
// Created by 廖志伟 on 2017/4/12.
//

#ifndef DYC_PROGRAMING_LINE_PIPELINE_H
#define DYC_PROGRAMING_LINE_PIPELINE_H

#include <vector>
#include <map>
using namespace std;

class Node{
public:
     Node(){}
     Node(int asTime,int nextNodeTime) : assemblyTime(asTime), toNextNodeTime(nextNodeTime){};
private:
     int assemblyTime;
     int toNextNodeTime;
};


class Pipeline {
public:
    Pipeline(int len);
    void findPath();
    void setInfo(int id,map<int,int> & map);
private:
    vector<Node> mPipeline1;
    vector<Node> mPipelien2;
};



#endif //DYC_PROGRAMING_LINE_PIPELINE_H
