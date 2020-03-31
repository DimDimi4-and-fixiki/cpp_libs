#include <iostream>
#include <string>

using namespace std;

inline int* z_function (string s) 
{
   int* z = new int[s.size()];
   int left = 0, right = 0; // границы z-блока
   z[0] = (int)s.size(); // массив для z-функции
   for (int i = 1; i < s.size(); ++i) {
       z[i] = 0; // заполняем начальным значением
       if (i <= right) {
           z[i] = min(z[i - right], right - i + 1); // если текуший левее
       }

        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) // обновляем значение z-функции 
            z[i]++;
        if (i + z[i] - 1 > right) { // обновляем z-блок
            left = i;
            right = i + z[i] - 1;
        }
   }
   return z;

}

