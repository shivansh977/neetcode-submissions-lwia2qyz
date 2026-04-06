class Solution {
private:
    string add(string& s1, string &s2){
        int n=s1.length();
        int m=s2.length();
        int reqlen=max(n,m)+1;
        int i1=s1.length()-1;
        int i2=s2.length()-1;
        int carry=0;
        string fa;
        for(int i=reqlen-1;i>=0;i--){
            int tmp=carry;
            if(i1>=0) tmp+=int(s1[i1--]-'0');
            if(i2>=0) tmp+=int(s2[i2--]-'0');
            fa.push_back(char((tmp%10)+'0'));
            carry=tmp/10;
        }
        while(fa.back()=='0') fa.pop_back();
        if(fa.empty()) fa="0";
        reverse(fa.begin(),fa.end());
        return fa;
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        vector<string> mult(10,"0");
        string tmp=num1;
        mult[1]=tmp;
        for(int i=2;i<=9;i++){
            tmp=add(tmp,num1);
            mult[i]=tmp;
        }
        string fa="0";
        for(int i=num2.size()-1;i>=0;i--){
            if(num2[i]=='0') continue;
            string tmp=mult[int(num2[i]-'0')];
            for(int j=0;j<num2.size()-1-i;j++) tmp.push_back('0');
            fa=add(fa,tmp);
        }
        return fa;
    }
};