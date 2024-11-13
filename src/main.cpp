#include "a_star.hpp"
#include "node.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>
int map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int main() {
    Node node_start, node_end;
    std::vector<Node> path;
    A_star a_star;
    node_start.x = 1;
    node_start.y = 1;
    node_end.x = 8;
    node_end.y = 8;

    path = a_star.search(node_start, node_end, map);
    for (auto& point : path)
        std::cout << '(' << point.x << ',' << point.y << ')' << "->";
};