// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Add_Node.h"
#include "Visitor.h"
//
// Constructor
//
Add_Node::Add_Node (void)
    {

    }

//
// Destructor
//
Add_Node::~Add_Node (void)
    {

    }

//
// Accept
//
void Add_Node::accept (Visitor & visitor)
    {
        visitor.Visit_Add_Node(*this);
    	return;
    }

//
// Priority
//
int Add_Node::Priority (void)
    {
        return 1;
    }
