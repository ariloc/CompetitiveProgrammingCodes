#include <algorithm>
#include <queue>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e5+5;

struct sword {
	ll c,d,r;
	int id;

	bool operator< (const sword &o) const {
		if ((d-r) != (o.d-o.r)) return (d-r) > (o.d-o.r);
		return d > o.d;
	}
};

sword arr[MAXN];
priority_queue<pair<ll,int>> maxD;
ll maxR = -1; int maxi_ind = -1;

int isPosib (ll H, int pos, ll cnt) {
	H -= (cnt-1LL) * (arr[pos].d - arr[pos].r);

	// I do the last kill
	if (cnt <= arr[pos].c && (H - arr[pos].d) <= 0)
		return pos;

	// someone not processed kills
	if (!maxD.empty() && maxD.top().fst >= H)
		return maxD.top().snd;

	// someone already processed kills
	if (maxi_ind != -1 && maxR >= H)
		return maxi_ind;

	return -1;
}

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u) {
	int n = (int)c.size();

	forn(i,n) arr[i] = {c[i],d[i],r[i],i};

	sort(arr,arr+n);

	forn(i,n) maxD.push({arr[i].d, i});

	bool posib = false;
	forn(i,n) {
		if (i && (arr[i].d - arr[i].r) <= 0) break;

		while (!maxD.empty() && maxD.top().snd <= i) maxD.pop();

		ll low = 0, high = arr[i].c + 1; // min 1 sword, max all my swords + killer
		while (high - low > 1) {
			ll mid = (high+low)/2;

			if (isPosib(H,i,mid) != -1) high = mid;
			else low = mid;
		}

		int aux = isPosib(H,i,high);
		if (aux != -1) {
			posib = true;

			if (aux == i)
				e.pb(arr[i].id), u.pb(high);
			else {
				if (high > 1) e.pb(arr[i].id), u.pb(high-1);
				
				if (aux < i) swap(e.back(),e[aux]), swap(u.back(), u[aux]);
				else e.pb(arr[aux].id), u.pb(1);
			}

			break;
		}

		if (arr[i].r > maxR)
			maxR = arr[i].r, maxi_ind = i;
		H -= (arr[i].c * (arr[i].d - arr[i].r));
		e.pb(arr[i].id), u.pb(arr[i].c);
	}

	if (!posib) {
		e.clear(), u.clear();
		return -1;
	}

	ll turns = 0;
	for (auto &i : u) turns += i;

	return turns;
}

