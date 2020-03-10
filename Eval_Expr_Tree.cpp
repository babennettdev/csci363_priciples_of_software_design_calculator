// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Eval_Expr_Tree.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Mod_Node.h"
#include "Integer_Node.h"
//
// Constructor
//
Eval_Expr_Tree::Eval_Expr_Tree (void)
    {

    }

//
// Destructor
//
Eval_Expr_Tree::~Eval_Expr_Tree (void)
    {

    }

//
// Visit Add Node
//
void Eval_Expr_Tree::Visit_Add_Node(Add_Node & add_node)
    {
        //visit left and right children
        add_node.getRightChild()->accept(*this);
        add_node.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        int result = number1 + number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Subtract Node
//
void Eval_Expr_Tree::Visit_Subtract_Node(Subtract_Node & subtract_node)
    {
        //visit left and right children
        subtract_node.getRightChild()->accept(*this);
        subtract_node.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        int result = number1 - number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Multiply Node
//
void Eval_Expr_Tree::Visit_Multiply_Node(Multiply_Node & multiply_node)
    {
        //visit left and right children
        multiply_node.getRightChild()->accept(*this);
        multiply_node.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        int result = number1 * number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Divide Node
//
void Eval_Expr_Tree::Visit_Divide_Node(Divide_Node & divide_node)
    {
        //visit left and right children
        divide_node.getRightChild()->accept(*this);
        divide_node.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        if (number2 == 0)
        {
            throw divide_by_zero_exception();
            return;
        }
        int result = number1 / number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Mod Node
//
void Eval_Expr_Tree::Visit_Mod_Node(Mod_Node & mod_node)
    {
        //visit left and right children
        mod_node.getRightChild()->accept(*this);
        mod_node.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        if (number2 == 0)
        {
            throw mod_by_zero_exception();
            return;
        }
        int result = number1 % number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Integer Node
//
void Eval_Expr_Tree::Visit_Integer_Node(Integer_Node & integer_node)
    {
        this->Result_Stack.push(integer_node.getValue());
        return;
    }

//
// Result
//
int Eval_Expr_Tree::result(void)
    {
        //return the result
        return this->Result_Stack.top();
    }

