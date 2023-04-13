#include <stdio.h>
#include <stdlib.h>
// �߲˵���
#define MOSS_UNIT 2.05
#define BEET_UNIT 1.15
#define CARROT_UNIT 1.09
// ������Ϣ
#define DISCOUNT 100
#define DISCOUNT_PERCENT 0.05
// �����շѱ�׼
#define POUND_5 6.5
#define POUND_5_20 14
#define POUND_20 0.5
int main(void)
{
    char option;         // �߲�ѡ��
    float moss = 0;      // ��޺������
    float beet = 0;      // ��˼�����
    float carrot = 0;    // ���ܲ�������
    float expense;       // ��ʼ����
    float all_expense;   // �߲˼�ȥ�ۿ۵��ܷ���
    float weight;        // ������
    float add;           // ÿ����ӵ��߲�����
    float discount = -1; // �ۿ�
    float freight = 0;   // �˷ѺͰ�װ����
    printf("��������Ҫ������߲�ѡ�\n");
    printf("a)��޺ 2.05��Ԫ/��\nb)��� 1.15��Ԫ/��\nc)���ܲ� 1.09��Ԫ/��\nq)����ѡ��\n");
    while ((option = getchar()) != 'q')
    {
        switch (option)
        {
        case 'a':
            printf("����������:");
            scanf("%f", &add);
            moss += add;
            printf("��޺----%f��\n\n", moss);
            break;
        case 'b':
            printf("����������:");
            scanf("%f", &add);
            beet += add;
            printf("���----%f��\n\n", beet);
            break;
        case 'c':
            printf("����������:");
            scanf("%f", &add);
            carrot += add;
            printf("���ܲ�---%f��\n\n", carrot);
            break;
        }
        while (getchar() != '\n')
            continue;
        printf("ѡ���߲�:");
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
        printf("��޺ 2.05��Ԫ/��----%f��\n", moss);
    }
    if (beet > 0)
    {
        printf("��� 1.15��Ԫ/��----%f��\n", beet);
    }
    if (carrot > 0)
    {
        printf("���ܲ� 1.09��Ԫ/��--%f��\n", carrot);
    }
    printf("������������----------%f(��)\n", weight);
    printf("�������߲��ܷ���------%f��Ԫ\n", expense);
    if (discount > 0)
    {
        printf("�ۿ�------------------%f��Ԫ\n", discount);
    }
    printf("�˷Ѱ�װ����----------%f��Ԫ\n", freight);
    printf("���еķ����ܶ�--------%f��Ԫ\n", all_expense);
    printf("**************************************************\n");

    system("pause");
    return 0;
}