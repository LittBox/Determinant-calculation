#include <stdio.h>
#include <math.h>
#define SIZE 10

double detcal(double det[][SIZE], int n);  //自定义函数的声明

int main()
{
    int n;
    double det[SIZE][SIZE];
    int i, j;
    double result;
    printf("输入阶数\n");
    scanf_s("%d", &n);
    printf("输入行列式元素\n");   //用二层循环实现二位数组的元素赋值
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf_s("%lf", &det[i][j]);
        }
    }
    result = detcal(det, n);//det[][]是数，det是数组首个元素的地址，实际是指针
    printf("行列式的值为\n");
    printf("%5.2lf\n", result);

    return 0;
}
