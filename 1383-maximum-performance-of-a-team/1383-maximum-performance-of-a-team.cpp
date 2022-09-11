#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> engg;
        for (int i = 0; i < n; i++)
        {
            engg.push_back({efficiency[i], speed[i]});
        }

        sort(engg.begin(), engg.end());

        for (auto x : engg)
        {
            cout << x.first << " " << x.second;
            cout << endl;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        long sum = 0, res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (pq.size() >= k)
            {
                sum -= pq.top();
                pq.pop();
            }
            sum += engg[i].second;
            pq.push(engg[i].second);
            res = max(res, sum * engg[i].first);
        }
        return (res % (long)(pow(10, 9) + 7));
    }
};