// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"
#include <memory>

/**
 * @class Binary_Expr_Node
 *
 *  Middle level hierarchy. Governs the binary expressions like add, subtract, etc
 */

class Binary_Expr_Node : public Expr_Node
{
public:
  /// Constructor
  Binary_Expr_Node (void);

  /// Destructor
   virtual ~Binary_Expr_Node (void);

  /**
   * accept
   *
   * traverses the tree
   * @param[in]       &Visitor    a reference to the visitor class
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

   /**
   * getRightChild
   *
   *
   * @return          &Expr_Node  the right child of the tree
   */
  std::shared_ptr<Expr_Node> getRightChild(void); //shared_ptr used for Proxy Pattern

   /**
   * getLeftChild
   *
   *
   * @return          &Expr_Node  the left child of the tree
   */
  std::shared_ptr<Expr_Node> getLeftChild(void); //shared_ptr used for Proxy Pattern
   /**
   * setRightChild
   *
   * @param[in]       *Expr_Node  the node to be placed as the right child
   */
  void setRightChild(std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern
   /**
   * setLeftChild
   *
   * @param[in]       *Expr_Node  the node to be placed as the left child
   */
  void setLeftChild(std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern
  //
  //        The way I am building my tree (from a postfix expression that I created
  //        using a similar method to Assignment 3) I need to be able to step back
  //        through the tree after reaching the bottom of a branch to set the children
  //        of other leaves.
  //        This is why I felt it necessary to include a getParent() and setParent()
  //        functions in my binary expression node.
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
    //left child of the expr node
    std::shared_ptr<Expr_Node> leftChild; //shared_ptr used for Proxy Pattern
    //right child of the expr node
    std::shared_ptr<Expr_Node> rightChild; //shared_ptr used for Proxy Pattern
    //parent of the expr node
    std::shared_ptr<Expr_Node> Parent; //shared_ptr used for Proxy Pattern
private:

  /// No private members

};


#endif   // !defined _BINARY_EXPR_NODE_H_
