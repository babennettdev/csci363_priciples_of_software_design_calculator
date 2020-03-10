// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Divide_Node.h"
#include "Multiply_Node.h"
#include "Mod_Node.h"
#include "Integer_Node.h"
#include "Parentheses_Node.h"
#include "Closed_Parentheses_Node.h"
#include <memory>
/**
 * @class Expr Tree Builder
 *
 *  Builds an expression tree
 */

class Expr_Tree_Builder : Expr_Builder
{
public:
  /// Constructor
  Expr_Tree_Builder (void);

  /// Destructor
   virtual ~Expr_Tree_Builder (void);
  /// Build Add Node
  virtual void Build_Add_Node(void);
  /// Build Subtract Node
  virtual void Build_Subtract_Node(void);
  /// Build Multiply Node
  virtual void Build_Multiply_Node(void);
  /// Build Divide Node
  virtual void Build_Divide_Node(void);
  /// Build Mod Node
  virtual void Build_Mod_Node(void);
  /// Build Integer Node
  virtual void Build_Integer_Node(int number);
  /// Build Parentheses Node
  virtual void Build_Parentheses_Node(void);
  /// Build ClosedParentheses Node
  virtual void Build_Closed_Parentheses_Node(void);

  void Build_Postfix(std::shared_ptr<Expr_Node> node);

  Expr_Node & Build_Tree(void);
  void findOpenParen(void);
private:

  Stack<std::shared_ptr<Expr_Node> > Operator_Stack;
  Stack<std::shared_ptr<Expr_Node> > Postfix_Stack;

};


#endif   // !defined _EXPR_TREE_BUILDER_H_
