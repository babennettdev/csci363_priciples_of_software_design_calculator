// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//#include "Stack_Iterator.h"




//
// Constructor
//
// curr_ begins at s.size() and will count down to zero for the iterator pattern
template <typename T>
Stack_Iterator<T>::Stack_Iterator (Stack <T> & s):
    s_ (s), curr_ (s.size())
    {

    }

//
// Destructor
//
template <typename T>
Stack_Iterator<T>::~Stack_Iterator (void)
{


}
//
// is_done
//
template <typename T>
bool Stack_Iterator<T>::is_done (void)
{
    //returns true when curr_ is less than or equal to 0
    return this->curr_ <= 0;
}

//
// advance
//
template <typename T>
void Stack_Iterator<T>::advance (void)
{
    //decrement curr_ and pop the stack
     -- this->curr_;
     s_.pop();
     return;
}
//
// Overloaded * operator
//
template <typename T>
T Stack_Iterator<T>::operator * (void)
{
    //get top of the stack
    return this->s_.top();
}

//
// Overloaded -> operator
//
template <typename T>
T * Stack_Iterator<T>::operator -> (void)
{
    //return address of the top of the stack
    return &this->s_.top();
}
