# For exception handling
- try
- catch
- throw
- noexpect
  - Specifies a function that does not throw exceptions or terminates the program if an exception is thrown within its scope
```
try{
    
}catch(const char* msg){
    std::cerr << "Error: "<< msg << std::endl; 
}
```
# Standard Exceptions
- std::exception
  - Base one for every class
- std::logic_error
  - errors that can be detected statically
- std::runtime_error
  - errors in the execution of the program
# Access violation
- Deferencing a null or invalid pointer
  ```
  int *p = nullptr;
  int x = *p;
  ```
- Access a array out of bounds
  ```
  int arr[5];
  int y = arr[6];
  ```
- Reading or writing to memory freed by the user or the operative system
  ```
  int* p2 = new int[10];
  delete[] p2;
  p2[3] = 42;
  ```
# Debugging Access Violations
- Using debuggers,static analyzers and profilers can help on this
- tools: Valgrind and addressSanitizer
    - It actually tells where is the problem which is nice
    - The sanitizer is more complex, it displays more information but is till a good tool tought
# Exit codes
- `0`
  - Standard for sucess
- `non-zero`
  - error
- We can throw this codes by using return in the main function or by using exit({code})