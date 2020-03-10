// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _VISITOR_H_
#define _VISITOR_H_

//Forward Declarations
class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Mod_Node;
class Integer_Node;
class Parentheses_Node;
class Closed_Parentheses_Node;
/**
 * @class Visitor
 *
 *  Crating an interface for the expression visitor
 */

class Visitor
{
public:
  /// Constructor
  Visitor (void);

  /// Destructor
   virtual ~Visitor (void)=0;
  /// Visit Add Node
  virtual void Visit_Add_Node(Add_Node & add_node) =0;
  /// Visit Subtract Node
  virtual void Visit_Subtract_Node(Subtract_Node & subtract_node) =0;
  /// Visit Multiply Node
  virtual void Visit_Multiply_Node(Multiply_Node & multiply_node) =0;
  /// Visit Divide Node
  virtual void Visit_Divide_Node(Divide_Node & divide_node) =0;
  /// Visit Mod Node
  virtual void Visit_Mod_Node(Mod_Node & mod_node) =0;
  /// Visit Integer Node
  virtual void Visit_Integer_Node(Integer_Node & integer_node) =0;

private:

  /// No private members

};


#endif   // !defined _VISITOR_H_
