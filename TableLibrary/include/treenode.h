#ifndef TREENODE_H
#define TREENODE_H

// Структура "узел дерева"
template<typename T>
struct TreeNode
{
	T data; // Данные
	TreeNode *left, *right; // Узлы-потомки
	
	// Конструктор по умолчанию
	TreeNode<T>()
	{
		this->data = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	// Конструктор с параметрами
	TreeNode<T>(const T& data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	// Конструктор с параметрами
	TreeNode<T>(const T& data, TreeNode<T> *left, TreeNode<T> *right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

#endif /* TREENODE_H */