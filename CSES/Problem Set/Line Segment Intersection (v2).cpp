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
 
struct pt {
	ll x,y;
	pt(){}
	pt(ll x, ll y) : x(x), y(y) {}
 
	pt operator- (const pt &o) const {return pt(x-o.x,y-o.y);}
	ll operator% (const pt &o) const {return x*o.y - y*o.x;}
 
	ll side (pt a, pt b) {
		return (b-a)%(*this-a);
	}
	int side2 (pt a, pt b) {
		ll aux = side(a,b);
		return !aux ? 0 : aux > 0 ? 1 : -1;
	}
};
 
bool touchSeg (pt p, pt a, pt b) {
	if (p.side2(a,b) != 0) return false;
	if (b.x < a.x) swap(a.x,b.x);
	if (b.y < a.y) swap(a.y,b.y);
	return (p.x >= a.x && p.x <= b.x && p.y >= a.y && p.y <= b.y);
}
 
bool intersect (pt p1, pt p2, pt p3, pt p4) {
	if (p3.side2(p1,p2) != p4.side2(p1,p2) && p1.side2(p3,p4) != p2.side2(p3,p4))
		return true;
	if (touchSeg(p3,p1,p2) || touchSeg(p4,p1,p2) || touchSeg(p1,p3,p4) || touchSeg(p2,p3,p4))
		return true;
	return false;
}
 
int main() {
	int t; scanf("%d",&t);
	forn(_,t) {
		pt p1,p2,p3,p4;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
 
		printf("%s\n", intersect(p1,p2,p3,p4) ? "YES" : "NO");
	}

	return 0;
}
