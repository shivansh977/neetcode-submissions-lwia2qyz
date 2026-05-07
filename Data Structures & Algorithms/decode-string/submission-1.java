class Solution {
    public String decodeString(String input) {
        Stack<List<Object>> st = new Stack<>();
            StringBuilder sb = new StringBuilder(input);
            StringBuilder num = new StringBuilder();
            StringBuilder fa = new StringBuilder();
            for(int i=0;i<sb.length();i++){
                if(sb.charAt(i)>='0'&&sb.charAt(i)<='9'){
                    num.append(sb.charAt(i));
                }
                else if(sb.charAt(i)=='['){
                    st.push(List.of(Integer.valueOf(num.toString()), new StringBuilder()));
                    num = new StringBuilder();
                }
                else if(sb.charAt(i)==']'){
                    List<Object> ob = st.pop();
                    if(st.empty()){
                        for(int j=0;j<(Integer) ob.getFirst();j++){
                            fa.append(ob.get(1).toString());
                        }
                    }
                    else {
                        for(int j=0;j<(Integer) ob.getFirst();j++){
                            ((StringBuilder) st.peek().get(1)).append(ob.get(1).toString());
                        }
                    }
                }
                else{
                    if(st.empty()){
                        fa.append(sb.charAt(i));
                    }
                    else{
                        ((StringBuilder) st.peek().get(1)).append(sb.charAt(i));
                    }
                }
            }
            return fa.toString();
    }
}