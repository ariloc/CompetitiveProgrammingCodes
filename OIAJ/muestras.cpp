#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1e5+5;

ii m[MAXN], m2[MAXN];

int analizar(vector<vector<int>> &muestras) {
    int n = muestras.size();
    forn(i,muestras.size()) {
        int mini = n+2, miniI = n+2;
        forn(j,muestras[i].size()) {
            mini = min(mini,(muestras[i][j]-i+n)%n);
            miniI = min(miniI,(i-muestras[i][j]+n)%n);
        }
        //cerr << ' ' << mini << ' ' << miniI << ' ' << i << endl;
        m[i] = {mini,miniI};
        m2[i] = {miniI,mini};
    }
    m[n+1] = {0,0};
    m2[n+1] = {0,0};
    sort(m,m+n+1);
    sort(m2,m2+n+1);
    int maxi = 0, maxi2 = 0;
    dforn(i,n+1) {
        int aux1 = m[i].snd, aux2 = m2[i].snd;
        m[i].snd = maxi;
        m2[i].snd = maxi2;
        maxi = max(maxi,aux1);
        maxi2 = max(maxi2,aux2);
    }
    int rta = n;
    forn(i,n+1) {
        rta = min(rta,m[i].fst+(m[i].snd ? m[i].fst : 0)+m[i].snd);
        rta = min(rta,m2[i].fst+(m2[i].snd ? m2[i].fst : 0)+m2[i].snd);
        //cerr << m2[i].fst << ' ' << m2[i].snd << ' ' << m2[i].fst+(m2[i].snd ? m2[i].fst : 0)+m2[i].snd << "!!!!" << endl;
    }
    return rta;
}
