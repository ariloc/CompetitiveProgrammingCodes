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

const int MAXN = 2e5+5;

int arr[MAXN],N,M,K;
set<ii> sorted, remain;
ll sum = 0;

void balance() {
    while ((int)sorted.size() > K) {
        remain.insert(*sorted.rbegin());
        sum -= (*sorted.rbegin()).fst;
        sorted.erase(prev(sorted.end()));
    }
    while ((int)sorted.size() < K && !remain.empty()) {
        sorted.insert(*remain.begin());
        sum += (*remain.begin()).fst;
        remain.erase(remain.begin());
    }
}

int main() {
    scanf("%d %d %d",&N,&M,&K);
    forn(i,N) scanf("%d",&arr[i]);

    forn(i,N) {
        if (i-M >= 0) {
            ii pr = {arr[i-M], i-M};
            if (sorted.erase(pr) > 0) sum -= pr.fst;
            remain.erase(pr);
            balance();
        }

        sorted.insert({arr[i], i});
        sum += arr[i];

        balance();

        if (i-M+1 >= 0) printf("%lld ",sum);
    }
   
    return 0;
}
