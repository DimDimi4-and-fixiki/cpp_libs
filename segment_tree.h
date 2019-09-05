const int N = 1e5 + 10;

int sum[N * 4], n, m, add[N * 4];

inline void push(int v){
    add[v * 2] += add[v];
    add[v * 2 + 1] += add[v];
    add[v] = 0;
}

inline void update(int v, int lf, int rg){
    int mid = (lf + rg) / 2;
    sum[v] = sum[v * 2] + add[v * 2] * (mid - lf + 1) + sum[v * 2 + 1] + add[v * 2 + 1] * (rg - mid);
}

inline int get_sum(int v, int lf, int rg, int l, int r){
    if (r < lf || l > rg) {
        return 0;
    }
    if(lf == l && rg == r){
        return sum[v] + (r - l + 1) * add[v];
    } else {
        int mid = (lf + rg) / 2;
        push(v);
        int res = get_sum(v * 2, lf, mid, l, min(mid, r)) + get_sum(v * 2 + 1, mid + 1, rg, max(mid + 1, l), r);
        update(v, lf, rg);
        return res;
    }
}

inline void add_v(int v, int lf, int rg, int l, int r, int x){
    if (l > r)
        return;
    if (lf == l && rg == r) {
        add[v] += x;
        return;
    }
    int mid = (lf + rg) / 2;
    push(v);
    add_v(v * 2, lf, mid, l, min(mid, r), x);
    add_v(v * 2 + 1, mid + 1, rg, max(mid + 1, l), r, x);
    update(v, lf, rg);
}
