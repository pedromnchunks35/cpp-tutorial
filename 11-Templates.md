# Templates
- Used to create generic code over something
- We can work with the same classes/functions and with different data types
# Template Functions
```
template<typename T>
T max(T a,T b){
  return (a>b)?a:b;
}
int result = max<int>(10,20);
```
# Template Classes
```
template<typename T1,typename T2>
class Pair{
    public:
        T1 first;
        T2 second;
        Pair(T1 first,T2 second): first(first),second(second){}
}
Pair<int,std::string> pair(1,"Hello");
```
# Template specialization
```
template <>
class Pair<char, char> {
public:
    char first;
    char second;

    Pair(char first, char second) : first(first), second(second) {
        // Special behavior for characters (e.g., convert to uppercase)
        this->first = std::toupper(this->first);
        this->second = std::toupper(this->second);
    }
};
``` 
# Full template specialization
```
// Generic template
template <typename T>
class MyContainer {
public:
    void print() {
        std::cout << "Generic container." << std::endl;
    }
};

// Full template specialization for int
template <>
class MyContainer<int> {
public:
    void print() {
        std::cout << "Container for integers." << std::endl;
    }
};

int main() {
    MyContainer<double> d;
    MyContainer<int> i;

    d.print(); // Output: Generic container.
    i.print(); // Output: Container for integers.

    return 0;
}
```
- We are having here overloading of classes
# Partial Template Specialization
- When we have multiple definitions for something 
```
// Primary template
template <typename T>
struct MyTemplate {
    static const char* name() {
        return "General case";
    }
};

// Partial specialization for pointers
template <typename T>
struct MyTemplate<T*> {
    static const char* name() {
        return "Partial specialization for pointers";
    }
};

// Full specialization for int
template <>
struct MyTemplate<int> {
    static const char* name() {
        return "Full specialization for int";
    }
};
```
# Variadic Templates
- Usefull when we have multiple args
```
// Base case for recursion
template <typename T>
T sum(T t) {
  return t;
}

// Variadic template
template <typename T, typename... Args>
T sum(T t, Args... args) {
  return t + sum(args...);
}

int main() {
  int result = sum(1, 2, 3, 4, 5);  // expands to 1 + 2 + 3 + 4 + 5
  std::cout << "The sum is: " << result << std::endl;

  return 0;
}
```
# Type traits
- Checks for characteristics of a value and we can use it to implement some behavior
- `std::is_pointer` checks if it is a pointer
- `std::is_arithmetic` checks if it is a arithmetic type
- `std::is_function`
# Composing type traits
- `std::conditional` if a given boolean value is true, use type A, otherwise use type B
- `std::enable_if`if a given value is true, use type A, otherwise there is no nested type
```
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type find_max(T a, T b) {
    return a > b ? a : b;
}
```
# SFINAE (Substitution Failure Is Not An Error)
- Basicly the compiler tries to get a overloading matcher code
  ```
    template <typename T, typename = void>
    struct foo_impl {
        void operator()(T t) {
            std::cout << "Called when T is not arithmetic" << std::endl;
        }
    };
    
    template <typename T>
    struct foo_impl<T, std::enable_if_t<std::is_arithmetic<T>::value>> {
        void operator()(T t) {
            std::cout << "Called when T is arithmetic" << std::endl;
        }
    };
    
    template <typename T>
    void foo(T t) {
        foo_impl<T>()(t);
    }
  ```