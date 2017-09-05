/*
In this exercise, you need to write a class that implements Array
for generic types. The requirements for the class template are as follows:
  0. This file should not contain main()
  1. There is a single parameter given to the template as an argument -
      the type of Array
  2. The name of the class should be precisely "Array"
  3. The current filename should remain "Array.hpp"
  4. The entire code for the template should be in the current file

The following methods should be implemented to interact with the Stack
object from outside:
1. Constructor that initializes the Array object. Create constructor that
    can initialize using an array size. The default constructor should
    set the array size to some prespecified value.
2. Destructor for the object. Free the memory allocated for this array.
3. resize(int value) resizes the Array to the size of type*value. The
    reasonable way to resize the array is to allocate new part of memory,
    copy the data, and free the old memory
4. getSize() return the integer number of elements type that the Array
    can store
5. The elements of your Array should be accessible using [], i.e. a[0].
    Overload the operator that is needed for that. Out of boundary check
    should be performed. If the index is out of bounds, throw out_of_range
    exception.

!!!!IMPORTANT!!!!
Failure to follow any of these requirements will lead to the
compilation failure by the grader and this problem receiving 0 points.
*/
#include <iostream>
#include <stdexcept>

template < typename T >
class Array{
    T *container;
    int size;
    
public:
    /**
     * Constructor
     */
    Array(int size = 2) : size(size){
        container = new T[size];
    }
    
    /**
     * Destructor
     */
    ~Array(){
        size = 0;
        delete[] container;
    }
    
    /**
     * Overload of '[]' operator, so we can use this array as normal one
     * If index is to bit, then throwing an exception
     */
    T& operator [] (const int& index){
        if(index >= size)
            throw std::out_of_range("Out of Bound Exception");
        
        return container[index];
    }
    
    /**
     * Resize of current array
     * @param value what new size do we want
     */
    void resize(int value){//type*value
        
        T* temp = container;//store all variables in temple "array"
        container = new T[value];//allocate new memory
        
        for (int i = 0; i < value; i++){
            container[i] = temp[i];
        }
        
        delete[] temp;//free memory
        
        for(int i = size; i < value; i++){
            T* t = new T();//default constructor
            container[i] = *t;
        }
        
        size = value;
    }
    
    /**
     * How much elements could be stored in the array
     */
    int getSize(){
        return size;
    }
};
