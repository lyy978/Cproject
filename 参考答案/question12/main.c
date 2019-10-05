#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��������
void sortCards(int *, int);
void showCards(int *, int);
void changeCard(int);
int getOneCard();

int Cards[55] = { 0 };//���ڼ�¼ÿ�����Ƿ��ù�( ����cards[0]
int main() //rand()%m+1,����0- m-1�������
{
    int i, iCount = 0;
    int Player_A[18] = { NULL };
    int Player_B[18] = { NULL };
    int Player_C[18] = { NULL };
    int countA=0;//ͳ��A��ҵ�������
    int countB=0;//ͳ��B��ҵ�������
    int countC=0;
    int max=0;
    int Ground[4] = { NULL };//Abandon all [0]

    for (i = 1; i <= 3; i++)//��ȡ����
    {
        Ground[i] = getOneCard();
    }
    sortCards(Ground, 4);//���ƴ�С����
    for (i = 1; i <= 17; i++)//Ϊ������ҷֱ���
    {
        Player_A[i] = getOneCard();
        Player_B[i] = getOneCard();
        Player_C[i] = getOneCard();
    }

    puts("Player's Cards");
        sortCards(Player_A, 18);
        sortCards(Player_B, 18);
        sortCards(Player_C, 18);
    puts("Player_A:");//��ӡA����
        showCards(Player_A, 17);
    puts("\n\nPlayer_B:");//��ӡB����
        showCards(Player_B, 17);
    puts("\n\nPlayer_C:");//��ӡC����
        showCards(Player_C, 17);
    puts("\n\nCards on the Ground:");
        showCards(Ground, 3);//��ӡ����
    puts("");

    countA=isLandlord(Player_A, 17);
    countB=isLandlord(Player_B, 17);
    countC=isLandlord(Player_C, 17);
  //  printf("%d\n",countA);
  //  printf("%d\n",countB);
  //  printf("%d\n",countC);
    countA;
    if(countA>=countB&&countA>=countC)
        printf("���A�ǵ���\n");
    else if(countB>=countA&&countB>=countC)
        printf("���B�ǵ���\n");
    else if(countC>=countB&&countC>=countA)
        printf("���C�ǵ���\n");

    system("pause");
    return 0;
}
int getOneCard()//ͨ�������ȡ��һ��û�ù�����
{
    int iRandNum;
    srand(time(0));//ȡʱ�������
    iRandNum = rand() % 54 + 1;
    while (Cards[iRandNum] == 1)//���ù����ƻ�����ȡ�����
    {
        iRandNum = rand() % 54 + 1;
    }
    Cards[iRandNum] = 1;
    return iRandNum;
}
void showCards(int *Player, int Count)//��ӡ��ҵ���
{
    int i;
    for (i = 1; i <= Count; i++)
    {
        if (Player[i] == 53)
        {
            printf(" С��", Player[i]);
        }
        else if (Player[i] == 54)
        {
            printf(" ����", Player[i]);
        }
        else if (Player[i] % 4 == 0)
        {
            printf(" ��");
            changeCard(Player[i]);
        }
        else if ((Player[i] + 1) % 4 == 0)
        {
            printf(" ��");
            changeCard(Player[i]);
        }
        else if (Player[i] % 2 == 0)
        {
            printf(" ��");
            changeCard(Player[i]);
        }
        else
        {
            printf(" ÷");
            changeCard(Player[i]);
        }
    }
}
void changeCard(int Card)//�����ֺ�ֽ�ƽ��жԻ�
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
void sortCards(int *Nums, int Length)//�������е���
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
int isLandlord(int *Player, int Count)//�ж��Ƿ��ǵ���
{
//    printf("A ");
    int i,j;
    int count=0;
    int num=0;
    for (i = 1; i <= Count; i++)
    {
        if (Player[i] == 53)    //С��
        {
           count++;
     //      printf("С�� ");
        }
        else if (Player[i] == 54)   //����
        {
            count++;
       //     printf("���� ");
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

