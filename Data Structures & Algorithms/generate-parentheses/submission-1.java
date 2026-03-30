class Solution {

    private void generate(List<String> fa, StringBuilder curr, int open, int close, int n){
        if(open+close==2*n){
            fa.add(curr.toString());
        }
        if(open<n){
            curr.append('(');
            generate(fa,curr,open+1,close,n);
            curr.deleteCharAt(curr.length()-1);
        }
        if(close<open){
            curr.append(')');
            generate(fa,curr,open,close+1,n);
            curr.deleteCharAt(curr.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        StringBuilder sb = new StringBuilder();
        List<String> fa=new ArrayList<>();
        generate(fa,sb,0,0,n);
        return fa;
    }
}
