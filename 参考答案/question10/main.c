#include <stdio.h>
#include <math.h>

#define ABS_FLOAT_0  0.0001

typedef struct Point_float
{
    float x;
    float y;
}point_float;

/*
 * 计算三角形面积
 */
float GetTriangleSquar(point_float pf1, point_float pf2, point_float pf3)
{
    float s;

 //   printf("%f\n\n",pf1.x);
    s=pf1.x*pf2.y-pf1.x*pf3.y+pf2.x*pf3.y-pf2.x*pf1.y+pf3.x*pf1.y-pf2.x*pf2.y;//S=(x1y2-x1y3+x2y3-x2y1+x3y1-x2y2)
    return fabs(s/2);
}

/*
 * 计算三角形面积
 */
float solve(point_float a,point_float b,point_float c)
{
    point_float A,B;
    A.x = b.x-a.x;
    A.y = b.y-a.y;
    B.x = c.x-a.x;
    B.y = c.y-a.y;
    return fabs(A.x*B.y-B.x*A.y)/2.0;
}


/*
 * 判断给定一点是否在三角形内或边上
*/
int IsInTriangle(point_float A, point_float B, point_float C, point_float D)
{
    float SABC, SADB, SBDC, SADC, Sum;
//    SABC = GetTriangleSquar(A, B, C);
//    SADB = GetTriangleSquar(A, D, B);
//    SBDC = GetTriangleSquar(B, D, C);
//    SADC = GetTriangleSquar(A, D, C);

    SABC = solve(A, B, C);
    SADB = solve(A, D, B);
    SBDC = solve(B, D, C);
    SADC = solve(A, D, C);
//    printf("%f\n",SABC);
//    printf("%f\n",SADB);
//    printf("%f\n",SBDC);
//    printf("%f\n",SADC);

    Sum = SADB + SBDC + SADC;

    if ((-ABS_FLOAT_0 < (SABC - Sum)) && ((SABC - Sum) < ABS_FLOAT_0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    point_float A, B, C, D;
    float px;
    float py;
    float pr;
    printf("请按逆时针顺序输入三点坐标：\n");
    printf("请输入A点坐标\n");
    scanf("%f %f",&A.x,&A.y);
    printf("请输入B点坐标\n");
    scanf("%f %f",&B.x,&B.y);
    printf("请输入C点坐标\n");
    scanf("%f %f",&C.x,&C.y);
    printf("请输入D点坐标\n");
    scanf("%f %f",&D.x,&D.y);

    if (IsInTriangle(A, B, C, D))
    {
        printf("D is in ABC\n");
    }
    else
    {
        printf("D is not in ABC\n");
    }
    return 0;
}


