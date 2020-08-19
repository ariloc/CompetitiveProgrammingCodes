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

const int MAXN = 1e6+5;

int KMPr[MAXN],KMPtmp[MAXN];

void bordesKMP (string s, int KMP[]) {
    int n = (int)s.size();
    forsn (i,1,n) {
        int j = KMP[i-1];
        while (j > 0 and s[i] != s[j])
            j = KMP[j-1];
        if (s[i] == s[j]) j++;
        KMP[i] = j;
    }
}
string s; vi bordes;

bool isPosib (int mid) {
    string x = s.substr(0,bordes[mid]), lookup; lookup += x+'#';
    lookup += s.substr(1); // así no se me repite en prefijo
    if (!x.size()) return false;

    forn(i,lookup.size()) KMPtmp[i] = 0;
    bordesKMP(lookup,KMPtmp);

    bool posib = false;
    forn(i,lookup.size()-1) if (KMPtmp[i] >= (int)x.size()) {posib = true; break;} // todos menos último

    return posib;
}

int main() {
    FAST_IO;

    cin >> s;
    bordesKMP(s,KMPr);

    int ind = s.size()-1;
    while (KMPr[ind] > 0) {bordes.pb(KMPr[ind]); ind = KMPr[ind]-1;}
    reverse(all(bordes));

    if (bordes.empty()) {cout << "Just a legend"; return 0;}

    int low = 0, high = bordes.size()-1;
    string rta;
    while (high-low>1) {
        int mid = (high+low)/2;

        if (isPosib(mid)) low = mid;
        else high = mid;
    }

    if (isPosib(high)) cout << s.substr(0,bordes[high]);
    else if (isPosib(low)) cout << s.substr(0,bordes[low]);
    else cout << "Just a legend";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!