#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
    if(source == destination)
        return true;
    
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    queue<int> q;
    
    // arrange edges to each vertex vector
    for(int i = 0 ; i < edges.size() ; i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    q.push(source);
    
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        visited[vertex] = true;
        if(vertex == destination)
            return true;
        for(int i = 0 ; i < graph[vertex].size() ; i++)
        {
            if(graph[vertex][i] == destination)
                return true;
            
            if(visited[graph[vertex][i]] == false)
                q.push(graph[vertex][i]);
        }
    }
    
    return false;
}

int main()
{
    freopen("1971.in", "r", stdin);
    freopen("1971.out", "w", stdout);

    int n, source, destination;
    vector<vector<int>> edges;
    
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int from, to;
        cin >> from >> to;
        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edges.push_back(edge);
    }
    cin >> source >> destination;
    
    if (validPath(n, edges, source, destination))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
