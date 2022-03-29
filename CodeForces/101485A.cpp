#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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
typedef long double ld;

const int MAXN = 6e5+10;

int evs[MAXN];
priority_queue<int,vi,greater<int>> maq;

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) {
        int a,s; scanf("%d %d",&a,&s);
        evs[2*i] = a;
        evs[2*i+1] = -(a+s);
    }

    sort(evs,evs+n+n,[](const int &a, const int &b){
        if (abs(a) != abs(b)) return abs(a) < abs(b);
        return a < b;
    });

    int rta = 0;
    forn(i,2*n) {
        while (!maq.empty() && maq.top()+m < abs(evs[i])) maq.pop();
        if (evs[i] > 0) {
            if (!maq.empty()) maq.pop();
            else rta++;
        }
        else maq.push(abs(evs[i]));
    }

    printf("%d",n-rta);

    return 0;
}