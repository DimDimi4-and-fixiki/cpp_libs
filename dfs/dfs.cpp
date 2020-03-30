#include <iostream>
#include <vector>

using namespace std;

inline void dfs (int vertex, vector<int>* graph, bool* used)
{
    used[vertex] = true; // помечаем, что были в вершине
    for (auto i : graph[vertex]) { // перебираем соседей
        if (!used[i]) 
            dfs(i, graph, used); // запускаем dfs из непоюзанного соседа
        
    }
}
