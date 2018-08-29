#include <vector>
#include <cmath>

using namespace std;

const int N = 1e5;

int len;
int sumB[N], n;

inline void build(vector<int>& a){
    len = sqrt(a.size());
    n = a.size();
    for(int i = 0; i < n; ++i){
        int block_number = i / len;
        sumB[block_number] += a[i];
    }
}

inline int sum(vector<int>& a, int lf, int rg){
    int res = 0;
    int start_block = lf / len, end_block = rg / len;
    if(start_block == end_block){
        for(int i = lf; i <= rg; ++i){
            res += a[i];
        }
        return res;
    }else{
        int next_lf = (start_block + 1) * len, prev_rg = end_block * len - 1;
        for(int i = start_block + 1; i < end_block; ++i)
            res += sumB[i];
        for(int i = lf; i < next_lf; ++i){
            res += a[i];
        }
        for(int i = rg; i > prev_rg; --i){
            res += a[i];
        }
    }

}

inline int update_elem(vector<int>& a, int elem){

}

inline int update_index(vector<int>& a, int index){

}

inline int update(vector<int>& a, int lf, int rg){

}



