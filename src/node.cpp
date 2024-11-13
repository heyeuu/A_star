
#include "node.hpp"
#include <cstdlib>
#include <exception>
#include <vector>
void Node::node_init(Node& self, int x, int y, Node& parent) {
    self.x = x;
    self.y = y;
    if (&parent == this)
        std::terminate();
    self.parent = &parent;
}

std::vector<Node> Node::generate_children(Node& nodethis) {
    std::vector<Node> children;

    for (int j = 0; j < 4; j++) {
        Node* node = new Node();
        node->node_init(
            *node, nodethis.x + offset_[j].first, nodethis.y + offset_[j].second, nodethis);

        children.push_back(*node);
    }
    return children;
}

int Node::culc_delta_g_value(Node& nodethis, Node& parent) {
    nodethis.g = parent.g + 1;
    return nodethis.g;
}

int Node::culc_delta_h_value(Node& nodethis, Node& nodeend) {
    nodethis.h = abs(nodethis.x - nodeend.x) + abs(nodethis.y - nodeend.y);
    return nodethis.h;
}
