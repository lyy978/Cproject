#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[100]="E:\\CodeblockProject\\question2\\sale.txt";
    int Production[4][5];       //����
    int Sales[4][5] ;           //����
    int x=1;                      //�˵�ѡ��
    double price[5];            //����
    double cost[5];             //�ɱ�
    getSales(Sales);
    getProduction(Production);
    getCost(cost);
    getPrice(price);
    menu();
    while(x)
    {
        printf("������ѡ�");
        scanf("%d",&x);
        switch(x)
        {
         case 1:printSales (Sales,price);break;
         case 2:printProfit(Sales,price,cost);break;
         case 3:printSalesAndProfit(Sales,price,cost);break;
         case 4:sortProfit(Sales,price,cost);break;
         case 5:sortSales(Sales,price,cost);break;
         case 6:x=0; break;
         default: {
             printf("error!\n\n");}

       break;
        }
    }

    return 0;
}

void printProfit(int a[][5],double *price,double *cost)
{
     int i,j;

     printf("ÿ�ֲ�Ʒÿ�ܵ�����ֵ\n");
        for(i=0;i<4;i++)
            {
                printf("Week(%d) ",i+1);
            for(j=0;j<5;j++)
            {
             //   fscanf(fw,"%d",&a[i][j]);//��ȡ�ļ��е����ݣ������ո�ͻ���ֹͣ����
                printf("%.2lf\t",a[i][j]*price[j]-a[i][j]*cost[j]);//���ļ���ӡ������
            }
                printf("\n");
            }
}

void printSales(int a[][5],double *price)
{
     int i,j;

     printf("ÿ�ֲ�Ʒÿ�ܵ�����ֵ\n");
        for(i=0;i<4;i++)
            {
                printf("Week(%d) ",i+1);
            for(j=0;j<5;j++)
            {
             //   fscanf(fw,"%d",&a[i][j]);//��ȡ�ļ��е����ݣ������ո�ͻ���ֹͣ����
                printf("%.2lf\t",a[i][j]*price[j]);//���ļ���ӡ������
            }
                printf("\n");
            }
}


void printSalesAndProfit(int a[][5],double *price,double *cost)    //����ÿ�ֲ�Ʒһ����������ֵ������
{
     int i,j;    //i������ ��j������
     double c[5][2]={0};
     printf("ÿ�ֲ�Ʒһ����������ֵ������\n");
        for(j=0;j<5;j++)
            {
            for(i=0;i<4;i++)
            {
                c[j][0]=c[j][0]+a[i][j]*price[j];
            }
            }
        for(j=0;j<5;j++)
            {
            for(i=0;i<4;i++)
            {
                c[j][1]=c[j][1]+a[i][j]*price[j]-a[i][j]*cost[j];
            }
            }

            printf("            ����ֵ       ����ֵ\n");

        for(i=0;i<5;i++)
            {
                printf("Product(%d) ",i+1);
            for(j=0;j<2;j++)
            {
             //   fscanf(fw,"%d",&a[i][j]);//��ȡ�ļ��е����ݣ������ո�ͻ���ֹͣ����
                printf(" %.2lf\t",c[i][j]);//���ļ���ӡ������
            }
                printf("\n");
            }
}

void sortSales(int a[][5],double *price,double *cost)//��һ���������۶�Բ�Ʒ��������ð�ݣ�
{
    int i,j,temp;    //i������ ��j������
     double c[5]={0};
        for(j=0;j<5;j++)
            {
            for(i=0;i<4;i++)
            {
                c[j]=c[j]+a[i][j]*price[j];
            }
            }
        for(i=0;i<5;i++)
            {
                 for(j=0;j<5-i-1;j++)
                 {
                    if(c[j]>c[j+1])
                    {
                        temp=c[j];
                        c[j]=c[j+1];
                        c[j+1]=temp;
                    }
                 }
            }
          for(i=0;i<5;i++)
            {
                printf("%.2lf ",c[i]);
            }
            printf("\n");
}


void sortProfit(int a[][5],double *price,double *cost)//��һ��������������Բ�Ʒ��������ð�ݣ�
{
    int i,j,temp;    //i������ ��j������
     double c[5]={0};
        for(j=0;j<5;j++)
            {
            for(i=0;i<4;i++)
            {
                c[j]=c[j]+a[i][j]*price[j]-a[i][j]*cost[j];;
            }
            }
        for(i=0;i<5;i++)
            {
                 for(j=0;j<5-i-1;j++)
                 {
                    if(c[j]>c[j+1])
                    {
                        temp=c[j];
                        c[j]=c[j+1];
                        c[j+1]=temp;
                    }
                 }
            }
          for(i=0;i<5;i++)
            {
                printf("%.2lf ",c[i]);
            }
            printf("\n");

}



void menu()
{
    printf("*************�˵�*************\n\n");
    printf("(1)ÿ�ֲ�Ʒÿ�ܵ�����ֵ\n\n");
    printf("(2)ÿ�ܲ�Ʒÿ�ܵ�����ֵ\n\n");
    printf("(3)ÿ�ֲ�Ʒһ����������ֵ������\n\n");
    printf("(4)������������\n\n");
    printf("(5)���۶�����\n\n");
    printf("(6)�˳�\n\n");
}


//********��ȡ���۱�*********
void getSales(int a[][5])
{
    getNumInt("E:\\CodeblockProject\\question2\\sale.txt",a);
}

//********��ȡ������************
void getProduction(int a[][5])
{
     getNumInt("E:\\CodeblockProject\\question2\\production.txt",a);
}

//********��ȡ�ļ�*************
void getNumInt(char filename[100],int a[][5])
{
    FILE *fw=fopen(filename,"r");
        int i,j;
        for(i=0;i<4;i++)
            {
            for(j=0;j<5;j++)
            {
                fscanf(fw,"%d",&a[i][j]);//��ȡ�ļ��е����ݣ������ո�ͻ���ֹͣ����
            //    printf("%d\t",a[i][j]);//���ļ���ӡ������
            }
          //      printf("\n");
            }
        fclose(fw);
}



//**********��ȡ����************
void getPrice(double *a)
{
  getNumFloat("E:\\CodeblockProject\\question2\\price.txt",a);
}

//**********��ȡ�ɱ�***********
void getCost(double *a)
{
     getNumFloat("E:\\CodeblockProject\\question2\\cost.txt",a);
}


void getNumFloat(char filename[100],double *a)
{
    FILE *fw=fopen(filename,"r");
    int i,j;
    for(i=0;i<5;i++)
        {
            fscanf(fw,"%lf",&a[i]);
          //  printf("%lf ",a[i]);//���ļ���ӡ������

        } // printf("\n");
    fclose(fw);
}

