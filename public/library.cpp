// public/library.cpp

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;
constexpr long long MOD = 998244353LL;

// fast pow modulo
ll modpow(ll a, ll e, ll mod = MOD) {
    ll r = 1;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

// nCr
ll nCr_mod(ll n, ll r, ll mod = MOD) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    ll num = 1, den = 1;
    for (ll i = 0; i < r; ++i) {
        num = num * (n - i) % mod;
        den = den * (i + 1) % mod;
    }
    return num * modpow(den, mod - 2, mod) % mod;
}

// UnionFind (DSU)
struct UnionFind {
    vector<int> p;
    UnionFind(int n = 0) : p(n) { iota(p.begin(), p.end(), 0); }
    int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
    bool same(int a, int b) { return root(a) == root(b); }
    void unite(int a, int b) { a = root(a); b = root(b); if (a != b) p[a] = b; }
};

// Dijkstra skeleton (weights >= 0)
struct Edge { int to; long long cost; };
vector<long long> dijkstra(int V, int s, const vector<vector<Edge>>& g) {
    vector<long long> dist(V, INF);
    using P = pair<long long,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;
        for (auto &e : g[v]) {
            if (dist[e.to] > d + e.cost) {
                dist[e.to] = d + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}

