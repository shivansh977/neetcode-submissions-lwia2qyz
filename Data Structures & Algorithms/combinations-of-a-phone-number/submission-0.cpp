class Solution {
private:
    map<char,vector<char>> dict;
    void lcs(vector<string>&fa, string& digits, int id, string &cur){
        if(id==digits.length()) {
            fa.push_back(cur);
            return;
        }
        for(char ch:dict[digits[id]]){
            cur.push_back(ch);
            lcs(fa,digits,id+1,cur);
            cur.pop_back();
        }
        return;
    }
public:
    Solution(){
        dict['2']={'a','b','c'};
        dict['3']={'d','e','f'};
        dict['4']={'g','h','i'};
        dict['5']={'j','k','l'};
        dict['6']={'m','n','o'};
        dict['7']={'p','q','r','s'};
        dict['8']={'t','u','v'};
        dict['9']={'w','x','y','z'};
    }
    vector<string> letterCombinations(string digits) {
        vector<string> fa;
        if(digits.length()==0){
            return fa;
        }
        string cur="";
        lcs(fa,digits,0,cur);
        return fa;
    }
};
