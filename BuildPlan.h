#ifndef __BUILD_PLAN__
#define __BUILD_PLAN__

#include "BP/Loader.h"
#include <map>
#include <stack>
#include <string.h>
#include <vector>

class BuildPlan {
    public:
    BuildPlan();
    bool AddItem(string name, int amount);
    vector<pair<string, int>> MakePlan();
    private:
    map<string, int> outputItems;
    vector<string> TopologicalSort(map<string, int> allNode);
    void TopoSortUtil(string node, stack<string> &sortStack,  map<string, bool> &visited);
};

#endif
