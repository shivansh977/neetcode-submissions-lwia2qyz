class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int i=0;
        int maxFreq=0;
        int ans=0;

        for (int j=0;j<s.size();j++) {
            cnt[s[j] - 'A']++;
            maxFreq = max(maxFreq, cnt[s[j] - 'A']);

            int windowLen = j-i+1;
            int required = windowLen-maxFreq;

            if (required > k) {
                cnt[s[i] - 'A']--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};