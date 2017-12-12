#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    double weight[20];
    double height[20];
}human;

human ary[20];


typedef struct{
    char food[20];
}calender;

calender food_list[20];

// calender month[12];
// calender day[31];

int window();
void operate();
void presskey();
void BMI();
void calorie();
void user_info_list();
//void food_calculate();

int main(void)
{
    int i,j,month,day;
    char *ID;
    char *PW;
        char * in_PW = "201720963";
    ID = (char*)malloc(sizeof(char) *10);
    PW = (char*)malloc(sizeof(char) *10);

    while(1)
    {

        printf("Input your birth: ");
        scanf("%s", ID);
        month =(*(ID+4)-'0')*10 + (*(ID+5)-'0');
        day = (*(ID+6)-'0')*10 +(*(ID+7)-'0');

        if(month < 1 || month > 12)
        {
            printf("ID error \n");
            continue;
        }
        else if(day < 1 || day > 31)
        {
            printf("ID error \n");
            continue;
        }
        else
            break;
    }
    while(1)
    {
        printf("Input your PW: ");
        scanf("%s", PW);

        for(i=0; i<9; i++)
        {
            if(*(PW+i) != *(in_PW+i))
            {
                j = 0;
                break;
            }
            j = 1;
        }
        if(j)
        {
            printf("Successful login \n");
            break;
        }
        else
        {
            printf("PW error \n");
            continue;
        }
    }
    free(ID);
    free(PW);
    operate();

    return 0;
}
int window()
{
    int token = 0;
    printf("\n\n");
    printf("------------- Health Improvement Management ------------ \n");
    printf("1. BMI_measurement 2.Measurement of basal metabolic rate 3.User_info_list 0.Exit \n"); // 1.BMI 측정 2. 기초대사량 측정  3. 사용자 리스트 출력
    printf("Select_your_number: ");
    scanf("%d", &token);
    printf("\n\n");
    return token;
}
void operate(int token)
{
    int c;
    while((c = window()) != 0)
    {
        switch(c)
        {
            case 0: exit(1);
                break;
            case 1: BMI();
                break;
            case 2: calorie();
                break;
            case 3: user_info_list();
                break;
           // case 4: food_calculate();
               // break;
            default:printf("\n Invaild input \n"); 
                break;
        }
    }
}

void BMI()
{
    int i;
    double bmi = 0;
    int count = 1;

    for(i=0; i<3; i++)
    {
         printf("User_%d \n", count);
         printf("\n");
         printf("EX) 84.3 175.2 \n");
         printf("Input your weight and height: ");
            scanf("%lf %lf", &ary[i].weight[i], &ary[i].height[i]);
        bmi = ary[i].weight[i] / (ary[i].height[i] * ary[i].height[i])*10000;
        printf("  Weight   Height\tBmi \n");
        printf("%8.1f %8.1f %8.1f \n", ary[i].weight[i], ary[i].height[i], bmi);
        if(bmi>30)
            printf("\n Obesity \n\n"); // 비만
        else if(bmi >= 25)
            printf("\n Overweight \n\n"); // 과체중
        else if(bmi >= 19)
            printf("\n Normal \n\n"); // 정상
        else
            printf("\n Underweight \n\n"); // 저체중
        count++;
     }
     presskey();
}
void calorie()
{
    int i;
    int gender = 0;
    int age = 0;
    double result = 0;
    int count = 1;

    for(i = 0; i<3; i++)
    {
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Male calorie average:2500 \t");
        printf("Female calorie average:2000 \n");
        printf("\n");
        printf("User_%d \n",count);
        printf("Enter your gender and age \n");
        scanf("%d %d",&gender, &age);

        if(gender == 1)
        {
              result = 66.47 +(13.75 * ary[i].weight[i]) + (5 * ary[i].height[i]) - (6.76* age);
           // result = 88 + (13 * ary[i].weight[i] + 4 * ary[i].height[i]) - (5 * age);
        }
        else if(gender == 2)
        {
              result = 655.1 +(9.56 * ary[i].weight[i]) +(1.85 * ary[i].height[i]) - (4.68 * age);
           // result = 44 + (9 * ary[i].weight[i] + 3 * ary[i].height[i]) - (4 * age);
        }
        else
        {
            printf("\n");
            printf("Invaild Input \n");
            break;
        }
        printf("\n");
        printf("User_%d \n", count);
        printf("Your basic metabolic capacity: %.1lf \n",result); //기초 대사량
        printf("\n");
        count++;
    }
    presskey();
}
void user_info_list()
{
    int i,j,k = 0;
    int cnt = 1;
    
    for(i = 0; i < 3; i++)
    {
        printf("user_%d \n", cnt);
        printf("\n");
        printf("print_info_weight:%.1lf \n", ary[i].weight[i]);
        printf("\n");
        printf("print_info_height:%.1lf \n", ary[i].height[i]);
        printf("\n");
        cnt++;
    }
    presskey();
}
/*void food_calculate()
{
    int i = 0;
    int calorie = 0;
    int tot = 0;
    int cnt = 0;
    char a = 0;
    
    for(int z = 0; z < 3; z++)
    {
        printf("exit to end \n");
        printf("Enter the food you ate: ");
           fgets(food_list[z].food[z], sizeof(calender.food), stdin);
           // fflush(stdin);
        if(food == "end")
            break;
        printf("input food calorie: ");
        scanf("%d", &calorie);
        printf("select count: ");
        scanf("%d", &cnt);
    }
    tot = calorie * cnt;
    for(i = 0; i < 3; i++)
    {
        printf("The list of food you ate:%s \n", food_list[i].food[i]);
        printf("result: %d \n", tot);
    }
    presskey();

    for(int a = 0; a < 5; a++)
    {
        if(food_list[i].food[i] == "end") break;
        printf("input: ");
        fgets(food_list[i].food[i], sizeof(food_list[i].food[i], stdin);
    }
    

}*/
void presskey()
{
    char c;
    fflush(stdin);
    printf("\n\n");
    scanf("%c", &c);
}
