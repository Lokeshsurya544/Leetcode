#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0, max_score = 0;
        int begin=0, end=tokens.size()-1;
        while (begin<=end)
        {
            if (power >= tokens[begin])
            {
                power -= tokens[begin];
                begin+=1;
                score += 1;
                max_score = (max_score, score);
            }
            else if (score > 0)
            {
                power += tokens[end];
                end-=1;
                score -= 1;
            }
            else
            {
                break;
            }
        }
        return max_score;
    }
};