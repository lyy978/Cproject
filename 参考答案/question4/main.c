#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];       //姓名
    char id[20];         //学号
    int age;             //年龄
    char birthplace[30]; //籍贯
    char post[5];           //是否为班干部
    int english;         //英语成绩   学分5分
    int math;            //数学成绩   学分6分
    int program;         //程序设计成绩    学分3分
    int economic;        //经济学成绩      学分3分
    float GPA;
} stu;
int count = 0;           //学生个数
stu s[100];
int main()
{
    int x;
    menu();
    printf("请输入您所需要的服务：");
    scanf("%d",&x);
    while(x!=6)
    {
        switch(x)
        {
            case 1:addStuInfo(s);break;
            case 2:addStuGradeInfo(s);break;
            case 3:searchGrade(s);break;
            case 4:statisticsGrade(s);break;
            case 5:countGpa(s);break;
        }
       // printf("姓名：%d\n",s[0].math);
        printf("请输入您所需要的服务：");
        scanf("%d",&x);
    }
    int i=0;

//
//    stu s1[2];
//    s[0].age=10;
//    s[1].age=20;
//    swapStu(&s[0],&s[1]);
//    printf("%d",s[0].age);
//

    return 0;
}

//***********学生信息录入**********
void addStuInfo(stu *s)
{
    int x;
    printf("请输入录入信息条数：");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        printf("请输入学生姓名：");
        fflush(stdin);
        gets(s[count+i].name);
        printf("请输入学生学号：");
        fflush(stdin);
        gets(s[count+i].id);
        printf("请输入学生年龄：");
        scanf("%d",&(s[count+i].age));
        printf("请输入学生籍贯：");
        fflush(stdin);
        gets(s[count+i].birthplace);
        printf("请输入是否为学生干部：");
        fflush(stdin);
        gets(s[count+i].post);
        s[count+i].english=0;
        s[count+i].math=0;
        s[count+i].program=0;
        s[count+i].program=0;
        s[count+i].GPA=0;

        printf("姓名：%s\n",s[i].name);
        printf("学号：%s\n",s[i].id);
        printf("年龄：%d\n",s[i].age);
        printf("籍贯：%s\n",s[i].birthplace);
        printf("是否为学生干部：%s\n",s[i].post);
    }
    count=count+x;

}

//**********学生成绩录入***********
void addStuGradeInfo(stu *s)
{
    char id[20];
    int x;
    int i;
    while (1)
    {
    printf("请输入录入学生的学号：");
    fflush(stdin);
    gets(id);
    for(i=0;i<count;i++)
    {

         if(strcmp(s[i].id,id)==0)
         {
            printf("姓名：%s\n",s[i].name);
            printf("学号：%s\n",s[i].id);
            printf("是否继续录入成绩\n\n");
            printf("(1)是\n");
            printf("(2)否\n");
            scanf("%d",&x);
            if(x==1)
            {
               printf("请输入数学成绩：");
               scanf("%d",&s[i].math);
               printf("请输入英语成绩：");
                scanf("%d",&s[i].english);
                printf("请输入程序设计成绩：");
                 scanf("%d",&s[i].program);
                 printf("请输入经济学成绩：");
                 scanf("%d",&s[i].economic);
                 printf("添加成功\n");
                 break;
            }
            else
                break;
         }
    }
        if(i==count)
            printf("不存在该学生！\n");
        printf("是否继续录入成绩\n\n");
        printf("(1)是\n");
        printf("(2)否\n");
        scanf("%d",&x);
        if(x==2)
            break;
    }
}

//**********学生成绩查询***********
void searchGrade(stu *s)
{
    int x;
    char id[20];
    char name[20];
    while(1)
    {


    printf("(1)按姓名查询\n\n");
    printf("(2)按学号查询\n\n");
    printf("(3)退出\n\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("请输入录入学生的姓名：");
        fflush(stdin);
        gets(name);
        for(int i=0;i<count;i++)
        {
             if(strcmp(s[i].name,name)==0)
             {
                printf("姓名:%s\n",s[i].name);
                printf("学号:%s\n",s[i].id);
                printf("年龄:%d\n",s[i].age);
                printf("英语成绩:%d\n",s[i].english);
                printf("数学成绩:%d\n",s[i].math);
                printf("程序设计成绩:%d\n",s[i].program);
                printf("经济学成绩:%d\n",s[i].economic);
            }
        }
    }
    else if(x==2)
    {
        printf("请输入录入学生的学号：");
        fflush(stdin);
        gets(id);
        for(int i=0;i<count;i++)
        {
             if(strcmp(s[i].id,id)==0)
             {
                printf("姓名:%s\n",s[i].name);
                printf("学号:%s\n",s[i].id);
                printf("年龄:%d\n",s[i].age);
                printf("英语成绩:%d\n",s[i].english);
                printf("数学成绩:%d\n",s[i].math);
                printf("程序设计成绩:%d\n",s[i].program);
                printf("经济学成绩:%d\n",s[i].economic);
            }
        }
    }
    else
        break;
    }
}

//***********学生成绩统计**********
void statisticsGrade(stu *s)
{
    int x=0;
    int english=0;
    int math=0;
    int program=0;
    int economic=0;
    int temp;
    int i=0;
    int j;
    int maxEconomic;
    int minEconomic;
    int maxProgram;
    int minProgram;
    int minMath;
    int maxMath;
    int minEnglish;
    int maxEnglish;
    int c=0;
    int k;
    printf("(1)平均成绩\n\n");
    printf("(2)成绩排名\n\n");
    printf("(3)退出\n\n");
    //printf("**%d\n",s[0].english);
    scanf("%d",&x);

    while(x!=3){
     if(x==1)
     {   printf("%d\n",count);
            for( i = 0;i < count;i++)      //分数求和
            {
                english += s[i].english;
                math += s[i].math;                             ///************??????
                program+= s[i].program;
                economic+= s[i].economic;

            }
                english = english/count;
                math = math / count;
                program = program / count;
                economic = economic /count;
                printf("count:%d\n",count);
                printf("数学考试平均分 %d\n",math);
                printf("英语考试平均分 %d\n",english);
                printf("程序设计考试平均分 %d\n",program);
                printf("经济学考试平均分 %d\n",economic);
     }
        else if(x==2)
        {
            c=0;
            while(c!=5)
            {
               printf("(1) 英语成绩排名\n");
               printf("(2) 数学成绩排名\n");
               printf("(3) 程序设计成绩排名\n");
               printf("(4) 经济学成绩排名\n");
               printf("(5) 退出\n");
                scanf("%d",&c);
                printf("%d",c);

                    if(c==1)  //按英语成绩排名
                    {
                   // printf("guagua\n");
                     for( i=0;i<count;i++)
                        {
                             //  printf("guagua12\n");
                            for(j=0;j<count-i-1;j++)
                            {
                               //    printf("guagua33\n");
                               if(s[j].english<s[j+1].english)
                                {
                                    //   printf("guagua44\n");
                                    swapStu(&s[j],&s[j+1]);
                                }
                            }
                        }

                        maxEnglish=s[0].english;
                        minEnglish=s[count-1].english;
                        printf("        最高分 最低分\n\n");
                        printf("英语     %d     %d\n\n",maxEnglish,minEnglish);
                        printf("学号 姓名 成绩\n\n");
                    for(k=0;k<count;k++)
                    {
                        printf("%s %s %d\n",s[k].id,s[k].name,s[k].english);
                    }
                }
                      if(c==2)
                    {
                          //按数学成绩排序
                          printf("***shuxu\n");
                            for( i=0;i<count;i++)
                            {
                                for(j=0;j<count-i-1;j++)
                                {
                                     if(s[j].math<s[j+1].math)
                                    {
                                        swapStu(&s[j],&s[j+1]);
                                    }
                                }
                            }
                             maxMath=s[0].math;
                             minMath=s[count-1].math;
                             printf("        最高分 最低分\n\n");
                             printf("数学     %d     %d\n\n",maxMath,minMath);
                                printf("学号 姓名 成绩\n\n");
                            for(k=0;k<count;k++)
                            {
                                printf("%s %s %d\n",s[k].id,s[k].name,s[k].math);
                            }
                    }
                      if(c==3)  //按程序设计排名
                    {
                         for( i=0;i<count;i++)
                        {
                            for(j=0;j<count-i-1;j++)
                            {
                               if(s[j].program<s[j+1].program)
                                {
                                    swapStu(&s[j],&s[j+1]);
                                }
                            }
                            }
                            maxProgram=s[0].program;
                            minProgram=s[count-1].program;
                            printf("        最高分 最低分\n\n");
                            printf("程序设计 %d     %d\n\n",maxProgram,minProgram);
                            printf("学号 姓名 成绩\n\n");
                        for(k=0;k<count;k++)
                        {
                            printf("%s %s %d\n",s[k].id,s[k].name,s[k].program);
                        }
                    }
                      if(c==4)    //经济学排名
                    {
                         for( i=0;i<count;i++)
                            {
                                for(j=0;j<count-i-1;j++)
                                {
                                   if(s[j].economic<s[j+1].economic)
                                    {
                                        swapStu(&s[j],&s[j+1]);
                                    }
                                }
                            }
                             maxEconomic=s[0].economic;
                             minEconomic=s[count-1].economic;
                             printf("        最高分 最低分\n\n");
                             printf("经济学   %d     %d\n\n",maxEconomic,minEconomic);
                             printf("学号 姓名 成绩\n\n");
                        for(k=0;k<count;k++)
                        {
                            printf("%s %s %d\n",s[k].id,s[k].name,s[k].economic);
                        }
                    }


           }

        }
         printf("(1)平均成绩\n\n");
        printf("(2)成绩排名\n\n");
        printf("(3)退出\n\n");
        scanf("%d",&x);
    }

}



void countGpa(stu *s)
{
    int i;
    int j;
    int temp;
    for(i=0;i<count;i++)
    {
        s[i].GPA=((s[i].english-50)/10*5+(s[i].math-50)/10*6+(s[i].economic-50)/10*3+(s[i].program-50)/10*3)/17;
    }
    for(i=0;i<count;i++)
    {
    for(j=0;j<count-i-1;j++)
    {
        if(s[j].GPA<s[j+1].GPA)
            {
             swapStu(&s[j],&s[j+1]);
            }
    }
    }
    for(i=0;i<count;i++)
    {
        printf("姓名:%s\n",s[i].name);
        printf("学号:%s\n",s[i].id);
   //     printf("%d %d %d %d \n",s[i].math,s[i].english,s[i].program,s[i].economic);
        printf("绩点:%f\n",s[i].GPA);
        printf("\n");
    }

}

//***********菜单函数**************
void menu()
{
    printf("**********菜单************\n\n");
    printf("(1)学生信息录入\n\n");
    printf("(2)学生成绩录入\n\n");
    printf("(3)学生成绩查询\n\n");
    printf("(4)成绩统计分析\n\n");
    printf("(5)成绩绩点计算\n\n");
    printf("(6)退出\n\n");

}


void swapStu(stu *p,stu *q)
{
     stu *temp;


     temp=(stu *)malloc(sizeof(struct student));

     temp->age=p->age;
     p->age=q->age;
     q->age=temp->age;

     strcpy(temp->birthplace,p->birthplace);
     strcpy(p->birthplace,q->birthplace);
     strcpy(q->birthplace,temp->birthplace);

     strcpy(temp->name,p->name);
     strcpy(p->name,q->name);
     strcpy(q->name,temp->name);

     strcpy(temp->id,p->id);
     strcpy(p->id,q->id);
     strcpy(q->id,temp->id);

     strcpy(temp->post,p->post);
     strcpy(p->post,q->post);
     strcpy(q->post,temp->post);

     temp->GPA=p->GPA;
     p->GPA=q->GPA;
     q->GPA=temp->GPA;

     temp->economic=p->economic;
     p->economic=q->economic;
     q->economic=temp->economic;

     temp->english=p->english;
     p->english=q->english;
     q->english=temp->english;

     temp->math=p->math;
     p->math=q->math;
     q->math=temp->math;

     temp->program=p->program;
     p->program=q->program;
     q->program=temp->program;



}
