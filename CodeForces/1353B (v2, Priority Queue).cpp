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

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n,k; scanf("%d %d",&n,&k);
        priority_queue<int,vi,greater<int>> A;
        priority_queue<int> B;
        
        forn(i,n) {int x; scanf("%d",&x); A.push(x);}
        forn(i,n) {int x; scanf("%d",&x); B.push(x);}

        while (k-- && B.top() > A.top()) {
            auto a = A.top(), b = B.top();
            A.pop(), B.pop();
            A.push(b), B.push(a);
        }

        int s = 0;
        while (!A.empty()) s += A.top(), A.pop();

        printf("%d\n",s);
    }

    return 0;
}