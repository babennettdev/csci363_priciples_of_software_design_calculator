// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Multiply_Node.h"
#include "Visitor.h"
//
// Constructor
//
Multiply_Node::Multiply_Node (void)
    {

    }

//
// Destructor
//
Multiply_Node::~Multiply_Node (void)
    {

    }
//
// Accept
//
void Multiply_Node::accept (Visitor & visitor)
    {
        visitor.Visit_Multiply_Node(*this);
    }

//
// Priority
//
int Multiply_Node::Priority (void)
    {
        return 2;
    }
