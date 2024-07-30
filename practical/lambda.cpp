#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int caramba = 3;
    int nonchange = 4;
    //? LAMBDA
    //? [], capture clause (capture inputs from outside the scope)
    //? (), parameters
    //? {}, function definition
    //? If we pass the reference we can change the variable otherwise we cannot change it
    //? We can also put all values from this function using either "&" or "=" only
    //? the "&" will pass all the pointers and the "=" will pass values only
    std::vector<int> v{2, 3, 7, 14, 23};
    std::cout << "Hello world\n";
    std::for_each(v.begin(), v.end(), [&](int x)
                  {
        caramba=2;
        std::cout << x << "\n";
        std::cout << caramba << "carambolas \n"; });
}