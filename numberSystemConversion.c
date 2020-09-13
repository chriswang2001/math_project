/*
  本程序用于进制间的相互转化
  作者：王浩舟
  日期：2020/2/7
*/

#include <stdio.h>
#include <stdbool.h>

void numberSystemConversion(int a, int b, char *original, char *result)
{
    int num1, i = 0, sum = 0;
    while (original[i] != '\0')
    {
        if (original[i] >= '0' && original[i] <= '9')
            num1 = original[i] - '0';
        else
            num1 = original[i] - 'a' + 10;

        sum = sum * a + num1;
        i++;
    }

    int k;
    int num2[10000];
    for (k = 0; sum > 0; k++)
    {
        num2[k] = sum % b;
        sum /= b;
    }

    result[k] = '\0';
    for (i = 0; i < k; i++)
    {
        if (num2[k - 1 - i] >= 0 && num2[k - 1 - i] <= 9)
            result[i] = num2[k - 1 - i] + '0';
        else
            result[i] = num2[k - 1 - i] + 'a' - 10;
    }
}

int main()
{
    int a, b;
    char original[10000], result[10000], m;
    bool n = true;

    while (n)
    {
        printf("请输入转换前的进制：");
        scanf("%d", &a);
        printf("请输入转换后的进制：");
        scanf("%d", &b);
        getchar();
        printf("请输入需要转换的数：");
        gets(original);

        numberSystemConversion(a, b, original, result);
        printf("结果为：%s\n", result);

        printf("是否继续？[y/n]");
        scanf("%c", &m);
        if (m == 'n')
            n = false;
    }

    return 0;
}