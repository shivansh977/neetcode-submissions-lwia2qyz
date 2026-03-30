class Solution {
private:
    bool good(map<char,int>& tdat, map<char,int>& mov){
        for(char ch='a';ch<='z';ch++){
            if(mov[ch]<tdat[ch]) return false;
        }
        for(char ch='A';ch<='Z';ch++){
            if(mov[ch]<tdat[ch]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        map<char,int> tdat;
        map<char,int> mov;
        int minlength=0,fi,fj;
        for(char c:t) tdat[c]++;
        int i=0,j=0;
        while(j<s.length()){
            mov[s[j]]++;
            if(good(tdat,mov)){
                break;
            }
            j++;
        }
        if(!good(tdat,mov)) return "";
        for(int k=i;k<=j;k++){
            mov[s[k]]--;
            if(!good(tdat,mov)){
                mov[s[k]]++;
                i=k;
                break;
            }
        }
        minlength=j-i+1;
        fi=i;
        fj=j;
        while(j<s.length()){
            char rc=s[i];
            mov[s[i]]--;
            i++;j++;
            mov[s[j]]++;
            if(!good(tdat,mov)){
                while(j<s.length()&&s[j]!=rc){mov[s[j]]++;j++;}
            }
            if(s[j]!=rc){
                break;
            }
            else mov[s[j]]++;
            for(int k=i;k<=j;k++){
                mov[s[k]]--;
                if(!good(tdat,mov)){
                    mov[s[k]]++;
                    i=k;
                    break;
                }
            }
            if(j-i+1<minlength){
                minlength=j-i+1;
                fi=i;
                fj=j;
            }
            //cout<<i<<" "<<j<<"\n";
        }
        return s.substr(fi,fj-fi+1);
    }
};
