// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Closed_Parentheses_Node.h"
#include "Eval_Expr_Tree.h"
#include <memory>
//
// Constructor
//
Closed_Parentheses_Node::Closed_Parentheses_Node (void)
    {

    }

//
// Destructor
//
Closed_Parentheses_Node::~Closed_Parentheses_Node (void)
    {

    }
// Accept method for closed parentheses necessary because of inheritance to Expr_Node, but should not actually do anything with visitation

//
// Accept
//
void Closed_Parentheses_Node::accept (Visitor & visitor)
    {
        //EMPTY
    }

//
// Priority
//
int Closed_Parentheses_Node::Priority (void)
    {
        return 5;
    }
//
// getParent
//
std::shared_ptr<Expr_Node> Closed_Parentheses_Node::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }


//
// setParent
//
void Closed_Parentheses_Node::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }
