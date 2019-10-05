#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Work
{
    char id[20];    //����
    char name[20];  //Ա������
    int  basepay;   //��������
    int dutywage;   //ְ����
    int allowance;  //����
    int healthcare; //ҽ�Ʊ���
    int acfund;     //������
    int total;      //�ܹ���
}Worker;
int count=0;        //Ա����

int main()
{
    int x;
    Worker worker[100];
    getWorkerInfo(worker);
    while(1)
    {
        menu();  //�˵�
        printf("������ѡ�");
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

//********�˵�****************
void menu()
{
    printf("*******�˵�********\n");
    printf("(1)�����¼\n");
    printf("(2)��ʾ��¼\n");
    printf("(3)�޸ļ�¼\n");
    printf("(4)ͳ��\n");
    printf("(5)�˳�\n");
}


//*********��ȡְ����Ϣ********
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
        printf("ID��   ����  ��������  ְ����  ����  ҽ�Ʊ���  ������  �ܹ���\n");
         while(!feof(fp))
        {
                fscanf(fp, "%s", &worker[i].id);
                printf("%4s   ",worker[i].id);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%s", &worker[i].name);
                printf("%4s   ",worker[i].name);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%d", &worker[i].basepay);
                printf("%4d",worker[i].basepay);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%d", &worker[i].dutywage);
                printf("%10d",worker[i].dutywage);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%d", &worker[i].allowance);
                printf("%8d",worker[i].allowance);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%d",&worker[i].healthcare);
                printf("%8d",worker[i].healthcare);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%d", &worker[i].acfund);
                printf("%8d",worker[i].acfund);//������Ϊ���ж�ȡ��������

                fscanf(fp, "%d", &worker[i].total);
                printf("%8d",worker[i].total);//������Ϊ���ж�ȡ��������
                printf("\n");
                i++;
                count++;

        }
    }
    fclose(fp);

}

//*********��ʾְ����Ϣ********
void showinfo(Worker *worker)
{
    int i=0;
    int x;
    char id[20];    //����
    char name[20];  //Ա������

    printf("(1)����������\n");
    printf("(2)�����Ų���\n");
    printf("������ѡ�");
    scanf("%d",&x);

    switch(x)
    {
        case 1:{
                printf("������ְ��������");
                fflush(stdin);
                gets(name);
                for(i=0;i<count;i++)
                {
                    if(strcmp(worker[i].name,name)==0)
                    {
                        printf("ID��   ����  ��������  ְ����  ����  ҽ�Ʊ���  ������  �ܹ���\n");
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
                    printf("������ְ�����ţ�");
                    fflush(stdin);
                    gets(id);
                    for(i=0;i<count;i++)
                    {
                        if(strcmp(worker[i].id,id)==0)
                        {
                            printf("ID��   ����  ��������  ְ����  ����  ҽ�Ʊ���  ������  �ܹ���\n");
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
        printf("�����ڸ�Ա����Ϣ��\n");


}

//*********¼��ְ����Ϣ*********
void writeinfo(Worker *worker)
{
    int i=0;
    int n;
    FILE *fp;
    fp = fopen("E:\\CodeblockProject\\question6\\workerinfo.txt","a+");
    printf("��������Ҫ¼���Ա����Ϣ������");
    scanf("%d",&n);
    for(i=count;i<count+n;i++)
    {
        printf("i=%d\n",i);
        printf("������ְ�����ţ�");
        fflush(stdin);
        gets(worker[i].id);
        printf("������ְ��������");
        fflush(stdin);
        gets(worker[i].name);
        printf("������������ʣ�");
        scanf("%d",&worker[i].basepay);
        printf("������ְ���ʣ�");
        scanf("%d",&worker[i].dutywage);
        printf("�����������");
        scanf("%d",&worker[i].allowance);
        printf("������ҽ�Ʊ��գ�");
        scanf("%d",&worker[i].healthcare);
        printf("�����빫����");
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

//****************�޸�ְ����Ϣ**************
void changeinfo(Worker *worker)
{
    int i=0;
    int x;
    char id[20];    //����
    char name[20];  //Ա������
    int c;
    FILE *fp;
    fp = fopen("E:\\CodeblockProject\\question6\\workerinfo.txt","w");
    printf("(1)�������޸�\n");
    printf("(2)�������޸�\n");
    printf("������ѡ�");
    scanf("%d",&x);
    switch(x)
    {
        case 1:{
                printf("������ְ��������");
                fflush(stdin);
                gets(name);
                for(i=0;i<count;i++)
                {
                    if(strcmp(worker[i].name,name)==0)
                    {
                        printf("ID��   ����  ��������  ְ����  ����  ҽ�Ʊ���  ������  �ܹ���\n");
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

                printf("(1)��������\n");
                printf("(2)ְ����\n");
                printf("(3)����\n");
                printf("(4)ҽ�Ʊ���\n");
                printf("(5)������\n");
                printf("�������޸���Ŀ��");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:{
                        printf("�������");
                        scanf("%d",&worker[i].basepay);
                        printf("**xiugai\n");
                    };break;
                    case 2:{
                        printf("�������");
                        scanf("%d",&worker[i].dutywage);
                        }
                        ;break;
                    case 3:{
                            printf("�������");
                            scanf("%d",&worker[i].allowance);
                    };break;
                    case 4:{
                        printf("�������");
                         scanf("%d",&worker[i].healthcare);
                    };break;
                    case 5:
                        {
                        printf("�������");
                        scanf("%d",&worker[i].acfund);
                        };
                        break;
                }
                worker[i].total=worker[i].basepay-worker[i].acfund+worker[i].allowance+worker[i].dutywage-worker[i].healthcare;

        };break;
        case 2:{
                    printf("������ְ�����ţ�");
                    fflush(stdin);
                    gets(id);
                    for(i=0;i<count;i++)
                    {
                        if(strcmp(worker[i].id,id)==0)
                        {
                            printf("ID��   ����  ��������  ְ����  ����  ҽ�Ʊ���  ������  �ܹ���\n");
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

                printf("�������޸���Ŀ��");
                printf("(1)��������\n");
                printf("(2)ְ����\n");
                printf("(3)����\n");
                printf("(4)ҽ�Ʊ���\n");
                printf("(5)������\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:{
                        printf("�������");
                        scanf("%d",&worker[i].basepay);
                    };break;
                    case 2:{
                        printf("�������");
                        scanf("%d",&worker[i].dutywage);
                        }
                        ;break;
                    case 3:{
                            printf("�������");
                            scanf("%d",&worker[i].allowance);
                    };break;
                    case 4:{
                        printf("�������");
                         scanf("%d",&worker[i].healthcare);
                    };break;
                    case 5:
                        {
                        printf("�������");
                        scanf("%d",&worker[i].acfund);
                        };
                        break;
                }
                worker[i].total=worker[i].basepay-worker[i].acfund+worker[i].allowance+worker[i].dutywage-worker[i].healthcare;

        }
    }
     if(i==count)
        printf("�����ڸ�Ա����Ϣ��\n");

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


//********ͳ��************
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
    printf("�������ֵ��%d\n",worker[0].total);
    printf("������Сֵ��%d\n",worker[count-1].total);
    printf("������λ����%d\n",worker[count/2+1].total);
    printf("\n");
    printf("������3000Ԫ���ϵ�Ա����%0.2f%%\n",per1/count*100);
    printf("������2000-3000Ԫ��Ա����%0.2f%%\n",per2/count*100);
    printf("������1000-2000Ԫ��Ա����%0.2f%%\n",per3/count*100);

     for(i=0;i<count;i++)
    {

            printf("ID��   ����  ��������  ְ����  ����  ҽ�Ʊ���  ������  �ܹ���\n");
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
