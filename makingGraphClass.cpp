#include<iostream>
#include<list>
using namespace std;

class Graph{
        int V;
        list<int>* l;

    public:

        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int u, int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void print(){
            for(int i=0; i<V; i++){
                cout<<i<<"-->";
                for(int nbr : l[i]){
                    cout<<nbr<<",";
                }
                cout<<endl;
            }
        }
};


class weightedGraph{
        int V;
        list<pair<int, int>>* l;

    public:

        weightedGraph(int V){
            this->V = V;
            l = new list<pair<int, int>>[V];
        }

        void addEdge(int u, int v, int weight){
            l[u].push_back({v, weight});
            l[v].push_back({u, weight});
        }

        void print(){
            for(int i=0; i<V; i++){
                cout<<i<<"-->";
                for(auto p : l[i]){
                    cout<<"("<<p.first<<", "<<p.second<<"), ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.print();

    weightedGraph wg(4);
    wg.addEdge(0, 1, 10);
    wg.addEdge(0, 2, 20);
    wg.addEdge(1, 2, 30);
    wg.addEdge(2, 3, 40);
    wg.print();
    return 0;
}