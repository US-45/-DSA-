class Solution {
public:
    int appendCharacters(string s, string t) {
        int ptr1 = 0, ptr2 =0, count = 0;
        while(ptr1 < s.length()){
            if(s[ptr1] == t[ptr2]){
                count++;
                ptr1++;ptr2++;
            }else{
                ptr1++;
            }
        }

        return t.length() - count;
    }
};