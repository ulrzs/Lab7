/* Task description:
Write a function that receives two numbers, and return !!both!! their sum and their product!
one function has to do that!
*/

#include <stdio.h>

void sum_prod(double a, double b, double *ps,double *pp){
    *ps=a+b;
    *pp=a*b;
}

int main(void) {
   double sum;
   double prod;
   double *psum=&sum;
   double *pprod=&prod;
   double a,b;
   printf("a b: ");
   scanf("%lf %lf",&a,&b);
   sum_prod(a,b,psum,pprod);
   printf("Sum: %g, prod: %g",sum,prod);

    return 0;
}
