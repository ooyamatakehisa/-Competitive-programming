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

const int m = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    map<char, int> d;
    string chokudai = "chokudai";
    map<char, int> no;
    rep (i, (int)(chokudai.length())) no[chokudai[i]] = i;
    for (char i : chokudai) d[i] = 0;
    int len = (int)(s.length());
    rep (i, len) {
        if (s[i] == 'c') d['c']++;
        else {
            d[s[i]] = (d[s[i]] + d[chokudai[no[s[i]] - 1]]) % m;
        }
    }

    cout << d['i'] << endl;
    return 0;
}