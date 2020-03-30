#include <iostream>
#include <algorithm>

using namespace std;

class SegmentTree
{
    public:
    static const int N = 1e5; // число элементов в массиве данных
    int max_tree[4 * N], min_tree[4 * N], sum_tree[4 * N]; // массивы для дерева

    inline void build(int v, int left, int right, int* a) // построение дерева
    {
        if (left == right) {  // случай, когда спустились в самый низ
            max_tree[v] = a[v];
            min_tree[v] = a[v];
            sum_tree[v] = a[v];
        }
        else {  // берем середину и рекурсивно строим на двух половинах
            int mid = (left + right) / 2;
            build(v * 2, left, mid, a);
            build(v * 2 + 1, mid + 1, right, a);
            max_tree[v] = max(max_tree[v * 2], max_tree[v * 2 + 1]);  // обновляем максимум
            min_tree[v] = min(min_tree[v * 2], min_tree[v * 2 + 1]);  // обновляем минимум
            sum_tree[v] = sum_tree[v * 2] + sum_tree[v * 2 + 1];  // обновляем сумму
        }
    }

    inline void update(int v, int left, int right, int idx, int value) // обновление в вершине
    {
        if (left == right) {  //  обновляем в листе
            max_tree[v] = value;
            min_tree[v] = value;
            sum_tree[v] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (idx <= mid) {
            update(v * 2, left, mid, idx, value);
        }
        else {
            update(v * 2 + 1, mid + 1, right, idx, value);
        }
        min_tree[v] = min(min_tree[v * 2], min_tree[v * 2 + 1]);  // считаем минимум в вершине
        max_tree[v] = max(max_tree[v * 2], max_tree[v * 2 + 1]);  // считаем максимум в вершине
        max_tree[v] = sum_tree[v * 2] + sum_tree[v * 2 + 1];  // считаем сумму в вершине
    }

    inline int get_max(int v, int left, int right, int l, int r) // максимум на отрезке
    {
        if (l > right || r < left || l > r){
            return -1e9;
        }
        if (l == left && r == right) {
            return max_tree[v];
        }
        else {
            int mid = (left + right) / 2;
            return max(get_max(2 * v, left, mid, l, min(r, mid)), 
            get_max(2 * v + 1, mid + 1, right, max(l, mid + 1), r));
        }
    }

    inline int get_min(int v, int left, int right, int l, int r) // минимум на отрезке
    {
        if (l > right || r < left || l > r){
            return 1e9;
        }
        if (l == left && r == right) {
            return min_tree[v];
        }
        else {
            int mid = (left + right) / 2;
            return min(get_min(2 * v, left, mid, l, min(r, mid)), 
            get_min(2 * v + 1, mid + 1, right, max(l, mid + 1), r));
        }
    }

    inline int get_sum(int v, int left, int right, int l, int r) // сумма на отрезке
    {
        if (l > right || r < left || l > r){
            return 0;
        }
        if (l == left && r == right) {
            return sum_tree[v];
        }
        else {
            int mid = (left + right) / 2;
            return get_sum(2 * v, left, mid, l, min(r, mid)) + 
            get_sum(2 * v + 1, mid + 1, right, max(l, mid + 1), r);
        }
    }
}
