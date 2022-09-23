
#define MOD 1000000007
#define ll long long
class Solution
{
    public:
        int concatenatedBinary(int n)
        {
            ll ans = 0;
            for (int i = 1; i <= n; i++)
            {
                int j = i;
                while (j)
                {
                    j >>= 1;
                    ans <<= 1;
                }
                ans = (ans + i) % MOD;
            }
            return ans;
        }
};