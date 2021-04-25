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

struct myPair {
    int l,r,sum;

    bool operator< (const myPair &o) const{
        return sum < o.sum;
    }
};

int arr[MAXN];
myPair pairs[(MAXN*(MAXN+1))/2]; int ind = 0;

bool areEqual (int i, int j) {
    int a = pairs[i].l, b = pairs[i].r, c = pairs[j].l, d = pairs[j].r;
    if (a == c or a == d) return true;
    if (b == c or b == d) return true;
    return false;
}

int main() {
    int n,x; scanf("%d %d",&n,&x);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) forsn(j,i+1,n) pairs[ind++] = {i,j,arr[i]+arr[j]};
    sort(pairs,pairs+ind);

    int j = ind-1;
    forn(i,ind) {
        while(j > i and (pairs[i].sum+pairs[j].sum > x ? 1 : pairs[i].sum+pairs[j].sum == x ? areEqual(i,j) : 0)) j--;
        if (j > i and pairs[i].sum+pairs[j].sum == x and !areEqual(i,j))
            {printf("%d %d %d %d",pairs[i].l+1,pairs[i].r+1,pairs[j].l+1,pairs[j].r+1); return 0;}
    }

    printf("IMPOSSIBLE");
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
