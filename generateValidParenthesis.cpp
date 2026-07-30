class Solution {
public:
    void fn(int open, int close, int n, string temp, vector<string>&ans){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            fn(open+1, close,n, temp + "(", ans);
        }
        if(close < open){
            fn(open, close+1,n, temp + ")", ans);
        }


    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string>ans;
        fn(0,0,n,temp,ans);
        return ans;
    }
};