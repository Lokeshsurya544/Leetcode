class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a)
    {
        int ct = 0;

		// sort characters by their attack power in ascending order
        sort(a.begin(), a.end(), [] (const vector<int>& lhs, const vector<int>& rhs) -> bool {
            if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
            return lhs[0] < rhs[0];
        });

        int right = a.back()[1];

        auto upperBound = [&] (int lo, int hi, const int x) -> int {
            int mid;
            int idx = -1;

            while (lo <= hi) {
                mid = lo + ((hi - lo) / 2);

                if (a[mid][0] == x) {
                    lo = mid + 1;
                } else {
                    idx = mid;
                    hi = mid - 1;
                }
            }

            return idx;
        };

        for (int i = a.size() - 2; i >= 0; --i) {
			// search for nearest attack power greater than a[i][0] in [i + 1, a.size())
            int idx = upperBound(i + 1, a.size() - 1, a[i][0]);
            if (idx != -1) {
				// if any character with better attack and defense power exists, then this i-th character is weak
                ct = ct + (a[i][1] < a[idx][1]);
            }
			// update the maximum defense power so far for future iterations
            right = std::max(a[i][1], right);
            a[i][1] = right;
        }

        return ct;
    }
};