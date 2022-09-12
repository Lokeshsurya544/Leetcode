class Solution
{
public:
    void func(int ind, vector<int> temp, vector<vector<int>> &res, int &n, vector<int> nums)
    {
        if (ind == n)
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(ind + 1, temp, res, n, nums);
        temp.pop_back();
        func(ind + 1, temp, res, n, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        int ind = 0;
        int n = nums.size();
        vector<int> temp;
        func(ind, temp, res, n, nums);
        return res;
    }
};