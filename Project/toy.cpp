#include <iostream>

#include "graph.hpp"

int main()
{
    Graph g(5);

    g.add_edge(0, 1, 1);
    g.add_edge(0, 3, 3);
    g.add_edge(0, 4, 10);

    g.add_edge(1, 0, 1);
    g.add_edge(1, 2, 5);

    g.add_edge(2, 1, 5);
    g.add_edge(2, 3, 2);
    g.add_edge(2, 4, 1);

    g.add_edge(3, 0, 3);
    g.add_edge(3, 2, 2);
    g.add_edge(3, 4, 6);

    g.add_edge(4, 0, 10);
    g.add_edge(4, 2, 1);
    g.add_edge(4, 3, 6);

    g.print_adj();

    cout << "--------------------------------------------------" << endl;

    g.Dijkstra(0, 0);
    g.Dijkstra(0, 1);
    g.Dijkstra(0, 2);
    g.Dijkstra(0, 3);



    return 0;
}