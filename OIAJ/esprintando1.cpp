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

vector<int> esprintando(int K, vector<int> &X, vector<int> &Y) {
    int w = abs(X[1]-X[0]) + abs(Y[1]-Y[0]), h = abs(X[2]-X[1]) + abs(Y[2]-Y[1]);
    if (h < w) swap(w,h);
    int perim = 2*w+2*h;
    return {K > w && K <= w+2*h ? w : K <= w ? K : min(K,perim-K),min(K,min(w+h,perim-K))};
}
