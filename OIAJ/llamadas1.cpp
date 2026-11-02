#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e6+5;

int bynum[MAXN];

vector<int> llamadas(vector<int> &a) {
    int n = sz(a);
    for (auto &i : a) bynum[i]++;
    int maxa = *max_element(all(a));

    vi tod;

    int bp = 0, bt = 1, acc = 0, done = 0;
    forsn(i,1,maxa+1) {
        acc += bynum[i];
        done += i * bynum[i];
        int p = acc, t = done + (n-acc)*i;
        if (p*(ll)bt > bp*(ll)t) {
            tod.clear();
            bp = p, bt = t;
            tod.pb(i);
        }
        else if (p*(ll)bt == bp*(ll)t) tod.pb(i);
    }

    return tod;
}
