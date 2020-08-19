#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2000;

struct cliente {
    int x,y; // ubicacion
    int h; // minutos
    int p; // patacones
    int id; // orden de input

    bool operator< (const cliente &o) const{
        return o.h > h;
    }
};

struct data {
    int padre;
    int patacones;
};

vector<cliente> posibles;
vector<data> dp;

int main() {
    FAST_IO;

    freopen("negocios.in","r",stdin);
    freopen("negocios.out","w",stdout);

    int N;
    cin >> N;

    posibles.push_back({0,0,-3,0});
    forn (i,N) {
        int x,y,h,p;
        cin >> x >> y >> h >> p;
        posibles.push_back({x,y,h,p,i+1});
    }

    sort(all(posibles));
    dp.resize(N+1,{-1,0});

    int best = -1, last = -1;

    forn (i,posibles.size()) {
        auto prev = posibles[i];
        forsn (j,i+1,posibles.size()) {
            auto act = posibles[j];
            ll d = abs(act.x-prev.x) + abs(act.y-prev.y);
            if (prev.h + 3 + d > act.h) continue;
            if (dp[i].patacones + act.p <= dp[j].patacones) continue;
            if (dp[i].padre == -1 and i) continue;

//            cerr << i << ' ' << j << ' ' << dp[i].patacones << ' ' << posibles[j].p << ' ' << dp[i].minutos << ' ' << dp[j].minutos << ' ' << d << endl;

            dp[j].patacones = dp[i].patacones + act.p;
            dp[j].padre = i;

            if (dp[j].patacones > best) {
                best = dp[j].patacones;
//                cerr << best << ' ' << i << ' ' << j << ' ' << dp[i].patacones << ' ' << dp[j].patacones << endl;
                last = j;
            }
        }
    }


    vi rta;
    for (int i = last; i != -1 and i != 0; i = dp[i].padre) {
        rta.push_back(posibles[i].id);
    }
    reverse(all(rta));

    cout << (best == -1 ? 0 : best) << '\n';

    for (auto &i : rta)
        cout << i << ' ';

    return 0;
}
