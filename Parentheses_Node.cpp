// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Parentheses_Node.h"
#include "Eval_Expr_Tree.h"
#include <memory>
//
// Constructor
//
Parentheses_Node::Parentheses_Node (void)
    {

    }

//
// Destructor
//
Parentheses_Node::~Parentheses_Node (void)
    {

    }
// Accept method for parentheses necessary because of inheritance to Expr_Node, but should not actually do anything with visitation

//
// Accept
//
void Parentheses_Node::accept (Visitor & visitor)
    {
        //EMPTY
    }

//
// Priority
//
int Parentheses_Node::Priority (void)
    {
        return 4;
    }
//
// getParent
//
std::shared_ptr<Expr_Node> Parentheses_Node::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }


//
// setParent
//
void Parentheses_Node::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }
