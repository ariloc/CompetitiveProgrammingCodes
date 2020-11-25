#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int X[] = {0,1,1,-1};
const int Y[] = {1,0,1,1};

const int MAXA = 26;
const int MAXD = 40;
const int MAXMOV = 4;
const int TOPN = 15;

vector<string> soup,words;
int mark[MAXD][MAXD], amLet[MAXD][MAXA]; // uso máscara de bits

int main() {
    FAST_IO;

    int L,C; cin >> L >> C;
    forn(i,L) {string s; cin >> s; soup.pb(s);}
    int N; cin >> N;
    forn(i,N) {string s; cin >> s; words.pb(s);}

    forn(i,N) forn(j,words[i].size()) amLet[i][words[i][j]-'A']++; // cuento letras por c/u

    forn(i,L) forn(j,C) {
        ii tend[MAXMOV]; int abc[MAXA][MAXMOV], valid = 0;
        forn(k,MAXA) forn(l,MAXMOV) abc[k][l] = 0; // reset
        forn(k,MAXMOV) {tend[k] = {i,j}; abc[soup[i][j]-'A'][k]++;}
        forn(k,TOPN+1) {
            forn(l,MAXMOV) {
                if (valid&(1<<l)) continue;
                forn(m,N) {
                    bool posib = true;
                    forn(n,MAXA) if(amLet[m][n] != abc[n][l]) {posib = false; break;}
                    if (posib) {
                        int tY = i, tX = j;
                        forn(n,k+1) {
                            mark[tY][tX] |= (1<<m);
                            tY += Y[l]; tX += X[l];
                        }
                    }
                }
                tend[l].fst += Y[l]; tend[l].snd += X[l];
                if (tend[l].fst >= L || tend[l].fst < 0 || tend[l].snd >= C || tend[l].snd < 0) {valid |= (1<<l); continue;}
                abc[soup[tend[l].fst][tend[l].snd]-'A'][l]++;
            }
        }
    }

    int cnt = 0;
    forn(i,L) forn(j,C)
        if (__builtin_popcount(mark[i][j]) > 1) cnt++;

    cout << cnt;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
