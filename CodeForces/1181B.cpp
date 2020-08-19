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

const int MAXN = 1e5+2;

int sumL[MAXN], sumR[MAXN];

vector<ii> posib;
vector<string> reduced;
string s;
int N;

string sumar(int r1) {
    int r1O = r1;
    int r2 = N-1;
    int accum = 0;
    string me;

    while (r1 >= 0 or r2 > r1O) {
        int pS = 0;
        if (r1 >= 0) pS += (s[r1]-'0');
        if (r2 > r1O) pS += (s[r2]-'0');
        pS += accum;
        me.pb((pS%10)+'0');
        accum = pS/10;
        r1--; r2--;
    }
    while (accum) {
        me.pb((accum%10)+'0');
        accum /= 10;
    }
    reverse(all(me));
    return me;
}

int main() {
    FAST_IO;

    cin >> N;
    cin >> s;

    forn (i,N-1) if (s[i+1]-'0') posib.pb({i,abs( (i+1) - (N-(i+1)) )});

    sort(all(posib),[](const ii &a, const ii &b){return a.snd < b.snd;});

    int lDif = posib[0].snd;
    int ind = 0;
    while (ind < N and posib[ind].snd == lDif) {
        //cerr << posib[ind].fst << endl;
        string x = sumar(posib[ind].fst);
        reduced.pb(x);
        ind++;
    }

    sort(all(reduced));
    cout << reduced[0];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!