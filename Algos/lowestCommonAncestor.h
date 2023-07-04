#ifndef LOWEST_COMMON_ANCESTOR_H
#define LOWEST_COMMON_ANCESTOR_H

#include <vector>
using namespace std;

namespace Algos
{
    vector<int> _tin, _tout, _depth;
    vector<vector<int>> _up;

    void dfs(int v, int p, int d, vector<vector<int>>& adj)
    {
        _tin[v] = _tout[v] = _depth[v] = d;
        _up[v][0] = p;
        for (int i = 1; i < _up[v].size(); ++i)
            _up[v][i] = _up[_up[v][i - 1]][i - 1];
        for (int u : adj[v])
        {
            if (u != p)
            {
                dfs(u, v, d + 1, adj);
                _tout[v] = max(_tout[v], _tout[u]);
            }
        }
    }

    bool isAncestor(int u, int v)
    {
        return _tin[u] <= _tin[v] && _tout[u] >= _tout[v];
    }

    int lca(int u, int v)
    {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;
        for (int i = _up[u].size() - 1; i >= 0; --i)
        {
            if (!isAncestor(_up[u][i], v))
                u = _up[u][i];
        }
        return _up[u][0];
    }
}

#endif // LOWEST_COMMON_ANCESTOR_H