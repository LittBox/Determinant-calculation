#include <stdio.h>
#include <math.h>
#define SIZE 10

double detcal(double det[][SIZE], int n);  //�Զ��庯��������

int main()
{
    int n;
    double det[SIZE][SIZE];
    int i, j;
    double result;
    printf("�������\n");
    scanf_s("%d", &n);
    printf("��������ʽԪ��\n");   //�ö���ѭ��ʵ�ֶ�λ�����Ԫ�ظ�ֵ
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf_s("%lf", &det[i][j]);
        }
    }
    result = detcal(det, n);//det[][]������det�������׸�Ԫ�صĵ�ַ��ʵ����ָ��
    printf("����ʽ��ֵΪ\n");
    printf("%5.2lf\n", result);

    return 0;
}
