// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Divide_Node.h"
#include "Visitor.h"
//
// Constructor
//
Divide_Node::Divide_Node (void)
    {

    }

//
// Destructor
//
Divide_Node::~Divide_Node (void)
    {

    }

//
// Accept
//
void Divide_Node::accept (Visitor & visitor)
    {
        visitor.Visit_Divide_Node(*this);
    }

//
// Priority
//
int Divide_Node::Priority (void)
    {
        return 2;
    }
