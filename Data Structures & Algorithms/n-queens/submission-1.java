class Solution {
    private boolean isValidPlace(List<StringBuilder> board, int i, int j){
        int n=board.size();
        int m=board.get(0).length();
        int k=1;
        while(i-k>=0&&j-k>=0){
            if(board.get(i-k).charAt(j-k)=='Q'){
                return false;
            }
            k++;
        }
        k=1;
        while(i-k>=0&&j+k<m){
            if(board.get(i-k).charAt(j+k)=='Q'){
                return false;
            }
            k++;
        }
        k=1;
        while(i-k>=0){
            if(board.get(i-k).charAt(j)=='Q'){
                return false;
            }
            k++;
        }
        return true;
    }

    private boolean solve(List<StringBuilder> board, int row, int n, List<List<String>> fa){
        if(row==n){
            List<String> tempBoard=new ArrayList();
            for(StringBuilder x:board){
                tempBoard.add(x.toString());
            }
            fa.add(tempBoard);
            return true;
        }
        boolean ans=false;
        for(int i=0;i<board.get(row).length();i++){
            if(isValidPlace(board,row,i)){
                board.get(row).setCharAt(i,'Q');
                if(solve(board,row+1,n,fa)) ans=true;
                board.get(row).setCharAt(i,'.');
            }
        }
        return ans;
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> fa=new ArrayList();
        List<StringBuilder> board=new ArrayList();
        StringBuilder ts=new StringBuilder();
        for(int i=0;i<n;i++){
            ts.append('.');
        }
        for(int i=0;i<n;i++){
            board.add(new StringBuilder(ts.toString()));
        }
        solve(board,0,n,fa);
        return fa;
    }
}
