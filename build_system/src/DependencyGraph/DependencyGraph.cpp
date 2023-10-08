#include "DependencyGraph.h"

DependencyGraph::~DependencyGraph() {
    for (auto v : graph) {
        for (const char* c : v.second) {
            delete c;
        }
    }
    delete &graph;
}