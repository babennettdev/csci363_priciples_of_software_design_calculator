// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Divide_Node
 *
 * Division node
 */

class Divide_Node : public Binary_Expr_Node
{
public:
  /// Constructor
  Divide_Node (void);

  /// Destructor
   virtual ~Divide_Node (void);


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


#endif   // !defined _DIVIDE_NODE_H_
