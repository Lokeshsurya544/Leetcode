class Solution
{
public:
    void backtrack(map<int, int> &freq, vector<vector<int>> &res, vector<int> &perm, vector<int> &a)
    {
        for (auto &x : freq)
        {
            if (perm.size() == a.size())
            {
                res.push_back(perm);
                return;
            }

            if (x.second > 0)
            {
                perm.push_back(x.first);
                x.second -= 1;
                backtrack(freq, res, perm, a);
                x.second += 1;
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &a)
    {
        map<int, int> freq;
        for (int i = 0; i < a.size(); i++)
        {
            freq[a[i]]++;
        }
        vector<vector<int>> res;
        vector<int> perm;
        backtrack(freq, res, perm, a);
        return res;
    }
};