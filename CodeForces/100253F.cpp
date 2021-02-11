#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXINP = 3e5+2;

pair<int,ld> tests[MAXINP];
map<int,ld> probs;

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d %Lf",&tests[i].fst,&tests[i].snd);

    int idx = 0, mex = -1;
    priority_queue<ii,vector<ii>,greater<ii>> Q;
    priority_queue<int,vi,greater<int>> mexQ;

    forn(i,min(n,m)) {
        Q.push({tests[idx].fst,idx});
        idx++;
    }

    ld rta = 0, prob = 1;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        //cerr << e.fst << ' ' << e.snd << endl;

        mexQ.push(e.snd);
        while (!mexQ.empty() && mexQ.top() == mex+1) {
            //cerr << "OKK" << endl;
            mexQ.pop(); mex++;
            probs[e.fst] += prob * (mex == n-1 ? 1 : (1-tests[mex].snd));
            prob *= tests[mex].snd;
        }

        if (idx < n) {
            Q.push({tests[idx].fst+e.fst,idx});
            idx++;
        }
    }

    for (auto &i : probs) rta += i.fst*i.snd;

    printf("%.15Lf",rta);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
