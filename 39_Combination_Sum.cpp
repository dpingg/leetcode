//dfs

class Solution {
public:
    void dfs(vector<int> current, int sum, int target, int depth, vector<vector<int> > &ans, vector<int> &candidates) {
        if(sum==target) {
            sort(current.begin(),current.end());
            ans.push_back(current);
            return;
        }
        if(sum>target) {
            return;
        }
        if(depth>=candidates.size()) {
            return;
        }
        dfs(current, sum, target, depth+1, ans, candidates);
        for(int j=1; sum+candidates[depth]*j<=target; j++) {
            current.push_back(candidates[depth]);
            dfs(current, sum+candidates[depth]*j, target, depth+1, ans, candidates);
            
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> current;
        vector<vector<int> > ans;
        dfs(current, 0, target, 0, ans, candidates);
        return ans;
    }
    
};
