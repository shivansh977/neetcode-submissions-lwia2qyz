class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int val=score.top();
                score.pop();
                int val1=score.top();
                score.push(val);
                score.push(val+val1);
            }
            else if(operations[i]=="D"){
                score.push(2*score.top());
            }
            else if(operations[i]=="C"){
                score.pop();
            }
            else{
                score.push(stoi(operations[i]));
            }
        }
        int ans=0;
        while(!score.empty()){
            ans+=score.top();
            score.pop();
        }
        return ans;
    }
};