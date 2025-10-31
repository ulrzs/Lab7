/* Task description:
1.  Create a function that receives an array of integers as parameter, and one integer value that has to be found in the array! 
    Return the index of the element if the value was found, or return −1, if it was not. (If the value occurs multiple times in the array, it is up to you which index you return.)
    Print the array with the indices to check the result of your function. Print the index returned by the function, or the text „not found”!

2.  Modify the function (and the program) to return the memory address, instead of the index of the found element! 
    What should be returned when the value was not found in the array? Using the modified function how can you determine the index of the found element (without another search)?
    Modify the loops in the program to use pointers instead of indices. 

*/


#include <stdio.h>

// int find_int(int *Arr,int size, int n){
//   for(int i=0;i<size;i++){
//     if(Arr[i]==n){
//       return i;
//     }
//   }
//   return -1;
// }

// int* find_int(int *Arr,int size, int n){
//   for(int i=0;i<size;i++){
//     if(Arr[i]==n){
//       return &Arr[i];
//     }
//   }
//   return 0;
// }

int* find_int(int *Arr,int size, int n){
  for(int *current=Arr;current<(Arr+size);current++){
    if(*current==n){
      return current;
    }
  }
  return 0;
}

int main(){
  int numbers[5];
  printf("Enter 5 numbers (with a space separating them)!\n");
  // scanf("%d %d %d %d %d",&numbers[0],&numbers[1],&numbers[2],&numbers[3],&numbers[4]);
  for(int *c=numbers;c<numbers+5;c++){
    scanf("%d",c);
  }
  // for(int i=0;i<5;i++){
  //   printf("numbers[%d]: %d\n",i,numbers[i]);
  // }
  for(int* c=numbers;c<numbers+5;c++){
    printf("numbers[%ld]: %d\n",c-numbers,*c);
  }
  int n;
  printf("\nNumber to find: ");
  scanf("%d",&n);
  // int r=find_int(numbers,5,n);

  // if(r==-1){
  //   printf("Not found");
  // }
  // else printf("Number found at index %d",r);

  if(!(find_int(numbers,5,n))){
    printf("Not found");
  }
  else {
    int *indp=find_int(numbers,5,n);
    int ind=indp-numbers;
    printf("Number found at index %d",ind);
  }
  
  return 0;
}
