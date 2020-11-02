// https://www.hackerrank.com/contests/simulacro-1-oia-2020/challenges/problem-1-cow-beauty-pageant/problem
#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 52;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int INF = 1e9+5;

bool done1[MAXN][MAXN];
int comp[MAXN][MAXN];
int dist[MAXN][MAXN][3];
char mat[MAXN][MAXN];

int cow_beauty(vector<string> v) {
    int prox_libre = 1;
    forn(i,v.size()) forn(j,v[0].size()) mat[i][j] = v[i][j];

    ii r[3] = {{-1,-1},{-1,-1},{-1,-1}};

    forn(i,MAXN) forn(j,MAXN) // determinamos números de manchas
        if (!comp[i][j] && mat[i][j] == 'X') {
            queue<ii> Q;
            Q.push({i,j});
            comp[i][j] = prox_libre;
            r[prox_libre-1] = {i,j};

            while (!Q.empty()) {
                auto e = Q.front(); Q.pop();

                forn(k,4) {
                    int tY = e.fst+Y[k], tX = e.snd+X[k];
                    if (tY < 0 || tX < 0 || tY >= MAXN || tX >= MAXN) continue;
                    if (comp[tY][tX]) continue;
                    if (mat[tY][tX] != 'X') continue;
                    comp[tY][tX] = prox_libre;
                    Q.push({tY,tX});
                }
            }
            prox_libre++;
        }

    //forn(i,MAXN) {forn(j,MAXN) cerr << comp[i][j]; cerr << endl;}

    int mini = INF;
    int d[3] = {INF,INF,INF}; // ES MUCHO MÁS FÁCIL HACERLO BRUTOOOOO!
    forn(i,MAXN) forn(j,MAXN) forn(k,MAXN) forn(l,MAXN) {
        if (comp[i][j] && comp[k][l]) {
            if (comp[i][j] == comp[k][l]) continue;
            if (comp[i][j] == 1 && comp[k][l] == 2) d[0] = min(d[0],abs(k-i)+abs(l-j)-1);
            if (comp[i][j] == 1 && comp[k][l] == 3) d[1] = min(d[1],abs(k-i)+abs(l-j)-1);
            if (comp[i][j] == 2 && comp[k][l] == 3) d[2] = min(d[2],abs(k-i)+abs(l-j)-1);
        }
    }

    forn(i,MAXN) forn(j,MAXN) {
        if (comp[i][j]) continue;
        int m[3] = {INF,INF,INF};
        forn(k,MAXN) forn(l,MAXN)
            if (comp[k][l]) m[comp[k][l]-1] = min(m[comp[k][l]-1],abs(i-k)+abs(l-j));
        mini = min(mini,m[0]+m[1]+m[2]-2);
    }

    sort(d,d+3);



    return min(d[0]+d[1],mini);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector <string> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    cout << cow_beauty(v) << endl;

    return 0;
}
