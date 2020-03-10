// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Integer_Node.h"



/**
 * @class Eval Expr Tree
 *
 *  Abstraction of the expression tree builder
 */

class Expr_Builder
{
public:
  /// Constructor
  Expr_Builder (void);

  /// Destructor
   virtual ~Expr_Builder (void) =0;
  /// Build Add Node
  virtual void Build_Add_Node(void) =0;
  /// Build Subtract Node
  virtual void Build_Subtract_Node(void) =0;
  /// Build Multiply Node
  virtual void Build_Multiply_Node(void) =0;
  /// Build Divide Node
  virtual void Build_Divide_Node(void) =0;
  /// Build Mod Node
  virtual void Build_Mod_Node(void) =0;
  /// Build Integer Node
  virtual void Build_Integer_Node(int number) =0;
  /// Build Parentheses Node
  virtual void Build_Parentheses_Node(void) =0;
  /// Build Closed Parentheses Node
  virtual void Build_Closed_Parentheses_Node(void) =0;

  int result(void);
private:

  int int_result;

};


#endif   // !defined _EXPR_BUILDER_H_
