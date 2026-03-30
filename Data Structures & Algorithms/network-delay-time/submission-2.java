class Solution {
    private void calcDist(List<List<Integer>>[] adj, int[] dist, int st){
        Queue<List<Integer>> q=new PriorityQueue<List<Integer>>((a,b)->a.get(0)-b.get(0));
        dist[st]=0;
        q.add(List.of(0,st));
        while(!q.isEmpty()){
            List<Integer> x=q.peek();
            q.poll();
            if(x.get(0)>dist[x.get(1)]){
                continue;
            }
            for(List<Integer> neigh:adj[x.get(1)]){
                if(dist[neigh.get(0)]>x.get(0)+neigh.get(1)){
                    dist[neigh.get(0)]=x.get(0)+neigh.get(1);
                    q.add(List.of(dist[neigh.get(0)], neigh.get(0)));
                }
            }
        }
    }
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Integer>>[] adj=new ArrayList[n];
        int[] dist=new int[n];
        for(int i=0;i<n;i++) {adj[i]=new ArrayList();dist[i]=1000000000;}
        for(int i=0;i<times.length;i++){
            adj[times[i][0]-1].add(List.of(times[i][1]-1,times[i][2]));
        }
        calcDist(adj, dist, k-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(dist[i]==1000000000) return -1;
            else ans=Math.max(ans,dist[i]);
        }
        return ans;
    }
}
