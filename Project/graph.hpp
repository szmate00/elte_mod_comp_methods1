#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::pair;
using std::make_pair;
using std::set;

// funny number
#define INF 6969

// Function to display the shortest path found by the Dijkstra algorithm
void display_Dijkstra(vector<int> distances, vector<int> parents, int source, int target)
{
   for(int i = 0 ; i < distances.size(); i++)
   {
       if (i == target)
       {
            int temp = parents[i]; 

            cout << "Path to node " << target << " from node " << source << ":" << endl;
            cout << i << " <- ";

            while(temp != -1)
            {
                std::cout << temp << " <- ";
                temp = parents[temp]; 
            }

            cout << endl; 
            cout << "Time = " << distances[i] << endl;
       }
   } 
}

class Graph
{
    private:

        // Number of nodes
        int V;

        // Adjacency lists for each node
        list<pair<int, int>> *adj;


    public:

        Graph(int v);

        void add_edge(int v1, int v2, int weight);

        void print_adj();

        void Dijkstra(int source, int target);
};


// Initializing the graph
Graph::Graph(int v)
{
    // Number of nodes
    V = v;

    // Adjacency lists for each node
    adj = new list<pair<int, int>>[v];
}


// For adding new edges to the graph
void Graph::add_edge(int v1, int v2, int weight)
{
    adj[v1].push_back(make_pair(v2, weight));
}


// Function for printing out the adjacency list for each node
void Graph::print_adj()
{
    cout << "Adjacent nodes and time to that node for each:" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << ": ";

        for (auto j = adj[i].begin(); j != adj[i].end() ; j++)
        {
            cout << "(" << (*j).first << ", " << (*j).second << ")" << "\t"; 
        }
        cout << endl;
    }
}


void Graph::Dijkstra(int source, int target)
{
    // Set is a sorted container, so we can easily pop of the first element, that is the node with the least distance
    set<pair<int, int>> queue;

    // All distances are initialized to infinity
    vector<int> distances(V, INF);

    // Parent vector for reconstructing the shortest path
    vector<int> parents(V);

    // Adding (distance, node number) pair for the source node
    queue.insert(make_pair(0, source));
    
    // Distance to source is 0
    distances[source] = 0;

    parents[source] = -1;


    while(!queue.empty())
    {
        // Popping of first element of queue
        pair<int, int> temp = *(queue.begin());
        queue.erase(queue.begin());

        // Number of the given node
        int u = temp.second;

        // Stopping if target node is reached
        if (u == target)
        {
            break;
        }

        // Iterating through the adjacency list of the given node
        for (auto i = adj[u].begin(); i != adj[u].end() ; i++)
        {
            // First element of the pair is the number of the adjacent node
            int v = (*i).first;
            // Second element of the pair is the weight of the edge to that node
            int weight = (*i).second;

            // Checking if the path is shorter
            if (distances[v] > distances[u] + weight)
            {
                // Removing the distance if it hasn't been checked yet
                if (distances[v] != INF)
                {
                    queue.erase(queue.find(make_pair(distances[v], v)));
                }

                // Updating the distance to the given node
                distances[v] = distances[u] + weight;

                parents[v] = u;
                
                queue.insert(make_pair(distances[v], v));
            }
        }
    }
    display_Dijkstra(distances, parents, source, target);
}

