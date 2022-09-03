class Solution {
public:
    void dfs(int i, int d, int cnt, int n, int k, set<int>& res) {
        if(d < 0 || d > 9) return;
        i = i * 10 + d;
        cnt++;
        if(cnt == n) {
            res.insert(i);
            return;
        }
        dfs(i, d - k, cnt, n, k, res);
        dfs(i, d + k, cnt, n, k, res);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> res;
        for(int i = 1; i < 10; i++) {
            dfs(0, i, 0, n, k, res);
        }
        vector<int> ans;
        for(int i : res) ans.push_back(i);
        return ans;
    }
};