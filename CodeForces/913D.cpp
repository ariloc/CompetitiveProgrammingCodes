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

const int MAXN = 2e5+2;
const int MAXT = 1e4+2;

pair<ii,int> ex[MAXN];
int cap[MAXN];

int main() {
    FAST_IO;

    int n,t; cin >> n >> t;

    forn (i,n) {cin >> ex[i].fst.fst >> ex[i].fst.snd; ex[i].snd = i+1;}

    sort(ex,ex+n,[](const pair<ii,int> &a, const pair<ii,int> &b)
         {if (a.fst.fst == b.fst.fst) return a.fst.snd < b.fst.snd; return a.fst.fst < b.fst.fst;});

    int Tacc = 0, solved = 0, best = 0, indB = -1;
    priority_queue<int> worse;
    dforn (i,n) {
        if (i < n-1 and ex[i].fst.fst != ex[i+1].fst.fst) {
            cap[ex[i+1].fst.fst] = min(solved,ex[i+1].fst.fst);
            if (cap[ex[i+1].fst.fst] > best) {
                best = cap[ex[i+1].fst.fst]; indB = ex[i+1].fst.fst;
            }
        }

        if (Tacc + ex[i].fst.snd > t) {
            if (!worse.empty() and ex[i].fst.snd < worse.top())
                {Tacc -= worse.top(); worse.pop(); worse.push(ex[i].fst.snd); Tacc += ex[i].fst.snd;}
        }
        else
            {solved++; Tacc += ex[i].fst.snd; worse.push(ex[i].fst.snd);}
    }
    cap[ex[0].fst.fst] = min(solved,ex[0].fst.fst);
    if (cap[ex[0].fst.fst] > best)
        {best = cap[ex[0].fst.fst]; indB = ex[0].fst.fst;}

    int ind = lower_bound(ex,ex+n,indB,[](const pair<ii,int> &a, const int &b){return a.fst.fst < b;}) - ex;
    priority_queue<ii, vector<ii>, greater<ii> > allR;
    forsn (i,ind,n) allR.push({ex[i].fst.snd,ex[i].snd});

    cout << best << '\n' << best << '\n';
    forn (i,best) {cout << allR.top().snd << ' '; allR.pop();}

    return 0;
}