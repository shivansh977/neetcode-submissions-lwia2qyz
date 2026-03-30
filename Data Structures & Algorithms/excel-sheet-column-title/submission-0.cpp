class Solution {
public:
    string convertToTitle(int n) {
        n--;
        string fa="";
        while(n>=0){
            fa.push_back(char('A'+(n%26)));
            n/=26;
            n--;
        }
        reverse(fa.begin(),fa.end());
        return fa;
    }
};