# Data types (the different ones otherwise im cooked)
- Pointers
```
int num = 42;
int *pNum = &num;
```
- References
```
int num = 42;
int& numRef = num;
```
# User defined data types
- Structures
```
struct Person{
    std::string name;
    int age;
    float heigth;
}
Person p1 = {"John Doe",30,5.9}
```
- Classes
  - By default access to members of a class is private
    ```
    class Person{
        public:
            std::string name;
            int age;
            void printInfo(){
                std::cout << "Name: " << name << ", Age: " << age << std::endl;
            }
    }
    Person p1;
    p1.name="John Doe";
    p1.age=30;
    ```
- Unions
  - Unions are used to store different data types in the same memory location
    ```
    union Data{
        int num;
        char letter;
        float decimal;
    }
    Data myData;
    myData.num=42;
    ```
# Run-Time Type Identification (RTTI)
- C++ feature that allows you to obtain the type info of a object during the program execution
- It has less performance because it required additional compiler generated information
- 2 mechanisms
  - typeid
  - dynamic_cast
- typeid example
  ```
  std::cout << "Type: " << typeid(*base_ptr).name() << '\n';
  ```
- dynamic_cast
  ```
  Derived *derived1_ptr = dynamic_cast<Derived1>(base_ptr);
  ```
# Dynamic typing
- We can have generic pointers
  ```
  void* void_ptr;
  *(static_cast<int*>(void_ptr))
  ```
    - the void pointer is a generic datatype pointer
    - we can store the reference of a object without knowing its type
  ```
  std::any any_value;
  std::any_cast<int>(any_value)
  ```
    - another generic datatype pointer but introduced in C++17