#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int temp = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            // cout << temp << endl;
            temp += shifts[i];
            // cout << temp << endl;
            temp %= 26;
            // cout << temp << " " << 'z' - 0 << " " << s[i] - 0 << endl;
            if (temp > 'z' - s[i])
                s[i] += temp - 26;
            else
                s[i] += temp;
            // cout << s << endl;
        }
        return s;
    }
};