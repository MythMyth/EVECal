#ifndef __BUILD_PLAN__
#define __BUILD_PLAN__

#include "BP/Loader.h"
#include <map>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>

struct ItemWorkDetail {
    string name;
    int amount;
    int jobRun;
    ItemWorkDetail(): name(""), amount(0), jobRun(0) {}
};

class BuildPlan {
    public:
    BuildPlan();
    bool AddItem(string name, int amount);
    vector<ItemWorkDetail> MakePlan(bool MaxBPRun);
    private:
    map<string, int> outputItems;
    vector<string> TopologicalSort(map<string, int> allNode);
    void TopoSortUtil(string node, stack<string> &sortStack,  map<string, bool> &visited);
    void GetAllNode(string node, map<string, int> &nodeMap);
};

#endif
