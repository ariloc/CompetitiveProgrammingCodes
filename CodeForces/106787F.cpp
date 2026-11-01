#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i <= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int,int> ii;

int const MAXN = 1e6+5;

string s;
int n;

struct pa {
    int cntb, rem;
};

bitset<MAXN> blocks;
vector<ii> blocksp;

int ind,k;
pa solve(bool par = true, int dep = 0) {
    int prim = ind;
    ++ind;

    vector<pa> hij;
    int let = 0;
    while (ind < n) {
        if (s[ind] == '(') {
            hij.pb(solve(dep+1));
        }
        else if (s[ind] == ')') break;
        else {let++;ind++;}
    }
    int cumlet = let, cumb = 0;
    for (auto &i : hij) {
        cumlet += i.rem;
        cumb += i.cntb;
    }
    if (cumlet == k) {
        cumlet = 0, ++cumb;
        blocksp.pb({dep,prim});
    }
    ++ind; // skip parentheses
    return {cumb, cumlet};
}

pa solve1() {
    pa cur = {0,0};
    while(ind < n) {
        if (s[ind]=='('){
            pa re = solve();
            cur.cntb += re.cntb;
            cur.rem += re.rem;
        }
        else ++ind;
    }
    return cur;
}

vector<string> foot, fin;
int indfoot = 1;
void recons() {
    bool infoot = false;
    if (blocks[ind]) {
        foot.back() += "[" + to_string(indfoot) + "]";
        foot.pb("[" + to_string(indfoot) + "] ");
        indfoot++;
        infoot = true;
    }
    else foot.back().pb('(');
    ++ind;
    while (ind < n) {
        if (s[ind] == '(') recons();
        else if (s[ind] == ')') break;
        else {foot.back().pb(s[ind]); ++ind;}
    }
    if (!infoot) foot.back().pb(')');
    else {fin.pb(foot.back()); foot.pop_back();}
    ++ind;
}

void recons1(){
    while(ind<n){
        if (s[ind]=='(')recons();
        else {foot.back().pb(s[ind]);++ind;}
    }
}

int main() {
    FAST_IO;

    cin >> s;
    n = sz(s);

    int lat = 0;
    for (auto &i : s) if (i >= 'a' && i <= 'z') lat++;

    if (lat%3) return cout << "impossible\n", 0;

    int quot = lat/3*2;

    vi divs;
    forsn(i,1,quot+1) if (!(quot%i)) divs.pb(i);

    for (auto &i : divs) {
        if (i != lat/3) continue;
        for (auto &j : blocksp) blocks[j.snd] = false;
        blocksp.clear();
        ind = 0, k = i;
        pa ret = solve1();
        if (ret.cntb >= quot/k) {
            sort(all(blocksp)); // TODO: cost?
            int need = quot/k;
            dforn(r,sz(blocksp)) {
                if (need <= 0) break;
                blocks[blocksp[r].snd] = true;
                --need;
            }
            ind = 0;
            foot.pb("");
            recons1();
            if (fin[0][1] > fin[1][1]) swap(fin[0],fin[1]);
            cout << foot.back() << '\n';
            forsn(r,0,sz(fin)) cout << fin[r] << '\n';
            return 0;
        }
    }

    cout << "impossible\n";

    return 0;
}
