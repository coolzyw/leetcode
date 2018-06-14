class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int pos = 0;
        vector<string> dictionary = {"I","V","X","L","C","D","M"};
            while (num/10 || num%10){
                int last_digit = num%10;
                string part = "";
                if (pos!=3){
                    if (last_digit%5!=4){
                        if (last_digit/5){
                            part+=dictionary[2*pos+1];
                        }
                        for (int i=0;i<last_digit%5;i++){
                            part+=dictionary[2*pos];
                        }
                    }
                    else{
                        //9
                        if (last_digit/5){
                            part+=dictionary[2*pos];
                            part+=dictionary[2*(pos+1)];
                        }
                        else{//4
                            part+=dictionary[2*pos];
                            part+=dictionary[2*pos+1];
                        }
                    }
                }
                else{
                    for (int i=0;i<last_digit;i++){
                        part+="M";
                    }
                }
                result.insert(0, part);
                num=num/10;
                pos++;
        }
        return result;
    }
};
