#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// True if u is ancestor of v
bool ancestor (int u, int v, int *tin, int *tout) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];  
}


// dfs of graph g
inline void dfs (int v, vector<int, int> *g, int *tin, int *tout, int *up[], int t, int logn) {
    for(int l = 1; l < logn; l++) {
        up[v][l] = up[up[v][l - 1]][l - 1];
    }
    tin[v] = t++;
    for(auto u : g[v]){
        up[u][0] = v;
        dfs(u, g, tin, tout, up, t, logn);
    }
    tout[v] = t++;
}

// gets lca
inline int lca(int u, int v, int *tin, int *tout, int *up[], int logn) {
    if (ancestor(v, u, tin, tout)) {
        return v;
    }
    if (ancestor(u, v, tin, tout)) {
        return u;
    }
    for (int l = logn - 1; l >= 0; --l) 
        if (!ancestor(up[v][l], u, tin, tout))
            v = up[v][l];
    return up[v][0];
        
    
}
