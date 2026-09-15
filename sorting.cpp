#include <stdio.h>
#include <assert.h>
#include <string.h>
#include<stdint.h>

void swap(void *firstValue, void *secondValue, size_t sizeType);
void qSort(void *array, size_t arrayLen,
           int (*comporator)(const void* first, const void* second), size_t sizeType);
int intComporator(const void *first, const void *second);

const int SIZE = 8;

int main()
{
    int array2[SIZE] = {10, 20, 30, 40, 10, 20, 10, 70};
    size_t arrayLen2 = sizeof(array2) / sizeof(int);
    size_t sizeType = sizeof(int);

    printf("\n-----------------------------------------\n");

    qSort(array2, arrayLen2, intComporator, sizeType);

    for (size_t i = 0; i < sizeof(array2) / sizeof(int); i++)
    {
        printf("%d ", array2[i]);
    }

    return 0;
}

void qSort(void *array, size_t arrayLen,
           int (*comporator)(const void* first, const void* second), size_t sizeType)
{
    assert(array);
    assert(comporator);
    assert(sizeType);

    if (arrayLen <= 1) return;

    uint8_t *last = (uint8_t*)array + (arrayLen - 1) * sizeType;
    size_t quantityLessLast = 0;

    for (size_t i = 0; i < arrayLen - 1; i++)
    {
        if (comporator((uint8_t*)array + i * sizeType, last) > 0)
        {
            swap((uint8_t*)array + quantityLessLast * sizeType, (uint8_t*)array + i * sizeType, sizeType);
            quantityLessLast++;
        }
    }
    swap((uint8_t*)array + quantityLessLast * sizeType, (uint8_t*)array + (arrayLen - 1) * sizeType, sizeType);

    qSort((uint8_t*)array, quantityLessLast, comporator, sizeType);

    qSort((uint8_t*)array + (quantityLessLast + 1) * sizeType, arrayLen - quantityLessLast - 1, comporator, sizeType);

    return;
}

void swap(void *firstValue, void *secondValue, size_t sizeType)
{
    assert(firstValue);
    assert(secondValue);

    char temp = 0;

    for (size_t i = 0; i < sizeType; i++)
    {
        memcpy(&temp, ((char*)firstValue) + i, 1);
        memcpy(((char*)firstValue) + i, ((char*)secondValue) + i, 1);
        memcpy(((char*)secondValue + i), &temp, 1);
    }

    return;
}

int intComporator(const void *first, const void *second)
{
    assert(first);
    assert(second);

    const int firstValue = *((const int*)first);
    const int secondValue = *((const int*)second);

    return secondValue - firstValue;
}
