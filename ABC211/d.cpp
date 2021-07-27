#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <climits>

//#include <bits/stdc++.h>


using namespace std;

#define FOR(i,a,b) for(int i=(a),i##formax=(b);i<i##formax;i++)
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

const int MAX = 1e9;
const int MOD = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > e(n);
    vector<int> d(n, MAX);
    vector<ll> cnt(n);
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    priority_queue<pair<int, int>, vector<P>, greater<P> > q;
    q.emplace(0, 0);
    // queue<int> q;
    // q.push(0);
    d[0] = 0;
    cnt[0] = 1;
    while (!q.empty()) {
        auto vd = q.top();
        int v = vd.second;
        int di = vd.first;
        // auto v = q.front();
        q.pop();
        // if (d[v] != di) continue;
        for (auto vi : e[v]) {
            if (d[vi] == d[v] + 1) {
                cnt[vi] += cnt[v];
                cnt[vi] = cnt[vi] % MOD;
            }
            else if (d[vi] > d[v] + 1) {
                d[vi] = d[v] + 1;
                q.emplace(d[vi], vi);
                // q.push(vi);
                cnt[vi] = cnt[v];
            }
        }
    }
    cout << cnt[n - 1] << endl;
    return 0;
}
// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int> > e(n);
//     vector<int> d(n, MAX);
//     vector<ll> cnt(n);
//     rep (i, m) {
//         int a, b;
//         cin >> a >> b;
//         --a; --b;
//         e[a].push_back(b);
//         e[b].push_back(a);
//     }
//     queue<int> q;
//     q.push(0);
//     d[0] = 0;
//     cnt[0] = 1;
//     while (!q.empty()) {
//         int v = q.front();
//         q.pop();
//         for (auto vi : e[v]) {
//             if (d[vi] == d[v] + 1) {
//                 cnt[vi] += cnt[v];
//                 cnt[vi] = (ll) (cnt[vi] % MOD);
//             }
//             else if (d[vi] == MAX) {
//                 d[vi] = d[v] + 1;
//                 q.push(vi);
//                 cnt[vi] = cnt[v];
//             }

//         }
//     }
//     cout << cnt[n - 1] << endl;
//     return 0;
// }