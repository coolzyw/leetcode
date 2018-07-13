class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> table(p.size()+1, vector<bool>(s.size()+1, false));
        // initialize
        table[0][0] = true;
        for (int i=0;i<s.size();i++){
            table[0][i+1]=false;
        }
        for (int i=0;i<p.size();i++){
            if (p[i]=='*') table[i+1][0] = table[i-2+1][0];
            else table[i+1][0] = false;
        }
        // recurrance relation
        for (int i=0;i<p.size();i++){
            for (int j=0;j<s.size();j++){
                if (p[i]==s[j]||p[i]=='.'){
                    table[i+1][j+1]=table[i-1+1][j-1+1];
                }
                else if (p[i]=='*'){
                    bool result1 = table[i-2+1][j+1];
                    bool result2 = false;
                    if (p[i-1]==s[j] || p[i-1]=='.'){
                        result2 = table[i+1][j+1-1];
                    }
                    else{
                        result2 = false;
                    }
                    table[i+1][j+1]=result1|result2;
                    /*
                    if (result1==true||result2==true){
                        table[i+1][j+1]=true;
                    }
                    else{
                        table[i+1][j+1]=false;
                    }
                    */
                }
                else{
                    table[i+1][j+1]=false;
                }
            }
        }
        for (int i=0;i<p.size()+1;i++){
            for (int j =0;j<s.size()+1;j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
        return table[p.size()][s.size()];
    }
};
