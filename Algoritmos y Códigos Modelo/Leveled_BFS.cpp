#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())

const int MAXN = 1005;
vector<int> g1[MAXN], g2[MAXN], g3[MAXN];
queue<int> Q0, Q1, Q2, Q3;
void bfs(int st){

    while(sz(Q0) || sz(Q1) || sz(Q2) || sz(Q3)){
        while(sz(Q0)){
            int p = Q0.front(); Q0.pop();
            // do stuff...
            for(int q : g1[p]){ // Los vecinos a distancia 1.
                // blabla..
                Q1.push(q);
            }
            for(int q : g2[p]){ // Los vecinos a distancia 2.
                // blabla..
                Q2.push(q);
            }
            for(int q : g3[p]){ // Los vecinos a distancia 3.
                // blabla..
                Q3.push(q);
            }
        }
        Q0 = Q1; Q1 = Q2; Q2 = Q3; Q3 = {};
    }
}
int main(){
	return 0;
}
