class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] ans=new int[k][2];
        Queue<List<Integer>> q=new PriorityQueue<List<Integer>>((a,b)->a.get(0)-b.get(0));
        for(int i=0;i<points.length;i++){
            q.add(List.of(points[i][0]*points[i][0]+points[i][1]*points[i][1], points[i][0], points[i][1]));
        }
        for(int i=0;i<k;i++){
            List<Integer> el=q.peek();
            q.poll();
            ans[i][0]=el.get(1);
            ans[i][1]=el.get(2);
        }
        return ans;
    }
}
