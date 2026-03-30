class Solution {
private:
    void generate(vector<string>& res, string& cur, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            generate(res, cur, open + 1, close, n);
            cur.pop_back();
        }

        if (close < open) {
            cur.push_back(')');
            generate(res, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        generate(res, cur, 0, 0, n);
        return res;
    }
};