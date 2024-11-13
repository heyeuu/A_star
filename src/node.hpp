#pragma once
#include <utility>
#include <vector>
class Node {
public:
    int x, y, g{0}, h{0}, f{g + h};
    Node* parent{nullptr};
    std::vector<Node*> generate_children(Node& nodethis);
    int culc_delta_g_value(Node& nodeparent);
    int culc_delta_h_value(Node& nodeend);

    Node(int x, int y, Node* parent);
    Node();

private:
    std::vector<std::pair<int, int>> offset_{
        {-1,  0},
        { 1,  0},
        { 0, -1},
        { 0,  1}
    };
};