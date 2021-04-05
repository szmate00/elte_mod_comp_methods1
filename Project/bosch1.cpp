#include <iostream>
#include <stdio.h>

// funny number
#define INF 6969
#define V 9


// function to find the the node with the least distance from another given node
int find_min_distance(int distances[], bool visited[])
{
    int min_val = INF;
    int min_node;
  
    // initialize a node as the nearest if it is not visited yet and has a distance smaller than min_val
    // do this for all nodes, return index of the nearest in the end
    for (int i = 0; i < V; i++)
    {
        if ( !visited[i] && distances[i] < min_val)
        {
            min_val = distances[i];
            min_node = i;
        }
    }

    return min_node;
}

void display(int distances[] , int parents[]){
   for(int i =0 ;i < V ;i++)
   {
       int temp = parents[i]; 

       std::cout << "Path to node " << i << ":" << std::endl;
       std::cout << i << " <- ";

       while(temp != -1)
       {
           std::cout << temp << " <- ";
           temp = parents[temp]; 
       }

       std::cout << std::endl; 
       std::cout << "Time = " << distances[i] << std::endl; 
       std::cout << "--------------------------------" << std::endl; 
   } 
}

void dijkstra(int graph[V][V], int source, int target)
{
    int parents[V];
    int distances[V];
    bool visited[V];

    // initializing distance and visited arrays
    for (int i = 0; i < V; i++)
    {
        distances[i] = INF;
        visited[i] = false;
    }

    // distance from source node is 0
    distances[source] = 0;

    parents[source] = -1;

    // go through all nodes until end node is found
    for (int i = 0; i < V; i++)
    {
        // find nearest node
        int u = find_min_distance(distances, visited);

        // put it into visited
        visited[u] = true;

        // break the loop when the target node is chosen
        /*
        if (u == target)
        {
            break;
        }
        */

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && distances[u] != INF &&
             distances[u] + graph[u][v] < distances[v])
            {
                distances[v] = distances[u] + graph[u][v];
                parents[v] = u;
            }
        }
    }
  
   display(distances, parents);
}

int main()
{
    // weighted graph from the "code like a bosch" challenge first level
    /*
    int graph[V][V] = { { 0, 2, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 2, 0, 10, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 10, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 8, 0, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 3, 0, 0, 10, 0, 4, 0, 0, 10, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 2, 0, 0, 4, 0, 6, 0, 0, 10, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 1, 0, 0, 6, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 10, 0, 0, 0, 0, 7, 0, 0, 3, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 10, 0, 0, 7, 0, 6, 0, 0, 5, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 10, 0, 0, 6, 0, 1, 0, 0, 2, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 7 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 4, 0, 7, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 7, 0, 2 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 2, 0 }};
    */
    
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    int source = 0;
    int target = 15;

    dijkstra(graph, source, target);

    


    return 0;
}