class Solution {
public:
    string decodeString(string s) {
        stack<char> sol;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                string temp="";
                string cnt="";
                while(sol.top()!='['){
                    temp.push_back(sol.top());
                    sol.pop();
                }
                sol.pop();
                while(!sol.empty()&&sol.top()<='9'&&sol.top()>='0'){
                    cnt.push_back(sol.top());
                    sol.pop();
                }
                reverse(temp.begin(),temp.end());
                reverse(cnt.begin(),cnt.end());
                int val=stoi(cnt);
                for(int i=0;i<val;i++){
                    for(int j=0;j<temp.size();j++){
                        sol.push(temp[j]);
                    }
                }
            }
            else sol.push(s[i]);
        }
        string ans="";
        while(!sol.empty()){
            ans.push_back(sol.top());
            sol.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};