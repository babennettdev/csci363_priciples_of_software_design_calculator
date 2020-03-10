// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Subtract_Node.h"
#include "Visitor.h"
//
// Constructor
//
Subtract_Node::Subtract_Node (void)
    {

    }

//
// Destructor
//
Subtract_Node::~Subtract_Node (void)
    {

    }

//
// Accept
//
void Subtract_Node::accept (Visitor & visitor)
    {
        visitor.Visit_Subtract_Node(*this);
    }

//
// Priority
//
int Subtract_Node::Priority (void)
    {
        return 1;
    }
