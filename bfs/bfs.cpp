#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline void bfs (int vertex, vector<int>* graph, bool* used, queue<int>* q, int )
{
    q.push(vertex); // помещаем стартовую вершину в очередь
    used[vertex] = true; // помечаем стартовую вершину
    while (!q.empty()) {
        int v = q.front(); // берем вершину с начала очереди
        q.pop(); // поп очереди
        for (auto u : graph[v]) { // смотрим соседей нашей вершины
            if (!used[u]) { 
                used[u] = true; // юзаем соседа
                q.push(u); // добавляем соседа в очередь
            }
        }
    }    
}
