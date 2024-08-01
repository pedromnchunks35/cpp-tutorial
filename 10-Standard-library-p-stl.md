# Info
- This is a collection of header files that provide several data structures,algorithms and functions to simplify your C++ experience
# Iterators
- To tranverse containers like arrays,lists and vectors
- `Input Iterator`
  - Used to read elements in a container only once, in a forward direction, they cannot modify elements
    ```
    std::vector<int> nums = {1,2,3,4};
    std::istream_iterator<int> input(std::cin);
    std::copy(input,std::istream_iterator<int>(),std::back_inserter(nums))
    ```
- `Output Interator`
  - Used to write elements in a container only once, in a forward direction, they cannot rewrite elements
    ```
    std::vector<int> nums = {1,2,3,4};
    std::ostream_iterator<int> output(srd::cout,",");
    std::copy(nums.begin(),nums.end(),output);
    ``` 
- `Forward Iterator`
  - Similar to input iterators but can be used for multiple passes over the elements in a container. They cannot move backward
    ```
    std::forward_list<int> nums = {1,2,3,4};
    std::forward_list<int>::iterator itr = nums.begin();
    while(itr != nums.end()){
        std::cout << *itr << " ";
        ++itr;
    }
    ```
- `Reverse Iterator`
  - Same as input iterators but can be used for multiple passes over the elements in a container and cannot move forward
  ```
  std::list<int> nums = {1,2,3,4};
  std::list<int>::reverse_iterator itr = nums.rbegin();
  while(itr != nums.rend()){
    std::cout << *itr << " ";
    ++itr;
  }
  ```  
- `Bidirectional Iterator`
  - Move forward and backwards in a container
    ```
    std::list<int> nums = {1,2,3,4};
    std::list<int>::iterator itr;
    for(itr=nums.begin();itr!=nums.end();++itr){
        std::cout << *itr << " ";
    }
    for(--itr; itr != nums.begin();--itr){
        std::cout << *itr << " ";
    }
    ```  
- `Random Access Iterator`
  - These iterators provide the most flexible ways to access elements in a container
  - Can move forward,backwards,jump to other elements and access elements in a given pos
   ```
   std::vector<int> nums = {1,2,3,4};
   std::vector<int>::iterator itr;
   for(itr = nums.begin();itr!=nums.end();++itr){
    std::cout << *itr << " ";
   }
   for(itr -=1 ; itr != nums.begin()-1 ;--itr){
    std::cout << *itr << " ";
   }
   ```
# iostream
- Basic I/O Operations
- `istream`
  - only for inputs
- `ostream`
  - only for outputs
- `iostream`
  - both input and outputs
## Basic commands
- `cin`, for read from the keyboard
- `cout`, for write the output
- `cerr`, for error messages
- `clog`, cimilar to cerr but the output can be buffered
# Algorithms
- Has the most common algorithms to our disposal
- It provides sorting algorithms such as `std::sort,std::stable_sort and std::partial_sort`
```
std::sort(nums.begin(),nums.end());
std::find(nums.begin(),nums.end(),9);
nums.erase(std::remove(nums.begin(),nums.end(),6),nums.end())
```
# Date/Time
- `Duration`
  - represents span of time
  - std::chrono::seconds
  - std::chrono::minutes
  - std::chrono::hours
    ```
        std::chrono::seconds sec(5);
        std::chrono::minutes min(2);
        std::chrono::hours hr(1);
    ```
- `Time Point`
  - Specific point in time
  - there are 3 types of clocks
    - `std::chrono::system_clock` to system-wide real time wall clock
    - `std::chrono::steady_clock` represents a monotonic clock that is guaranteeed to never be adjusted
    - `std::chrono::high_resolution_clock`clock with shortest tick period
- `Clock`
  - To get the current time
  - `time_point` for specific time period
  - `duration` the time duration between two time points
  - `now()` returns the current time
# Containers
- `Vector`
  - Can resize themselves as needed
    ```
     std::vector<int> vec = {1,2,3,4,5};
     vec.push_back(6);
    ```
- `List`
  - Doubly linked list
  - Random access does not work
  - Better for insert and remove elements in the middle frequently
    ```
    std::list<int> lst = {1,2,3,4,5};
    lst.push_back(6);
    ```
- `Map`
  - For key value pairs
  - Keys inserted in ascending order
    ```
    std::map<std::string,int>m;
    m["one"]=1;
    m["two"]=2;
    ```
- `Unordered_map`
  - Also stores key value pairs but it uses a hash table
  - Better performance because it does not maintain order in a average-case scenario
  - In worst case scneario its worst than map
    ```
    std::unordered_map<std::string,int>um;
    um["one"]=1;
    um["two"]=2;
    ```
# Multithreading
- `Basic Thread Creation`
  ```
  #include <iostream>
  #include <thread>
  void my_function(){
    std::cout << "THis function is executing in a separate thread" << std::endl;
  }
  int main(){
    std::thread t(my_function);
    t.join();
  }
  ```
- `Thread with arguments`
    ```
  #include <iostream>
  #include <thread>
  void my_function(int a,int b){
    std::cout << "THis function is executing in a separate thread" << std::endl;
  }
  int main(){
    std::thread t(my_function,5,6);
    t.join();
  }
- `Mutex and Locks`
  - Basic locks
  - But we have a lot more for threads sucj as thread pools,condition variables,atomic operations,etc..
  ```
  #include <iostream>
  #include <mutex>
  #include <thread>
  std::mutex mtx;
  void print_block(int n,char c){
    {
        std::unique_lock<std::mutex> locker(mtx);
        for(int i = 0;i<n;++i){
            std:cout<<c;
        }
        std::cout << std::endl;
    }
  }
  int main(){
    std:: thread t1(print_block,50,"");
    srd:: thread t2(print_block,50,'$');
    t1.join();
    t2.join();
  }
  ```
