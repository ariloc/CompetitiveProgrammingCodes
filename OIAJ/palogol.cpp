#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int BORDX = 732, BORDY = 232;

vector<string> palogol(vector<int> &x, vector<int> &y) {
    vector<string> rta;
    forn(i,x.size()) {
        ii coords {x[i],y[i]};
        if (coords.fst > 0 && coords.fst < BORDX && coords.snd < BORDY)
            rta.pb("GOL");
        else if (coords.fst >= 0 && coords.fst <= BORDX && coords.snd <= BORDY)
            rta.pb("PALO");
        else rta.pb("AFUERA");
    }
    return rta;
}
