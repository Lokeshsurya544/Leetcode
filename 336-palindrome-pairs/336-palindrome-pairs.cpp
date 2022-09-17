// static const auto fastIO = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<int,unordered_map<string,int>> memo;
        for(int g=0;g<words.size();g++){
            string str = string( words[g].rbegin() , words[g].rend() );
            memo[ words[g].size() ][ str ] = g;
        }
        
        auto check = [&](string& str,int i,int j) -> bool {
            while( i < j ){
                if( str[i] != str[j] ) break;
                i++;
                j--;
            }
            return i >= j;
        };
        
        vector<vector<int>> res;
        for(int g=0;g<words.size();g++){
            
            string& str = words[g];
            
            for(auto& p : memo){
                if( p.first > str.size() ) break;
                
                if( p.first == str.size() ){
                    
                    if( p.second.count(str) && p.second[str] != g ){
                        res.push_back( { g , p.second[str] } );
                    }
                    
                    continue;
                }
                
                if( check( str , 0 , words[g].size()-1 - p.first ) && p.second.count( words[g].substr(words[g].size()-p.first) ) ){
                    // cout<<"first"<<endl;
                    res.push_back( { p.second[ words[g].substr( words[g].size()-p.first ) ] , g } );
                }
                
                if( check( str , words[g].size() - ( words[g].size() - p.first ) , words[g].size()-1 ) && p.second.count( words[g].substr( 0 , p.first ) ) ){
                    // cout<<"second"<<endl;
                    res.push_back( { g , p.second[ words[g].substr( 0 , p.first ) ] } );
                }
            }
        }
        return res;
        
    }
};