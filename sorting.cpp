#include <stdio.h>
#include <assert.h>

void bubbleSort(int *array, int arrayLen, int (*comporator)(int first, int second));
void swap(int *firstValue, int *secondValue);
// void qSort(int *array, int arrayLen);
// void recursive(int *array, int arrayLen);
int comporator(int first, int second);

const int SIZE = 8;

int main()
{
    int array1[SIZE] = {10, 20, 30, 40, 10, 20, 10, 70};
    int arrayLen1 = sizeof(array1) / sizeof(int);
    int array2[SIZE] = {10, 20, 30, 40, 10, 20, 10, 70};
    int arrayLen2 = sizeof(array2) / sizeof(int);

    bubbleSort(array1, arrayLen1, comporator);

    for (int i = 0; i < arrayLen1; i++)
    {
        printf("%d ", array1[i]);
    }

    printf("\n-----------------------------------------\n");

    // recursive(array2, arrayLen);

    return 0;
}

void bubbleSort(int *array, int arrayLen, int (*comporator)(int first, int second))
{
    assert(array);

    for (int j = 0; j < arrayLen; j++)
    {
        for (int i = 0; i < arrayLen - j - 1; i++)
        {
            if (comporator(array[i], array[i + 1]) > 0)
            {
                swap(&array[i], &array[i + 1]);
            }
        }
    }

    return;
}

//TODO - mergeSort, selectionSort, qSort
//mergeSort

// void recursive(int *array, int arrayLen)
// {
//     qsort(int *array, int arrayLen);
//
//     recursive();
//
//     return;
// }
//
// void qsort(int *array, int arrayLen)
// {
//     for (int i = 0; i < arrayLen)
//     {
//
//
//
//     }
//
//     return
// }

void swap(int *firstValue, int *secondValue)
{
    assert(firstValue);
    assert(secondValue);

    int temp = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temp;

    return;
}

int comporator(int first, int second)
{
    return first - second;
    printf("%d\n", first - second);
}
