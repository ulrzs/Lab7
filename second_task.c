/* Task description:
Write a function that receives the length of an edge of a cube as a parameter. The function should return the volume and the surface area of the cube in two further parameters passed by address. 
(The return type of the function is void.) Call this function from the main to calculate the volume and the surface area of a cube of 2.7 edge length, then print the results in main!

*/
void cube(double edge, double *parea, double *pvolume){
    *parea=6*edge*edge;
    *pvolume=edge*edge*edge;
}

#include <stdio.h>

int main(){
    
    double area;
    double volume;
    double* parea=&area;
    double* pvolume=&volume;
    cube(2.7,parea,pvolume);
    printf("Area: %lf, volume: %lf",area,volume);

return 0;
}
