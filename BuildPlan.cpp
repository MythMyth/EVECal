#include "BuildPlan.h"

BuildPlan::BuildPlan() {}

bool BuildPlan::AddItem(string name, int amount) {
    if(!Loader::GetInstance()->have_bp(name)) return false;
    outputItems[name] += amount;
    return true;
}

vector<ItemWorkDetail> BuildPlan::MakePlan(bool MaxBPRun) {
    map<string, int> nodeMap;
    for(auto it: outputItems) {
        GetAllNode(it.first, nodeMap);
    }
    for(auto it: outputItems) {
        nodeMap[it.first] = it.second;
    }

    vector<string> reverseBuildOrder = TopologicalSort(nodeMap);
    vector<ItemWorkDetail> ret;

    for(string s: reverseBuildOrder) {
        ItemWorkDetail detail;
        detail.name = s;
        detail.amount = nodeMap[s];
        if(Loader::GetInstance()->have_bp(s)) {
            BP* bp = Loader::GetInstance()->getBP(s);
            map<string, int> run_material = bp->Calculate(nodeMap[s], detail.jobRun, MaxBPRun);
            for(auto it: run_material) {
                nodeMap[it.first] += it.second;
            }
        }
        ret.push_back(detail);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void BuildPlan::GetAllNode(string node, map<string, int> &nodeMap) {
    if(nodeMap.find(node) != nodeMap.end()) return;
    nodeMap[node] = 0;
    if(Loader::GetInstance()->have_bp(node)) {
        BP* bp = Loader::GetInstance()->getBP(node);
        for(auto it: bp->material) {
            GetAllNode(it.first, nodeMap);
        }
    }
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