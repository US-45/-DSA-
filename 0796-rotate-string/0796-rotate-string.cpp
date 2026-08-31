class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        string concatenated = s + s;

        if(concatenated.find(goal) != string::npos){
            return true;
        }else{
            return false;
        }
    }
};