#include <stdio.h>
#include <stdlib.h>
// 蔬菜单价
#define MOSS_UNIT 2.05
#define BEET_UNIT 1.15
#define CARROT_UNIT 1.09
// 打折信息
#define DISCOUNT 100
#define DISCOUNT_PERCENT 0.05
// 重量收费标准
#define POUND_5 6.5
#define POUND_5_20 14
#define POUND_20 0.5
int main(void)
{
    char option;         // 蔬菜选项
    float moss = 0;      // 洋藓计数器
    float beet = 0;      // 甜菜计数器
    float carrot = 0;    // 胡萝卜计数器
    float expense;       // 初始费用
    float all_expense;   // 蔬菜减去折扣的总费用
    float weight;        // 总重量
    float add;           // 每次添加的蔬菜重量
    float discount = -1; // 折扣
    float freight = 0;   // 运费和包装费用
    printf("请输入你要购买的蔬菜选项：\n");
    printf("a)洋藓 2.05美元/磅\nb)甜菜 1.15美元/磅\nc)胡萝卜 1.09美元/磅\nq)结束选择\n");
    while ((option = getchar()) != 'q')
    {
        switch (option)
        {
        case 'a':
            printf("请输入重量:");
            scanf("%f", &add);
            moss += add;
            printf("洋藓----%f磅\n\n", moss);
            break;
        case 'b':
            printf("请输入重量:");
            scanf("%f", &add);
            beet += add;
            printf("甜菜----%f磅\n\n", beet);
            break;
        case 'c':
            printf("请输入重量:");
            scanf("%f", &add);
            carrot += add;
            printf("胡萝卜---%f磅\n\n", carrot);
            break;
        }
        while (getchar() != '\n')
            continue;
        printf("选择蔬菜:");
    }
    expense = moss * MOSS_UNIT + beet * BEET_UNIT + carrot * CARROT_UNIT;
    if (expense > DISCOUNT)
    {
        discount = expense * DISCOUNT_PERCENT;
        all_expense = expense - discount;
    }
    else
    {
        all_expense = expense;
    }
    weight = moss + beet + carrot;
    if (weight <= 5)
    {
        freight = POUND_5;
    }
    else if (weight > 5 && weight <= 20)
    {
        freight = POUND_5_20;
    }
    else
    {
        freight = (weight - 20) * POUND_20 + POUND_5_20;
    }
    all_expense += freight;
    printf("**************************************************\n");
    if (moss > 0)
    {
        printf("洋藓 2.05美元/磅----%f磅\n", moss);
    }
    if (beet > 0)
    {
        printf("甜菜 1.15美元/磅----%f磅\n", beet);
    }
    if (carrot > 0)
    {
        printf("胡萝卜 1.09美元/磅--%f磅\n", carrot);
    }
    printf("订购的总重量----------%f(磅)\n", weight);
    printf("订购的蔬菜总费用------%f美元\n", expense);
    if (discount > 0)
    {
        printf("折扣------------------%f美元\n", discount);
    }
    printf("运费包装费用----------%f美元\n", freight);
    printf("所有的费用总额--------%f美元\n", all_expense);
    printf("**************************************************\n");

    system("pause");
    return 0;
}