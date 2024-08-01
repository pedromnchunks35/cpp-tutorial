# Info
- This is a way to organize your code to make it mroe maintainable,efficient and easier to understand
# Namespaces
- Provide a named scoped for different identifiers you create like functions,classes and variables
- Help avoid name clashes and make code more modular
```
namespace MyNamespace{
    int aFunction(){

    }
}
//? To use the function
MyNamespace::aFunction();
```
# Include Guards
- To make sure that we only include a library once
```
#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H
//? THE CODE
#endif
```
# Header and Source Files
- Using headers and cpp files to struct the code out
- header file (MyClass.h)
    ```
    #ifndef MY_CLASS_H
    #define MY_CLASS_H
    class MyClass{
        public:
            MyClass();
            int myMethod();
    }
    #endif 
    ```
- cpp file (MyClass.cpp)
  ```
  #include "Myclass.h"
  MyClass::MyClass(){

  }
  int MyClass::mymethod(){

  }
  ```
# Scope
- The visibility and accessibility of variables,functions,classes and other identifiers in a C++ program
- `Global Scope`
  - Variables that are declared outside of a function or class
  ```
  #include <iostream>
  int globalVar;
  int main(){
    ...
  }
  ```
- `Local Scope`
  - Identifiers declared within a function or a block have local scope
  ```
    int main(){
        int lul=3;
    }
  ```
- `Namespace Scope`
  - Named scope that groups related identifiers together
  ```
    namespace lul{
        int lolitos=42;
    }
    lul::lolitos; //? to access it
  ```
- `Class Scope`
  - The identifiers that are retained within a class
  - We can access those using ::,.,->
    ```
    class MyClass{
        public:
            static int staticMember;
            int nonStatic
            MyClass(int value):nonStaticMember(value){}
    }
    ```
    ```
    int MyClass::staticMember=7;
    MyClass obj(10);
    MyClass::staticMember
    obj.nonStaticMember
    ```
# Namespace
```
namespace animals {
    std::string dog = "Bobby";
    std::string cat = "Lilly";
}
```
- We can also make nested namespaces
```
namespace outer{
    int x = 10;
    namespace inner{
        int y = 20;
    }
}
```
- We can "remove" the obligation to identify the scope inside of a scope using `using`
```
namespace animals{
    std::string dog = "Bobby";
    std::string cat = "fluffly";
}
int main(){
    using animals::dog;
    std::cout << dog << std::endl;
}
int main(){
    using animals;
    std::cout<<dog<< std::endl;
    std::cout<<cat<< std::endl;
}
```
# Forward declaration
- Declaring something without actually defining it in the code
```
class ClassA;
```
```
void do_something(Class A& obj);
class ClassB{
    public:
        void another_func(ClassA& obj);
}
```
- declaring something but only using it later
```
int add(int a,int b);
int main(){
    int result = add(2,3);
}
int add(int a,int b){
    return a+b;
}
```
# Code Spliting
- Breaking code into more smaller, more manageable files or modules
- To achieve this we create separated compilation ,header files and source files
## Header files (.h or .hpp)
- Work like a interface and it is used when we need the same code for multiple source files
```
#ifndef EXAMPLE_H
#define EXAMPLE_H
class Example{
    public:
        void printMessage();
};
#endif
```
## Source Files (.cpp)
- To implement the actuall functionality
# Separate compilation
- We can compile files independly so it makes it faster to build because we can compile the only file that we changed