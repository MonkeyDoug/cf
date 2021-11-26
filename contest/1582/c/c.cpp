// Author : 3
// Time : 2021 11 07
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
#define mx(n) *max_element(n.begin().n.end())
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


bool cmp(ll a, ll b) {
	return a > b;
}

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

// Iterate over every removable letter, scan over every string with two iterators, one from the left and one from the right, check if chars at these two pointers can form a palindrome.
// If left char == right char then they can form a palindrome.
// If left char != right char two cases arise
// first both of the chars are not equal to the removable letter, then there is no way a palindrome can be formed, thus return -1.
// secondly, if one of the chars is the removable letter, remove the letter and move the pointer to the next iteration, then continue on the iteration.
void solve(){
	ll n; read(n);
	vc v(n);
	set<char> s;
	trav(e,v) {
		read(e);
		s.insert(e);
	}
	ll ans = INF;
	trav(e,s) {
		dbg(e);
		ll l = 0, r = n - 1;
		ll tmp = 0;
		while ( l <= r ) {
			dbg(l);
			dbg(r);
			dbg(v[l]);
			dbg(v[r]);
			if ( v[l] != v[r] ) {
				if ( (v[l] != e) && (v[r] != e)) {
					tmp = INF;
					dbg("Break");
					break;
				}
				if ( v[l] == e ) {
					l++;
					tmp++;
				}
				if ( v[r] == e ) {
					r--;
					tmp++;
				}
			} else {
				l++; r--;
			}
		}
		dbg(l);
		dbg(r);
		dbg(tmp);
		ans = min(ans,tmp);
		dbg("End");
	}
	if ( ans == INF ) {
		cout << -1 << nl;
	} else {
		cout << ans << nl;
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while ( T-->0 ) solve();
	return 0;
}
