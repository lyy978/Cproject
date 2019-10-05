#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[100]="E:\\CodeblockProject\\question2\\sale.txt";
    int Production[4][5];       //产量
    int Sales[4][5] ;           //销量
    int x=1;                      //菜单选择
    double price[5];            //单价
    double cost[5];             //成本
    getSales(Sales);
    getProduction(Production);
    getCost(cost);
    getPrice(price);
    menu();
    while(x)
    {
        printf("请输入选项：");
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

     printf("每种产品每周的利润值\n");
        for(i=0;i<4;i++)
            {
                printf("Week(%d) ",i+1);
            for(j=0;j<5;j++)
            {
             //   fscanf(fw,"%d",&a[i][j]);//读取文件中的数据，遇到空格和换行停止读。
                printf("%.2lf\t",a[i][j]*price[j]-a[i][j]*cost[j]);//将文件打印出来。
            }
                printf("\n");
            }
}

void printSales(int a[][5],double *price)
{
     int i,j;

     printf("每种产品每周的销售值\n");
        for(i=0;i<4;i++)
            {
                printf("Week(%d) ",i+1);
            for(j=0;j<5;j++)
            {
             //   fscanf(fw,"%d",&a[i][j]);//读取文件中的数据，遇到空格和换行停止读。
                printf("%.2lf\t",a[i][j]*price[j]);//将文件打印出来。
            }
                printf("\n");
            }
}


void printSalesAndProfit(int a[][5],double *price,double *cost)    //计算每种产品一个月内销售值和利润
{
     int i,j;    //i是行数 ，j是列数
     double c[5][2]={0};
     printf("每种产品一个月内销售值和利润\n");
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

            printf("            销售值       利润值\n");

        for(i=0;i<5;i++)
            {
                printf("Product(%d) ",i+1);
            for(j=0;j<2;j++)
            {
             //   fscanf(fw,"%d",&a[i][j]);//读取文件中的数据，遇到空格和换行停止读。
                printf(" %.2lf\t",c[i][j]);//将文件打印出来。
            }
                printf("\n");
            }
}

void sortSales(int a[][5],double *price,double *cost)//按一个月内销售额对产品进行排序（冒泡）
{
    int i,j,temp;    //i是行数 ，j是列数
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


void sortProfit(int a[][5],double *price,double *cost)//按一个月内销售利润对产品进行排序（冒泡）
{
    int i,j,temp;    //i是行数 ，j是列数
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
    printf("*************菜单*************\n\n");
    printf("(1)每种产品每周的销售值\n\n");
    printf("(2)每周产品每周的利润值\n\n");
    printf("(3)每种产品一个月内销售值和利润\n\n");
    printf("(4)销售利润排名\n\n");
    printf("(5)销售额排名\n\n");
    printf("(6)退出\n\n");
}


//********读取销售表*********
void getSales(int a[][5])
{
    getNumInt("E:\\CodeblockProject\\question2\\sale.txt",a);
}

//********读取生产表************
void getProduction(int a[][5])
{
     getNumInt("E:\\CodeblockProject\\question2\\production.txt",a);
}

//********读取文件*************
void getNumInt(char filename[100],int a[][5])
{
    FILE *fw=fopen(filename,"r");
        int i,j;
        for(i=0;i<4;i++)
            {
            for(j=0;j<5;j++)
            {
                fscanf(fw,"%d",&a[i][j]);//读取文件中的数据，遇到空格和换行停止读。
            //    printf("%d\t",a[i][j]);//将文件打印出来。
            }
          //      printf("\n");
            }
        fclose(fw);
}



//**********读取单价************
void getPrice(double *a)
{
  getNumFloat("E:\\CodeblockProject\\question2\\price.txt",a);
}

//**********读取成本***********
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
          //  printf("%lf ",a[i]);//将文件打印出来。

        } // printf("\n");
    fclose(fw);
}

