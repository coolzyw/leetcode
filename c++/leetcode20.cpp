class Solution {
public:
    bool isValid(string s) {
        // solve with stack
        if (s.size()%2==1){
            return false;
        }
        vector<char> temp;
        for (int i=0;i<s.size();i++){
            if(!temp.empty()){
                if ((temp.back()=='('&&s[i]==')') || 
                    (temp.back()=='[' && s[i]==']' || 
                     (temp.back()=='{' && s[i]=='}'))){
                    temp.pop_back();
                    continue;
                }
                temp.push_back(s[i]);
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if (temp.empty()) return true;
        else return false;
    }
};
