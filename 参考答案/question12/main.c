#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//函数声明
void sortCards(int *, int);
void showCards(int *, int);
void changeCard(int);
int getOneCard();

int Cards[55] = { 0 };//用于记录每张牌是否被用过( 丢弃cards[0]
int main() //rand()%m+1,产生0- m-1的随机数
{
    int i, iCount = 0;
    int Player_A[18] = { NULL };
    int Player_B[18] = { NULL };
    int Player_C[18] = { NULL };
    int countA=0;//统计A玩家的主牌数
    int countB=0;//统计B玩家的主牌数
    int countC=0;
    int max=0;
    int Ground[4] = { NULL };//Abandon all [0]

    for (i = 1; i <= 3; i++)//获取底牌
    {
        Ground[i] = getOneCard();
    }
    sortCards(Ground, 4);//按牌大小排序
    for (i = 1; i <= 17; i++)//为三个玩家分别发牌
    {
        Player_A[i] = getOneCard();
        Player_B[i] = getOneCard();
        Player_C[i] = getOneCard();
    }

    puts("Player's Cards");
        sortCards(Player_A, 18);
        sortCards(Player_B, 18);
        sortCards(Player_C, 18);
    puts("Player_A:");//打印A的牌
        showCards(Player_A, 17);
    puts("\n\nPlayer_B:");//打印B的牌
        showCards(Player_B, 17);
    puts("\n\nPlayer_C:");//打印C的牌
        showCards(Player_C, 17);
    puts("\n\nCards on the Ground:");
        showCards(Ground, 3);//打印底牌
    puts("");

    countA=isLandlord(Player_A, 17);
    countB=isLandlord(Player_B, 17);
    countC=isLandlord(Player_C, 17);
  //  printf("%d\n",countA);
  //  printf("%d\n",countB);
  //  printf("%d\n",countC);
    countA;
    if(countA>=countB&&countA>=countC)
        printf("玩家A是地主\n");
    else if(countB>=countA&&countB>=countC)
        printf("玩家B是地主\n");
    else if(countC>=countB&&countC>=countA)
        printf("玩家C是地主\n");

    system("pause");
    return 0;
}
int getOneCard()//通过随机数取得一张没用过的牌
{
    int iRandNum;
    srand(time(0));//取时间随机数
    iRandNum = rand() % 54 + 1;
    while (Cards[iRandNum] == 1)//被用过的牌会重新取随机数
    {
        iRandNum = rand() % 54 + 1;
    }
    Cards[iRandNum] = 1;
    return iRandNum;
}
void showCards(int *Player, int Count)//打印玩家的牌
{
    int i;
    for (i = 1; i <= Count; i++)
    {
        if (Player[i] == 53)
        {
            printf(" 小王", Player[i]);
        }
        else if (Player[i] == 54)
        {
            printf(" 大王", Player[i]);
        }
        else if (Player[i] % 4 == 0)
        {
            printf(" 黑");
            changeCard(Player[i]);
        }
        else if ((Player[i] + 1) % 4 == 0)
        {
            printf(" 方");
            changeCard(Player[i]);
        }
        else if (Player[i] % 2 == 0)
        {
            printf(" 红");
            changeCard(Player[i]);
        }
        else
        {
            printf(" 梅");
            changeCard(Player[i]);
        }
    }
}
void changeCard(int Card)//将数字和纸牌进行对换
{
    Card /= 4.001;
    switch (Card)
    {
    case 0:printf("3 "); break;
    case 1:printf("4 "); break;
    case 2:printf("5 "); break;
    case 3:printf("6 "); break;
    case 4:printf("7 "); break;
    case 5:printf("8 "); break;
    case 6:printf("9 "); break;;
    case 7:printf("10 "); break;
    case 8:printf("J"); break;
    case 9:printf("Q"); break;
    case 10:printf("K"); break;
    case 11:printf("A"); break;
    case 12:printf("2"); break;
    }
}
void sortCards(int *Nums, int Length)//排序手中的牌
{
    int i, j, iTemp;
    for (i = 1; i <= Length - 1; i++)
    {
        for (j = 1; j <= Length - 2; j++)
        {
            if (Nums[j]>Nums[j + 1])
            {
                iTemp = Nums[j];
                Nums[j] = Nums[j + 1];
                Nums[j + 1] = iTemp;
            }
        }
    }
}
int isLandlord(int *Player, int Count)//判断是否是地主
{
//    printf("A ");
    int i,j;
    int count=0;
    int num=0;
    for (i = 1; i <= Count; i++)
    {
        if (Player[i] == 53)    //小王
        {
           count++;
     //      printf("小王 ");
        }
        else if (Player[i] == 54)   //大王
        {
            count++;
       //     printf("大王 ");
        }
        else if (((Player[i]-1)/4) == 12)   //2
        {
            count++;
      //      printf("2 ");
        }
    }
    for(j=0;j<12;j++)
    {
        for(i = 1; i <= Count; i++)
        {
            if(((Player[i]-1) /4)==j)
                num++;
        }
        if(num==4)
            count+=4;
        num=0;
    }
   // printf("\n");
    return count;
}

