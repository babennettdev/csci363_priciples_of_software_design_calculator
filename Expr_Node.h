// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_
#include <memory>
//forward declaring the Visitor class
class Visitor;
/**
 * @class Expr_Node
 *
 *  Creates a hierarchy of nodes for evaluation
 */

class Expr_Node
{
public:
  /// Constructor
  Expr_Node (void);

  /// Destructor
   virtual ~Expr_Node (void)=0;


  /**
   * accept
   *
   * Used to traverse the tree
   *
   * @param[in]       &Visitor    a reference to a visitor class
   *
   */
  virtual void accept (Visitor & visitor) = 0;

  /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  virtual int Priority (void) = 0;
  virtual std::shared_ptr<Expr_Node> getParent (void) =0; //shared_ptr used for Proxy Pattern
  virtual void setParent (std::shared_ptr<Expr_Node> node) =0; //shared_ptr used for Proxy Pattern
private:

  /// No private members

};


#endif   // !defined _EXPR_NODE_H_
