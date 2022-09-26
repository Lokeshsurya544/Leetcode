class Solution
{
    public:
        int par[1001];
    int rk[1001];
    int findpar(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }
    void unionfun(int u, int v)
    {
        u = findpar(u);
        v = findpar(v);
        if (rk[u] < rk[v])
            par[u] = v;
        else if (rk[v] < rk[u])
            par[v] = u;
        else
        {
            rk[u]++;
            par[v] = u;
        }
    }
    bool equationsPossible(vector<string> &eqs)
    {
        for (int i = 0; i < 1001; i++)
        {
            par[i] = i;
            rk[i] = 0;
        }
        for (auto it: eqs)
        {
            if (it[1] == '=')
                unionfun(it[0] - '0', it[3] - '0');
        }
        for (auto it: eqs)
        {
            if (it[1] == '!')
            {
                if (findpar(it[0] - '0') == findpar(it[3] - '0'))
                    return false;
            }
        }
        return true;
    }
};