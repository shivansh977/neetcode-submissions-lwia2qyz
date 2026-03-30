class Solution {
public:
    string simplifyPath(string path) {
        string fa="";
        vector<string> paths;
        vector<string> paths1;
        string cur="";
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                if(cur.size()) {paths.push_back(cur);cur="";}
            }
            else{
                cur.push_back(path[i]);
            }
        }
        if(cur.size()) paths.push_back(cur);
        if(paths[0]!=".."&&paths[0]!=".") paths1.push_back(paths[0]);
        for(int i=1;i<paths.size();i++){
            if(paths[i]==".."){
                if(!paths1.empty()) paths1.pop_back();
            }
            else if(paths[i]==".") continue;
            else paths1.push_back(paths[i]);
        }
        for(int i=0;i<paths1.size();i++){
            fa.push_back('/');
            fa+=paths1[i];
        }
        if(fa.empty()) fa.push_back('/');
        return fa;
    }
};