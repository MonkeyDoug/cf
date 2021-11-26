// Author : 3
// Time : 2021 10 16
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define all(x) x.begin(), x.end()
#define sza(x) ((int)x.size())
#define trav(a, x) for (auto &a : x)
#define mn(n) *min_element(n.begin(), n.end())
#define mx(n) *max_element(n.begin().n.end())
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define forn(i, n) for (ll i = 0; i < n; i++)
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define nl '\n'
#define MOD 1e9 + 7
#define INF 1e9

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifdef DEBUG
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

bool cmp(ll a, ll b) { return a > b; }

vl ntv(ll X) {
  vl final;
  while (X) {
    final.pb(X % 10);
    X /= 10;
  }
  reverse(all(final));
  return final;
}

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

void solve() {
  int n;
  cin >> n;
  vi v(n);
  trav(e, v) cin >> e;
  sort(all(v), cmp);
  dbg(v);
  ll pos;
  ll x = 0;
  ll y = 0;
  if (n % 2 == 0) {
    pos = n / 2;
  } else {
    pos = n / 2 + 1;
  }
  dbg(pos);
  for (int i = 0; i < pos; i++) {
    x += v[i];
  }
  for (int i = n - 1; i >= pos; i--) {
    y += v[i];
  }
  ll ans = (x*x) + (y*y);
  cout << ans;
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T-- > 0)
    solve();
  return 0;
}
