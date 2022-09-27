class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int L = dominoes.length();
        int i=0,r=-1,c,l=-1,lId;
        
        while(i<L) {
            //if substring start with R and end with R make entire substring R
            if(dominoes[i] == 'R') {
                if(r != -1) {
                    for(int j=r+1 ; j<i ; j++)
                        dominoes[j] = 'R';
                }
                r = i;
            }
            //loginc for substring starting with R ending with L
            else if(dominoes[i] == 'L') {
                if(r != -1) {
                    c = (i-r-1);
                    if(c%2 == 0)
                        lId = r+c/2+1;
                    else
                        lId = r+c/2+2;
                    c/=2;
                    for(int j=r+1 ; j<=r+c ; j++)
                        dominoes[j] = 'R';
                    for(int j=lId ; j<i ; j++)
                        dominoes[j] = 'L';
                }
                //if substring start with L and end with L make entire substring L
                else if(l != -1) {
                    for(int j=l+1 ; j<i ; j++)
                        dominoes[j] = 'L';
                }
                l = i;
                r = -1;
            }
            i++;
        }
        
        //if very first non '.' character is L the update 0 to i with L
        i=0;
        while(i<L && dominoes[i] == '.') {
            i++;
        }
        if(i<L && dominoes[i] == 'L') {
            for(int j=0 ; j<i ; j++)
                dominoes[j] = 'L';
        }
        
        //if very first non '.' character from right side is R the update i to l-1 with R
        i=L-1;
        while(i>=0 && dominoes[i] == '.') {
            i--;
        }
        if(i>=0 && dominoes[i] == 'R') {
            for(int j=i+1 ; j<L ; j++)
                dominoes[j] = 'R';
        }
        
        return dominoes;
    }
};