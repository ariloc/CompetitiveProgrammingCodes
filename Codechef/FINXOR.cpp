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

const int MAXQ = 20;

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);

        int sum = 0; // entra en int por las cotas
        printf("1 %d\n",1<<20);
        fflush(stdout);
        scanf("%d",&sum);
        sum -= (1<<20)*n;

        int pot = 2, num = (sum&1); // si la suma es impar, el xor es impar
        forsn(i,1,MAXQ) {
            printf("1 %d\n", pot);
            fflush(stdout);
            
            int x; scanf("%d",&x);
            int k2 = (n - (x-sum)/pot)/2;
            if (k2&1) num |= (1<<i);

            pot <<= 1;
        }

        printf("2 %d\n", num);
        fflush(stdout);
        int ans; scanf("%d",&ans);
        if (ans == -1) return 0;
    }

    return 0;
}
