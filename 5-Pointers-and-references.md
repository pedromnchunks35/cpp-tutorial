# Pointers
```
int num = 10;
int *ptr = &num;
int value = *ptr; (to access the value)
```
- We can also point a function
```
int add(int a,int b){return a+b}
int (*funcptr)(int,int)=add;
funcptr(4,5);
```
# References
- It cannot be null
- Should always be referenced and after that not changed
```
int var = 10;
int& ref = var;
void swap(int& a,int& b){
int temp = a;
a=b;
b=temp;
}
```
# Memory model
## Stack Memory
- Automatic storage duration variables
  - Allocation and deallocation are done automatically
  - Its LIFO (Last In First Out)
  ```
  void func(){
    int x = 10; //? stored in the stack memory
  }
  ```
## Heap Memory
- For dynamic storage duration variables, such as objects created used with `new`
- We have control over the allocation and deallocation of heap memory using `new` and `delete`
- Heap memory is a part of memory that is larger but with slower access time
  ```
  void function(){
    int* p = new int;
    *p = 10;
    delete p;
  }
  ```
## Data Segment
- Composed of two parts:
  - initialized data
  - unitialized data
- `ininitialized data`
  - store global,static and constant variables with initial values
  ```
  int globalVar = 10; //global var
  static int staticVar = 10; //static local variables
  static int constVar = 10; // constant variables with value
  ```
- `uninitialized data`
  - uninitialized variables
  ```
  int globalVar;
  ```
## Code Segment
- Stores executable code (machine code) of the program
- Usually read-only
# Object Lifetime in C++
- There are four categories for a object lifetime:
  - `Static Storage Duration`
    - They exist for the entire run of the program
    - Allocated at the beginning of the program's run and deallocated when the program terminates
    - Global vars,static data members and static local variables fall into this category
    ```
    int global_var;
    class MyClass{
        static int static_var;
    }
    void myFunction(){
        static int local_var;
    }
    ```
  - `Thread Storage Duration`
    - Objects with thread storage duration exist for the lifetime of the thread they belong to
    - Created when a thread starts and destroyed when the thread exits
    - Thread storage duration can be specified using the `thread_local` keyword
    ```
     thread_local int my_var;
    ```
  - `Automatic Storage Duration`
    - Created at definition point and destroyed when exited
    - "local" or "stack" objects
    ```
     void myfunction(){
        int local_var;
     }
    ```
  - `Dyncamic Storage Duration`
    - Objects created at runtime using memory allocation function such as new or malloc
    - The lifetime is managed manually
    - We must destroy it using delete and free
    ```
     int *ptr = new int;
     delete ptr;
    ```
# Weak Pointer
- std::weak_ptr
- used with shared_ptr
- shared_ptr is a wrapper for a normal raw pointer
- Its mean to automate the life management of both
- With shared pointers basicly we only loose the reference if the scope its lost which does not happen with unique pointers
- With normal pointers it does not get deleted at all even loosing the scope to it
- A shared pointer is a strong reference because there is something that prevents it from beeing deleted
- We cant delete sharepoints
- Weak pointer puts a lock to the reference, making it impossible to delete in case is has a lock
- We can also use it to know how many places in the program are using it
```
std::weak_ptr<MyClass> weak;
std::shared_ptr<MyClass> shared = std::make_shared<MyClass>();
weak=shared;
if(auto sharedFromWeak = weak.lock()){
  //? Safely use the object
}
//? When shared goes out of scope and we are using it throught a weak, then it gets destroyed
```
# Shared Pointer
- A pointer that gots shared between multiple parts of the program
- The Object will be automatically deallocated only when the last shared_ptr that points to it its destroyed
- There is a counter that increments everytime the pointer is created
- When all decremented it gets destroyed
```
std::shared_ptr<MyClass> ptr2 = ptr1;
```
# Unique Pointer
- We cannot copy unique pointers
- Only one pointer is allowed to own a object at a time
```
std::unique_ptr<int> p1(new int(5));
std::unique_ptr<int> p2 = std::make_unique<int>(10);
```
# Raw Pointers and `new` and `delete` operators
- Low level pointers and serve to manually manage pointers
```
int* ptr = new int;
*ptr = 42;
```
```
int* ptr = new int;
*ptr=42;
delete ptr;
```
- We can also allocate and deallocate using arrays
```
int n = 10;
int* arr = new int[n];
for(int i=0;i<n;i++){
  arr[i]=i;
}
delete[] arr;
```
# Memory Leakage
- Occurs when we dont free memory when we are no longer needing things
- This results in poor performance and crashes
- This happens when using raw pointers