#pragma once
#include "map.hpp"
#include "node.hpp"
#include "queue"
#include <queue>
class A_star {
public:
    bool in_colored_map(const Node& node);
    bool in_unvailable(const Node& node, int (&map)[10][10]);
    std::vector<Node> search(Node& nodestart, Node& nodeend, int (&map)[10][10]);

private:
    struct compare {
        bool operator()(const Node* a, const Node* b) { return a->f > b->f; }
    };
    std::priority_queue<Node*, std::vector<Node*>, compare> open_list_;
    // std::queue<Node*> open_list_;

    void colored_map_clear();
    int colored_map[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};