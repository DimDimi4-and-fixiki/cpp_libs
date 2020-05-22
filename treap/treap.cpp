#include <iostream>
#include <bits/stdc++.h>

 
using namespace std;

//structure of node
struct node {
    int key, prior;
    long long sum;
    node *l = nullptr, *r = nullptr;
    node(int _key){
        key = _key;
        prior = rand();
        sum = key;
    }
};
 
// finds key k in treap
inline bool find(node * v, int x) {
    if(v == nullptr) {
        return false;
    }
    if(v -> key == x) {
        return true;
    }
    if(v -> key > x) {
        return find(v -> l, x);
    }else {
        return find(v -> r, x);
    }
}
 
// gets sum in vertex 
inline long long sum(node* v) {
     return v ? v -> sum : 0; 
}

// update in vertex
inline void upd(node *v) {
    if(!v){
        return;
    }
    v -> sum = sum(v -> l) + sum(v -> r) + v -> key;
}

// merge two treaps 
node* merge (node *l, node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}
 
typedef pair<node*, node*> Pair;

// splits treap into two treaps
Pair split (node *p, int x) {
    if (!p) return {0, 0};
    if (p->key <= x) {
        Pair q = split(p->r, x);
        p->r = q.first;
        upd(p);
        upd(q.second);
        return {p, q.second};
    }
    else {
        Pair q = split(p->l, x);
        p->l = q.second;
        upd(p);
        upd(q.first);
        return {q.first, p};
    }
}
 
node *root = nullptr;
 
 
// inserts key into treap
void insert (int x) {
    if(!find(root, x)) {
        Pair q = split(root, x);
        node *t = new node(x);
        root = merge(q.first, merge(t, q.second));
    }
}
 
// gets sum of line
inline long long get_sum(int l, int r) {
    Pair rq = split(root, r);
    Pair lq = split(rq.first, l - 1);
    long long res = sum(lq.second);
    root = merge(lq.first, merge(lq.second, rq.second));
    return res;
}
