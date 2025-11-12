#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createIntArray(int size)
{
    int *p = (int *)malloc(size * sizeof(int));
    return p;
}

void fillArray(int *array, int size)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(array + i) = rand() % 100;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }
}

int sumArray(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + *(array + i);
    }
    return sum;
}

void findMinMax(int *array, int size, int *min_ptr, int *max_ptr)
{
    *min_ptr = array[0];
    *max_ptr = array[0];

    for (int i = 1; i < size; i++)
    {

        if (array[i] < *min_ptr)
        {
            *min_ptr = array[i];
        }

        if (array[i] > *max_ptr)
        {
            *max_ptr = array[i];
        }
    }
}

void freeArray(int *array)
{
    free(array);
}

int main()
{

    int *myArray = NULL;
    int N;
    printf("输入数组大小\n");
    scanf("%d", &N);
    printf("正在创建大小为 %d 的动态数组...\n", N);
    myArray = createIntArray(N);

    if (myArray == NULL)
    {
        printf("错误：内存分配失败！\n");
        return 1;
    }
    printf("数组创建成功。\n\n");

    fillArray(myArray, N);

    printf("数组内容：\n");
    printArray(myArray, N);
    printf("\n");

    int total = sumArray(myArray, N);
    printf("数组总和：%d\n", total);
    printf("\n");

    int myMin = 0;
    int myMax = 0;
    findMinMax(myArray, N, &myMin, &myMax);

    printf("最小值：%d\n", myMin);
    printf("最大值：%d\n", myMax);
    printf("\n");

    printf("正在释放内存...\n");
    freeArray(myArray);
    myArray = NULL;
    printf("内存已释放。\n");

    return 0;
}
