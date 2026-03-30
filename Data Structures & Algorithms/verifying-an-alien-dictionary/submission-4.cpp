class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<vector<bool>> isCorrect(26,vector<bool>(26,false));
        for(int i=0;i<order.size();i++){
            for(int j=i+1;j<order.size();j++){
                isCorrect[int(order[i]-'a')][int(order[j]-'a')]=true;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            int w1=words[i].size();
            int w2=words[i+1].size();
            int id=-1;
            for(int j=0;j<min(w1,w2);j++){
                if(words[i][j]!=words[i+1][j]){
                    id=j;break;
                }
            }
            if((id==-1&&w1>w2)||(id!=-1&&!isCorrect[int(words[i][id]-'a')][int(words[i+1][id]-'a')])){
                return false;
            }
        }
        return true;
    }
};