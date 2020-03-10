// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Mod_Node.h"
#include "Visitor.h"
//
// Constructor
//
Mod_Node::Mod_Node (void)
    {

    }

//
// Destructor
//
Mod_Node::~Mod_Node (void)
    {

    }


//
// Accept
//
void Mod_Node::accept (Visitor & visitor)
    {
        visitor.Visit_Mod_Node(*this);
    }

//
// Priority
//
int Mod_Node::Priority (void)
    {
        return 2;
    }
