class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> j;
        for(char ch : jewels){
            j.insert(ch);
        }
        int count = 0;
        for(char ch : stones){
            if(j.find(ch) != j.end()){
                count++;
            }
        }
        return count;
    }
};