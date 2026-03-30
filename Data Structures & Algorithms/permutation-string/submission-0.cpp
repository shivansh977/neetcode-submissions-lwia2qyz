class Solution {
private:
    bool isAPerm(vector<int> &arr1, vector<int>& arr2){
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> req(26,0);
        vector<int> act(26,0);
        bool fa=false;
        if(s2.length()<s1.length()){
            return false;
        }
        for(int i=0;i<s1.length();i++){
            req[int(s1[i]-'a')]++;
            act[int(s2[i]-'a')]++;
        }
        fa=fa|isAPerm(req,act);
        for(int i=1;i<=s2.length()-s1.length();i++){
            act[int(s2[i-1]-'a')]--;
            act[int(s2[i+int(s1.length())-1]-'a')]++;
            fa=fa|isAPerm(req,act);
        }
        return fa;
    }
};
