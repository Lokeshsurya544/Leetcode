class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(colors[i] == colors[i+1]){
                int sum = neededTime[i];
                int maxx = sum;
                while(i<n-1 and colors[i] == colors[i+1]){
                    sum += neededTime[i+1];
                    maxx = max(maxx,neededTime[i+1]);
                    i++;
                }
                ans += (sum - maxx);
            }
        }
        return ans;
    }
};