#include<stdio.h>
#define PI 3.14
void main(){
int r,a,c,d;
printf( "enter radius");

scanf("%d",&r);
a=PI*r*r;
c=2*PI*r;
d=2*r;
printf(" area is=%d", a);
printf("\n circumference is=%d", c);
printf(" \n diameter is=%d", d);
}