
#include "a_star.hpp"
#include "iostream"
#include "node.hpp"
#include "queue"
#include <exception>
#include <vector>
int i = 0;

std::vector<Node> A_star::search(Node& nodestart, Node& nodeend, int (&map)[10][10]) {
    bool find = false;
    std::vector<Node> path;
    open_list_.push(&nodestart);

    while (!open_list_.empty() || find == false) {
        Node* current_node = open_list_.top();
        open_list_.pop();

        colored_map[current_node->x][current_node->y] = 1;
        if (current_node->x == nodeend.x && current_node->y == nodeend.y) {
            find = true;
            while (current_node->parent != &nodestart) {

                current_node = current_node->parent;
                path.push_back(*current_node);
                // std::cout << '(' << current_node->x << ',' << current_node->y << ')' << "->";
            }
            return path;
        }
        // std::cout << i++ << std::endl;
        // if (i >= 2 && (current_node->parent == (current_node->parent)->parent)) {
        //     std::terminate();
        // }

        std::vector<Node*> children = current_node->generate_children(*current_node);
        for (auto& child : children) {
            child->culc_delta_g_value(*current_node);
            child->culc_delta_h_value(nodeend);
        }

        for (auto& child : children) {
            if (!in_colored_map(*child) && !in_unvailable(*child, map)) {
                // std::cout << "hello" << std::endl;
                // if (child->parent == child)
                //     std::terminate();
                // printf("%p -> %p\n", child, child->parent);
                open_list_.push(child);
            }
        }
    };

    while (!open_list_.empty()) {
        delete open_list_.top();
        open_list_.pop();
    }
    colored_map_clear();
    return {};
}

bool A_star::in_colored_map(const Node& nodethis) {
    if (colored_map[nodethis.x][nodethis.y] == 1)
        return true;
    else
        return false;
}

bool A_star::in_unvailable(const Node& nodethis, int (&map)[10][10]) {
    if (map[nodethis.x][nodethis.y] == 1)
        return true;
    else
        return false;
    ;
}

void A_star::colored_map_clear() {
    for (auto& x : colored_map)
        for (int& xy : x)
            xy = 0;
}