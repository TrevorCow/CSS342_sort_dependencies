#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {
        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }
        nodes[src]->add(dest);
        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

void DirectedGraph::topologySort(int node, LinkedStack<int> &sorted, set<int> &visited) { // Depth-first search
    if (visited.find(node) != visited.end()) // Return if already visited
        return;

    for (int neighbourNode : *nodes[node]) { // Visit all the neighbour nodes
        topologySort(neighbourNode, sorted, visited);
    }
    visited.insert(node); // Set this node as visited
    sorted.push(node); // Add it to the sorted stack
}

vector<int> *DirectedGraph::topologySort() {

    LinkedStack<int> sortStack;
    set<int> visited;

    for (auto const&[node, neighbourNodes] : nodes) { // For every node in the graph, if it has not been visited yet then visit it
        if (visited.find(node) == visited.end()) {
            topologySort(node, sortStack, visited);
        }
    }

    auto *sorted = new vector<int>();
    while (!sortStack.isEmpty()) { // Reverse the sorted stack to get the sorted graph
        sorted->push_back(sortStack.peek());
        sortStack.pop();
    }
    return sorted;
}

