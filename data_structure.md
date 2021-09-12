
### vector
- n要素のvectorの宣言はvector<type> name(n)でできる。vector<type> name(n,0) みたいな感じで二つ目の引数に初期化の値
- vector aに対して `a.push_back(要素内容)` で追加。
- a[i]=aでも追加可能（初期化した値を書き換えている。）
- 昇順ソートは `sort(a.begin(),a.end())` で可能、降順は `sort(a.rbigin(),a.rend())` で可能
- 二分探索もできる `binary_search(a.begin(), a.end(), ai)` (aiが検索対象で返り値はaiがあったらtrue)
- 要素数は `a.size()` で可能
- vectorのコピーは要素ごとにおこなわず `vector<int> b = a` のようにする。
- 最大値: `max = *max_element(a.begin(), a.end())` もしくは `for(auto e:v) mx = max(mx, e)`
- ソートしたあと前後で重複があるものは `unique(a.begin(), a.end())` で重複が取り除かれる
- `reverse(a.begin(), a.end())` で逆転
- `a.back()` でベクトルaの最後の要素がとってこれる
- int型なら10^6くらいまでの長さの配列は作れる1e9は無理だった
- 要素がpairの時は `emplace_back(first, second)` でそのままpush_back的なことができる
- clear()で前要素削除できる
- `a.resize(n)` で要素数変更できる

### touple
- a,b,cの要素の組を作りたいときはtie(a, b, c)で作成可能。

### stack
- スタック, LIFOのデータ構造
- stack<int> a; で宣言
- push(), pop(), top(), size(), empty()

### pair
二つの要素のタプル
- １つ目の要素はfirst,２つ目がsecond
- make_pair(_,_)でつくれる

### map
- 辞書、連想リスト（キー、値）
- 内部ではソートされてる、平衡２分木、計算量は挿入取得ともにlogn
- `map<string,int> a` で宣言
- もしくは `map<string,int> a {{"abc", 1}, {"def", 2}}` とも
- 追加するときは `a["first"] = 1`
- 同様に value:1 は a["first"] でとってくる
- countが0,1しか返さないからfind的な使い方ができる
- 特定の要素の削除はerace["first"]とかでできる

## set
- 二分探索木での実装
- 集合のデータ構造 -> 要素を追加しても重複があるものは入らない
- set<string> st; の感じで初期化
- 中身はソートされていて for(string a : st) cout << a で昇順に出力できる
- 要素の追加は st.insert("ss") もしくはemplace("ssa")
- mapのキーがないバージョンで計算量とｋはmapと同じ
- countが0,1しか返さないからfind的な使い方ができる

## queue
- dq.front() で先頭取得
- 要素の追加 : dq.push(), dq.push()
- 要素の削除 : dq.pop(), dq.pop()
- size()でサイズ

## priority_queue
- 一番小さい(大きい)値へのアクセスはq.top()
- 後の操作はだたいqueueとかと同じ
- デフォルトで降順なので，照準にするためにはpriority_queue<T, vecotr<T>, greater<T>> と宣言する，vecotr<T>, greater<T>はおまじない

## deque
- deque<int> dq{1,4,3,6,2,8,2,5} もしくはdeque<int> dq で初期化
- dq.front(), dq.back()で先頭と最後尾取得
- 要素の追加 : dq.push_back(), dq.push_front()
- 要素の削除 : dq.pop_back(), dq.pop_front()
- size()でサイズ


# union find
連結成分を管理してくれる。これとこれが同じ連結成分に含まれているかなどのクエリがわかる
各連結成分のサイズも高速にとってこれる
単純には繋がっている辺をDFSなりで辿ってラベルをつけてもいいけど...
unit関数を繰り返して作っていく．
同時に複数の連結成分を扱える
木で実装している、d[x]は要素ｘの親のid、木のrootがｘならd[x]は木のサイズのマイナスをとったもの
集合を合わすのに良い

```C++
// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    // 木の根のidを返す
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y); // 小さい方の木を大きい方の根にくっつけることで深さが長くならない
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};
```

