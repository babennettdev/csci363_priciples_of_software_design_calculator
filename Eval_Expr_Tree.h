// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Stack.h"
#include "Visitor.h"
#include <exception>


//creating our exceptions for divide and mod by zero errors
/**
 *@class divide_by_zero_exception
 *
 *Exception thrown to indicate a divide by zero error
 */

class divide_by_zero_exception : public std::exception
  {
  public:
        divide_by_zero_exception (void):
                std::exception()
                {
                }
  };
  /**
 *@class divide_by_zero_exception
 *
 *Exception thrown to indicate a divide by zero error
 */

class mod_by_zero_exception : public std::exception
  {
  public:
        mod_by_zero_exception (void):
                std::exception()
                {
                }
  };
/**
 * @class Eval Expr Tree
 *
 *  Evaluates the expression tree
 */

class Eval_Expr_Tree : public Visitor
{
public:
  /// Constructor
  Eval_Expr_Tree (void);

  /// Destructor
   virtual ~Eval_Expr_Tree (void);
  /// Visit Add Node
  virtual void Visit_Add_Node(Add_Node & add_node);
  /// Visit Subtract Node
  virtual void Visit_Subtract_Node(Subtract_Node & subtract_node);
  /// Visit Multiply Node
  virtual void Visit_Multiply_Node(Multiply_Node & multiply_node);
  /// Visit Divide Node
  virtual void Visit_Divide_Node(Divide_Node & divide_node);
  /// Visit Mod Node
  virtual void Visit_Mod_Node(Mod_Node & mod_node);
  /// Visit Integer Node
  virtual void Visit_Integer_Node(Integer_Node & integer_node);
  int result();
private:

  Stack<int>  Result_Stack;

};


#endif   // !defined _EVAL_EXPR_TREE_H_
