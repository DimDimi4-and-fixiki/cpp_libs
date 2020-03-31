#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

inline vector<int> factorize (int x) // функция факторизации числа
{
    vector<int> answer;  // вектор для ответа
    for (int i = 1; i <= sqrt(x); ++i){  // перебираем делители
        if (x % i == 0) {
            answer.push_back(i); // помещаем делитель вектор
            if (x / i != i) 
                answer.push_back(x / i); // добавляем делитель с другой стороны от корня
        }
    }
    return answer;
}

