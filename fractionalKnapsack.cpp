// greedy approach for fractional knapsack problem
// it can be solved like this : sort the items according to their value/weight
//  ratio in descending order and then take the items one by one until the capacity
//  is filled. If the next item cannot be taken completely, take the fraction of it that
// fits into the knapsack.

class Solution {
  public:
    
    static bool cmp(pair<pair<double,int>,int>& a,
                pair<pair<double,int>,int>& b) {
        return a.first.first < b.first.first; // descending
    }
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<pair<double,int>,int>>arr;
        int n = val.size();
        for(int i=0; i<n; i++){
            arr.push_back({{(double)val[i]/wt[i], wt[i]},val[i]});
            
        }
        sort(arr.begin(), arr.end(), cmp);
        double ans = 0;
        
        for(int i=n-1; i>= 0; i--){
            if(capacity < arr[i].first.second && capacity > 0){
                ans += (arr[i].first.first)*capacity;
                break;
                
            }else if(capacity > 0){
                capacity -= arr[i].first.second;
                ans += arr[i].second;
            }
        }
        return ans;
    }
};