#include <iostream>
#include <string>

using namespace std;

inline int* prefix_function (string s) 
{
    int* p = new int[s.size()]; // массив для префикс функции 
    p[0] = 0; // префикс от нуля равен 0
    for (int i = 0; i < s.size(); ++i) {
        p[i] = p[i - 1]; // идентифицируем прошлым 
        while (p[i] > 0 && s[i] != s[p[i]]) // постепенно считаем префикс функцию
            p[i] = p[p[i] - 1];
        if (s[i] == s[p[i]])
            p[i]++;
    }
    return p

}

