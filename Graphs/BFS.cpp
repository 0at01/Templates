#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V 7;

template<typename T>

class graph
{
    map<T, list<T>> l;

public:

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;


        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";


            for(auto nbr: l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }


        }
    }

    void dfsHelper(T src, map<T, bool>&visited)
    {
        cout << src << " ";
        visited[src] = true;

        for(T nbr: l[src])
        {
            if(!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool>visited;

        for(auto p: l)
        {
            T node = p.first;
            visited[node] = false;
        }

        dfsHelper(src, visited);
    }


    bool cycleHelper(int node, bool *visited, int parent)
    {
        visited[node] = true;

        for(auto nbr: l[node])
        {
            if(!visited[nbr])
            {
                bool cycle_found = cycleHelper(nbr, visited, node);

                if(cycle_found)
                    return true;
            }

            else if(nbr!=parent)
            {
                return true;
            }
        }

        return false;
    }


    bool contains_cycle()
    {
        bool visited* = new bool[V];

        for(int i=0; i<V; i++)
        {
            visited[i] = false;
        }

        return cycleHelper(0, visited, -1);
    }


};

int main()
{
    graph<int>g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0); cout << endl;
    g.dfs(0);

    if(g.contains_cycle())
        cout << "contains cycle" << endl;
    else
        cout << "does not contain cycle" << endl;
    
}    