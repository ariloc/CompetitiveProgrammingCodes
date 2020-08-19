#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

const int MAXN = 62;

char num[MAXN];

int main() {
    //FAST_IO;

    int t; scanf("%d",&t);

    forn (i,t) {
        ll n,m; scanf("%lld %lld",&n,&m);
        ll base = ((1LL<<m)-1)/2; // original binary median, the LL after 1 avoids overflow

        set<ll> near; // I make a set with all the numbers in [base-m; base+m] (with safety margins)
        ll bottom = max((ll)0,base-m-2);
        ll top = base+m+2;
        forsn(j,bottom,top+1) near.insert(j); // NOTE forsn MACRO WAS CHANGED TO LL, to avoid errors

        // As max numbers I delete is 100, I have no trouble deleting them from the set in O(log n)
        int desfaseAt = 0;
        forn (j,n) {
            scanf("%s",num);
            ll x = strtoll(num,NULL,2); // I can transform from binary string to number
            if (near.count(x)) near.erase(x); // when erasing, order is preserved in set plus indices shift
            else if (x < bottom) desfaseAt--;
            // if deleted number is a lower number below the range, I count the positions to shift
        }

        vector<ll> actList; for (auto &o : near) actList.pb(o);
        // I put all the remaining numbers in a vector for convenience

        ll newI = ((1LL<<m)-n-1)/2;
        newI -= (bottom+desfaseAt); // index of actual median, accounting for shifted positions in lower nums
        ll val = actList[newI]; // I get the actual median

        vector<bool> rta;
        forn(o,m) {rta.pb(val & 1); val>>=1;} // decomposing the number in its bits
        dforn (o,rta.size()) printf("%d",(rta[o]?1:0)); // printing result
        printf("\n");
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!