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

const int MAXN = 1001;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        pair<ii,int> activ[MAXN];
        int N; cin >> N;

        forn (j,N) {cin >> activ[j].fst.fst >> activ[j].fst.snd; activ[j].snd = j;}

        sort(activ,activ+N,
             [](const pair<ii,int> &a, const pair<ii,int> &b){return a.fst.fst < b.fst.fst;});

        int C = 0, J = 0;
        cout << "Case #" << i+1 << ": ";
        string rta; bool posib = true;
        rta.resize(N);
        forn (j,N) {
            if (C <= activ[j].fst.fst) {rta[activ[j].snd] = 'C'; C = activ[j].fst.snd;}
            else if (J <= activ[j].fst.fst) {rta[activ[j].snd] = 'J'; J = activ[j].fst.snd;}
            else {posib = false; break;}
        }

        if (posib) cout << rta << '\n';
        else cout << "IMPOSSIBLE\n";

    }

    return 0;
}
