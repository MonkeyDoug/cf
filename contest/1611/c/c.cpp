// Author : 3
// Time : 2021 11 26
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
#define sz(x) ((int)x.size())
#define trav(a, x) for (auto &a : x)
#define mn(n) *min_element(n.begin(), n.end())
#define mx(n) *max_element(n.begin(), n.end())
#define unq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define rev(i, n) for (ll i = n - 1; i >= 0; --i)
#define loop(i, a, b) for (ll i = a; i < b; ++i)
#define nl '\n'
#define MOD 1e9 + 7
#define INF 1e9

template <class A> void read(vector<A> &v);
template <class A, size_t S> void read(array<A, S> &a);
template <class T> void read(T &x) { cin >> x; }
void read(double &d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double &d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T> void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A> void read(vector<A> &x) { trav(a, x) read(a); }
template <class A, size_t S> void read(array<A, S> &x) { trav(a, x) read(a); }

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

/*
Since the inital array is a permutation containing all numbers from 1 to n,
and the resulting array removes the smaller element, we know that the last
element must be the largest element in the initial array, or n.

By checking whether n is the first or last, we know whether in the last step,
n was added to the left or the right. Note that if n is neither the first or
last, it means that the resulting array given is invalid since it is
impossible based on how the initial array is prepared, we can output -1.

If the resulting array is left appended, we must make sure n is paired with
the last element of the resulting array, therefore, we first print
out n, then print out the array starting at the last element until the second
element.

If the initial array right appended, we must make sure n is paired with the
first elememt of the resulting array, therefore, we first print out the array
starting from the second to last element, until the beginning of the array,
we then print out n.
*/

void solve() {
  int n;
  read(n);
  vi v(n);
  trav(e, v) { read(e); }
  if (v.front() == n) {
    // Left Appended
    cout << n << ' ';
    for (int i = n - 1; i >= 1; --i) {
      cout << v[i] << ' ';
    }
    cout << nl;
  } else if (v.back() == n) {
    // Right Appended
    for (int i = n - 2; i >= 0; --i) {
      cout << v[i] << ' ';
    }
    cout << n;
    cout << nl;
  } else {
    cout << -1 << nl;
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T-- > 0)
    solve();
  return 0;
}
