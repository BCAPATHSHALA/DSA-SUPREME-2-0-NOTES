// ✅HW 05: Isomorphic Strings (Leetcode-205) (IMP)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};
        bool isTMapped[256] = {0};

        if(s.size() != t.size()){
            return false;
        }

        for(int i=0; i<s.size(); i++){
            if(hash[s[i]] == 0 && isTMapped[t[i]] == 0){
                hash[s[i]] = t[i];
                isTMapped[t[i]] = true;
            }
        }

        for(int i=0; i<s.size(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};