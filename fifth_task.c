/* Task description:
Write a function that receives an integer array, and separates the even and the odd elements of the array.
The even elements are put into a second array, and the odd ones are put into a third array; both of them are function arguments, and are assumed to be large enough to store all even and odd elements.

Write a function to print the integer array received as a function parameter!

Write a main function that separates the even and odd elements of an array and prints them to the screen!

*/


#include <stdio.h>

void separator(int* Arr, int size, int* even, int* odd, int* sizes){
  sizes[0]=0;sizes[1]=0;
  for(int i=0;i<size;i++){
    if(Arr[i]%2==0){
      even[sizes[0]]=Arr[i];
      sizes[0]++;
    }
    else{
      odd[sizes[1]]=Arr[i];
      sizes[1]++;
    }
  }
}

void arr_print(int* Arr, int size){
  for(int *c=Arr;c<Arr+size;c++){
    printf("%d ",*c);
  }
}

int main(){
  int numbers[6];
  printf("Enter 6 numbers! \n");
  for(int i=0;i<6;i++){
    scanf("%d",&numbers[i]);
  }

  printf("\nOG array: ");
  arr_print(numbers,6);

  int evens[6], odds[6], even_odd_sizes[2];
  separator(numbers,6,evens,odds,even_odd_sizes);

  printf("\nEven numbers: ");
  arr_print(evens, even_odd_sizes[0]);

  printf("\nOdd numbers: ");
  arr_print(odds, even_odd_sizes[1]);

  return 0;
}
