#include <stdio.h>
#include <stdlib.h>
#define BASIC_SALARY_UNIT 10.00 //基本工资
#define BASIC_TIME 40           //不加班的最长工作时间
#define RATIO 1.5               //倍率
#define FRONT_TAX 0.15          // 前300美元
#define ADD_TAX 0.20            //续150美元
#define REMAINING_TAX 0.25      // 余下的
#define FRONT_SALARY 300        // 300美元
#define ADD_SALARY 150          // 150美元
int main(void)
{
    int time;            //工作时间
    float salary = 0.0;  // 工资总额
    float tallage = 0.0; // 税金

    printf("请输入一周工作的小时数: ");
    scanf("%d", &time);
    // 计算salary
    if (time > 0 && time <= BASIC_TIME)
    {
        salary = BASIC_SALARY_UNIT * time;
    }
    else if (time > BASIC_TIME)
    {
        salary = BASIC_SALARY_UNIT * ((time - BASIC_TIME) * RATIO + BASIC_TIME);
    }
    // 计算tallage
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
    printf("工资总额为:%f\n税金为:%f\n净收入为:%f\n", salary, tallage, salary - tallage);

    system("pause");
    return 0;
}