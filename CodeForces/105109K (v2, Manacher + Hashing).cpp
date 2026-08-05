#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 1e5+5;

struct Hash {
    int P=1777771,MOD[2],PI[2];
    vi h[2],pi[2];
    Hash(){}
    Hash(const string &s){
        MOD[0]=999727999;MOD[1]=1070777777;
        PI[0]=325255434;PI[1]=10018302;
        forn(k,2)h[k].resize(sz(s)+1),pi[k].resize(sz(s)+1);
        forn(k,2){
            h[k][0]=0;pi[k][0]=1;
            ll p=1;
            forsn(i,1,sz(s)+1){
                h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
                pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
                p=(p*P)%MOD[k];
            }
        }
    }
    ll get(int s, int e){
        ll r[2]; forn(k,2) {
            r[k]=(h[k][e]-h[k][s]+MOD[k])%MOD[k];
            r[k]=(1LL*r[k]*pi[k][s])%MOD[k];
        }
        return (r[0]<<32)|r[1];
    }
};
 
Hash pre, suf;

int d1[MAXN],d2[MAXN];
void manacher(string &s) {
    int l=0,r=-1,n=s.size();
    forn(i,n){
        int k=i>r?1:min(d1[l+r-i],r-i);
        while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
        d1[i]=k--;
        if(i+k>r)l=i-k,r=i+k;
    }
    l=0;r=-1;
    forn(i,n){
        int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
        while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
        d2[i]=--k;
        if(i+k-1>r)l=i-k,r=i+k-1;
    }
}

int n;
ll dp[MAXN];

int main() {
    FAST_IO;

    cin >> n;
    string s; cin >> s;

    manacher(s);

    pre = Hash(s);
    reverse(all(s));
    suf = Hash(s);
    reverse(all(s));

    forn(i,n) dp[i+1] = dp[i] + s[i]-'a'+1;

    set<ll> seenHash;
    ll sum = 0;
    forn(i,n) {
        if (d2[i]) {
            int l = i-d2[i], r = i+d2[i]-1;
            while (l < r) {
                ll hashcur = pre.get(l,r+1);
                if (seenHash.count(hashcur)) break;
                seenHash.insert(hashcur);
                sum += dp[r+1]-dp[l];
                ++l, --r;
            }
        }

    }

    forn(i,n) {
        int l = i-d1[i]+1, r = i+d1[i]-1;
        while (l <= r) {
            ll hashcur = pre.get(l,r+1);
            if (seenHash.count(hashcur)) break;
            seenHash.insert(hashcur);
            sum += dp[r+1]-dp[l];
            ++l, --r;
        }
    }

    cout << sum << '\n';

    return 0;
}
