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

const ll INF = 9e18;

struct pt {
	ll x,y;

	pt(ll x, ll y) : x(x), y(y) {}
	pt(){}

	pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
	ll operator% (const pt &o) const {return x*o.y - y*o.x;}
	ll operator* (const pt &o) const {return x*o.x + y*o.y;}

	bool operator< (const pt &o) const {
		if (x != o.x) return x < o.x;
		return y < o.y;
	}
	bool ccw (const pt &a, const pt &b) {
		return (b-a)%(*this-a) > 0;
	}
};

vector<pt> chull (vector<pt> p) {
	vector<pt> r;
	sort(all(p));
	forn(i,p.size()) {
		while (r.size() >= 2 && r.back().ccw(r[r.size()-2],p[i])) r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back(); int k = r.size();
	dforn(i,p.size()) {
		while (r.size() >= k+2 && r.back().ccw(r[r.size()-2],p[i])) r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}

ll area (int i, int j, int k, vector<pt> &poly) {
	pt a = poly[i], b = poly[j], c = poly[k];
	return abs((b-a)%(c-a));
}

ll get_area (int i, int j, vector<pt> &poly) {
	int m = (int)poly.size();
	int low = j, high = m+i;
	while (high - low > 1) {
		int mid = (high+low)/2;
		if (area(i,j,mid%m,poly) >= area(i,j,(mid+1)%m,poly)) high = mid;
		else low = mid;
	}
	return area(i,j,high%m,poly);
}

int main() {
	int n;
	while (scanf("%d",&n) != -1) {
		vector<pt> pts;
		forn(i,n) {
			int x,y; scanf("%d %d",&x,&y);
			pts.pb(pt(x,y));
		}

		vector<pt> poly = chull(pts);

		ll max_area = -INF;
		int m = poly.size();

		int j = 1;
		forn(i,m) {
			while (j != (i-2+m)%m && get_area(i,j,poly) <= get_area(i,(j+1)%m,poly)) j = (j+1)%m;
			max_area = max(max_area, get_area(i,j,poly));
		}

		printf("%.1f\n",max_area/(double)2);
	}

	return 0;
}
