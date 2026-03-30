class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] ans=new int[k];
        Map<Integer,Integer> m=new HashMap();
        for(int i=0;i<nums.length;i++){
            int val=0;
            if(m.get(nums[i])!=null) val=m.get(nums[i]);
            m.put(nums[i],val+1);
        }
        List<List<Integer>> l=new ArrayList();
        for(Map.Entry<Integer,Integer> es:m.entrySet()){
            l.add(List.of(es.getKey(),es.getValue()));
        }
        l.sort((a,b)->{
            return b.get(1)==a.get(1)?a.get(0)-b.get(0):b.get(1)-a.get(1);
        });
        for(int i=0;i<k;i++){
            ans[i]=l.get(i).get(0);
        }
        return ans;
    }
}
