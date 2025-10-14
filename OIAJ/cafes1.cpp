#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

struct cafe {
    string nom;
    int p,d;
    int i;
};

string cafes(vector<string> &nombres, vector<int> &precios, vector<int> &distancias) {
    vector<cafe> places;
    int n = (int)nombres.size();
    forn(i,n) places.pb({nombres[i],precios[i],distancias[i],i});
    auto comp = [](const cafe &lhs, const cafe &rhs) {
        int a = lhs.p*lhs.d, b = rhs.p*rhs.d;
        if (a != b) return a < b;
        if (lhs.p != rhs.p) return lhs.p < rhs.p;
        return lhs.i < rhs.i;
    };
    sort(all(places),comp);
    return places[0].nom;
}
