# Info
- Sometimes we need libraries in order to work with c++
- In order to achieve this we can either add static (.lib) or dynamic libraries (.dll)
# Create a library 
- In order to create a library we need to compile the files to machine code files and then bundle them into an archive
```
g++ -c sourcefile.cpp -o objectfile.o
ar rcs libmystaticlibrary.a objectfile.o
```
- To pass this libraries we can pass the path to our library file
```
g++ main.cpp -o myprogram -L /path/to/your/library/ -lmystaticlibrary
```
- We may need to update the `LD_LIBRARY_PATH` variable