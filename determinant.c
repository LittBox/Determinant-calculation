#include <math.h>
#define SIZE 10
double detcal(double det[][SIZE], int n)
{
    double fenmu, fenzi, k;
    int i, j, m;       //ѭ�����Ʊ���
    double temp, result = 1;
    int sign;   //���ڼ�¼��һ��Ԫ�ز�Ϊ�������

    int count = 0;     //û��ž���0������ʽ����ţ�����һ�У�count+1��count��Ϊ-1��ָ�� 
    for (i = 0; i < n - 1; i++)     //������ѭ��ʵ�ֽ�����ʽת��Ϊ����������ʽ
    {
        if (det[i][i] == 0)      //����һ��Ԫ�ز�Ϊ0���з��ڵ�һ��
        {
            int e;
            for (e = i + 1; e < n; e++)
            {
                if (det[e][i] != 0)
                {
                    sign = e;      //������ʵ�ֽ�sign�к͵�i�е�����Ԫ�ؽ��л�����������ʽҪ���
                    int q;
                    for (q = 0; q < n; q++)
                    {
                        temp = det[sign][q];
                        det[sign][q] = det[i][q];
                        det[i][q] = temp;
                    }
                    count++;   //-1��ָ�� ,���ڼ�¼����ʽ�ķ���
                    break;
                }
            }
            if (count == 0)    //˵����i�е�Ԫ�ض�Ϊ0�����ʱ���ִ��i+1
            {
                goto E;     //����E
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
        ;      //ֱ�������⣬ִ����һѭ��
    }
    result = pow(-1, count);
    for (i = 0; i < n; i++)        //������������ʽ���㷨����������ʽ��ֵ
    {
        result *= det[i][i];
    }
    return result;     //��������ʽ��ֵ
}