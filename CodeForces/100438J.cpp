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

const int MAXN = 6;
const int MAXOP = 4;
const ll INF = 1e18+5;

struct op {
    ll a,b,c; int typ; //typ || 1 -> suma | 2 -> resta | 3->multiplicación | 4-> división
};

vector<op> myRta;
ll myApprox, target;
vector<op> myOps;

void test(ll &approx) {
    if (abs(myApprox-target) > abs(approx-target)) {
        myApprox = approx;
        myRta = myOps;
    }
}

void solve(vector<ll> &arr) {
    if (arr.size() == 1) return;

    forn (i,arr.size()) {
        forsn(j,i+1,arr.size()) {

            ll t1 = arr[i], t2 = arr[j];
            ll a = t1+t2, b = t1-t2, c = t2-t1, d = t1*t2, e = t1/t2, f = t2/t1;

            //cerr << t1 << ' ' << t2 << ' '<< endl;

            vector<ll> tmpArr; tmpArr = arr;
            tmpArr.erase(tmpArr.begin()+j); tmpArr.erase(tmpArr.begin()+i);

            if (a > 0) {
                myOps.pb({t1,t2,a,1});tmpArr.pb(a);
                test(a); solve(tmpArr);
                myOps.pop_back(); tmpArr.pop_back();
            }
            if (b > 0) {
                myOps.pb({t1,t2,b,2});tmpArr.pb(b);
                test(b); solve(tmpArr);
                myOps.pop_back(); tmpArr.pop_back();
            }
            if (c > 0) {
                myOps.pb({t2,t1,c,2});tmpArr.pb(c);
                test(c); solve(tmpArr);
                myOps.pop_back(); tmpArr.pop_back();
            }
            if (d > 0) {
                myOps.pb({t1,t2,d,3});tmpArr.pb(d);
                test(d); solve(tmpArr);
                myOps.pop_back(); tmpArr.pop_back();
            }
            if (!(t1 % t2)) {
                myOps.pb({t1,t2,e,4});tmpArr.pb(e);
                test(e); solve(tmpArr);
                myOps.pop_back(); tmpArr.pop_back();
            }
            if (!(t2 % t1)) {
                myOps.pb({t2,t1,f,4});tmpArr.pb(f);
                test(f); solve(tmpArr);
                myOps.pop_back(); tmpArr.pop_back();
            }
        }
    }
}

int main() {
    //FAST_IO;

    int t; scanf("%d",&t);

    forn (i,t) {
        myRta.clear(); myOps.clear(); myApprox = INF;

        vector<ll> arr; vector<op> empt;
        forn (j,MAXN) {ll x; scanf("%lld",&x); arr.pb(x);}
        cin >> target;

        forn (j,MAXN) test(arr[j]);

        solve(arr);

        printf("Target: %lld\n",target);
        for (auto &o : myRta) {
            char thisOP;
            switch (o.typ) {
                case 1 : thisOP = '+'; break;
                case 2 : thisOP = '-'; break;
                case 3 : thisOP = '*'; break;
                case 4 : thisOP = '/'; break;
            }

            printf ("%lld %c %lld = %lld\n",o.a,thisOP,o.b,o.c);
        }
        printf("Best approx: %lld\n\n",myApprox);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!