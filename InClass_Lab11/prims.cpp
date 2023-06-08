#include <iostream>
using namespace std;

#define INFINITY 9999999
#define V 6

int minDistance(int distance[], bool mstSet[])
{
    int min = INFINITY;
    int minIndex;

    for (int v=0; v<V; v++)
    {
        if (mstSet[v]== false && distance[v] < min)
        {
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int G[V][V], int src)
{
    cout << "Edge  : Weight" << endl;
    for(int i = 1; i < V; i++)
    {
        if (i != src)
        {
            cout << parent[i] << " - " << i << " :\t" << G[i][parent[i]] << endl;
        }
        
    }
}

void primMST(int G[V][V], int src)
{
    bool mstSet[V];
    int parent[V];
    int distance [V];

    for(int v=0; v<V; v++)
    {
        distance[v] = INFINITY;
        mstSet[v] = false;
    }

    distance[src] = 0;
    parent[src] = -1;

    for(int count = 0; count < V-1; count++)
    {
        int u = minDistance(distance, mstSet);
        mstSet[u] = true;
        for (int v=0; v < V; v++)
        {
            if (G[u][v] && mstSet[v] == false && G[u][v ]< distance[v]) 
            {
                parent[v] = u;
                distance[v] = G[u][v];
            }
        }

    }
    printMST(parent, G, src);
}

int main()
{
    int G[V][V] = { { 0,  3,  0,  0,  0,  1},
                    { 3,  0,  2,  1, 10,  0},
                    { 0,  2,  0,  3,  0,  5},
                    { 0,  1,  3,  0,  5,  0},
                    { 0, 10,  0,  5,  0,  4},
                    { 1,  0,  5,  0,  4,  0}
    };

    primMST(G, 0);
    return 0;
}