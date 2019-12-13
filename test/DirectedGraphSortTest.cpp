#include "DirectedGraph.h"
#include "gtest/gtest.h"

TEST(topology_sort, print_test) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    {0, 1},
                    {0, 3},
                    {1, 2},
                    {1, 3},
                    {2, 4},
                    {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));
    graph.printGraph();
}

TEST(topology_sort, test_5_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    {0, 1},
                    {0, 3},
                    {1, 2},
                    {1, 3},
                    {2, 4},
                    {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));

    graph.printGraph();

    auto v = graph.topologySort();
    vector<int> ans1{0, 1, 3, 2, 4,};
    vector<int> ans2{0, 1, 2, 3, 4,};

    ASSERT_TRUE((*v) == ans1 || (*v) == ans2);

    delete v;
}

TEST(topology_sort, test_2_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    {1, 0}
            };

    DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));
    auto v = graph.topologySort();
    vector<int> ans{1, 0};

    ASSERT_TRUE((*v) == ans);

    delete v;
}

TEST(topology_sort, test_1_nodes) {
    Edge edges[] = {};

    DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));
    auto v = graph.topologySort();

    ASSERT_TRUE((*v).empty());

    delete v;
}

TEST(topology_sort, test_8_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    {7, 5},
                    {7, 6},
                    {5, 2},
                    {5, 4},
                    {6, 4},
                    {6, 3},
                    {2, 1},
                    {3, 1},
                    {1, 0}
            };

    DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));

    auto v = graph.topologySort();
    vector<int> ans1{7, 6, 5, 4, 3, 2, 1, 0,};

    ASSERT_TRUE((*v) == ans1);

    delete v;
}

