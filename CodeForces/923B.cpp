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

const int MAXN = 1e5+5;

int pilas[MAXN], temp[MAXN]; ll TAdR[MAXN], rest[MAXN];
int FT[MAXN];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) cin >> pilas[i];
    forn(i,n) {
        cin >> temp[i];
        TAdR[i] = temp[i];
    }

    forsn(i,1,n) TAdR[i] += TAdR[i-1];

    ll sumCompensar = 0;
    forn (i,n) {
        int ind = lower_bound(TAdR,TAdR+n,pilas[i]+sumCompensar) - TAdR;
        if (ind >= n and TAdR[i] == (pilas[i]+sumCompensar))
            {setFT(i+1,1); setFT(ind+2,-1);} // sumo que tendrán su K normal
        else {
            setFT(i+1,1); setFT(ind+1,-1);
            //cerr << abs(TAdR[ind]-(pilas[i]+sumCompensar)) << ' ' << pilas[i] << "!!" << ' ' << ind << ' ' << temp[i] << endl;
            rest[ind] += temp[ind]-abs(TAdR[ind]-(pilas[i]+sumCompensar));
        }

        sumCompensar += temp[i];
    }

    /*forn (i,n) cerr << getFT(i+1) << ' ';
    cerr << endl;

    forn(i,n) cerr << rest[i] << ' ';
    cerr << endl;*/

    forn (i,n) cout << getFT(i+1)*(ll)temp[i] + rest[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!