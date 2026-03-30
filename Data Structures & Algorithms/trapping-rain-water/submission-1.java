class Solution {
    public int trap(int[] height) {
        int fa=0;
        Deque<Integer> stack = new ArrayDeque<>();
        int ans=0;
        for(int i=0;i<height.length;i++){
            if(stack.isEmpty()||height[i]>=stack.peek()){
                stack.push(height[i]);
                fa+=ans;
                ans=0;
            }
            else{
                ans+=(stack.peek()-height[i]);
            }
        }
        stack = new ArrayDeque<>();
        ans = 0;
        for(int i=height.length-1;i>=0;i--){
            if(stack.isEmpty()||height[i]>stack.peek()){
                stack.push(height[i]);
                fa+=ans;
                ans=0;
            }
            else{
                ans+=(stack.peek()-height[i]);
            }
        }
        return fa;
    }
}
