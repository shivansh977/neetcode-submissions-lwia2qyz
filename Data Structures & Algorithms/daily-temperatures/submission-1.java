class Solution {
    public int[] dailyTemperatures(int[] temperature) {
        int[] ans = new int[temperature.length];
        Stack<List<Integer>> st = new Stack<>();

        for(int i=0;i<temperature.length;i++){
            while(!st.empty()&&st.peek().get(0)<temperature[i]){
                List<Integer> ele=st.peek();
                st.pop();
                ans[ele.get(1)]=i-ele.get(1);
            }
            st.add(List.of(temperature[i],i));
        }
        return ans;
    }
}
