#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 1005;
int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};
char const CD[] = {'R','D','L','U'};

struct togo {
    vector<ii> chk;
    int ndir;
    ii npos;
    char c;
};

vector<togo> CHK[5];

struct posic {
    int i,j,dir;

    bool operator== (const posic &o) const {
        return i == o.i && j == o.j && dir == o.dir;
    }
};

char tab[MAXN][MAXN];
int dis[MAXN][MAXN][5];
pair<posic,char> P[MAXN][MAXN][5];

ii ady(int k) {
    return {X[k],Y[k]};
}

ii ady2(int k) {
    ii ad = ady(k);
    if (X[k]) ad.fst += X[k];
    if (Y[k]) ad.snd += Y[k];
    return ad;
}

void preproc() {
    forn(k,4) {
        vector<ii> chk = {ady(k),ady2(k)};
        CHK[0].pb({chk,k+1,ady(k),CD[k]});
    }

    forn(k,4) {
        CHK[k+1].pb({{ady2(k)},0,ady2(k),CD[k]});
        CHK[k+1].pb({{ady((k+2)%4)},0,ady((k+2)%4),CD[(k+2)%4]});
        vector<ii> see = {{0,0},ady(k)};
        if (X[k]) {
            for (auto &j : see) j.snd++;
            CHK[k+1].pb({see,k+1,{0,1},'R'});
            for (auto &j : see) j.snd -= 2;
            CHK[k+1].pb({see,k+1,{0,-1},'L'});
        }
        if (Y[k]) {
            for (auto &j : see) j.fst++;
            CHK[k+1].pb({see,k+1,{1,0},'D'});
            for (auto &j : see) j.fst -= 2;
            CHK[k+1].pb({see,k+1,{-1,0},'U'});
        }
    }
}

int main(){
    FAST_IO;

    preproc();

    int n,m; cin >> n >> m;

    forn(i,n) forn(j,m) cin >> tab[i][j];

    ii ini, fin;
    forn(i,n) forn(j,m) if (tab[i][j] == 'C') ini = {i,j}, tab[i][j] = '.';
    forn(i,n) forn(j,m) if (tab[i][j] == 'E') fin = {i,j}, tab[i][j] = '.';

    forn(i,MAXN) forn(j,MAXN) forn(k,5) dis[i][j][k] = -1;

    queue<posic> Q;
    dis[ini.fst][ini.snd][0] = 0;
    Q.push({ini.fst,ini.snd,0});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.i == fin.fst && e.j == fin.snd && e.dir == 0)
            break;
        
        for (auto &tr : CHK[e.dir]) {
            bool posib = true;
            for (auto &ad : tr.chk) {
                int di = e.i + ad.fst, dj = e.j + ad.snd;
                if (di < 0 || dj < 0 || di >= n || dj >= m || tab[di][dj] == '#') {
                    posib = false; break;
                }
            }
            if (!posib) continue;
            int di = e.i + tr.npos.fst, dj = e.j + tr.npos.snd;
            if (di < 0 || dj < 0 || di >= n || dj >= m) continue;
            if (tab[di][dj] == '#') continue;
            if (dis[di][dj][tr.ndir] != -1) continue;
            dis[di][dj][tr.ndir] = dis[e.i][e.j][e.dir] + 1;
            P[di][dj][tr.ndir] = {{e.i,e.j,e.dir},tr.c};
            Q.push({di,dj,tr.ndir});
        }
    }

    if (dis[fin.fst][fin.snd][0] == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << dis[fin.fst][fin.snd][0] << '\n';

    string cam;
    posic cur = {fin.fst,fin.snd,0};
    posic inip = {ini.fst,ini.snd,0};
    while (!(cur == inip)) {
        cam.pb(P[cur.i][cur.j][cur.dir].snd);
        cur = P[cur.i][cur.j][cur.dir].fst;
    }

    reverse(all(cam));

    cout << cam << '\n';
    
    return 0;
}
