// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Integer_Node.h"
#include "Visitor.h"
//
// Constructor
//
Integer_Node::Integer_Node (int number):
    int_value(number),
    Parent(nullptr)
    {

    }

//
// Destructor
//
Integer_Node::~Integer_Node (void)
    {

    }


//
// Accept
//
void Integer_Node::accept (Visitor & visitor)
    {
        visitor.Visit_Integer_Node(*this);
    }

//
// Priority
//
int Integer_Node::Priority (void)
    {
        return 0;
    }
//
// getParent
//
std::shared_ptr<Expr_Node> Integer_Node::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }


//
// setParent
//
void Integer_Node::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }

//
// getValue
//
int Integer_Node::getValue(void)
    {
        return int_value;
    }
