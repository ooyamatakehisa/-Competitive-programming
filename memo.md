### 計算量
2msで
Nが10^6 → O(N)かO(N log N)
Nが10^5 → O(N log N)かO(N log2 N)
Nが3000 → O(N2)
Nが300 → O(N^3)(シンプルな処理)
Nが100 → O(N^3)
Nが50 → O(N^4)
Nが20 → O(2^N)かO(N*2N)

### int,llなど
intは2.147483647*10^9まで
llは10^19くらいまで
切り捨ては割るだけでよい、A/Bの切り上げは(A+B-1)/Bの商に等しい
A/Bのきりすては(A-A%B)/B
数字aの桁数はto_string(a).length()で取得できる。

## double, floatなど (ABC169C)
構成	 符号部	　指数部   仮数部
float	1bit	8bit	23bit
double	1bit	11bit	52bit
doubleでは2^53 以下の整数は正確に表現できます。253 はおよそ 9.01×10^15 なので少数以下も含めて10進法で15桁くらいまでしか表現できない
そもそもdoubleは二進数でパソコン内では表現してるから0.1とかは二進数で無限に続いて、どうしても誤差が発生する
-> できるだけ整数に変換して扱おう！

### string関連
- stringの長さ取得関数length()の返り値はsize_t型で0以上の値しか取らないため-string.length()とかは変な値を取る。これを避けるためにこのメソッドを使うときは(int)(strint.length())のように使う。
- string型の文字列Sのn番目の文字を取り出したいときS[n-1]と書くが、この値はchar型となる、一般的にchar型など一文字のときはその文字をシングルクォーテーション(')で囲み複数の文字列の場合はダブルクォーテーション(")で囲む。改行コードは''で囲む。
- charはintに対応している。例えばASCIIコードにおいて'A'=65であってchar a='A'-'B'でaにはASCIIコードが1の文字が入る。
- つまりchar->int の変換は '3' - '0' で表せる。一方string型の変数aについてはatoi(a.c_str())で行える。
- stringstreamでsplitとかできるhttps://chakku.hatenablog.com/entry/2016/02/15/155106

### math
- 累乗計算pow(a, b)はdouble型で式の途中で(int)(pow(a,b))と使うと何故か変な値になる。これをint型の値と計算式で用いる場合は一度別の変数int c = (int)(pow(a,b))のように他のint型の変数に代入してから用いる。3乗くらいまでならa*a*aのように書く。
- π(pi)はacos(-1)で取得できるMath.acos()じゃなくてacos()だけでいける


# 入出力
- puts("aaaa") ""の中のstringを出力してそのあと改行してくれるやつ
- 入力行数が不明な時は以下の感じで実装できる、wordsがある行の単語リスト
    string line;
    while (!cin.eof()) {
        getline(cin, line);
        vector<string> words = split(line, ' ');
- pythonの標準入力の仕方input()からキャスト！(abc186c)


# gcd
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
計算量はlog(n)
gcdの和を求める問題とかはgcd = iとなるものの数diを出せば
Σi*diで求められる

# lcm : 最小公倍数
ll lcm(ll x, ll y) { return a / gcd(a, b) * b; }

# a以下のbの最大の倍数
a / b * b

# 素因数分解
O(√n) 普通にprime_factor(n)とかでnの(素数, その素数の数)のpairのvectorが得られる
ABC169D
template <typename T>
vector<pair<T, T>> prime_factor(T n) {
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++) {
        T cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        ret.push_back(make_pair(i, cnt));
    }
    if (n != 1) ret.push_back(make_pair(n, 1));
    return ret;
}

# XOR
- 交換法則: a^b = b^a
- 結合法則: (a^b)^c = a^(b^c)
- 単位元の存在: a^0 = a
- 逆元は自分自身: a^a = 0
- a^b=c -> a^b^b=c^b -> a^0=b^c -> a=b^c
    -> 三つの値でひと固まり
- aとbの交換アルゴリズム
    a = a^b
    b = a^b = a^b^b = a^0 = a
    a = a^a = a^b^a = b^0 = b
- (4n)^(4n+1)^(4n+2)^(4n+3)=0 ⇔ (4n)^(4n+1)^(4n+2)=(4n+3) ⇔ (4n)^(4n+1)=(4n+3)^(4n+2) ...
- コード上での演算子が ^



# mint 勝手にMODとってくれる
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() const { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
const int MOD = 1e9 + 7;
using mint = Fp<MOD>;

# split string
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}


# ダイクストラ
vector<vector<int> > e(n);  // エッジ
vector<int> d(n, MAX);  // 距離

// この後ろの二つのvectorとgreaterはおまじない。これによって昇順になる
priority_queue<pair<int, int>, vector<P>, greater<P> > q;

q.emplace(0, 0);
d[0] = 0;
cnt[0] = 1;
while (!q.empty()) {
    auto vd = q.top();
    int v = vd.second;
    int di = vd.first;
    q.pop();
    if (d[v] != di) continue;
    for (auto vi : e[v]) {
        if (d[vi] > d[v] + 1) {
            d[vi] = d[v] + 1;
            q.emplace(d[vi], vi);
        }
    }
}
