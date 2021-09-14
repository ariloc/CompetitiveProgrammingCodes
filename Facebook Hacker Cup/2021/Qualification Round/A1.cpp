#include <bits/stdc++.h>
    
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
    
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
    
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int INF = 1e9;
const int MAXA = 26;

bool isVow (int x) {
    x += 'A';
    return (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U');
}

int main() {
    FAST_IO;

    freopen("salidita.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        string s; cin >> s;

        int cnt[MAXA];
        forn(i,MAXA) cnt[i] = 0;
        forn(i,s.size()) cnt[s[i]-'A']++;

        int mini = INF;
        forn(i,MAXA) {
            int aux = 0;
            forn(j,MAXA) if (i != j)  {
                aux += (1 + (isVow(i) == isVow(j))) * cnt[j];
            }
            mini = min(mini,aux);
        }

        cout << "Case #" << o+1 << ": " << mini << '\n';
    }

    return 0;
}