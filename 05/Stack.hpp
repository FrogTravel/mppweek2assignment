/*
In this exercise, you need to write a class that implements a Stack
for generic types. The requirements for the class template are as follows:
  0. This file should not contain main()
  1.  There is a single parameter given to the template as an argument -
      the type of Array
  2. The name of the class should be precisely "Stack"
  3. The current filename should remain "Stack.hpp"
  4. The entire code for the template should be in the current file
  5. The data structure that stores elements of the stack should be
      implemented using Array

The following methods should be implemented to interact with the Stack
object from outside:
1. push(type value)
    Pushes the value into the stack. This method does not return anything.
2. pop()
    Pop the value out of the stack. Returns the reference to the
    latest pushed object
3. numberOfElements()
    Return the integer number of elements currently in the stack.
    When the stack is empty returns 0.
4. empty() return boolean value that indicates whether the
    stack is empty or not
5. You should provide the constructor that can initialize from the existing
    Stack object. Also, create the constructor that
    can initialize using stack size. The default constructor should
    set the stack size to some prespecified value.

!!!!IMPORTANT!!!!
Failure to follow any of these requirements will lead to the
compilation failure by the grader and this problem receiving 0 points.
*/

#include "Array.hpp"
#include <iostream>

template < typename T >
class Stack{
    int top;
    Array<T> S;
    int size;
public:
    Stack() : top(-1), size(1), S(1){}
    
    Stack(const int userSize) : top(-1), S(userSize){
        size = userSize;
    }
    
    /**
     * Pushing new element to stack, only if there is room for it
     * @param V element we want to push
     */
    void push(T& V){
        if( top < size-1 ){
            top++;
            S[top] = V;
        }
    }
    
    /**
     * @return element
     * If no other element in stack return from 0 position
     */
    T & pop () {
        if(top > -1) {
            top--;
            return S[top + 1];
        }
        return S[0];
    }
    
    /**
     * @return number of elements in stack right now
     */
    int numberOfElements(){
        return top+1;
    }
    
    /**
     * @return true if there is no element
     */
    bool empty(){
        return top == -1;
    }
    
    /**
     * Copying constructor
     * @param stack old stack that we want to copy
     */
    Stack(Stack& stack): top(stack.top), S(stack.size), size(stack.size){
        for(int i = 0; i < stack.numberOfElements(); i++)
            S[i] = stack.S[i];
    }
};

