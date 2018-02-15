#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <memory>

template <class T>
class BinaryTree
{
public:
    BinaryTree():
    root(nullptr)
    {}
    
    bool insert(T value);
    void remove(T value);
    bool search(T value);
    void display();
    unsigned int numberNodes();
    unsigned int numberLeafNodes();
    unsigned int height();
    
private:
    class TreeNode
    {
    public:
        TreeNode(T value):
        data(value),
        left(nullptr),
        right(nullptr)
        {}
        
        T data;
        std::shared_ptr<TreeNode> left;
        std::shared_ptr<TreeNode> right;
    };
    
    std::shared_ptr<TreeNode> root;
    
    void display(std::shared_ptr<TreeNode> ptr);
    bool insert(std::shared_ptr<TreeNode>& ptrNode, std::shared_ptr<TreeNode> ptrNew);
    void remove(std::shared_ptr<TreeNode>& ptrNode, T value);
    void remove(std::shared_ptr<TreeNode>& ptrNode);
    unsigned int numberNodes(std::shared_ptr<TreeNode> data);
    unsigned int numberLeafNodes(std::shared_ptr<TreeNode> data);
    unsigned int height(std::shared_ptr<TreeNode> data);
    void destructor(std::shared_ptr<TreeNode> data);
    
};

//--------------------------------------------------------------------------------------


template <class T>
void BinaryTree<T>::remove(T value)
{
    remove(root, value);
}

template <class T>
void BinaryTree<T>::remove(std::shared_ptr<TreeNode>& ptrNode, T value)
{
    
    if (ptrNode->data == value)
    {
        remove(ptrNode);
    }
    else if (ptrNode->data < value)
    {
        if(ptrNode->right!=NULL)
        {
            remove(ptrNode->right, value);
        }
        else
        {
            std::cout << "Sorry, value not found :(" << std::endl;
        }

    }
    else if (ptrNode->data > value)
    {
        if(ptrNode->left!=NULL)
        {
            remove(ptrNode->left, value);
        }
        else
        {
            std::cout << "Sorry, value not found :(" << std::endl;
        }

    }
    
        //std::cout << "Sorry, value not found :(" << std::endl;
    
}

template <class T>
void BinaryTree<T>::remove(std::shared_ptr<TreeNode>& ptrNode)
{
    if (ptrNode->right == nullptr)
    {
        ptrNode = ptrNode->left;
    }
    else if (ptrNode->left == nullptr)
    {
        ptrNode = ptrNode->right;
    }
    else
    {
        std::shared_ptr<TreeNode> ptrAttach = ptrNode->right;
        while (ptrAttach->left != nullptr)
        {
            ptrAttach = ptrAttach->left;
        }
        ptrAttach->left = ptrNode->left;
        ptrNode = ptrNode->right;
    }
}


template <class T>
bool BinaryTree<T>::search(T value)
{
    std::shared_ptr<TreeNode> ptr = this->root;
    while (ptr != nullptr)
    {
        
        if (ptr->data == value)
        {
            
            return true;
        }
        else if (ptr->data < value)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }
    
    return false;
}


template <class T>
bool BinaryTree<T>::insert(T value)
{
    std::shared_ptr<TreeNode> ptrNew = std::make_shared<TreeNode>(value);
    
    return insert(root, ptrNew);
}

template <class T>
bool BinaryTree<T>::insert(std::shared_ptr<TreeNode>& ptrNode, std::shared_ptr<TreeNode> ptrNew)
{
    if (ptrNode == nullptr)
    {
        ptrNode = ptrNew;
        return true;
    }
    else if (ptrNode->data < ptrNew->data)
    {
        if(insert(ptrNode->right, ptrNew))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (ptrNode->data > ptrNew->data)
    {
        if (insert(ptrNode->left, ptrNew))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (ptrNode->data == ptrNew->data)
    {
        return false;
    }
    else
    {
        return false;
    }
}

template <class T>
void BinaryTree<T>::display()
{
    display(root);
}

template <class T>
void BinaryTree<T>::display(std::shared_ptr<TreeNode> ptr)
{
    if (ptr == nullptr) return;
    
    display(ptr->left);
    std::cout << ptr->data << std::endl;
    display(ptr->right);
}

template <class T>
unsigned int BinaryTree<T>::numberNodes()
{
    return numberNodes(root);
}

template <class T>
unsigned int BinaryTree<T>::numberNodes(std::shared_ptr<TreeNode> data)
{
    if(data == NULL)
    {
        return 0;
    }
    else
    {
        return numberNodes(data->left) + numberNodes(data->right) + 1;
    }
    
}

template <class T>
unsigned int BinaryTree<T>::numberLeafNodes()
{
    return numberLeafNodes(root);
}

template <class T>
unsigned int BinaryTree<T>::numberLeafNodes(std::shared_ptr<TreeNode> data)
{
    if (data == NULL)
    {
        return 0;
    }
    if(data->left == NULL && data->right == NULL)
    {
        return 1;
    }
    else
    {
        return numberLeafNodes(data->left) + numberLeafNodes(data->right);
    }
    
}

template <class T>
unsigned int BinaryTree<T>::height()
{
    return height(root);
}


template <class T>
unsigned int BinaryTree<T>::height(std::shared_ptr<TreeNode> data)
{
    if (data == nullptr)
    {
        return 0;
    }
    
    unsigned int leftSide = height(data->left);
    unsigned int rightSide = height(data->right);
    
    if(rightSide > leftSide)
    {
        return rightSide + 1;
    }
    else
    {
        return leftSide + 1;
    }
}

#endif


