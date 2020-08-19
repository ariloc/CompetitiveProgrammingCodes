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

const int MAXN = 5005;

int AL[MAXN], AR[MAXN], BR[MAXN], BL[MAXN];

int main() {
    FAST_IO;

    string s; cin >> s;

    int a = 0, b = 0;
    forn (i,s.size()) {
        if (s[i] == 'a') a++;
        else b++;
        AL[i+1] = a; BL[i+1] = b;
    }
    a = b = 0;
    dforn (i,s.size()) {
        if (s[i] == 'a') a++;
        else b++;
        AR[i+1] = a; BR[i+1] = b;
    }

    int maxi = -1;
    forsn (i,1,s.size()+2) forsn(j,i,s.size()+2)
        maxi = max(maxi,AL[i-1]+BR[i]-BR[j+1]+AR[j+1]);

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!