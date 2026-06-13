// for finding MST (minimum spanning tree) of a graph

int  prims(int v, vector<vector<pair<int,int>>>&adj){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    pq.push({0,0}); //{wt, node}
    vector<bool>inMST(v,false);
    int mstCost = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(!inMST[u]){
            inMST[u] = true;
            mstCost += wt;
        }

        for(auto e : adj[u]){
            int v = e.first;
            int w = e.second;

            if(!inMST[v]){
                pq.push({w,v});
            }
        }
    }
    return mstCost;
}