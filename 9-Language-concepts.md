# Auto (for automatic type deduction)
- Its good for when its hard to deduct the type
- This way we have less error prone code and easier to read
```
auto myAUtoInt = 5;
```
# Casting
- We can do
```
float b = (float)5;
```
- Or at compile time
```
float b = static_cast<float>(5);
```
- Or the following at running time that can be used to convert a type to a another type class
```
class Derived : public Base{}
Base* base_ptr = new Derived();
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
``` 
- Or the following for a bitwise cast (it interprets the underlying bits)
```
int* a=new int(42);
long b = reinterpret_cast<long>(a);
```  
- Or the following to cast a const to a var
```
const int a = 10;
int *ptr = const_cast<int*>(&a);
*ptr = 20;
```
# Adl
- Basicly depending of what we initiated it will invoke a function from a given namespace without explicity mentioning the namespace itself
```
namespace MyNamespace {
    class MyClass {
    public:
        int value;
    };

    std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << "MyClass: " << obj.value;
        return os;
    }
}
int main() {
    MyNamespace::MyClass obj;
    obj.value = 42;
    using std::cout; // Required to use 'cout' without fully qualifying it.
    cout << obj << std::endl; // ADL is used to find the correct overloaded 'operator<<'.
}
```
# Macros
- You can create variables and functions like they where headers
```
#define PI 3.14159
#define SQUARE(x)((x)*(x))
```