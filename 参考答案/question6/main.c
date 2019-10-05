#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Work
{
    char id[20];    //工号
    char name[20];  //员工姓名
    int  basepay;   //基本工资
    int dutywage;   //职务工资
    int allowance;  //津贴
    int healthcare; //医疗保险
    int acfund;     //公积金
    int total;      //总工资
}Worker;
int count=0;        //员工数

int main()
{
    int x;
    Worker worker[100];
    getWorkerInfo(worker);
    while(1)
    {
        menu();  //菜单
        printf("请输入选项：");
        scanf("%d",&x);
        switch(x)
        {
        case 1:writeinfo(worker);break;
        case 2:showinfo(worker);break;
        case 3:changeinfo(worker);break;
        case 4:statistics(worker);break;
        case 5:return 0;break;
        }
    }


    return 0;
}

//********菜单****************
void menu()
{
    printf("*******菜单********\n");
    printf("(1)输入记录\n");
    printf("(2)显示记录\n");
    printf("(3)修改记录\n");
    printf("(4)统计\n");
    printf("(5)退出\n");
}


//*********读取职工信息********
void getWorkerInfo(Worker *worker)
{
    int i=0;
    FILE *fp;
    fp = fopen("E:\\CodeblockProject\\question6\\workerinfo.txt","r");
    if(fp == NULL)
    {
         printf("Open filefailure!");
         exit(1);
    }
    else
    {
        printf("ID号   姓名  基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
         while(!feof(fp))
        {
                fscanf(fp, "%s", &worker[i].id);
                printf("%4s   ",worker[i].id);//这两行为按行读取所有数据

                fscanf(fp, "%s", &worker[i].name);
                printf("%4s   ",worker[i].name);//这两行为按行读取所有数据

                fscanf(fp, "%d", &worker[i].basepay);
                printf("%4d",worker[i].basepay);//这两行为按行读取所有数据

                fscanf(fp, "%d", &worker[i].dutywage);
                printf("%10d",worker[i].dutywage);//这两行为按行读取所有数据

                fscanf(fp, "%d", &worker[i].allowance);
                printf("%8d",worker[i].allowance);//这两行为按行读取所有数据

                fscanf(fp, "%d",&worker[i].healthcare);
                printf("%8d",worker[i].healthcare);//这两行为按行读取所有数据

                fscanf(fp, "%d", &worker[i].acfund);
                printf("%8d",worker[i].acfund);//这两行为按行读取所有数据

                fscanf(fp, "%d", &worker[i].total);
                printf("%8d",worker[i].total);//这两行为按行读取所有数据
                printf("\n");
                i++;
                count++;

        }
    }
    fclose(fp);

}

//*********显示职工信息********
void showinfo(Worker *worker)
{
    int i=0;
    int x;
    char id[20];    //工号
    char name[20];  //员工姓名

    printf("(1)按姓名查找\n");
    printf("(2)按工号查找\n");
    printf("请输入选项：");
    scanf("%d",&x);

    switch(x)
    {
        case 1:{
                printf("请输入职工姓名：");
                fflush(stdin);
                gets(name);
                for(i=0;i<count;i++)
                {
                    if(strcmp(worker[i].name,name)==0)
                    {
                        printf("ID号   姓名  基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
                        printf("%4s   ",worker[i].id);
                        printf("%4s  ",worker[i].name);
                        printf("%4d ",worker[i].basepay);
                        printf("%10d ",worker[i].dutywage);
                        printf("%8d ",worker[i].allowance);
                        printf("%8d ",worker[i].healthcare);
                        printf("%8d ",worker[i].acfund);
                        printf("%8d",worker[i].total);
                        printf("\n");
                        break;
                    }

                }
        };break;
        case 2:{
                    printf("请输入职工工号：");
                    fflush(stdin);
                    gets(id);
                    for(i=0;i<count;i++)
                    {
                        if(strcmp(worker[i].id,id)==0)
                        {
                            printf("ID号   姓名  基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
                            printf("%4s   ",worker[i].id);
                            printf("%4s  ",worker[i].name);
                            printf("%4d ",worker[i].basepay);
                            printf("%10d ",worker[i].dutywage);
                            printf("%8d ",worker[i].allowance);
                            printf("%8d ",worker[i].healthcare);
                            printf("%8d ",worker[i].acfund);
                            printf("%8d",worker[i].total);
                            printf("\n");
                            break;
                        }
                    }
        }
    }
    if(i==count)
        printf("不存在该员工信息！\n");


}

//*********录入职工信息*********
void writeinfo(Worker *worker)
{
    int i=0;
    int n;
    FILE *fp;
    fp = fopen("E:\\CodeblockProject\\question6\\workerinfo.txt","a+");
    printf("请输入需要录入的员工信息条数：");
    scanf("%d",&n);
    for(i=count;i<count+n;i++)
    {
        printf("i=%d\n",i);
        printf("请输入职工工号：");
        fflush(stdin);
        gets(worker[i].id);
        printf("请输入职工姓名：");
        fflush(stdin);
        gets(worker[i].name);
        printf("请输入基本工资：");
        scanf("%d",&worker[i].basepay);
        printf("请输入职务工资：");
        scanf("%d",&worker[i].dutywage);
        printf("请输入津贴：");
        scanf("%d",&worker[i].allowance);
        printf("请输入医疗保险：");
        scanf("%d",&worker[i].healthcare);
        printf("请输入公积金：");
        scanf("%d",&worker[i].acfund);
        worker[i].total=worker[i].basepay-worker[i].acfund+worker[i].allowance+worker[i].dutywage-worker[i].healthcare;
    }
    count+=n;
    for(i=count-n;i<count;i++)
    {
        fprintf(fp, "\n");
        fprintf(fp, "%s ", worker[i].id);
        printf("%s ",worker[i].id);
        fprintf(fp, "%s ", worker[i].name);
        printf("%s ",worker[i].name);
        fprintf(fp, "%d ", worker[i].basepay);
        printf("%d ",worker[i].basepay);
        fprintf(fp, "%d ", worker[i].dutywage);
        printf("%d ",worker[i].dutywage);
        fprintf(fp, "%d ", worker[i].allowance);
        printf("%d ",worker[i].allowance);
        fprintf(fp, "%d ",worker[i].healthcare);
        printf("%d ",worker[i].healthcare);
        fprintf(fp, "%d ", worker[i].acfund);
        printf("%d ",worker[i].acfund);
        fprintf(fp, "%d", worker[i].total);
        printf("%d",worker[i].total);
        printf("\n");
    }
    fclose(fp);
}

//****************修改职工信息**************
void changeinfo(Worker *worker)
{
    int i=0;
    int x;
    char id[20];    //工号
    char name[20];  //员工姓名
    int c;
    FILE *fp;
    fp = fopen("E:\\CodeblockProject\\question6\\workerinfo.txt","w");
    printf("(1)按姓名修改\n");
    printf("(2)按工号修改\n");
    printf("请输入选项：");
    scanf("%d",&x);
    switch(x)
    {
        case 1:{
                printf("请输入职工姓名：");
                fflush(stdin);
                gets(name);
                for(i=0;i<count;i++)
                {
                    if(strcmp(worker[i].name,name)==0)
                    {
                        printf("ID号   姓名  基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
                        printf("%4s   ",worker[i].id);
                        printf("%4s  ",worker[i].name);
                        printf("%4d ",worker[i].basepay);
                        printf("%10d ",worker[i].dutywage);
                        printf("%8d ",worker[i].allowance);
                        printf("%8d ",worker[i].healthcare);
                        printf("%8d ",worker[i].acfund);
                        printf("%8d",worker[i].total);
                        printf("\n");
                        break;
                    }
                }

                printf("(1)基本工资\n");
                printf("(2)职务工资\n");
                printf("(3)津贴\n");
                printf("(4)医疗保险\n");
                printf("(5)公积金\n");
                printf("请输入修改项目：");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:{
                        printf("请输入金额：");
                        scanf("%d",&worker[i].basepay);
                        printf("**xiugai\n");
                    };break;
                    case 2:{
                        printf("请输入金额：");
                        scanf("%d",&worker[i].dutywage);
                        }
                        ;break;
                    case 3:{
                            printf("请输入金额：");
                            scanf("%d",&worker[i].allowance);
                    };break;
                    case 4:{
                        printf("请输入金额：");
                         scanf("%d",&worker[i].healthcare);
                    };break;
                    case 5:
                        {
                        printf("请输入金额：");
                        scanf("%d",&worker[i].acfund);
                        };
                        break;
                }
                worker[i].total=worker[i].basepay-worker[i].acfund+worker[i].allowance+worker[i].dutywage-worker[i].healthcare;

        };break;
        case 2:{
                    printf("请输入职工工号：");
                    fflush(stdin);
                    gets(id);
                    for(i=0;i<count;i++)
                    {
                        if(strcmp(worker[i].id,id)==0)
                        {
                            printf("ID号   姓名  基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
                            printf("%4s   ",worker[i].id);
                            printf("%4s  ",worker[i].name);
                            printf("%4d ",worker[i].basepay);
                            printf("%10d ",worker[i].dutywage);
                            printf("%8d ",worker[i].allowance);
                            printf("%8d ",worker[i].healthcare);
                            printf("%8d ",worker[i].acfund);
                            printf("%8d",worker[i].total);
                            printf("\n");
                            break;
                        }
                    }

                printf("请输入修改项目：");
                printf("(1)基本工资\n");
                printf("(2)职务工资\n");
                printf("(3)津贴\n");
                printf("(4)医疗保险\n");
                printf("(5)公积金\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:{
                        printf("请输入金额：");
                        scanf("%d",&worker[i].basepay);
                    };break;
                    case 2:{
                        printf("请输入金额：");
                        scanf("%d",&worker[i].dutywage);
                        }
                        ;break;
                    case 3:{
                            printf("请输入金额：");
                            scanf("%d",&worker[i].allowance);
                    };break;
                    case 4:{
                        printf("请输入金额：");
                         scanf("%d",&worker[i].healthcare);
                    };break;
                    case 5:
                        {
                        printf("请输入金额：");
                        scanf("%d",&worker[i].acfund);
                        };
                        break;
                }
                worker[i].total=worker[i].basepay-worker[i].acfund+worker[i].allowance+worker[i].dutywage-worker[i].healthcare;

        }
    }
     if(i==count)
        printf("不存在该员工信息！\n");

   for(i=0;i<count;i++)
    {
        fprintf(fp, "\n");
        fprintf(fp, "%s ", worker[i].id);
        printf("%s ",worker[i].id);
        fprintf(fp, "%s ", worker[i].name);
        printf("%s ",worker[i].name);
        fprintf(fp, "%d ", worker[i].basepay);
        printf("%d ",worker[i].basepay);
        fprintf(fp, "%d ", worker[i].dutywage);
        printf("%d ",worker[i].dutywage);
        fprintf(fp, "%d ", worker[i].allowance);
        printf("%d ",worker[i].allowance);
        fprintf(fp, "%d ",worker[i].healthcare);
        printf("%d ",worker[i].healthcare);
        fprintf(fp, "%d ", worker[i].acfund);
        printf("%d ",worker[i].acfund);
        fprintf(fp, "%d", worker[i].total);
        printf("%d",worker[i].total);
        printf("\n");
    }

    fclose(fp);
}


//********统计************
void statistics(Worker *worker)
{
    int i;
    int t;
    int j;
    float per1=0;
    float per2=0;
    float per3=0;

    printf("count=%d\n",count);
    for(i=0;i<count;i++)
    {
        for(j=0;j<count-i-1;j++)
        {

            if(worker[j].total<worker[j+1].total)
            {
            printf("444\n");
            swapworker(&worker[j],&worker[j+1]);
            }

        }
    }
    for(i=0;i<count;i++)
    {
        t=worker[i].allowance+worker[i].basepay+worker[i].basepay+worker[i].dutywage;
        if(t>3000)
            per1++;
        else if(t>2000)
            per2++;
        else if(t>1000)
            per3++;
    }
    printf("工资最大值：%d\n",worker[0].total);
    printf("工资最小值：%d\n",worker[count-1].total);
    printf("工资中位数：%d\n",worker[count/2+1].total);
    printf("\n");
    printf("工资在3000元以上的员工：%0.2f%%\n",per1/count*100);
    printf("工资在2000-3000元的员工：%0.2f%%\n",per2/count*100);
    printf("工资在1000-2000元的员工：%0.2f%%\n",per3/count*100);

     for(i=0;i<count;i++)
    {

            printf("ID号   姓名  基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
            printf("%4s   ",worker[i].id);
            printf("%4s  ",worker[i].name);
            printf("%4d ",worker[i].basepay);
            printf("%10d ",worker[i].dutywage);
            printf("%8d ",worker[i].allowance);
            printf("%8d ",worker[i].healthcare);
            printf("%8d ",worker[i].acfund);
            printf("%8d",worker[i].total);
            printf("\n");
    }

}

void swapworker(Worker *p,Worker *q)
{
     Worker *temp;

     temp=(Worker *)malloc(sizeof(struct Work));

     temp->acfund=p->acfund;
     p->acfund=q->acfund;
     q->acfund=temp->acfund;

     strcpy(temp->name,p->name);
     strcpy(p->name,q->name);
     strcpy(q->name,temp->name);

     strcpy(temp->id,p->id);
     strcpy(p->id,q->id);
     strcpy(q->id,temp->id);

     temp->allowance=p->allowance;
     p->allowance=q->allowance;
     q->allowance=temp->allowance;

     temp->dutywage=p->dutywage;
     p->dutywage=q->dutywage;
     q->dutywage=temp->dutywage;

     temp->healthcare=p->healthcare;
     p->healthcare=q->healthcare;
     q->healthcare=temp->healthcare;

     temp->total=p->total;
     p->total=q->total;
     q->total=temp->total;

     temp->basepay=p->basepay;
     p->basepay=q->basepay;
     q->basepay=temp->basepay;
}
