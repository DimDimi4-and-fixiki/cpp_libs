#include <iostream>

using namespace std;

inline int binsearch (int* array, int left, int right, int value) 
{   
    while (right - left > 3) // уменьшаем границы поиска до длины 3
    {
        int mid = (left + right) / 2;
        if (array[mid] == value) { // нашли нужный индекс
            return mid;
        }
        if (array[mid] < value) { // нужное значение правее
            left = mid + 1;
        }
        if  (array[mid] > value) { // нужное значение левее
            right = mid - 1;
        }
    }

    for (int i = left; i <= right; ++i) { // проходимся руками по оставшемуся отрезку
        if (array[i] == value) {
            return i;
        }
    }
}

