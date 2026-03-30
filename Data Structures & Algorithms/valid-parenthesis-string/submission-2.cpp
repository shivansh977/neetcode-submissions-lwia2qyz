class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        if(n==1) return false;
        int openB=0,closeB=0;
        int star=0;
        vector<int> ids;
        for(int i=0;i<n;i++){
            if(s[i]=='(') openB++;
            else if(s[i]==')') closeB++;
            else {star++;ids.push_back(i);}
        }
        int dif=openB-closeB;
        bool isNeg=dif<0;
        dif=max(dif,-dif);
        if(dif>star) return false;
        int rob=(star-dif)/2;
        int rcb=rob;
        if(isNeg) rob+=dif;
        else rcb+=dif;
        for(int i=0;i<rob;i++){
            s[ids[i]]='(';
        }
        for(int i=0;i<rcb;i++){
            s[ids[ids.size()-1-i]]=')';
        }
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            if(cnt<0) return false;
        }
        return true;
    }
};
