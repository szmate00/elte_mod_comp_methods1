#include <iostream>

#include "graph.hpp"

int main()
{
    Graph g(16);

    // A1
    g.add_edge(0, 1, 2);
    g.add_edge(0, 4, 8);

    // A2
    g.add_edge(1, 0, 2);
    g.add_edge(1, 2, 10);
    g.add_edge(1, 5, 3);

    // A3
    g.add_edge(2, 1, 10);
    g.add_edge(2, 3, 1);
    g.add_edge(2, 6, 2);

    // A4
    g.add_edge(3, 2, 1);
    g.add_edge(3, 7, 1);

    // B1
    g.add_edge(4, 0, 8);
    g.add_edge(4, 5, 10);
    g.add_edge(4, 8, 10);

    // B2
    g.add_edge(5, 1, 3);
    g.add_edge(5, 4, 10);
    g.add_edge(5, 6, 4);
    g.add_edge(5, 9, 10);

    // B3
    g.add_edge(6, 2, 2);
    g.add_edge(6, 5, 4);
    g.add_edge(6, 7, 6);
    g.add_edge(6, 10, 10);

    // B4
    g.add_edge(7, 3, 1);
    g.add_edge(7, 6, 6);
    g.add_edge(7, 11, 2);

    // C1
    g.add_edge(8, 4, 10);
    g.add_edge(8, 9, 7);
    g.add_edge(8, 12, 3);

    // C2
    g.add_edge(9, 5, 10);
    g.add_edge(9, 8, 7);
    g.add_edge(9, 10, 6);
    g.add_edge(9, 13, 5);

    // C3
    g.add_edge(10, 6, 10);
    g.add_edge(10, 9, 6);
    g.add_edge(10, 11, 1);
    g.add_edge(10, 14, 2);

    // C4
    g.add_edge(11, 7, 2);
    g.add_edge(11, 10, 1);
    g.add_edge(11, 15, 7);

    // D1
    g.add_edge(12, 8, 3);
    g.add_edge(12, 13, 4);

    // D2
    g.add_edge(13, 9, 5);
    g.add_edge(13, 12, 4);
    g.add_edge(13, 14, 7);

    // D3
    g.add_edge(14, 10, 2);
    g.add_edge(14, 13, 7);
    g.add_edge(14, 15, 2);

    // D4
    g.add_edge(15, 11, 7);
    g.add_edge(15, 14, 2);

    g.print_adj();

    cout << "--------------------------------------------------" << endl;

    g.Dijkstra(0, 15);
}