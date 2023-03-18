struct bucket
{
    int count; //кол-во эл-ов в корзине
    int* data; //массив эл-во корзины
};

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
{}

void bucketSort(int* arr, int n)
{}