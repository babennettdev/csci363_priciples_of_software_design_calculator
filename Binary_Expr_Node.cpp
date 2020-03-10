// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Binary_Expr_Node.h"
#include <memory>
//
// Constructor
//
Binary_Expr_Node::Binary_Expr_Node (void):
    rightChild(nullptr),
    leftChild(nullptr),
    Parent(nullptr)
    {

    }

//
// Destructor
//
Binary_Expr_Node::~Binary_Expr_Node (void)
    {
        //PROXY PATTERN TAKES CARE OF DESTRUCTION
    }

//
// getRightChild
//
std::shared_ptr<Expr_Node> Binary_Expr_Node::getRightChild(void)    //shared_ptr used for Proxy Pattern
    {
        return this->rightChild;
    }

//
// getLeftChild
//
std::shared_ptr<Expr_Node> Binary_Expr_Node::getLeftChild(void) //shared_ptr used for Proxy Pattern
    {
        return this->leftChild;
    }

//
// setRightChild
//
void Binary_Expr_Node::setRightChild(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->rightChild = node;
    }
//
// setLeftChild
//
void Binary_Expr_Node::setLeftChild(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->leftChild = node;
    }

//
// getParent
//
std::shared_ptr<Expr_Node> Binary_Expr_Node::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }


//
// setParent
//
void Binary_Expr_Node::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }
