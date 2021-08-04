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

int main() {
    FAST_IO;
    freopen("truco.in","r",stdin);
    freopen("truco.out","w",stdout);

    int N;
    cin >> N;

    vi amigos(N),equipo1;
    iota(all(amigos),1);
    int ind = 0;
    forn (i,40) {
        int x; char c;
        cin >> x >> c;
        if (x == 12 and amigos.size() > N/2) {
            equipo1.push_back(amigos[ind]);
            amigos.erase(amigos.begin()+ind);
            ind--;
        }
        ind++;
        if (ind >= amigos.size()) ind = 0;
    }
    for (auto &i : equipo1) cout << i << ' ';
    cout << '\n';
    for (auto &i : amigos) cout << i << ' ';

    return 0;
}