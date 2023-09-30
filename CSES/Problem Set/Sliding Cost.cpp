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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 2e5;

void fs (int &x) {
    char c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for(; c >= '0' && c <= '9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

int arr[MAXN];
bool assigned[MAXN];
priority_queue<ii,vector<ii>,greater<ii>> QH;
priority_queue<ii> QL;
ll sl = 0, sh = 0;
int n,k;

int main() {
    fs(n); fs(k);
    forn(i,n) fs(arr[i]);

    forn(i,k) QL.push({arr[i],i}), sl += arr[i], assigned[i] = 0;
    int szl = (k+1)/2, szr = k/2;

    while ((int)QL.size() > szl) {
        auto e = QL.top(); QL.pop();
        sl -= e.fst, sh += e.fst;
        assigned[e.snd] = 1;
        QH.push(e);
    }

    forn(i,n-k+1) {
        int med = QL.top().fst;
        ll difl = szl * (ll)med - sl;
        ll difh = sh - szr * (ll)med;
        printf("%lld ",difl + difh);

        if (arr[i+k] < med) {
            QL.push({arr[i+k],i+k});
            sl += arr[i+k];
            assigned[i+k] = 0;
            if (assigned[i]) {
                ii x = QL.top();
                sl -= x.fst, sh += x.fst;
                assigned[x.snd] = 1;
                sh -= arr[i];
                QH.push(x); QL.pop();
            }
            else sl -= arr[i];
        }
        else if (arr[i+k] > med) {
            QH.push({arr[i+k],i+k});
            sh += arr[i+k];
            assigned[i+k] = 1;
            if (!assigned[i]) {
                ii x = QH.top();
                sh -= x.fst, sl += x.fst;
                assigned[x.snd] = 0;
                sl -= arr[i];
                QL.push(x); QH.pop();
            }
            else sh -= arr[i];
        }
        else if (!assigned[i]) {
            QL.push({arr[i+k],i+k});
            assigned[i+k] = 0;
            sl += arr[i+k], sl -= arr[i];
        }
        else {
            QH.push({arr[i+k],i+k});
            assigned[i+k] = 1;
            sh += arr[i+k], sh -= arr[i];
        }

        while (!QH.empty() && QH.top().snd <= i) QH.pop();
        while (!QL.empty() && QL.top().snd <= i) QL.pop();
    }

    return 0;
}
