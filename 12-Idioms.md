# Idioms
- Well established patterns or techniques that are commonly used in C++ programming to achieve a specific outcome
# 1- Resource Acquisition is Initialization (RAII)
- Making always sure that the resources are acquired and then released
```
class Resource{
    public:
        Resource(){}
        ~Resource(){}
};
void function(){
    Resource r; **AQUIRED**
}**DEALLOCATED/RELEASED**
```
```
class Lock {
public:
    Lock(std::mutex& mtx) : mutex_(mtx) {
        mutex_.lock();
    }

    ~Lock() {
        mutex_.unlock();
    }

private:
    std::mutex& mutex_;
};
```
## 2- Rule of Three
- If a class defines resources it should define all three:
  - `copy constructor,copy assignment,operator and destructor`
## 3- Rule of Five
- Extends the rule of three to the move and move assignment
  - `move,move-assignment`
## 4- PImpl (Pointer to Implementation) idiom
- Separate implementation details of a class from its interface
- It results in a faster compile times and the ability to change implementation without affecting clients
- Abstraction in C
  ```
  class MyClass{
    public:
    MyClass();
    ~MyClass();
    void someMethod();
  }
  class MyClass::Impl {
    public:
    void someMethod() { /* Implementation */ }
    };
  ```
## 5 - Non-Virtual Interface (NVI)
- This inforces a public interface and allows subclasses to only override specific private or protected virtual methods
```
class Base {
public:
    void publicMethod() {
        // Common behavior
        privateMethod(); // Calls overridden implementation
    }

protected:
    virtual void privateMethod() = 0; // Pure virtual method
};

class Derived : public Base {
protected:
    virtual void privateMethod() override {
        // Derived implementation
    }
};
```
# CRTP (Curiously Recurring Template Pattern)
- Basicly creates a way to shift the current type and invoke its members instead of using a virtual method for overwriting it
  ```
  template <typename Derived>
    class Base {
    public:
        void interface() {
            static_cast<Derived*>(this)->implementation();
        }

        void implementation() {
            std::cout << "Default implementation in Base" << std::endl;
        }
    };

    class Derived1 : public Base<Derived1> {
    public:
        void implementation() {
            std::cout << "Custom implementation in Derived1" << std::endl;
        }
    };

    class Derived2 : public Base<Derived2> {
        // No custom implementation, so Base::implementation will be used.
    };
  ```
# Non-copiable
- Prevents objects from beeing copied or assigned
- We can inherit this behavior to other classes
```
class NonCopyable {
public:
  NonCopyable() = default;
  ~NonCopyable() = default;

  // Delete the copy constructor
  NonCopyable(const NonCopyable&) = delete;

  // Delete the copy assignment operator
  NonCopyable& operator=(const NonCopyable&) = delete;
};
class MyClass : private NonCopyable {
  // MyClass is now non-copyable
};
```
# Erase-remove idiom
- Common C++ technique to efficiently remove elements from a container 
- The idiom consists of the following:
  - `std::remove` which moves the elements towards the end of the container and return an iterator poiting to the first element to remove
  - `container.erase()` removes the elements from the container using the iterator obtained in the prev step
```
std::vector<int> numbers = {1,2,3,4,5,3};
numbers.erase(std::remove(numbers.begin(),numbers.end(),3),numbers.end());
```
# Copy and Swap
- C++ idiom that leverages the copy constructor and swap function to create an assignment operator
- `copy`
  - Create a local copy of the right-hand side object
- `swap`
  - swap the contents of the left-hand side object with the temporary copy. This step typically involves swapping internal pointers and resources
  - Usually here it simply swaps the references
- `destruction`
  - Destroy the temporary copy
```
class String {
    // ... rest of the class ...

    String(const String& other);
    
    friend void swap(String& first, String& second) {
        using std::swap; // for arguments-dependent lookup (ADL)
        swap(first.size_, second.size_);
        swap(first.buffer_, second.buffer_);
    }

    String& operator=(String other) {
        swap(*this, other);
        return *this;
    }
};
```
# Copy and Write
- Is used to minimize the overhead of actual copy operations by using shared references