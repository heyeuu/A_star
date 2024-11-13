
#include "node.hpp"
#include <cstdlib>
#include <exception>
#include <vector>
Node::Node(int px, int py, Node* parent)
    : x(px)
    , y(py)
    , parent(parent) {
    if (parent == this)
        std::terminate();
}

Node::Node() = default;

std::vector<Node*> Node::generate_children(Node& nodethis) {
    std::vector<Node*> children;

    for (int j = 0; j < 4; j++) {
        Node* node =
            new Node(nodethis.x + offset_[j].first, nodethis.y + offset_[j].second, &nodethis);

        children.push_back(node);
    }
    return children;
}

int Node::culc_delta_g_value(Node& parent) {
    this->g = parent.g + 1;
    return this->g;
}

int Node::culc_delta_h_value(Node& nodeend) {
    h = abs(x - nodeend.x) + abs(y - nodeend.y);
    return h;
}
