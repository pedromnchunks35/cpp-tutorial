# Info 
- We will skip the common concepts to other languages
# OOP In C++
- We can inherit classes like this:
```
class dog : public Animal{
    ...
}
```
- We can override methods like this
```
class Animal{
    public:
        virtual void makeSound(){
            std::count << "The animal makes a sound" << std::endl;
        }
}
```
```
class Dog : public Animal{
    public:
        void makeSound() override{
            std::cout << "Dog barks!" << std::endl;
        }
}
```
# Templates
- Powerful feature in C++ that allows to create generic function or classes
- We get static polymorphism using this
```
template<typename T>
void print(const T& value){
    std::cout << "Print value"<< value << std:: endl
}
```
- We can use this over overloading with different types the same signature
# Virtual Methods
- Virtual methods are methods that can be overrided
```
class Shape{
    public:
        virtual double area() const{
            return 0;
        }
}
class Circule : public Shape{
    public:
        Circle(double r): radius (r){}
        double area() const override{
            return 3.14*radius*radius;
        }
    private:
        double radius;
}
```
# Virtual Tables
- Basicly when we create a object using a pointer we are creating a virtual table
- We can say that the type of this pointer is the base class but still assign a value that is actually a subclass of this base class
- The virtual table will point to the correct method of the correct class
- Basicly is a array of pointers that point to the correct methods to use which are virtual
- Every object has a hidden pointer called vptr, this vptr points to the actual class of the object
```
class Base{
    public:
        virtual void show(){std::cout<<"lul"<<std:endl;}
}
class Derived:public Base{
    public:
        void show() override{std::cout<<"Derived show"<<std::endl;}
}
int main(){
    Base* ptr = new Derived();
    ptr->show();
}
```
# Rule of Zero,Five,Three
- Guidelines to manage object resources in modern C++
- This rules deal with default behavior of constructors,destructures and other special member functions
## Rule of Zero
- If a class or a structure does not explicity manage resources the compiler will do that automatically
```
struct MyResource{
    std::string name;
    int value;
}
```
## Rule of Three
- A class or structure that manage resources should define the following threee special member functions:
  - Destructor
  - Copy Constructor
  - Copy Assigment Operator
- These functions are necessary for proper resource management, such as releasing memory or correcly handling deep copies
```
class MyResource{
    public:
        MyResource():data(new int[200]){}
        ~MyResource(){delete[] data;}
        
        //? COPY CONSTRUCTOR
        MyResource(const MyResource& other):data(new int[100]){
            std::copy(other.data,other.data+100,data);
        }

        //? COPY ASSIGNMENT OPERATOR
        MyResource& operator = (const MyResource& other){
            if(&other==this){return *this;}
            std::copy(other.data,other.data+100,data);
            return *this;
        }
    private:
        int* data;
}
```
- Copy constructor is copping our data to other object
- Copy assignment operator is the other objecting getting our data
- Applies to heap area objects usually (new,delete), basicly objects with manual management of memory
# Rule of five
- Extend of rule of three because we also have to assign the move constructor and move assignment operator
```
class MyResource{
    public:
        MyResource() : data(new int[100]){}
        ~MyResource(){delete[] data;}
        
        //? Copy constructor
        MyResource(const MyResource& other) : data (new int[100]){
            std::copy(other.data,other.data+100,data);
        }

        //? Copy assignment operator
        MyResource& operator=(const MyResource& other){
            if(&other==this){return *this;}
            std::copy(other.data,other.data+100,data);
            return *this;
        }

        //? Move constructor
        MyResource(MyResource&& other) noexcept: data(other.data){
            other.data = nullptr;
        }

        //? Move assignment operator
        MyResource& operator = (MyResource&& other) noexpect{
            if(&other == this){return *this;}
            delete[] data;
            data=other.data;
            other.data=nullptr;
            return *this;
        }
    private:
      int* data;
}
```
# Multiple Inheritance
- A class here can have multiple inherante where the ihneretance concept only speaks about one
- It becomes a mixture of their properties and behaviors
```
class DerivedClass: access-specifier Baseclass1,access-specifier BaseClass2,...
{

};
```
- `access-specifier` is public,protected or private
- We basicly inherit all that we are passing to this derivedclass
```
class Animal{
    public:
        void eat()
        {
            std::cout<< "I can east!" << std::endl;
        }
}
class Mamal{
    public:
        void breath(){
            std::cout << "I can breathe!" << std::endl;
        }
}
class Dog: public Animal, public Mammal
{
    public:
        void bark()
        {
           std::cout<< "I can bark! Woof woof!" << std::endl; 
        }
}
int main(){
    Dog myDog;
    myDog.eat();
    myDog.breath();
    myDog.breath();
    myDog.bark();
}
```
- Multiple ihnerance can throw problems such as the "diamond problem"
# Diamond Inheritance
- Happens when we inherit multiple classes and some of those classes inherit from the same base class
- If the base class is virtual this resolves this problem because like this we are ensurring that the base class will only be applied once and there will be not duplicates
```
class Base{
    public:
        void print(){
            std::cout << "Base class" << std::endl;
        }
}

class Derived1 : virtual public Base{
    public:
        void derived1Print(){
            std::cout << "Derived1 class" << std::endl;
        }
}

class Derived2: virtual public Base{
    public:
        void derived2Print(){
            std::cout << "Derived2 class" << std::endl;
        }
}

class Derived3: public Derived1,public Derived2{
    public:
        void derived3Print(){
            std::cout << "Derived3 class" << std::endl;
        }
}
```