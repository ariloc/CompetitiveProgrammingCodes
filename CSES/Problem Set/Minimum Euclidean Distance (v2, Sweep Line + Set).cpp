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
 
const ll INF = 2e9+5;
const ll INFL = 9e18;
const int MAXN = 2e5+5;
 
struct pt {
	int x,y;
	pt(int x, int y) : x(x), y(y) {};
	pt() {};
 
	bool operator< (const pt &o) const {
		if (x != o.x) return x < o.x;
		return y < o.y;
	}
};
 
pt arr[MAXN];
int n;
 
ll calc (pt a, pt b) {
	ll dx = (b.x - a.x), dy = (b.y - a.y);
	return dx*dx + dy*dy;
}
 
int main() {
	scanf("%d",&n);
	forn(i,n) scanf("%d %d",&arr[i].x,&arr[i].y);
 
	sort(arr,arr+n);
 
	queue<pt> Q;
	set<pt> window;
 
	int prv_x = -1;
	ll rta = INFL;
	forn(i,n) {
		if (i && arr[i-1].x != arr[i].x) prv_x = arr[i].x;
 
		#define sq(a) ((ll)a*a)
		while (!Q.empty() && sq(arr[i].x - Q.front().x) > rta) {
			pt aux = Q.front(); Q.pop();
			swap(aux.x,aux.y);
			window.erase(aux);
		}
 		#undef sq
 
		vector<pt> toCmp;
		if (prv_x != -1) {	
			auto it = window.upper_bound({arr[i].y, prv_x});
			if (it != window.end()) toCmp.pb(*it);
 
			it = window.lower_bound({arr[i].y, prv_x});
			if (it != window.end()) toCmp.pb(*it);
			if (it != window.begin()) toCmp.pb(*(prev(it)));
		}
		if (i) toCmp.pb(arr[i-1]), swap(toCmp.back().x,toCmp.back().y);
 
		for (auto &j : toCmp) {
			swap(j.x,j.y);
			rta = min(rta, calc(j,arr[i]));
		}
		
		Q.push(arr[i]);
		window.insert(pt(arr[i].y, arr[i].x));
	}
 
	printf("%lld",rta);
 
	return 0;
}
