## Implement a topology sort for the given directed graph class (100pt)

Use folder ```sort_dependencies```.

### 1. (80pt) Implemented the topology sort in the topologySort() function in src/DirectedGraph.cpp

What is "topology sort", you ask?

Remember the in-class demo we saw on day 1 about figuring out odering based on a graph of dependencies? If not, Page 9 to 15 of [the class slides](https://github.com/pdgetrf/UWB_CSS342_2019_Fall/blob/master/class1/class1.pptx) have detailed exmaples. 

In short, given a directed graph, topological sort produces a linear ordering of vertices such that for every directed edge u to v, vertex u comes before v in the ordering:

- A directed graph consists of a set of vertices and edges. 
- A vertex contains a value and is connected to other vertices by at least one edge. 
- An edge connects two vertices with a direction denoted by a start vertex and an end vertex, written in the code as src and dest.
- In the code provided in DirectedGraph.h and DirectedGraph.cpp, a vertex is represented as a map entry in the class provided. The key of the map entry is the vertex's value. The value of the map entry is the "neighbours" of this vertex. A vertex y is considered a "neighbour" of a vertex x when there is a edge that goes from x to y. Take a look at the graph on page 13 of [our first class slides](https://github.com/pdgetrf/UWB_CSS342_2019_Fall/blob/master/class1/class1.pptx), here's the printout of the vertices and their neighbours:
```bash
node(0) has edges: 1 3 
node(1) has edges: 2 3 
node(2) has edges: 4 
node(3) has edges: 4 
node(4) has edges: 
```

The directed graph class is provided in src/DirectedGraph.h and src/DirectedGraph.cpp
```c++
struct Edge {
    int src;
    int dest;
};
class DirectedGraph {
private:
    // an array of vertices, each with a list to its neighbours
    map<int, SingleLinkedList<int> *> nodes;

    void topologySort(int val, LinkedStack<int> &, set<int> &);

public:
    explicit DirectedGraph(Edge *edges, int size);

    void printGraph();

    virtual ~DirectedGraph();

    vector<int> *topologySort();
};
```

The task of this homework is to implement the topologySort() in src/DirectedGraph.cpp:

```c++
vector<int> *DirectedGraph::topologySort() {
    // homework
    // the return here is a placeholder. replace with your own code
    return new vector<int>();
}
```

**If you need to use a stack, only the LinkedStack<T> from LinkedStack.h is permitted.** 

Unit tests that are already provided in test/DirectedGraphSortTest.cpp should pass. Any test failure of these cases will result in a 20pt-penalty for this task.

### 2. (20pt) Add a unit test using the case in this graph

![topology sort test case](https://github.com/pdgetrf/UWB_CSS342_2019_Fall/blob/master/class9/homework/sort_dependencies/images/ts-testcase.png)

For your reference, the printGraph() result of this graph should be
```bash
node(0) has edges: 
node(1) has edges: 0 
node(2) has edges: 1 
node(3) has edges: 1 
node(4) has edges: 
node(5) has edges: 4 2 
node(6) has edges: 4 3 
node(7) has edges: 5 6 
```
