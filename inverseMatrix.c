/*
  本程序用于逆矩阵的计算
  作者：王浩舟
  日期：2020/2/8
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double determinant(int n,double a[n][n]);
double cofactor(int n,int j,int k,double a[n][n]);
void inverseMatrix (int n,double original[n][n],double inverse[n][n]);

int main()
{
    bool continuity = true;

    while(continuity)
    {
        int n;
        printf("请输入矩阵阶数：");
        scanf("%d",&n);
        
        int j, k;
        double original[n][n];
        printf("请输入矩阵（以空格隔开）：");
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                scanf("%lf",&original[j][k]);
        getchar();

        double det = determinant(n, original);
    
        if(det == 0)
        {
            printf("该矩阵不可逆\n");
        }

       else
       {
           double inverse[n][n];
            inverseMatrix(n, original,inverse);
            for(j = 0; j < n; j++)
            {
                for(k = 0; k < n; k++)
                    printf("%13f",inverse[j][k]);
                putchar('\n');
            }     
       }

        char c;
        printf("是否继续？[y/n]");
        scanf("%c",&c);
        if(c == 'n') continuity = false;
    }
    
    return 0;
}

double cofactor(int n,int j,int k,double a[n][n])
{
    int x, y;
    double b[n-1][n-1];

    for(x = 0; x < j; x++)
    {
        for(y = 0; y < k; y++)
            b[x][y] = a[x][y];
        for(y = k+1; y < n; y++)
            b[x][y-1] = a[x][y];
    }

    for(x = j+1; x < n; x++)
    {
        for(y = 0; y < k; y++)
            b[x-1][y] = a[x][y];
        for(y = k+1; y < n; y++)
            b[x-1][y-1] = a[x][y];
    }

    return determinant(n-1, b);
}

double determinant(int n,double a[n][n])
{
    if(n == 1)
        return a[0][0];
    else
    {
        int i;
        double sum = 0;

        for(i = 0; i < n; i++)
        {
            sum += a[0][i]*pow(-1,i+2)*cofactor(n,0,i,a);
        }
        return sum;
    }
}

void inverseMatrix (int n,double original[n][n],double inverse[n][n])
{
    double det = determinant(n, original);
    
    if(det == 0)
    {
        printf("该矩阵不可逆\n");
        return;
    }

    else
    {
        int j, k;
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
            {   
                inverse[j][k] = pow(-1,j+k+2)*cofactor(n, k, j, original)/det;
            }
    }
    
}