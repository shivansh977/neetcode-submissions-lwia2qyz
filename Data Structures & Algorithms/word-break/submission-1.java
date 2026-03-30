class Solution {
    private boolean listHasWord(String word, List<String> wordDict){
        for(String w:wordDict){
            if(w.equals(word)) return true;
        }
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        StringBuilder sb=new StringBuilder(s);
        int n=s.length();
        boolean dp[]=new boolean[n+1];
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(listHasWord(sb.substring(j-1,i).toString(), wordDict)&&dp[j-1]){
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
}
