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

const int MAX = 1<<30;

set<int> nums;

int query (int x) {
    printf("? %d\n",x);
    fflush(stdout);
    int aux; scanf("%d",&aux);
    if (aux == -1) exit(0);
    return aux^x;
}

void recur (int mini, int maxi) {
    int diff = mini^maxi;
    int pos = 31-__builtin_clz(diff);

    if (pos > 0) {
        int x = query((maxi >> pos) << pos);
        if (!nums.count(x))
            nums.insert(x), recur(x,maxi);
    }

    int x = query(mini | ((1<<pos)-1));
    if (!nums.count(x))
        nums.insert(x), recur(mini,x);
}

int main() {
    int n; scanf("%d",&n);
    
    int maxi = query(MAX-1);
    nums.insert(maxi);

    if (n == 1) return printf("! %d\n",maxi), 0;

    int mini = query(0);
    nums.insert(mini);

    if (n == 2) return printf("! %d %d\n",mini,maxi), 0;

    recur(mini,maxi);

    printf("! ");
    for (auto &i : nums) printf("%d ",i);
    
    return 0;
}