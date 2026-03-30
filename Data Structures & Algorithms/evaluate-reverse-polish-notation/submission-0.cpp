class Solution {
private:
    bool isExpr(const string& s){
        return s=="+"||s=="-"||s=="*"||s=="/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(!isExpr(tokens[i])){
                s.push(stoi(tokens[i]));
            }
            else{
                int val1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                int val3=0;
                if(tokens[i]=="+"){
                    val3=val2+val1;
                } else if(tokens[i]=="-"){
                    val3=val2-val1;
                } else if(tokens[i]=="*"){
                    val3=val2*val1;
                } else if(tokens[i]=="/"){
                    val3=val2/val1;
                }
                s.push(val3);
            }
        }
        return s.top();
    }
};
