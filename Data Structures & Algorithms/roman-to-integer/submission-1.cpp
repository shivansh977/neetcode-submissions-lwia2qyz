class Solution {
public:
    int romanToInt(string s) {
        int fa=0;
        unordered_map<char,int> dict;
        dict['I']=1;
        dict['V']=5;
        dict['X']=10;
        dict['L']=50;
        dict['C']=100;
        dict['D']=500;
        dict['M']=1000;
        for(int i=0;i<s.length();i++){
            if(i<s.length()-1&&((s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X'))||(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C'))||(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M')))){
                fa-=dict[s[i]];
            }
            else fa+=dict[s[i]];
            
        }
        return fa;
    }
};