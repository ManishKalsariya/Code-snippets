// activity selection problem on gfg can be solved with
// the help of making vector of pairs of (startTime, endTime)
// and sort them in ascending order by endTime...

class Solution {
  public:
  
    static bool cmp(pair<int,int>& p1, pair<int,int>& p2){
        return p1.second < p2.second;
    }
  
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>vec;
        for(int i=0; i<start.size(); i++){
            vec.push_back({start[i],finish[i]});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        int endTime = -1;
        int cnt = 0;
        
        for(int i=0; i<vec.size(); i++){
            int st = vec[i].first;
            if(st > endTime){
                cnt++;
                endTime = vec[i].second;
            }
        }
        return cnt;
    }
};