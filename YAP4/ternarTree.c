#include <stdio.h>

typedef struct list_node
{
	struct list_node* next;
	void* data;
}list_node_t;
typedef struct list {
	int size;
	list_node_t* head;
	list_node_t* tail;
}list_t;

list_t* create_list(void)
{
	list_t* lt = malloc(sizeof(list_t));
	lt->size = 0;
	lt->head = NULL;
	lt->tail = lt->head;

	return lt;
}

void list_push(list_t* lt, void* data)
{
	list_node_t* node = malloc(sizeof(list_node_t));
	node->data = data;
	node->next = lt->head;

	lt->head = node;
	lt->size += 1;
}
void* list_pop(list_t* lt)
{
	if (lt->size == 0)
	{
		return NULL;
	}
	list_node_t* node = lt->head;
	void* ret_val = node->data;
	lt->size -= 1;
	lt->head = node->next;

	free(node);

	if (lt->size == 0)
	{
		lt->head = NULL;
		lt->tail = NULL;
	}
	return ret_val;

}


void list_push_back(list_t* lt, void* data)
{
	list_node_t* node = malloc(sizeof(list_node_t));
	node->data = data;
	if (lt->tail != NULL)
		lt->tail->next = node;
	else
	{
		lt->head = node;
	}
	lt->tail = node;
	lt->size += 1;
}

typedef struct tree
{
	int key;
	struct tree* left;
	struct tree* right;
	struct tree* middle;
	int isVisited;
} node;
node* create(node* root, int key)
{
	node* tmp = malloc(sizeof(node));
	tmp->key = key;
	tmp->middle = NULL;
	tmp->left = tmp->right = NULL;
	root = tmp;
	return root;
}
node* add(node* root, int key)
{
	node* root2 = root, * root3 = NULL;
	node* tmp = malloc(sizeof(node));
	tmp->key = key;
	while (root2 != NULL)
	{
		root3 = root2;
		if (key < root2->key)
			root2 = root2->left;
		else if (key > root2->key)
			root2 = root2->right;
		else
			root2 = root2->middle;
	}

	tmp->left = NULL;
	tmp->middle = NULL;
	tmp->right = NULL;
	tmp->isVisited = 0;

	if (key < root3->key)
		root3->left = tmp;
	else if (key > root3->key)
		root3->right = tmp;
	else
		root3->middle = tmp;
	return root;
}
static int count = 0;
node* search(node* root, int key)
{

	if ((root == NULL) || (root->key == key))
		return root;
	if (key < root->key)
	{
		count++;
		return search(root->left, key);
	}
	else if (key > root->key)
	{
		count++;
		return search(root->right, key);
	}
	else
	{
		count++;
		return search(root->middle, key);
	}
}

int min(x, z, y)
{
	if (x < y)
		return x;
	else if (x > y)
		return y;
	else
		return z;
}

int searchInDeep(node* root, int element, int i)
{
	int FoundInL = NULL; // Found in Left child
	int FoundInM = NULL;
	int FoundInR = NULL;
	if (root->key == element) // if Find return level+1
	{
		return i + 1;
	}
	else
	{
		FoundInL = -1;
		if (root->left != NULL)
		{
			FoundInL = searchInDeep(root->left, element, i + 1);
		}
		FoundInM = -1;
		if (root->middle != NULL)
		{
			FoundInM = searchInDeep(root->middle, element, i + 1);
		}
		FoundInR = -1;
		if (root->right != NULL)
		{
			FoundInR = searchInDeep(root->right, element, i + 1);
		}
		if (FoundInL == -1) // esli net v L
		{
			return FoundInR;
		}
		else if (FoundInR == -1)
		{
			return FoundInL;
		}
		else
		{
			return min(FoundInL, FoundInM, FoundInR);
		}

	}
}




int tree()
{
	node* derevo = NULL;
	derevo = create(derevo, 0);
	printf("Enter tree elems \n");
	int elem;
	int length = 0;
	/*
	for (int i = 0; i < 8; i++)
	{
		scanf_s("%d", &elem);
		add(derevo, elem);
	}
	printf("Enter element to find length \n");
	scanf_s("%d", &elem);
	length = searchInDeep(derevo, elem);
	printf("%d", length);*/



	add(derevo, 0);
	add(derevo, 0);

	add(derevo, -1);
	add(derevo, -2);
	add(derevo, -1);

	add(derevo, 1);
	add(derevo, 1);
	add(derevo, 2);
	add(derevo, 3);

	length = searchInDeep(derevo, -2, -1);

	printf("%d", length);
	return 0;
}













//typedef struct Node
//{
//	int iKey;
//	struct Node* pLeft;
//	struct Node* pMiddle;
//	struct Node* pRight;
//} Node_t;
//
//void Add(Node_t* pNode, int iData)
//{
//	if (pNode == NULL)
//	{
//		pNode = malloc(sizeof(struct Node));
//		memset(pNode, 0, sizeof(struct Node));
//		pNode->iKey = iData;
//		return;
//	}
//
//	if (iData < pNode->iKey)
//	{
//		 Add(pNode->pLeft, iData);
//	}
//	else if (iData > pNode->iKey)
//	{
//		 Add(pNode->pRight, iData);
//
//	}
//	else
//	{
//		Add(&pNode->pMiddle, iData);
//
//	}
//}
//
//void Print(struct Node* pNode)
//{
//	if (!pNode)
//	{
//		return;
//	}
//
//	Print(pNode->pLeft);
//	printf("%d,", pNode->iKey);
//	Print(pNode->pMiddle);
//	Print(pNode->pRight);
//}
//
//struct Node* Search(struct Node* pNode, int iWhat)
//{
//	if (!pNode)
//	{
//		return NULL;
//	}
//
//	if (iWhat < pNode->iKey)
//	{
//		return Search(pNode->pLeft, iWhat);
//	}
//	else if (iWhat > pNode->iKey)
//	{
//		return Search(pNode->pRight, iWhat);
//	}
//	else
//	{
//		return Search(pNode->pMiddle, iWhat);
//	}
//}
//
//int main()
//{
//	Node_t (*pRoot) = NULL;
//
//	for (int i = 0; i < 10; ++i)
//	{
//		 Add(&pRoot, i);
//	}
//
//	Print(&pRoot);
//
//	printf("\n");
//
//	return 0;
//
//}