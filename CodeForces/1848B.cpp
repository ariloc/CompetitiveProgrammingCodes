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

int const MAXN = 2e5+5;
int const INF = 1e9;

int arr[MAXN], col[MAXN];
ii maxi[MAXN];

void addval (int v, int i) {
    if (v >= maxi[i].fst) {
        swap(maxi[i].fst, maxi[i].snd);
        maxi[i].fst = v;
    }
    else if (v > maxi[i].snd) {
        maxi[i].snd = v;
    }
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n,k; scanf("%d %d",&n,&k);
        forn(i,n) scanf("%d",&arr[i]), arr[i]--;

        forn(i,k) maxi[i] = {-INF,-INF}, col[i] = -1;
    
        col[arr[0]] = 0;
        maxi[arr[0]].fst = 0;
        forsn(i,1,n) {
            int dif = i-col[arr[i]]-1;
            addval(dif,arr[i]);
            col[arr[i]] = i;
        }
        forn(i,k) addval(n-col[i]-1,i);

        int mini = INF;
        forn(i,k) {
            mini = min(mini, max(maxi[i].fst/2,maxi[i].snd));
        }

        printf("%d\n",mini);
    }
             
    return 0;
}
