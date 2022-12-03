#include <math.h>
#define SIZE 10
double detcal(double det[][SIZE], int n)
{
    double fenmu, fenzi, k;
    int i, j, m;       //循环控制变量
    double temp, result = 1;
    int sign;   //用于记录第一个元素不为零的行数

    int count = 0;     //没变号就是0，行列式不变号，交换一行，count+1，count作为-1的指数 
    for (i = 0; i < n - 1; i++)     //用三层循环实现将行列式转换为上三角行列式
    {
        if (det[i][i] == 0)      //将第一个元素不为0的行放在第一行
        {
            int e;
            for (e = i + 1; e < n; e++)
            {
                if (det[e][i] != 0)
                {
                    sign = e;      //接下来实现将sign行和第i行的所有元素进行互换，且行列式要变号
                    int q;
                    for (q = 0; q < n; q++)
                    {
                        temp = det[sign][q];
                        det[sign][q] = det[i][q];
                        det[i][q] = temp;
                    }
                    count++;   //-1的指数 ,用于记录行列式的符号
                    break;
                }
            }
            if (count == 0)    //说明第i列的元素都为0，这个时候就执行i+1
            {
                goto E;     //跳到E
            }
        }
        fenmu = det[i][i];
        for (j = i + 1; j < n; j++)
        {
            fenzi = det[j][i];
            k = fenzi / fenmu;
            for (m = i; m < n; m++)
            {
                det[j][m] -= k * det[i][m];
            }
        }
    E:
        ;      //直接跳到这，执行下一循环
    }
    result = pow(-1, count);
    for (i = 0; i < n; i++)        //用上三角行列式计算法则计算出行列式的值
    {
        result *= det[i][i];
    }
    return result;     //返回行列式的值
}