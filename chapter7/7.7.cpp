#include <stdio.h>
#include <stdlib.h>
#define BASIC_SALARY_UNIT 10.00 //��������
#define BASIC_TIME 40           //���Ӱ�������ʱ��
#define RATIO 1.5               //����
#define FRONT_TAX 0.15          // ǰ300��Ԫ
#define ADD_TAX 0.20            //��150��Ԫ
#define REMAINING_TAX 0.25      // ���µ�
#define FRONT_SALARY 300        // 300��Ԫ
#define ADD_SALARY 150          // 150��Ԫ
int main(void)
{
    int time;            //����ʱ��
    float salary = 0.0;  // �����ܶ�
    float tallage = 0.0; // ˰��

    printf("������һ�ܹ�����Сʱ��: ");
    scanf("%d", &time);
    // ����salary
    if (time > 0 && time <= BASIC_TIME)
    {
        salary = BASIC_SALARY_UNIT * time;
    }
    else if (time > BASIC_TIME)
    {
        salary = BASIC_SALARY_UNIT * ((time - BASIC_TIME) * RATIO + BASIC_TIME);
    }
    // ����tallage
    if (salary <= FRONT_SALARY)
    {
        tallage = salary * FRONT_TAX;
    }
    else if (salary < FRONT_SALARY + ADD_SALARY)
    {
        tallage = FRONT_SALARY * FRONT_TAX + (salary - FRONT_SALARY) * ADD_TAX;
    }
    else
    {
        tallage = FRONT_SALARY * FRONT_TAX + ADD_SALARY * ADD_TAX + (salary - FRONT_SALARY - ADD_SALARY) * REMAINING_TAX;
    }
    printf("�����ܶ�Ϊ:%f\n˰��Ϊ:%f\n������Ϊ:%f\n", salary, tallage, salary - tallage);

    system("pause");
    return 0;
}