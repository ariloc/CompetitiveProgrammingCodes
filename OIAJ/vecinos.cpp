#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
const int MAXN = 1000;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi vec[MAXN];
//int dist[MAXN] = {};
//ii maxdist = {-1,-1};
//vi done (MAXN,false);
//int a = 0, b = 0;

/*void bfs(int &i) {
    queue<int> Q;
    done[i] = true;
    Q.push(i);
    //dist[i] = 0;

    while(not Q.empty()) {
        int x = Q.front(); Q.pop();
        int hechoCadaUno = 0;
        for (auto e : vec[x]) {
            if (done[e]) continue;
            done[e] = true;
            Q.push(e);
            //dist[e] = dist[x]+1;
            if (dist[e] > maxdist.fst) {
                maxdist.fst = dist[e];
                maxdist.snd = e;
                cout << maxdist.snd << ' ';
            }//
        }
    }
}*/

int main()  {
    freopen("vecinos.in","r",stdin);
    freopen("vecinos.out","w",stdout);

    int N,r;
    set<int> vecinos;
    cin >> N;
    forn (i,N) {
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        if (vecinos.count(a)) vecinos.erase(a);
        else vecinos.insert(a);
        if (vecinos.count(b)) vecinos.erase(b);
        else vecinos.insert(b);
    }

    cout << N << endl;
    while (not vecinos.empty()) {
        int x = *vecinos.upper_bound(0);
        cout << x << ' ';
        vecinos.erase(x);
    }
    return 0;
}
