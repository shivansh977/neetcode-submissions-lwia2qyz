class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        string ans="";
        for(int len=1;len<=min(n,m);len++){
            if(n%len==0&&m%len==0){
                bool flag=true;
                for(int i=0;i<n;i++){
                    if((str1[i%len]!=str2[i%len])||
                    (str1[i%len])!=str1[i]){
                        flag=false;
                        break;
                    }
                }
                for(int i=0;i<m;i++){
                    if((str1[i%len]!=str2[i%len])||
                    (str2[i%len])!=str2[i]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans=str1.substr(0,len);
                }
            }
        }
        return ans;
    }
};