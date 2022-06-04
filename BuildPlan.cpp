#include "BuildPlan.h"

BuildPlan::BuildPlan() {}

bool BuildPlan::AddItem(string name, int amount) {
    if(!Loader::GetInstance()->have_bp(name)) return false;
    outputItems[name] += amount;
    return true;
}

vector<pair<string, int>> BuildPlan::MakePlan() {

}

vector<string> BuildPlan::TopologicalSort(map<string, int> allNode) {
    stack<string> sortStack;
    map<string, bool> visited;
    for(auto it: allNode) {
        visited[it.first] = false;
    }
    for(auto it: visited) {
        TopoSortUtil(it.first, sortStack, visited);
    }
    vector<string> ret;
    while(!sortStack.empty()) {
        ret.push_back(sortStack.top());
        sortStack.pop();
    }
    return ret;
}

void BuildPlan::TopoSortUtil(string node, stack<string> &sortStack, map<string, bool> &visited) {
    if(visited[node]) return;
    if(!Loader::GetInstance()->have_bp(node)) {
        sortStack.push(node);
        visited[node] = true;
        return;
    }
    BP* bp = Loader::GetInstance()->getBP(node);
    visited[node] = true;
    for(auto it: bp->material) {
        TopoSortUtil(it.first, sortStack, visited);
    }
    sortStack.push(node);
}