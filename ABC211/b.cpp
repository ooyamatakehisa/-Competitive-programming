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

int main(){
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    map<string, bool> d;
    d["H"] = false;
    d["HR"] = false;
    d["2B"] = false;
    d["3B"] = false;

    d[s1] = true;
    d[s2] = true;
    d[s3] = true;
    d[s4] = true;

    if (d["H"] && d["HR"] && d["2B"] && d["3B"]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}