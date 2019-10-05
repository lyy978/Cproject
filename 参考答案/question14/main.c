#include <stdio.h>
#include <stdlib.h>

typedef struct Word{

    char word[20];
    int count;
    struct Word *next;
}words;

int main()
{
    words *text;
    text=(words *)malloc(sizeof(struct Word));//头结点 不存数据
    text->next=NULL;
    getText(text);
    del(text);
    save(text);
    return 0;
}

//***********读取文本信息************
void getText(words *text)
{
    int i=0;
    FILE *fp;
    words *p;

    fp = fopen("E:\\CodeblockProject\\question14\\corpus.txt","r");
   // text=(words *)malloc(sizeof(struct Word));
   // text->next=NULL;
    if(fp == NULL)
    {
         printf("Open filefailure!");
         exit(1);
    }
    else
    {
         while(!feof(fp))
        {
            p=(words *)malloc(sizeof(struct Word));
            fscanf(fp,"%s", p->word);
            p->count=1;
            p->next=text->next;
            text->next=p;
        }
    }
    fclose(fp);
    p=text->next;
    while(p)
        {
            printf("%s ",p->word);//这两行为按行读取所有数据
            printf("%d\n", p->count);
            p=p->next;
        }
}

//******删除重复节点********
void del(words *text)
{
    printf("删除的单词:\n");
    words *p;
    words *q;
    words *s;    //q节点的前一个节点
    words *m;
    p=(words *)malloc(sizeof(struct Word));
    q=(words *)malloc(sizeof(struct Word));
    s=(words *)malloc(sizeof(struct Word));
    m=(words *)malloc(sizeof(struct Word));
    printf("%d",text->next->count);
    p=text->next;

    while(p)  //如果p，q单词相同，那么删除q，p->count++
    {
        s=p;
        q=p->next;
        while(q)
        {
            if(strcmp(p->word,q->word)==0)
                {
                    p->count++;
                    s->next=q->next;
                }
            s=q;
            q=q->next;
        }
        p=p->next;
    }
    s=text;
    m=s->next;
    while(m)
    {
        if(m->count<2)
            {
                printf("%s ",m->word);
                printf("%d\n",m->count);
                s->next=m->next;
                m=s->next;
            }
        else{
             s=m;
             m=m->next;
        }

    }
    printf("剩下的节点：****\n");
    p=text->next;
     while(p)  //如果p，q单词相同，那么删除q，p->count++
    {
        printf("%s ",p->word);
        printf("%d\n",p->count);
        p=p->next;
    }
}

//****************保存删除后的文本**********
void save(words *text)
{
    FILE *fp;
    fp = fopen("E:\\CodeblockProject\\question14\\filter.txt","a+");
    words *p;
    p=(words *)malloc(sizeof(struct Word));
    p=text->next;
    while(p)
    {
            fprintf(fp, "%s ", p->word);
            //fscanf(fp,"%d",p->count);
            p=p->next;

    }
    fclose(fp);
}

