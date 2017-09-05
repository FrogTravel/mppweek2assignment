/*
In this exercise, you need to write a class that implements a Stack
for generic types. The requirements for the class template are as follows:
  0. This file should not contain main()
  1. There are two parameters given to the template as an argument
  2. The first parameter is the type of Stack
  3. The second parameter is optional and determines the stack size
  4. The name of the class should be precisely "Stack"
  5. The current filename should remain "Stack.hpp"
  6. The entire code for the template should be in the current file

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
    Stack object

!!!!IMPORTANT!!!!
Failure to follow any of these requirements will lead to the
compilation failure by the grader and this problem receiving 0 points.
*/


#include <iostream>
template < typename T, int G = 1>
class Stack{
    int top;
    T S[G];
public:
    Stack() : top(-1){}
    
    /**
     * Pushing new element to stack, only if there is room for it
     * @param V element we want to push
     */
    void push(T& V){
        if( top < G-1 ){
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
     * @return Number of elements in the stack
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
    Stack(Stack& stack): top(stack.top){
        for(int i = 0; i < stack.numberOfElements(); i++)
            S[i] = stack.S[i];
    }
};
