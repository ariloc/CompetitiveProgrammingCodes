#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 3e5+5;

struct mon {
    int sum,l,r;
};

vector<mon> bag;
vi pref;
int arr[MAXN];
int DUM;

int newNode(int i) {
    if (i != -1) bag.pb(bag[i]);
    else bag.pb({0,-1,-1});
    return (int)bag.size() - 1;
}

int update(int i, int tl, int tr, const int &p, const int &v) {
    if (tl > p || tr <= p) return i;
    i = newNode(i);

    if (tr-tl == 1) bag[i].sum += v;
    else {
        int mid = (tl+tr)/2;
        bag[i].l = update(bag[i].l,tl,mid,p,v);
        bag[i].r = update(bag[i].r,mid,tr,p,v);
        bag[i].sum = (bag[i].l == -1 ? 0 : bag[bag[i].l].sum) + (bag[i].r == -1 ? 0 : bag[bag[i].r].sum);
    }
    return i;
}

ii query (int i1, int i2, int tl, int tr, int p) {
    i1 = i1 == -1 ? DUM : i1;
    i2 = i2 == -1 ? DUM : i2;

    if (tr-tl == 1) return {tl, bag[i1].sum - bag[i2].sum};

    int s = (bag[i1].l == -1 ? 0 : bag[bag[i1].l].sum) - (bag[i2].l == -1 ? 0 : bag[bag[i2].l].sum);
    int mid = (tl+tr)/2;
    if (s < p) 
        return query(bag[i1].r,bag[i2].r,mid,tr,p-s);
    return query(bag[i1].l,bag[i2].l,tl,mid,p);
}

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;

    bag.clear();
    pref.clear();
    pref.pb(-1);

    vi nums;
    forn(i,n) cin >> arr[i], nums.pb(arr[i]);
    sort(all(nums));
    nums.erase(unique(all(nums)),nums.end());

    forn(i,n) {
        int ind = lower_bound(all(nums),arr[i]) - nums.begin();
        arr[i] = ind;
    }

    int N = (int)nums.size()+1;

    forn(i,n) pref.pb(update(pref.back(),0,N,arr[i],1));

    bag.pb({0,-1,-1}); // last dummy
    DUM = (int)bag.size()-1;
    forn(_,q) {
        int l,r,k; cin >> l >> r >> k;

        vi cand;
        int cot = (r-l+1)/k;

        if (r-l+1 < k) {
            forn(i,r-l+1) cand.pb(i+1);
        }
        else {
            int a = cot;
            while (a <= r-l+1) {
                cand.pb(a);
                a += cot;
            }
        }

        bool done = false;
        for (auto &i : cand) {
            ii auxi = query(pref[r],l > 1 ? pref[l-1] : DUM,0,N,i);
            if (auxi.snd > cot) cout << nums[auxi.fst] << ' ', done = true;
            if (done) break;
        }
        if (!done) cout << "-1";
        cout << '\n';
    }

    return 0;
}
