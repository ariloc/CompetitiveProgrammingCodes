
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
typedef long double ld;

const int MAXN = 1e5+5;

int A[MAXN], B[MAXN], K,L;
set<ii> best, worse;
ll prefs[MAXN], sufs[MAXN];
ll sum_best = 0;

void balance () {
    while ((int)best.size() > L) {
        auto e = *best.begin();
        sum_best -= e.fst;
        worse.insert(e);
        best.erase(best.begin());
    }
    while ((int)best.size() < L) {
        auto e = *prev(worse.end());
        sum_best += e.fst;
        best.insert(e);
        worse.erase(prev(worse.end()));
    }
}

int main() {
    int n; scanf("%d",&n);

    forn(i,n) scanf("%d",&A[i]);
    forn(i,n) scanf("%d",&B[i]);

    scanf("%d %d",&K,&L);

    forn(i,K) {
        best.insert({B[i], i});
        sum_best += B[i];
    }
    balance();

    forn(i,n) prefs[i+1] = prefs[i] + A[i];
    dforn(i,n) sufs[i+1] = sufs[i+2] + A[i];

    int l = K, r = n-1;
    ll maxi = 0;
    while (l >= 0) {
        ll sum = prefs[l] + sufs[r+2];
        sum += sum_best;
        maxi = max(maxi,sum);

        ii aux_pair = {B[l-1],l-1};
        if (best.count(aux_pair)) {
            best.erase(aux_pair);
            sum_best -= B[l-1];
        }
        else worse.erase(aux_pair);

        balance();

        best.insert({B[r],r});
        sum_best += B[r];

        balance();

        l--, r--;
    }

    printf("%lld",maxi);
    
    return 0;
}
