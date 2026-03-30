class Solution {
public:
    long long minEnd(int n, int x) {
        string ans=bitset<64>(x).to_string();
        n--;
        for(int i=63;i>=0;i--){
            if(ans[i]=='0'){
                ans[i]=char('0'+n%2);
                n/=2;
            }
        }
        return std::stoll(ans, nullptr, 2);
    }
};