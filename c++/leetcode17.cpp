class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return helper(digits);
    }
    
    vector<string> helper(string &digits){
        vector<string> result;
        if (digits.empty()){
            return result;
        }
        if (digits.size()==1){
            //cout<<"hello"<<endl;
            result = letter(atoi(&digits[0]));
        }
        else{
            //cout<<"nonono"<<endl;
            vector<string> previous;
            char temp = digits[0];
            digits.erase(digits.begin());
            previous = helper(digits);
            vector<string> next = letter(atoi(&temp));
            for (int i=0;i<next.size();i++){
                for (int j = 0; j<previous.size();j++){
                    result.push_back(next[i]+previous[j]);
                }
            }
        }
        return result;
    }
    
    vector<string> letter(int num){
        //cout<<"num "<<num<<endl;
        vector<string> result;
        if (num==0){
            return result;
        }
        else if(num<7){
            for (int i=0;i<3;i++){
                string element = "";
                element=char(97+(num-2)*3+i);
                //cout<<"push "<<element<<endl;
                result.push_back(element);
            }
        }
        else if (num==7){
            for (int i=0;i<4;i++){
                string element = "";
                element = char(97+(num-2)*3+i);
                result.push_back(element);
            }            
        }
        else if (num<9){
            for (int i=0;i<3;i++){
                string element = "";
                element=char(97+(num-2)*3+i+1);
                //cout<<"push "<<element<<endl;
                result.push_back(element);
            }            
        }
        else{
            for (int i=0;i<4;i++){
                string element = "";
                element = char(97+(num-2)*3+i+1);
                result.push_back(element);
            }
        }
        /*
        for (int i =0; i<result.size();i++){
            cout<<"result is: "<<result[i]<<endl;
        }*/
        return result;
    }
};
