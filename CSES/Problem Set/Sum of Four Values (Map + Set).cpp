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

const int MAXN = 1002;

int arr[MAXN];
map<int,set<int>> sums;

int main() {
    int n,x; scanf("%d %d",&n,&x);
    forn(i,n) scanf("%d",&arr[i]);

    tuple<int,int,int> rta = {-1,-1,-1};
    forn(i,n) {
        bool out = false;
        forsn(j,i+1,n) {
            int dif = x-arr[i]-arr[j];
            if (sums.count(dif)) {
                auto itOne = &sums[dif];
                auto it = itOne->begin();
                while (it != itOne->end() and ((*it) == j or (*it) == i)) it++;
                if (it == itOne->end()) continue;
                rta = {i,j,(*it)};
                out = true; break;
            }
        }
        if (out) break;
        forsn(j,i+1,n) sums[arr[i]+arr[j]].insert(j);
    }

    if (get<0>(rta) == -1) printf("IMPOSSIBLE");
    else {
        int a,b,c,d; tie(a,b,c) = rta;
        int dif = x-arr[a]-arr[b];
        forn(i,n) if (arr[i]+arr[c] == dif and i != a and i != b and i != c) {d = i; break;}
        printf("%d %d %d %d",a+1,b+1,c+1,d+1);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
