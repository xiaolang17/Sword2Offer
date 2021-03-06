// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <string>

using namespace std;

  struct ListNode {
       int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };
  struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  struct RandomListNode {
  int label;
  struct RandomListNode *next, *random;
  RandomListNode(int x) :
  label(x), next(NULL), random(NULL) {
  }
  };

  struct TreeLinkNode {
  int val;
  struct TreeLinkNode *left;
  struct TreeLinkNode *right;
  struct TreeLinkNode *next;
  TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

  }
  };
  
  



//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution_1 {
public:
	bool Find(int target, vector<vector<int>> array) {
		int l = array.size();
		int m = array[0].size();
		for (int i = 0; i<l; i++)
			for (int j = 0; j<m; j++)
			{
				if (array[i][j] == target)
					return true;
			}
		return false;
	}
};
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution_2 {
public:
	bool Find(int target, vector<vector<int>> array) {
		for (vector<vector<int>>::iterator x = array.begin(); x != array.end(); x++)
		{
			for (vector<int>::iterator y = x->begin(); y != x->end(); y++)
			{
				if (*y == target)
					return true;
			}
		}
		return false;
	}
};
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution_3 {
public:
	void replaceSpace(char *str, int length) {
		char *dest = str;
		int n = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				n++;
		}
		int j = length + n * 2 - 1;
		for (int i = length - 1; i >= 0; i--)
		{
			if (dest[i] == ' ')
			{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
			}
			else
			{
				str[j--] = dest[i];
			}
		}
	}
};

//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution_4 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>  list;
		vector<int>  result;
		ListNode* temp = head;
		while (temp != NULL) {
			list.push_back(temp->val);
			temp = temp->next;
		}
		for (int i = list.size() - 1; i >= 0; i--) {
			result.push_back(list[i]);
		}
		return result;
	}
};
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
using namespace std;
class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
			return NULL;
		TreeNode* fina = new TreeNode(pre[0]);
		int i;
		for (int j = 0; j<pre.size(); j++)
		{
			if (pre[0] == vin[j])
			{
				i = j;
				break;
			}
		}
		vector<int> left_in, left_pre, right_in, right_pre;
		for (int j = 0; j<i; j++)
		{
			left_in.push_back(vin[j]);
			left_pre.push_back(pre[j + 1]);//前序第一个为根节点
		}
		for (int j = i + 1; j<pre.size(); j++)
		{
			right_in.push_back(vin[j]);
			right_pre.push_back(pre[j]);
		}
		fina->left = reConstructBinaryTree(left_pre, left_in);
		fina->right = reConstructBinaryTree(right_pre, right_in);
		return fina;

	}
};
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
using namespace std;
class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
			return NULL;
		TreeNode* fina = new TreeNode(pre[0]);
		int i;
		for (i = 0; i<pre.size(); i++)
		{
			if (pre[0] == vin[i])
			{
				break;
			}
		}
		vector<int> lr_in, lr_pre;
		lr_pre.assign(pre.begin() + 1, pre.begin() + i + 1);
		lr_in.assign(vin.begin(), vin.begin() + i);
		fina->left = reConstructBinaryTree(lr_pre, lr_in);
		lr_pre.assign(pre.begin() + i + 1, pre.end());
		lr_in.assign(vin.begin() + i + 1, vin.end());
		fina->right = reConstructBinaryTree(lr_pre, lr_in);
		return fina;

	}
};
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}
	int pop() {
		int a;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();
		stack2.pop();
		return a;

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//题目描述
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
class Solution {
public:
	int minNumberInRotateArray(vector<int> array) {
		if (array.size() == 0)
			return 0;
		int left = 0;
		int right = array.size() - 1;
		int middle = -1;
		while (array[left] >= array[right]) {
			if (right - left == 1) {
				middle = right;
				break;
			}
			middle = left + (right - left) / 2;
			if (array[middle] >= array[left]) {
				left = middle;
			}
			if (array[middle] <= array[right]) {
				right = middle;
			}
		}
		return array[middle];
	}
};
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
//n <= 39
class Solution {
public:
	int Fibonacci(int n) {
		int a = 0, b = 1, c = 0;
		if (n<2)
			b = n;
		for (int i = 0; i<n - 1; i++)
		{
			c = b;
			b = a + b;
			a = c;
		}
		return b;
	}
};
//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 2)
			return number;
		else
			return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};
//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloorII(int number) {
		int a = 1;
		for (int i = 1; i<number; i++)
		{
			a += jumpFloorII(number - i);
		}
		return a;
	}
};
//题目描述
//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
class Solution {
public:
	int rectCover(int number)
	{
		if (number <= 2)
			return number;
		return rectCover(number - 2) + rectCover(number - 1);
	}
};
//
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
class Solution {
public:
	int  NumberOf1(int n) {
		int flag = 1, a = 0;
		while (flag)
		{
			if (n&flag)
				a++;
			flag = flag << 1;
		}
		return a;
	}
};
////给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution {
public:
	double Power(double base, int exponent) {
		double data = 1;
		if (exponent >= 0)
		{
			for (int i = 0; i<exponent; i++)
				data *= base;
			return data;
		}
		else
		{
			for (int i = 0; i<-exponent; i++)
				data *= base;
			data = 1 / data;
			return data;

		}
	}
};
//题目描述
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> ou;
		for (auto iter = array.begin(); iter != array.end(); iter++)
		{
			if (*iter % 2 == 1)
			{
				ou.push_back(*iter);
			}
		}
		for (auto iter = array.begin(); iter != array.end(); iter++)
		{
			if (*iter % 2 == 0)
			{
				ou.push_back(*iter);
			}
		}
		array = ou;
	}
};
//输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *pList = pListHead, *a = pListHead;
		int i = 0;
		for (; pList != NULL; i++)
		{
			pList = pList->next;
			if (i >= k)
				a = a->next;
		}
		return i<k ? NULL : a;
	}
};
//题目描述输入一个链表，反转链表后，输出新链表的表头。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode * ReverseList(ListNode* pHead) {
		ListNode* p1, *p2, *p3;
		if (pHead == NULL)
			return NULL;
		p1 = pHead;
		p3 = NULL;
		p2 = NULL;
		while (p1)
		{
			p2 = p1->next;
			p1->next = p3;
			if (p3 == pHead)
				p3->next = NULL;
			p3 = p1;
			p1 = p2;
		}
		return p3;
	}
};
//题目描述
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;
		ListNode* Head = NULL;
		if (pHead1->val<pHead2->val)
		{
			Head = pHead1;
			Head->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			Head = pHead2;
			Head->next = Merge(pHead1, pHead2->next);
		}
		return Head;
	}
};
//题目描述
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 /*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	bool doseAB(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL && pRoot2 != NULL) return false;
		if (pRoot2 == NULL) return true;
		if (pRoot1->val == pRoot2->val)
			return doseAB(pRoot1->left, pRoot2->left) && doseAB(pRoot1->right, pRoot2->right);
		else
			return false;
	}
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool a = false;
		if (pRoot1 != NULL && pRoot2 != NULL)
		{
			a = doseAB(pRoot1, pRoot2);
			if (a == false)
			{
				return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return a;
	}

};
//题目描述
//操作给定的二叉树，将其变换为源二叉树的镜像。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot)
		{
			TreeNode *pR = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = pR;
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	}
};
//题目描述
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> a;
		int row = matrix.size();
		int column = matrix[0].size();
		int circle = ((row<column ? row : column) - 1) / 2 + 1;
		for (int i = 0; i<circle; i++)
		{
			for (int j = i; j<column - i; j++)
				a.push_back(matrix[i][j]);
			for (int j = i + 1; j<row - i; j++)
				a.push_back(matrix[j][column - i - 1]);//ok
			for (int j = column - 2 - i; (j>i - 1) && (row - i - 1 != i); j--)
				a.push_back(matrix[row - i - 1][j]);//
			for (int j = row - 2 - i; (j>i) && (column - i - 1 != i); j--)
				a.push_back(matrix[j][i]);
		}
		return a;
	}
};
//题目描述
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））
class Solution {
public:
	void push(int value) {
		StackInt.push(value);
		if (Stack2.empty())
			Stack2.push(value);
		if (value <= Stack2.top())
			Stack2.push(value);
	}
	void pop() {
		if (StackInt.top() == Stack2.top())
			Stack2.pop();
		StackInt.pop();
	}
	int top() {
		return StackInt.top();
	}
	int min() {
		return Stack2.top();
	}
private:
	stack<int> StackInt;
	stack<int> Stack2;
};
//题目描述
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> st;
		int n = 0;
		for (int i = 0; i<popV.size(); i++)
		{
			if (!st.empty() && st.top() == popV[n])
			{
				st.pop(); n++;
			}
			if ((pushV[i] == popV[n]))
			{
				n++;
			}
			else
				st.push(pushV[i]);
		}
		if (!st.empty() || n != popV.size())
			for (int i = n; i<popV.size(); i++)
			{
				if (!st.empty() && st.top() == popV[n])
				{
					n++;
					st.pop();
				}
			}
		if (st.empty())
			return true;
		else
			return false;
	}
};



/////////////////////////////////////////////////////////////////


//题目描述
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> data;
		queue<TreeNode*> q;
		if (root == NULL) return data;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* fr = q.front();
			data.push_back(fr->val);
			if (fr->left)
				q.push(fr->left);
			if (fr->right)
				q.push(fr->right);
			q.pop();
		}
		return data;
	}
};
//题目描述
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
class Solution {
public:
	bool judge(vector<int> seq, int l, int r)
	{
		if (l >= r)return true;
		int i = r;
		while (i>l&&seq[i - 1]>seq[r])--i;
		for (int j = l; j<i - 1; j++)if (seq[j]>seq[r])return false;
		return judge(seq, l, i - 1) && judge(seq, i, r - 1);

	}
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;
		return judge(sequence, 0, sequence.size() - 1);
	}
};

//二叉树中和为某一值的路径
//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	vector<vector<int> > data;
	vector<int> da;
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (!root) return data;
		da.push_back(root->val);
		if ((expectNumber - root->val) == 0 && (root->left == NULL) && (root->right == NULL))
		{
			data.push_back(da);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
		if (da.size() != 0)
			da.pop_back();
		return data;

	}
};

//题目描述
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (!pHead) return NULL;
		RandomListNode *currNode = pHead;
		while (currNode)
		{
			RandomListNode *cu = new RandomListNode(currNode->label);
			cu->next = currNode->next;
			currNode->next = cu;
			currNode = cu->next;
		}
		currNode = pHead;
		while (currNode) {
			RandomListNode *node = currNode->next;
			if (currNode->random)
				node->random = currNode->random->next;
			currNode = node->next;
		}
		RandomListNode *pCloneHead = pHead->next;
		RandomListNode *tmp;
		currNode = pHead;
		while (currNode->next)
		{
			tmp = currNode->next;
			currNode->next = tmp->next;
			currNode = tmp;
			// currNode->next=tmp->next;
		}
		return pCloneHead;
	}
};

//题目描述
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:void Cover(TreeNode* pRootof, TreeNode* &p)
{
	if (pRootof == NULL)return;
	Cover(pRootof->left, p);
	pRootof->left = p;
	if (p)p->right = pRootof;
	p = pRootof;
	Cover(pRootof->right, p);

}
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;
		TreeNode* p = nullptr;
		Cover(pRootOfTree, p);
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;
	}

};


//题目描述
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。
//输入描述:
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
class Solution {
public:void PermutationHelp(vector<string> &ans, int k, string str) //遍历第k位的所有可能
{
	if (k == str.size() - 1)
		ans.push_back(str);
	unordered_set<char> us;
	sort(str.begin() + k, str.end());
	for (int i = k; i<str.size(); i++)
	{
		if (us.find(str[i]) == us.end())
		{
			us.insert(str[i]);
			swap(str[k], str[i]);
			PermutationHelp(ans, k + 1, str);
			swap(str[i], str[k]);
		}
	}
}
public:vector<string> Permutation(string str) {
	vector<string> ans;
	PermutationHelp(ans, 0, str);
	return ans;
}
};


//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> a;
		for (int i = 0; i<numbers.size(); i++)
		{
			a[numbers[i]]++;
			if (a[numbers[i]]>numbers.size() / 2)
			{
				return numbers[i];
			}
		}
		return 0;
	}
};

//最小的K个数
//题目描述
//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.empty() || k>input.size()) return res;
		sort(input.begin(), input.end());
		for (int i = 0; i<k; i++)
			res.push_back(input[i]);
		return res;
	}
};
//连续子数组的最大和
//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中, 常常需要计算连续子向量的最大和, 当向量全为正数的时候, 问题很好解决。但是, 如果向量中包含负数, 是否应该包含某个负数, 并期望旁边的正数会弥补它呢？例如:{6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
	class Solution {
	public:
		int FindGreatestSumOfSubArray(vector<int> array) {
			int max = array[0];
			int a;
			for (auto iter = array.begin(); iter != array.end(); iter++)
			{
				a = *iter;
				if (max<a)max = a;
				for (auto it = iter + 1; it != array.end(); it++)
				{
					a += *it;
					if (a>max)max = a;
				}
			}
			return max;
		}
};


//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次, 但是对于后面问题他就没辙了。ACMer希望你们帮帮他, 并把问题更加普遍化, 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
	class Solution {
	public:
		int NumberOf1Between1AndN_Solution(int n)
		{
			int a = 0;
			for (int i = 1; i <= n; i++)
			{
				int b = i;
				while (i >= 1)
				{
					if (i % 10 == 1)
						a++;
					i = i / 10;
				}
				i = b;
			}
			return a;
		}
	};

//把数组排成最小的数字
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{ 3，32，321 }，则打印出这三个数字能排成的最小数字为321323。
	class Solution {
	public:
		string PrintMinNumber(vector<int> numbers) {
			int len = numbers.size();
			if (len == 0) return "";
			sort(numbers.begin(), numbers.end(), cmp);
			string res = "";
			for (int i = 0; i<len; i++)
				res += to_string(numbers[i]);
			return res;
		}
	public: bool static cmp(int a, int b)
	{
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A<B;
	}
	};


//丑数
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index<7) return index;
		vector<int> res(index);
		res[0] = 1;
		int t1 = 0, t2 = 0, t3 = 0;
		for (int i = 1; i<index; i++)
		{
			res[i] = min(res[t1] * 2, min(res[t2] * 3, res[t3] * 5));
			if (res[i] == res[t1] * 2)t1++;
			if (res[i] == res[t2] * 3)t2++;
			if (res[i] == res[t3] * 5)t3++;
		}
		return res[index - 1];
	}
};

//题目描述
//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		map<char, int> mp;
		for (int n = 0; n<str.size(); n++)
			mp[str[n]]++;
		for (int n = 0; n<str.size(); n++)
			if (mp[str[n]] == 1)
				return n;
		return -1;
	}
};
//题目描述
//数组中的逆序对
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组, 求//
//出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P % 1000000007
//输入描述:
//题目保证输入的数组中没有的相同的数字
//
//数据范围：
//
//对于 % 50的数据, size <= 10 ^ 4
//
//对于 % 75的数据, size <= 10 ^ 5
//
//对于 % 100的数据, size <= 2 * 10 ^ 5
//
//示例1
//输入
//复制
//1, 2, 3, 4, 5, 6, 7, 0
//输出
//复制
//7
class Solution {
public:
	int InversePairs(vector<int> data) {
		int length = data.size();
		if (length <= 0)
			return 0;
		vector<int> copy;
		for (int i = 0; i<length; i++)
			copy.push_back(data[i]);
		long long count = InversePairsCore(data, copy, 0, length - 1);
		//delete[]copy;
		return count % 1000000007;
	}
	long long InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
	{
		if (start == end)
		{
			copy[start] = data[start];
			return 0;
		}
		int length = (end - start) / 2;
		long long left = InversePairsCore(copy, data, start, start + length);
		long long right = InversePairsCore(copy, data, start + length + 1, end);
		int i = start + length;
		int j = end;
		int indexcopy = end;
		long long count = 0;
		while (i >= start && j >= start + length + 1)
		{
			if (data[i]>data[j])
			{
				copy[indexcopy--] = data[i--];
				count = count + j - start - length;          //count=count+j-(start+length+1)+1;
			}
			else
			{
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= start; i--)
			copy[indexcopy--] = data[i];
		for (; j >= start + length + 1; j--)
			copy[indexcopy--] = data[j];
		return left + right + count;
	}
};





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//题目描述
//输入两个链表，找出它们的第一个公共结点。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
//长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
//长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共，一起到结尾NULL。
class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1 != p2)
		{
			p1 = (p1 == NULL ? pHead2 : p1->next);
			p2 = (p2 == NULL ? pHead1 : p2->next);
		}
		return p1;
	}
};


//统计一个数字在排序数组中出现的次数。
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int a = 0;
		if (data.empty())return 0;
		for (auto iter = data.begin(); iter != data.end(); iter++)
			if (*iter == k)a++;
		return a;
	}
};

//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int l = TreeDepth(pRoot->left);
		int r = TreeDepth(pRoot->right);
		return l>r ? l + 1 : r + 1;
	}
};


//题目描述
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;
		int left = get_depth(pRoot->left);
		int right = get_depth(pRoot->right);
		if (left > right + 1 || left + 1 < right)
			return false;
		else
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

	}
public:
	int get_depth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int left = get_depth(pRoot->left);
		int right = get_depth(pRoot->right);
		return left>right ? left + 1 : right + 1;
	}

};

////一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		vector<int> da;
		vector<int> dad;
		bool a = false;
		for (auto iter = data.begin(); iter != data.end(); iter++)
		{
			for (auto it = iter + 1; it != data.end(); it++)
			{
				if (*iter == *it)
				{
					da.push_back(*iter);
				}
			}
		}
		for (auto iter = data.begin(); iter != data.end(); iter++)
		{
			for (auto it = da.begin(); it != da.end(); it++)
			{
				if (*iter == *it)
				{
					a = true;
				}
			}
			if (!a)
			{
				dad.push_back(*iter);
			}
			a = false;
		}
		*num1 = dad[0];
		*num2 = dad[1];
	}
};


//和为S的连续正数序列
//小明很喜欢数学, 有一天他在做数学作业时, 要求计算出9~16的和, 他马上就写出了正确答案是100。但是他并不满足于此, 他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久, 他就得到另一组连续正数和为100的序列:18, 19, 20, 21, 22。现在把问题交给你, 你能不能也很快的找出所有和为S的连续正数序列 ? Good Luck!
//输出描述 :
//	输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
//根据数学公式计算:(a1+an)*n/2=s  n=an-a1+1
//(an+a1)*(an-a1+1)=2*s=k*l(k>l)
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > data;
		int ph = 2, pl = 1;
		while (ph>pl)
		{
			int cur = (ph + pl)*(ph - pl + 1) / 2;
			if (cur<sum)
				ph++;
			if (cur == sum) {
				vector<int> res;
				for (int i = pl; i <= ph; i++)
					res.push_back(i);
				data.push_back(res);
				pl++;
			}
			if (cur>sum)
				pl++;
		}
		return data;
	}
};




//和为S的两个数字
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
//输出描述 :
//对应每个测试案例，输出两个数，小的先输出。
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> out;
		int n = array.size();
		int i = 0;
		int j = n - 1;
		while (i<j)
		{
			if ((array[i] + array[j])>sum)
				j--;
			if ((array[i] + array[j])<sum)
				i++;
			if ((array[i] + array[j]) == sum)
			{
				out.push_back(array[i]);
				out.push_back(array[j]);
				break;
			}
		}
		return out;
	}
};


//汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
class Solution {
public:
	string LeftRotateString(string str, int n) {
		string st;
		int len = str.size();
		if (len == 0 || n == 0)
			return str;
		n = n % len;
		for (int i = 0; i<len; i++)
		{
			if (i<(len - n))
			{
				st[i] = str[i + n];
			}
			else
				st[i] = str[i - len + n];
		}
		return st;
	}
};

class Solution {
public:
	string LeftRotateString(string str, int n) {
		string st = "";
		int len = str.size();
		if (len == 0 || n == 0)
			return str;
		st = str.substr(0, n);
		str.erase(0, n);
		str += st;
		return str;
	}
};


//翻转单词序列
//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
class Solution {
public:
	string ReverseSentence(string str) {
		auto size = str.size();
		if (size == 0) return "";
		int mark = 0;
		str += ' ';
		for (int i = 0; i<size + 1; i++)
		{
			if (str[i] == ' ')
			{
				ReverseWord(str, mark, i - 1);
				mark = i + 1;
			}
		}
		str = str.substr(0, size);
		ReverseWord(str, 0, size - 1);
		return str;
	}
	void ReverseWord(string &str, int l, int r) {
		while (l < r) {
			swap(str[l], str[r]);
			++l;
			--r;
		}
	}
};


//扑克牌
//LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		int max = 0;
		int min = 14;
		if (numbers.empty())
			return false;
		for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
		{
			if (*iter>max)
				max = *iter;
			if ((*iter<min) && (*iter != 0))
				min = *iter;
			for (auto it = iter + 1; it != numbers.end(); it++)
			{
				if ((*iter == *it) && (*iter != 0))
				{
					return false;
				}
			}
		}
		if ((max - min)>4)
			return false;
		return true;
	}
};
//题目描述
//每年六一儿童节, 牛客都会准备一些小礼物去看望孤儿院的小朋友, 今年亦是如此。HF作为牛客的资深元老, 自然也准备了一些小游戏。其中, 有个游戏是这样的:首先, 让小朋友们围成一个大圈。然后, 他随机指定一个数m, 让编号为0的小朋友开始报数。每次喊到m - 1的那个小朋友要出列唱首歌, 然后可以在礼品箱中任意的挑选礼物, 并且不再回到圈中, 从他的下一个小朋友开始, 继续0...m - 1报数....这样下去....直到剩下最后一个小朋友, 可以不用表演, 并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下, 哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n - 1)
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		else
		{
			return (LastRemaining_Solution(n - 1, m) + m) % n;
		}
	}

};
//题目描述
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		bool ans = (n>0) && ((sum += Sum_Solution(n - 1))>0);
		return sum;
	}
};



//题目描述
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
class Solution {
public:
	int Add(int num1, int num2)
	{
		return num2 ? Add(num1^num2, (num2&num1) << 1) : num1;
	}
};
//题目描述
//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)
//，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
//输入描述:
//输入一个字符串,包括数字字母符号,可以为空
//输出描述:
//如果是合法的数值表达则返回该数字，否则返回
class Solution {
public:
	int StrToInt(string str) {
		int n = str.size(), s = 1, a = 0;
		if (n == 0)return 0;
		if (str[0] == '-')s = -1;
		for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i<n; i++)
		{
			if ((str[i]<'0') || (str[i]>'9'))return 0;
			a = a * 10 + str[i] - '0';
		}
		return a * s;
	}
};


//在一个长度为n的数组里的所有数字都在0到n - 1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{ 2,3,1,0,2,5,3 }，那么对应的输出是第一个重复的数字2。
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		map<int, int> a;
		if (numbers == NULL || length == 0 || duplication == NULL) return 0;
		for (int i = 0; i<length; i++)
			for (int j = i + 1; j<length; j++)
			{
				if (numbers[i] == numbers[j])
				{
					*duplication = numbers[i];
					return true;
				}
			}
		return false;

	}
};

//构建乘积数组
//给定一个数组A[0, 1, ..., n - 1], 请构建一个数组B[0, 1, ..., n - 1], 其中B中的元素B[i] = A[0] * A[1] * ...*A[i - 1] * A[i + 1] * ...*A[n - 1]。不能使用除法。
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int> B(len);
		if (len != 0)
		{
			B[0] = 1;
			for (int i = 1; i<len; i++)
				B[i] = B[i - 1] * A[i - 1];
			int dada = 1;
			for (int i = len - 1; i>0; i--)
			{
				dada *= A[i];
				B[i - 1] *= dada;
			}
		}
		return B;

	}
};
//正则表达式匹配
//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == 0 && *pattern == 0)return true;
		if (*str != 0 && *pattern == 0)return false;
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*str != 0 && *pattern == '.'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		else
		{
			if (*str == *pattern || (*str != 0 && *pattern == '.'))
				return match(str + 1, pattern) || match(str, pattern + 2);
			else
				return match(str, pattern + 2);
		}
	}
};


//题目描述
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和" - 1E-16"都表示数值。 但是"12e","1a3.14","1.2.3"," + -5"和"12e+4.3"都不是。
class Solution {
public:
	bool isNumeric(char* str)
	{
		bool sign = false, decimal = false, hasE = false;
		for (int i = 0; i<strlen(str); i++)
		{
			if (str[i] == 'e' || str[i] == 'E') {
				if (i == (strlen(str) - 1))return false;
				if (hasE)return false;
				hasE = true;
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				if (sign&&str[i - 1] != 'e'&&str[i - 1] != 'E')return false;
				if (!sign&&i>0 && str[i - 1] != 'e'&&str[i - 1] != 'E')return false;
				sign = true;
			}
			else if (str[i] == '.')
			{
				if (hasE || decimal) return false;
				decimal = true;
			}
			else if (str[i]<'0' || str[i]>'9')
			{
				return false;
			}
		}
		return true;
	}

};


//题目描述
//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
//输出描述:
//如果当前字符流没有存在出现一次的字符，返回#字符。
class Solution
{
public:string str;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		has[ch]++;
		if (has[ch] == 1)
			data.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!data.empty() && has[data.front()] >= 2) {
			data.pop();
		}
		if (data.empty())
			return '#';
		return data.front();
	}
private:
	unsigned char has[128];
	queue<char> data;

};




//题目描述
//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* fast = pHead, *slow = pHead;
		if (pHead == NULL || pHead->next == NULL) return NULL;
		while (fast->next->next&&slow->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				if (slow == pHead)
					return pHead;
				while (pHead->next&&slow->next)
				{
					slow = slow->next;
					pHead = pHead->next;
					if (slow == pHead)
						return slow;
				}
			}

		}
		return NULL;
	}
};




//题目描述
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode * deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return pHead;
		ListNode* node;
		if (pHead->val == pHead->next->val)
		{
			node = pHead->next;
			while (node&&node->val == pHead->val)
				node = node->next;
			//while(node->next&&node->val==node->next->val) 重复数字变成数量为1
			return deleteDuplication(node);
		}
		else
		{
			pHead->next = deleteDuplication(pHead->next);
			return pHead;
		}
	}
};


/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode * deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)return pHead;
		if (pHead->val == pHead->next->val)
		{
			ListNode* pNode = pHead->next;
			while (pNode != NULL && pNode->val == pHead->val)
				pNode = pNode->next;
			return deleteDuplication(pNode);
		}
		else
		{
			pHead->next = deleteDuplication(pHead->next);
			return pHead;
		}

	}
};


//题目描述
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};
*/
class Solution {
public:
	TreeLinkNode * GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr) {
			return nullptr;
		}
		TreeLinkNode* next = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode* a = pNode->right;
			while (a->left)
			{
				a = a->left;
			}
			next = a;
		}            //向父结点遍历
		else if (pNode->next != nullptr) {
			TreeLinkNode* parentNode = pNode->next;
			TreeLinkNode* currentNode = pNode;
			while (parentNode != nullptr  && currentNode == parentNode->right) {
				currentNode = parentNode;
				parentNode = parentNode->next;
			}
			next = parentNode;
		}
		return next;
	}
};


//题目描述请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr&&pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2 ->left);
	}
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		return isSymmetrical(pRoot->left, pRoot->right);
	}
};


//题目描述请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > vv;
		vector<int> ve;
		queue<TreeNode*> q;
		queue<int> d;
		int depth = 0;
		bool i = true;
		TreeNode* node;
		if (pRoot)
		{
			q.push(pRoot);
			d.push(depth);
		}
		while (!q.empty())
		{
			node = q.front();
			if (depth != d.front())
			{
				depth = d.front();
				if (i)
				{
					vv.push_back(ve);
					i = !i;
				}
				else
				{
					vector<int> v;
					for (auto riter = ve.rbegin(); riter != ve.rend(); riter++)
					{
						v.push_back(*riter);
					}
					vv.push_back(v);
					i = !i;
				}
				ve.clear();
			}
			q.pop();
			d.pop();
			if (node)
			{
				q.push(node->left);
				q.push(node->right);
				d.push(depth + 1);
				d.push(depth + 1);
				ve.push_back(node->val);
			}
		}
		return vv;
	}

};

//题目描述
//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> vv;
		vector<int> ve;
		queue<TreeNode*> que;
		queue<int> dque;
		int depth = 0;
		TreeNode *node;
		if (pRoot)
		{
			que.push(pRoot);
			dque.push(depth);
		}
		while (!que.empty())
		{
			node = que.front();
			if (depth != dque.front())
			{
				vv.push_back(ve);
				ve.clear();
				depth = dque.front();
			}
			que.pop();
			dque.pop();
			if (node)
			{
				que.push(node->left);
				que.push(node->right);
				dque.push(depth + 1);
				dque.push(depth + 1);
				ve.push_back(node->val);
			}
		}
		return vv;
	}

};

//题目描述
//请实现两个函数，分别用来序列化和反序列化二叉树
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
typedef int* pint;
class Solution {
public:
	vector<int> buf;
	void dfs1(TreeNode* p) {
		if (!p)buf.push_back(0x1fffffff);
		else {
			buf.push_back(p->val);
			dfs1(p->left);
			dfs1(p->right);
		}
	}
	TreeNode* dfs2(int* &p) {
		if (*p == 0x1fffffff)
		{
			p++;
			return NULL;
		}
		TreeNode *pp = new TreeNode(*p);
		p++;
		pp->left = dfs2(p);
		pp->right = dfs2(p);
		return pp;
	}
public:
	char* Serialize(TreeNode *p) {
		buf.clear();
		dfs1(p);
		int *r = new int[buf.size()];
		for (int i = 0; i<buf.size(); i++)r[i] = buf[i];
		return (char*)r;

	}
	TreeNode* Deserialize(char *str) {
		int *p = (int*)str;
		return dfs2(p);
	}
};

//题目描述
//给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:  vector<int> data;
public:  TreeNode * fina;
public:
	void search(TreeNode* p)
	{
		if (p)
		{
			data.push_back(p->val);
			search(p->left);
			search(p->right);
		}
	}
public:
	TreeNode * get_TreeNode(TreeNode* p, int d)
	{
		if (p)
		{
			if (p->val == d)
			{
				return p;
			}
			fina = get_TreeNode(p->left, d);
			fina = get_TreeNode(p->right, d);
		}
		return fina;
	}
public:
	TreeNode * KthNode(TreeNode* pRoot, int k)
	{
		if (!pRoot || k < 1) return nullptr;
		search(pRoot);
		if (data.size()<k) return nullptr;
		sort(data.begin(), data.end());
		return get_TreeNode(pRoot, data[k - 1]);
	}
};


//题目描述
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
class Solution {
private:
	vector<int> min;
	vector<int> max;
public:
	void Insert(int num)
	{
		int size = min.size() + max.size();
		if ((size & 1) == 0)
		{
			if (max.size()>0 && num<max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else
		{
			if (min.size()>0 && num>min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = min.size() + max.size();
		if (size <= 0)
			return 0;
		if ((size & 1) == 0)
			return (max[0] + min[0]) / 2.0;
		else
			return min[0];
	}

};



//题目描述
//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{ 2,3,4,2,6,2,5,1 }及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{ 4,4,6,6,6,5 }；针对数组{ 2,3,4,2,6,2,5,1 }的滑动窗口有以下6个：{ [2,3,4],2,6,2,5,1 }，{ 2,[3,4,2],6,2,5,1 }，{ 2,3,[4,2,6],2,5,1 }，{ 2,3,4,[2,6,2],5,1 }，{ 2,3,4,2,[6,2,5],1 }，{ 2,3,4,2,6,[2,5,1] }。
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> data;
		int max = 0;
		if (size == 0) return data;
		for (int i = 0; i<num.size() - size + 1; i++)
		{
			for (int j = i; j<i + size; j++)
			{
				if (max<num[j])
					max = num[j];
			}
			data.push_back(max);
			max = 0;
		}
		return data;
	}
};



//题目描述
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任
//意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的
//某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条
//字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二
//个格子之后，路径不能再次进入该格子。
class Solution {
public:
	bool isPath(char* matrix, int rows, int cols, char* str, int i, int j, vector<char> flags)
	{
		if (i<0 || i >= rows || j<0 || j >= cols) //越界的点
			return false;
		if ((*str != matrix[i*cols + j]) || (flags[i*cols + j] == 1))return false;
		flags[i*cols + j] = 1;
		if (*(str + 1) == 0)return true;
		bool f = isPath(matrix, rows, cols, str + 1, i + 1, j, flags) ||
			isPath(matrix, rows, cols, str + 1, i - 1, j, flags) ||
			isPath(matrix, rows, cols, str + 1, i, j + 1, flags) ||
			isPath(matrix, rows, cols, str + 1, i, j - 1, flags);
		if (f == false)flags[i*cols + j] = 0;
		return f;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		vector<char> flags(rows*cols, 0);
		if (*str == 0) return true;
		for (int i = 0; i<rows; i++)
			for (int j = 0; j<cols; j++)
			{
				if (isPath(matrix, rows, cols, str, i, j, flags))
					return true;
			}
		return false;
	}


};



//题目描述
//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方
//向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35, 37），因为3 + 5 + 3 + 7 = 18。但是，它不能进入方格（35, 38），因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子？

class Solution {
public:
	int getsum(int num)
	{
		int sum = 0;
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
	int move(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		int count = 0;
		if ((i >= 0) && (i<rows) && (j >= 0) && (j<cols) && ((getsum(i) + getsum(j)) <= threshold) && flag[i *

			cols + j] == false)
		{
			flag[i * cols + j] = true;
			count = 1 + move(threshold, rows, cols, i + 1, j, flag)
				+ move(threshold, rows, cols, i - 1, j, flag)
				+ move(threshold, rows, cols, i, j - 1, flag)
				+ move(threshold, rows, cols, i, j + 1, flag);
		}
		return count;
	}

	int movingCount(int threshold, int rows, int cols)
	{
		bool *flag = new bool[rows*cols];
		for (int i = 0; i<rows*cols; i++)
			flag[i] = false;
		return move(threshold, rows, cols, 0, 0, flag);
	}
};

//int main()
//{
//	//vector<vector<int>> array(20,vector<int>(5,2));
//	vector< vector<int> > array(10, vector<int>(5));
//	vector<vector<vector<int>> > array_3(10,vector<vector<int>>(5,vector<int>(2,0)));
//	Solution_1 *a= new Solution_1();
//	//bool x = a->Find(1, array);
//	cout << a->Find(1, array);
//	system("pause");
//    return 0;
//}
////


