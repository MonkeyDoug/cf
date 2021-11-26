// Author : 3
// Time : 2021 11 12
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define trav(a,x) for (auto& a : x)
#define mn(n) *min_element(n.begin(),n.end())
#define mx(n) *max_element(n.begin(),n.end())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define forn(i,n) for(ll i=0;i<n;++i)
#define rev(i,n) for(ll i=n-1;i<=0;--i)
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define nl '\n'
#define MOD 1e9+7
#define INF 1e9

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vector<A>& x) {
	trav(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	trav(a, x)
		read(a);
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

vl ntv(ll X) {
	vl final;
	while (X) {
		final.pb(X%10); X/=10;
	}
	reverse(all(final)); return final;
}

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

// Keep 50 pointers to the highest positions of all each color. When we query, update the queried color to position 1, and add 1 to the position of every color before it since they now move back by one position because of the queried color moving to the first position.

void solve(){
	int n, q; read(n,q);
	// vi pos(51);
	// fill(all(pos),-1);
	// for ( int i = 0 ; i < n ; ++i ) {
	// 	int tmp; read(tmp);
	// 	if ( pos[tmp] == -1 ) pos[tmp] = i+1;
	// }
	// while(q--) {
	// 	int in; read(in);
	// 	cout << pos[in] << ' ';
	// 	for ( int i = 1 ; i <= 50 ; ++i ) {
	// 		if ( pos[i] != -1 && pos[i] < pos[in] && i != in ) pos[i]++;
	// 	}
	// 	pos[in] = 1;
	// }
	// Alternate Solution No DP
	// This works in time limit because after the inital search, only the first k elements, where k is the number of unique colors in the element, will contain all the highest colors, speeding up the O(3*10^5 * n) complexity to only O(k * n).
	vi v(n);
	trav(e,v) read(e);
	while(q--) {
		int in; read(in);
		int pos = find(all(v),in)-v.begin();
		cout << pos+1 << ' ';
		rotate(v.begin(),v.begin()+pos,v.begin()+pos+1); // only rotate those before pos. rotate is non-exclusive for last so we need to add 1
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	while ( T-->0 ) solve();
	return 0;
}
