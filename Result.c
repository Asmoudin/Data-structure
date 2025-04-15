#include <stdio.h>
int main(){
int a, b, c, d, e;
int total;
float average;
 printf (" Enter the First subject:");
scanf("%d",&a);
while(a<0 || a> 100){
printf(" Enter a Valid number between 0 aqnd 100:");
scanf("%d", &a);
}
 printf (" Enter the second subject:");
scanf("%d",&a);
while(a<0 || a> 100){
printf(" Enter a Valid number between 0 aqnd 100:");
scanf("%d", &a);
}
 printf (" Enter the Third subject:");
scanf("%d",&a);
while(a<0 || a> 100){
printf(" Enter a Valid number between 0 aqnd 100:");
scanf("%d", &a);
}
 printf (" Enter the Fourth subject:");
scanf("%d",&a);
while(a<0 || a> 100){
printf(" Enter a Valid number between 0 aqnd 100:");
scanf("%d", &a);
}
 printf (" Enter the Fifth subject:");
scanf("%d",&a);
while(a<0 || a> 100){
printf(" Enter a Valid number between 0 aqnd 100:");
scanf("%d", &a);
}
 total= a+b+c+d+e;
average= total/5;
printf("the total of the five subject is:%d\n", total);
printf("the average of the five subject is : %2.f\n", average);
return 0;
}