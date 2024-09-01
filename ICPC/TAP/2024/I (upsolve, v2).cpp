#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1005;
int const MAXG = 2*MAXN;

bool board[MAXN][MAXN];
vi G[MAXG];
int deg[MAXG];
bitset<MAXG> done;
int rta[MAXN][MAXN];

struct edge {
	int y;
	list<edge>::iterator rev;
	edge(int y):y(y){}
};
list<edge> g[MAXG];
void add_edge(int a, int b){
	g[a].push_front(edge(b));auto ia=g[a].begin();
	g[b].push_front(edge(a));auto ib=g[b].begin();
	ia->rev=ib;ib->rev=ia;
}
vector<int> p;
void go(int x){
	while(g[x].size()){
		int y=g[x].front().y;
		g[y].erase(g[x].front().rev);
		g[x].pop_front();
		go(y);
	}
	p.push_back(x);
}
vector<int> get_path(int x){ // get a path that begins in x
// check that a path exists from x before calling to get_path!
	p.clear();go(x);reverse(p.begin(),p.end());
	return p;
}

void check(int st) {
    done[st] = true;
    for (auto &i : G[st])
        if(!done[i]) check(i);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) forn(j,m) {
        char x; cin >> x;
        if (x == '.') board[i][j] = true;
    }

    forn(i,n) forn(j,m)
        if (board[i][j]) {
            int row = i;
            int col = n+j;
            add_edge(row,col);
            G[row].pb(col), G[col].pb(row);
            deg[row]++, deg[col]++;
        }

    vi odd;
    forn(i,MAXG) if (deg[i]&1) odd.pb(i);

    if ((int)odd.size() > 2)
        return cout << "*\n", 0;

    forn(i,MAXG)
        if (deg[i] > 0) {
            check(i); break;
        }
    forn(i,MAXG) 
        if (deg[i] > 0 && !done[i])
            return cout << "*\n", 0;

    vi path;
    if (!odd.empty()) {
        int a = odd[0], b = odd[1];
        path = get_path(a);
    }
    else {
        int auxi = -1;
        forn(i,MAXG)
            if (deg[i] > 0) {
                auxi = i; break;
            }
        if (auxi != -1)
            path = get_path(auxi);
    }

    int cnt = 1, prv = -1;
    for (auto &i : path) {
        if (prv != -1) {
            if (prv < n && i >= n) {
                rta[prv][i-n] = cnt++;
            }
            else if (prv >= n && i < n){
                rta[i][prv-n] = cnt++;
            }
        }
        prv = i;
    }

    forn(i,n) forn(j,m)
        cout << rta[i][j] << " \n"[j == m-1];

    return 0;
}
