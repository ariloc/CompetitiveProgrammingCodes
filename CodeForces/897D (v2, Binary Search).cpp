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

const int INF = 2e9;

void modif (vi &vec, int pos, int v) {
    if (pos >= (int)vec.size()) vec.pb(v);
    else vec[pos] = v;
}

int main() {
    int n,m,c; scanf("%d %d %d",&n,&m,&c);

    vi bagl = {-INF}, bagr = {INF};
    forn(i,m) {
        int p; scanf("%d",&p);

        if (p <= c/2) { // bagl
            int pos = upper_bound(all(bagl),p)-bagl.begin();
            modif(bagl,pos,p);
            printf("%d\n",pos);
        }
        else { // bagr
            int pos = lower_bound(bagr.rbegin(),bagr.rend(),p)-bagr.rbegin();
            pos = (int)bagr.size()-pos-1;
            pos++;
            modif(bagr,pos,p);
            printf("%d\n",n-pos+1);
        }
        fflush(stdout);

        if ((int)bagl.size() + (int)bagr.size() - 2 == n) break;
    }

    return 0;
}
