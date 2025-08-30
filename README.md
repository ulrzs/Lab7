# Laboratory_7

Tasks:

->Following pointers

->Cube

->Sum & product

->Array search

->Array separation



# Memo: Pointers and Passing by Reference in C

## 1. What is a Pointer?

- A **pointer** is a variable that stores the **memory address** (location) of another variable.
- Syntax:
  ```c
  type *ptr; //or type* ptr;
  ```

### Example
```c
int x = 10;
int *p = &x;  // p stores the address of x

printf("x = %d\n", x);
printf("Address of x = %p\n", &x);
printf("p points to %p with value %d\n", p, *p);
```

- `&x` gives the address of `x`.
- `*p` (dereference) accesses the value stored at that address.

---

## 2. Passing by Value vs Passing by Reference

- In C, **function arguments are passed by value** (a copy is made).
- To modify the original variable, we must pass its **address** (pointer).
- To return with more than one variable from a function you have to provide memory space for these variables and pass them by pointer!
  Function call mechanism allows only one return VALUE (it is also a copy)!

### Example: Pass by Value
```c
void incrementValue(int n) { //there is a NEW variable when the function called, initialized by argument
    n++; //that copy increased
} //that copy earised

int main() {
    int a = 5;
    incrementValue(a); //5 passed, not a!
    printf("a = %d\n", a); // still 5, of course
}
```

### Example: Pass by Reference
```c
void incrementRef(int *n) { //location to an int is passed
    (*n)++; // modify the original meaining: go to the location, increase the value you found there!
}

int main() {
    int a = 5;
    incrementRef(&a); //now the location is passed, so the function reaches the variable!
    printf("a = %d\n", a); // now 6
}
```

---

## 3. Arrays as Pointers

- An **array name** in C is a pointer to its first element.
- Example:
  ```c
  int arr[3] = {10, 20, 30}; //here a memory part is allocated and filled with the numbers, arr is the safekeeper of the array

  printf("arr[0] = %d\n", arr[0]); //that converted to *(arr+0)
  printf("*(arr) = %d\n", *(arr));   // same as arr[0]
  printf("*(arr+1) = %d\n", *(arr+1)); // same as arr[1]
  ```

- The array name (`arr`) is essentially the address of the first element.

---

## 4. Passing Arrays to Functions

- When passing an array to a function, you actually pass a **pointer** to its first element.

### Example: Function with Array Parameter
```c
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    printArray(nums, 5); // nums acts like a pointer here
}
```

- Equivalent function signature:
  ```c
  void printArray(int *arr, int size); //Now we know arr is just a pointer, it does not know the array's size! we always need to pass it too!
  ```

- Both `int arr[]` and `int *arr` mean a pointer to an integer.

- So what is the difference between pointer and arrays? -arrays have memory allocated!
---

## 5. Modifying Arrays Inside Functions

- Since arrays are passed as pointers, functions can modify the original array.

```c
void doubleElements(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int nums[3] = {1, 2, 3};
    doubleElements(nums, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d ", nums[i]); // prints 2 4 6
    }
}
```

---

## 6. Key Points to Remember
- A pointer stores the address of another variable.
- Use `&` to get an address, and `*` to access the value at an address.
- C always passes arguments by value. To change the original, pass a pointer.
- Array names act as pointers to the first element.
- Passing an array to a function passes its address, not a copy.

---


