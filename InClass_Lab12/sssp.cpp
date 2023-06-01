#include <iostream>
using namespace std;

#define INFINITY 9999
#define max 6

int minTime(int avgTime[], bool sptSet[])
{
    int min = INFINITY; 
    int min_index;

    for (int v = 0; v< max; v++) {
        if (sptSet[v] == false && avgTime[v] <= min)
        {
            min = avgTime[v];
            min_index = v;
        }
    }
    return min_index;
}

void displaySol(int avgTime[], int src)
{
    cout << "Starting from " << src << endl;
    for(int i = 0; i < max; i++)
    {
        cout << "Distance of node "<< i <<  " = " << avgTime[i] << endl;
    }   
}

void dijkstra(int G[max][max], int startnode) {
    int avgTime[max];
    bool sptSet[max];

    for (int i = 0; i < max; i++) {
        avgTime[i] = INFINITY;
        sptSet[i] = false;
    }
    avgTime[startnode] = 0;

    for(int count = 0; count < max-1; count++) {
        int u = minTime(avgTime, sptSet);
        sptSet[u] = true;

        for(int v = 0; v < max; v++) {
            if (!sptSet[v] && G[u][v] && avgTime[u] != INT_MAX && avgTime[u] + G[u][v] < avgTime[v])
            {
                avgTime[v] = avgTime[u] + G[u][v];
            }
        }
    }

    displaySol(avgTime, startnode);    
}

int main() {
    int G[max][max] = {
        { 0, 10,  0,  0, 15,  5},
        {10,  0, 10, 30,  0,  0},
        { 0, 10,  0, 12,  5,  0},
        { 0, 30, 12,  0,  0, 20},
        {15,  0,  5,  0,  0,  0},
        { 5,  0,  0, 20,  0,  0}
    };
    int src = 5;
    dijkstra(G, src);
    return 0;
}