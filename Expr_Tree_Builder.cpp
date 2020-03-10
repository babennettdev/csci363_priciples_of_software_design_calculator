// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn



#include "Expr_Tree_Builder.h"
#include "Stack_Iterator.h"
#include <memory>



//
// Constructor
//
Expr_Tree_Builder::Expr_Tree_Builder (void):
	Operator_Stack(),
	Postfix_Stack()
    {

    }
//
// Destructor
//
Expr_Tree_Builder::~Expr_Tree_Builder (void)
    {

        //HANDLED BY SHARED POINTERS IN PROXY PATTERN
    }

/* These functions build our nodes using the builder pattern*/
void Expr_Tree_Builder::Build_Add_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Add_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_Subtract_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Subtract_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_Multiply_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Multiply_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_Divide_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Divide_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_Mod_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Mod_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_Integer_Node(int number)
    {
        std::shared_ptr<Expr_Node> node(new Integer_Node(number)); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_Parentheses_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Parentheses_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }
void Expr_Tree_Builder::Build_Closed_Parentheses_Node(void)
    {
        std::shared_ptr<Expr_Node> node(new Closed_Parentheses_Node()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }
//
// findOpenParen
//
void Expr_Tree_Builder::findOpenParen(void)
{
    //check for open paren
    while(this->Operator_Stack.top()->Priority() != 4)
    {
        //for all other operators push to postfix stack and pop
        this->Postfix_Stack.push(this->Operator_Stack.top());
        this->Operator_Stack.pop();
    }
    //pop the open paren
    this->Operator_Stack.pop();
    return;
}

void Expr_Tree_Builder::Build_Postfix(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        //push all integers directly to the Postfix Stack
        if(node->Priority() == 0)
        {
            this->Postfix_Stack.push(node);
        }
        //push the first node onto the Operator stack
        else if(this->Operator_Stack.is_empty())
        {
            this->Operator_Stack.push(node);
            return;
        }
        //check if the node is a parentheses
        else if(node->Priority() == 4)
        {
            this->Operator_Stack.push(node);
            return;
        }
        //check for closed parentheses
        else if(node->Priority() == 5)
        {

            this->findOpenParen();
            return;
        }
        //compare priority of node with that on the operator stack
        else if(node->Priority() > this->Operator_Stack.top()->Priority())
        {
            this->Operator_Stack.push(node);
            return;
        }
        //for all other cases push operators to postfix stack and pop stack (until we find an open parentheses)
        else
        {
//***********************USING THE ITERATOR PATTERN TO EMPTY MY OPERATOR_STACK AND PUSH TO POSTFIX_STACK************************************
            for(Stack_Iterator<std::shared_ptr<Expr_Node> > s_iter(Operator_Stack); !s_iter.is_done() && (*s_iter)->Priority() != 4; s_iter.advance() ) //shared_ptr used for Proxy Pattern
            {
                this->Postfix_Stack.push(*s_iter);
            }
//*********************************************END ITERATOR PATTERN USE ********************************************************************


            //push operator to stack
            this->Operator_Stack.push(node);
            return;
        }
    }

//builds a tree from a Postfix expression contained in Postfix_Stack
//Checks right children until it finds a number_node or nullptr
//steps back through the tree always checking right children before left to build our tree
Expr_Node & Expr_Tree_Builder::Build_Tree(void)
    {
        //create a root and current node
        std::shared_ptr<Expr_Node> root; //shared_ptr used for Proxy Pattern
        std::shared_ptr<Binary_Expr_Node> current; //shared_ptr used for Proxy Pattern


//***********************USING THE ITERATOR PATTERN TO EMPTY MY OPERATOR_STACK AND PUSH TO POSTFIX_STACK************************************

        //empty the operator stack first
        for(Stack_Iterator<std::shared_ptr<Expr_Node> > s_iter(Operator_Stack); !s_iter.is_done(); s_iter.advance() ) //shared_ptr used for Proxy Pattern
            {
                this->Postfix_Stack.push(*s_iter);
            }
//*********************************************END ITERATOR PATTERN USE ********************************************************************


        //set our root and set root as the current node
        root = this->Postfix_Stack.top();
        this->Postfix_Stack.pop();
        current = std::dynamic_pointer_cast<Binary_Expr_Node>(root); //Dynamic casting used to convert the type of our shared pointer
        //set children to nullptr to facilitate setting of children
        current->setLeftChild(nullptr);
        current->setRightChild(nullptr);

        //while postfix stack isn't empty
        while(this->Postfix_Stack.is_empty() == false)
        {
            //check right child availability
            if(current->getRightChild() == nullptr)
            {

                current->setRightChild(this->Postfix_Stack.top());
                this->Postfix_Stack.top()->setParent(current);

                if(Postfix_Stack.top()->Priority() != 0) //check for nonintegers
                    {
                        //Dynamic casting used to convert the type of our shared pointer
                        current = std::dynamic_pointer_cast<Binary_Expr_Node>(this->Postfix_Stack.top()); //set new current node
                    }
                this->Postfix_Stack.pop();
            }

            //check left child availability
            else if (current->getLeftChild() == nullptr)
            {

                current->setLeftChild(this->Postfix_Stack.top());
                this->Postfix_Stack.top()->setParent(current);
                if(Postfix_Stack.top()->Priority() != 0) //check for nonintegers
                    {
                        //Dynamic casting used to convert the type of our shared pointer
                        current = std::dynamic_pointer_cast<Binary_Expr_Node>(this->Postfix_Stack.top()); //set new current node
                    }
                this->Postfix_Stack.pop();
            }
            else
            {

                //set current leaf to its parent
                if(current == root)
                {
                    //do nothing (root should not have a parent)
                }
                else
                {
                    //Dynamic casting used to convert the type of our shared pointer
                    current = std::dynamic_pointer_cast<Binary_Expr_Node>(current->getParent()); //set current to current's parent node
                }


            }
        }
        //return the root node for use in visitation
        return *root;
    }

