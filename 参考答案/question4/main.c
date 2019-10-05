#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];       //����
    char id[20];         //ѧ��
    int age;             //����
    char birthplace[30]; //����
    char post[5];           //�Ƿ�Ϊ��ɲ�
    int english;         //Ӣ��ɼ�   ѧ��5��
    int math;            //��ѧ�ɼ�   ѧ��6��
    int program;         //������Ƴɼ�    ѧ��3��
    int economic;        //����ѧ�ɼ�      ѧ��3��
    float GPA;
} stu;
int count = 0;           //ѧ������
stu s[100];
int main()
{
    int x;
    menu();
    printf("������������Ҫ�ķ���");
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
       // printf("������%d\n",s[0].math);
        printf("������������Ҫ�ķ���");
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

//***********ѧ����Ϣ¼��**********
void addStuInfo(stu *s)
{
    int x;
    printf("������¼����Ϣ������");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        printf("������ѧ��������");
        fflush(stdin);
        gets(s[count+i].name);
        printf("������ѧ��ѧ�ţ�");
        fflush(stdin);
        gets(s[count+i].id);
        printf("������ѧ�����䣺");
        scanf("%d",&(s[count+i].age));
        printf("������ѧ�����᣺");
        fflush(stdin);
        gets(s[count+i].birthplace);
        printf("�������Ƿ�Ϊѧ���ɲ���");
        fflush(stdin);
        gets(s[count+i].post);
        s[count+i].english=0;
        s[count+i].math=0;
        s[count+i].program=0;
        s[count+i].program=0;
        s[count+i].GPA=0;

        printf("������%s\n",s[i].name);
        printf("ѧ�ţ�%s\n",s[i].id);
        printf("���䣺%d\n",s[i].age);
        printf("���᣺%s\n",s[i].birthplace);
        printf("�Ƿ�Ϊѧ���ɲ���%s\n",s[i].post);
    }
    count=count+x;

}

//**********ѧ���ɼ�¼��***********
void addStuGradeInfo(stu *s)
{
    char id[20];
    int x;
    int i;
    while (1)
    {
    printf("������¼��ѧ����ѧ�ţ�");
    fflush(stdin);
    gets(id);
    for(i=0;i<count;i++)
    {

         if(strcmp(s[i].id,id)==0)
         {
            printf("������%s\n",s[i].name);
            printf("ѧ�ţ�%s\n",s[i].id);
            printf("�Ƿ����¼��ɼ�\n\n");
            printf("(1)��\n");
            printf("(2)��\n");
            scanf("%d",&x);
            if(x==1)
            {
               printf("��������ѧ�ɼ���");
               scanf("%d",&s[i].math);
               printf("������Ӣ��ɼ���");
                scanf("%d",&s[i].english);
                printf("�����������Ƴɼ���");
                 scanf("%d",&s[i].program);
                 printf("�����뾭��ѧ�ɼ���");
                 scanf("%d",&s[i].economic);
                 printf("��ӳɹ�\n");
                 break;
            }
            else
                break;
         }
    }
        if(i==count)
            printf("�����ڸ�ѧ����\n");
        printf("�Ƿ����¼��ɼ�\n\n");
        printf("(1)��\n");
        printf("(2)��\n");
        scanf("%d",&x);
        if(x==2)
            break;
    }
}

//**********ѧ���ɼ���ѯ***********
void searchGrade(stu *s)
{
    int x;
    char id[20];
    char name[20];
    while(1)
    {


    printf("(1)��������ѯ\n\n");
    printf("(2)��ѧ�Ų�ѯ\n\n");
    printf("(3)�˳�\n\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("������¼��ѧ����������");
        fflush(stdin);
        gets(name);
        for(int i=0;i<count;i++)
        {
             if(strcmp(s[i].name,name)==0)
             {
                printf("����:%s\n",s[i].name);
                printf("ѧ��:%s\n",s[i].id);
                printf("����:%d\n",s[i].age);
                printf("Ӣ��ɼ�:%d\n",s[i].english);
                printf("��ѧ�ɼ�:%d\n",s[i].math);
                printf("������Ƴɼ�:%d\n",s[i].program);
                printf("����ѧ�ɼ�:%d\n",s[i].economic);
            }
        }
    }
    else if(x==2)
    {
        printf("������¼��ѧ����ѧ�ţ�");
        fflush(stdin);
        gets(id);
        for(int i=0;i<count;i++)
        {
             if(strcmp(s[i].id,id)==0)
             {
                printf("����:%s\n",s[i].name);
                printf("ѧ��:%s\n",s[i].id);
                printf("����:%d\n",s[i].age);
                printf("Ӣ��ɼ�:%d\n",s[i].english);
                printf("��ѧ�ɼ�:%d\n",s[i].math);
                printf("������Ƴɼ�:%d\n",s[i].program);
                printf("����ѧ�ɼ�:%d\n",s[i].economic);
            }
        }
    }
    else
        break;
    }
}

//***********ѧ���ɼ�ͳ��**********
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
    printf("(1)ƽ���ɼ�\n\n");
    printf("(2)�ɼ�����\n\n");
    printf("(3)�˳�\n\n");
    //printf("**%d\n",s[0].english);
    scanf("%d",&x);

    while(x!=3){
     if(x==1)
     {   printf("%d\n",count);
            for( i = 0;i < count;i++)      //�������
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
                printf("��ѧ����ƽ���� %d\n",math);
                printf("Ӣ�￼��ƽ���� %d\n",english);
                printf("������ƿ���ƽ���� %d\n",program);
                printf("����ѧ����ƽ���� %d\n",economic);
     }
        else if(x==2)
        {
            c=0;
            while(c!=5)
            {
               printf("(1) Ӣ��ɼ�����\n");
               printf("(2) ��ѧ�ɼ�����\n");
               printf("(3) ������Ƴɼ�����\n");
               printf("(4) ����ѧ�ɼ�����\n");
               printf("(5) �˳�\n");
                scanf("%d",&c);
                printf("%d",c);

                    if(c==1)  //��Ӣ��ɼ�����
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
                        printf("        ��߷� ��ͷ�\n\n");
                        printf("Ӣ��     %d     %d\n\n",maxEnglish,minEnglish);
                        printf("ѧ�� ���� �ɼ�\n\n");
                    for(k=0;k<count;k++)
                    {
                        printf("%s %s %d\n",s[k].id,s[k].name,s[k].english);
                    }
                }
                      if(c==2)
                    {
                          //����ѧ�ɼ�����
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
                             printf("        ��߷� ��ͷ�\n\n");
                             printf("��ѧ     %d     %d\n\n",maxMath,minMath);
                                printf("ѧ�� ���� �ɼ�\n\n");
                            for(k=0;k<count;k++)
                            {
                                printf("%s %s %d\n",s[k].id,s[k].name,s[k].math);
                            }
                    }
                      if(c==3)  //�������������
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
                            printf("        ��߷� ��ͷ�\n\n");
                            printf("������� %d     %d\n\n",maxProgram,minProgram);
                            printf("ѧ�� ���� �ɼ�\n\n");
                        for(k=0;k<count;k++)
                        {
                            printf("%s %s %d\n",s[k].id,s[k].name,s[k].program);
                        }
                    }
                      if(c==4)    //����ѧ����
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
                             printf("        ��߷� ��ͷ�\n\n");
                             printf("����ѧ   %d     %d\n\n",maxEconomic,minEconomic);
                             printf("ѧ�� ���� �ɼ�\n\n");
                        for(k=0;k<count;k++)
                        {
                            printf("%s %s %d\n",s[k].id,s[k].name,s[k].economic);
                        }
                    }


           }

        }
         printf("(1)ƽ���ɼ�\n\n");
        printf("(2)�ɼ�����\n\n");
        printf("(3)�˳�\n\n");
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
        printf("����:%s\n",s[i].name);
        printf("ѧ��:%s\n",s[i].id);
   //     printf("%d %d %d %d \n",s[i].math,s[i].english,s[i].program,s[i].economic);
        printf("����:%f\n",s[i].GPA);
        printf("\n");
    }

}

//***********�˵�����**************
void menu()
{
    printf("**********�˵�************\n\n");
    printf("(1)ѧ����Ϣ¼��\n\n");
    printf("(2)ѧ���ɼ�¼��\n\n");
    printf("(3)ѧ���ɼ���ѯ\n\n");
    printf("(4)�ɼ�ͳ�Ʒ���\n\n");
    printf("(5)�ɼ��������\n\n");
    printf("(6)�˳�\n\n");

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
