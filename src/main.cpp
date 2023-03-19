#include <cstddef>

struct bucket
{
    int count;
    int* data;
};

int main()
{

    return 0;
}

int getMax(int* arr, int n)
{
    int max = arr[0];
    for (size_t i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int getExp(int value)
{
    int exp = 1;

    while (value > 10)
    {
        value /= 10;
        exp *= 10;
    }

    return exp;
}

void countSort(int* arr, int n)
{
    if (!n)
    {
        return;
    }

    int* output = new int[n];
    int max = getMax(arr, n);
    int* count = new int[max + 1];

    for (int i = 0; i < max + 1; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++; //подсчитываем частоту появления элементов
    }

    for (int i = 1; i <= max; ++i)
    {
        count[i] += count[i-1]; // вычисляем накопленные суммы
    }

     for(int i = n - 1; i >= 0; --i) 
    {
        output[count[arr[i]] - 1] = arr[i];  // устанавливаем элемент на корректное место 
        count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }
        
    delete[] output;
    delete[] count;
}

void bucketSort(int* arr, int n)
{
    bucket buckets[10];

    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < 10; ++i)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }

    for (int i = 0; i < n; ++i)
    {
        int bi = arr[i] / exp; // вычисляем индекс корзины
        buckets[bi].data[buckets[bi].count++] = arr[i]; // добавляем элемент в корзину
    }

    //Шаг 4: После того как все элементы распределены, 
    //мы выполняем сортировку внутри каждого кармана 
    //и соединяем их в один массив по порядку их индексов.

    
}

