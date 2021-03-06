// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _PARENTHESES_NODE_H_
#define _PARENTHESES_NODE_H_

#include "Expr_Node.h"
#include <memory>

/**
 * @class Parentheses_Node
 *
 * Parentheses node
 */

class Parentheses_Node : public Expr_Node
{
public:
  /// Constructor
  Parentheses_Node (void);

  /// Destructor
   virtual ~Parentheses_Node (void);


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
     /**
   * getParent
   *
   * @return       *Expr_Node  a pointer to the parent node
   */
  virtual std::shared_ptr<Expr_Node> getParent (void); //shared_ptr used for Proxy Pattern
   /**
   * setParent
   *
   * @param[in]       *Expr_Node  the node to be placed as the left child
   */
  virtual void setParent (std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern


protected:
    //parent of the expr node
    std::shared_ptr<Expr_Node> Parent; //shared_ptr used for Proxy Pattern
private:

  /// No private members

};


#endif   // !defined _PARENTHESES_NODE_H_
