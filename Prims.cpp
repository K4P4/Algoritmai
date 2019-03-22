#include <iostream>
#include <vector>
#include <limits>

using std::vector;

const int V = 5;
/*
int graph[V][V] = {{0, 2, 0, 6, 0},
                  {2, 0, 3, 8, 5},
                  {0, 3, 0, 0, 7},
                  {6, 8, 0, 0, 9},
                  {0, 5, 7, 9, 0}};
*/

int graph[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

struct edge{
    int curr;
    int next;
    int cost;
};

void next(vector<edge>& vek){
    int minimum =  std::numeric_limits<int>::max();
    bool Listed;
    int ret, crr;

    for(int j = 0; j < vek.size()+1; j++){
        for(int i = 0; i < V; i++){
            if(graph[vek[j].next][i] < minimum && graph[vek[j].next][i] != 0){
                Listed = false;
                for(int k = 0; k < vek.size()+1; k++){
                    if(vek[k].next == i || vek[k].curr == i) Listed = true;
                }
                if(Listed == false){
                minimum = graph[vek[j].next][i];
                crr = vek[j].next;
                ret = i;
                }
            }
        }
    }
    edge temp;
    temp.curr = crr;
    temp.next = ret;
    temp.cost = graph[temp.next][temp.curr];
    vek.push_back(temp);
}

int main(){
    vector<edge> optimal;
    optimal.reserve(V);

    optimal[0].curr = 0;
    optimal[0].next = 0;
    for(int i = 0; i < V-1; i++){
            next(optimal);
    }

    for(int i = 0; i < V-1; i++){
        std::cout << optimal[i].curr << " " << optimal[i].next << " " << optimal[i].cost << std::endl;
    }
}
