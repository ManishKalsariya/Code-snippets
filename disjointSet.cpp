#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
    public :
    int n;
    vector<int> parent, rank;
    DisjointSet(int n){
        this->n = n;
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank[i] = 0;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return find(parent[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }else{
            parent[parA] = parB;
        }
    }
};

int main(){
    DisjointSet ds(5);
    ds.unionByRank(0,1);
    ds.unionByRank(1,2);
    ds.unionByRank(3,4);

    cout<<ds.find(0)<<endl;
    cout<<ds.find(1)<<endl;
    cout<<ds.find(2)<<endl;
    cout<<ds.find(3)<<endl;
    cout<<ds.find(4)<<endl;

    return 0;
}