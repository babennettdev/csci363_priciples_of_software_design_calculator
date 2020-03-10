// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Expr_Node.h"
#include "Visitor.h"
/**
 * @class Add_Node
 *
 * Addition node
 */

class Add_Node: public Binary_Expr_Node
{
public:
  /// Constructor
  Add_Node (void);

  /// Destructor
   virtual ~Add_Node (void);


  /**
   * accept
   *
   * traverses the tree
   * @param[in]       &Visitor    a reference to the visitor class
   *
   */

  virtual void accept (Visitor & visitor);
   /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  virtual int Priority (void);



protected:
  /// No protected members
private:

  /// No private members

};


#endif   // !defined _ADD_NODE_H_
