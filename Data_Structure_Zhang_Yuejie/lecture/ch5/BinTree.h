#pragma once

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template<class U>
class Node {
	template<class T>
	friend class BinTree;
public:
	Node(U data = U(), Node<U>* leftChild = nullptr, Node<U>* rightChild = nullptr)
		: _data(data), _lc(leftChild), _rc(rightChild) {}
private:
	U _data;
	Node<U>* _lc;
	Node<U>* _rc;
};

template <class T>
class BinTree {
	using NodePtr = Node<T>*;
private:
	NodePtr _root;

public:
	BinTree(void) : _root(nullptr) {}

	// use preorder traversal to copy a btree
	BinTree(const BinTree& rhs) : _root(nullptr) {
		if (this == &rhs) {
			return;
		}
		_root = copyHelper(rhs._root);
	}

	NodePtr copyHelper(NodePtr curr) {
		if (!curr) {
			return nullptr;
		}
		NodePtr newNode = new Node<T>;
		newNode->_data = curr->_data;
		newNode->_lc = copyHelper(curr->_lc);
		newNode->_rc = copyHelper(curr->_rc);
		return newNode;
	}

	NodePtr parent(NodePtr start, NodePtr target) {
		// find the parent of target starting from start
		// first check if start is the parent, then
		// check left subtree using recurssion,
		// base case is start == nullptr, return nullptr
		if (!start) {
			return nullptr;
		}
		if (start->_lc == target || start->_rc == target) {
			return start;
		}
		else {
			if (parent(start->_lc, target) == nullptr) {
				return nullptr;
			}
			else {
				return parent(start->_rc, target);
			}
		}
	}

	void clear(NodePtr& start) {
		// also uses recurssion, clear left subtree, right subtree
		// clear start node
		if (!start) {
			clear(start->_lc);
			clear(start->_rc);
			delete start;

		}
		start = nullptr;  // prevent dangling pointer
	}

	

	void preOrderRecur(NodePtr start) {
		preOrderRecurHelper(start, 0);
	}

	void preOrderRecerParenth(NodePtr start) {
		if (start) {
			cout << start->_data;
			if (start->_lc) {
				cout << "(";
				preOrderRecerParenth(start->_lc);
				if (start->_rc)
				{
					cout << ",";
					preOrderRecerParenth(start->_rc);
				}
				cout << ")";
			}
		}
	}

	void preOrderRecurHelper(NodePtr start, int depth) {
		if (start != nullptr) {
			//cout << "depth = " << depth << endl;
			cout << string(depth * 2, '-');
			cout << start->_data << endl;
			preOrderRecurHelper(start->_lc, depth + 1);
			preOrderRecurHelper(start->_rc, depth + 1);
		}

	}

	void preOrderRecur() {
		preOrderRecerParenth(_root);
	}

	void preOrderStack() {
		preOrderStack(_root);
	}

	void preOrderStack(NodePtr start) {
		stack<NodePtr> st;
		st.push(start);
		while (!st.empty()) {
			NodePtr top = st.top();
			st.pop();
			cout << top->_data << " ";
			if (top->_rc) {
				st.push(top->_rc);
			}
			if (top->_lc) {
				st.push(top->_lc);
			}
		}
		cout << endl;
	}

	void levelOrder() {
		levelOrder(_root);
	}

	void levelOrder(NodePtr start) {
		queue<NodePtr> que;
		que.push(start);
		while (!que.empty()) {
			NodePtr front = que.front();
			que.pop();
			cout << front->_data << " ";
			if (front->_lc)
				que.push(front->_lc);
			if (front->_rc)
				que.push(front->_rc);
		}
		cout << endl;
	}

	void inOrderRecur() {
		inOrderRecur(_root);
	}

	void inOrderRecur(NodePtr start) {
		inOrderRecurHelper(start, 0);
	}

	void inOrderRecurHelper(NodePtr start, int depth) {
		if (start != nullptr) {
			//cout << "depth = " << depth << endl;
			inOrderRecurHelper(start->_lc, depth + 1);
			cout << string(depth * 2, '-');
			cout << start->_data << endl;
			inOrderRecurHelper(start->_rc, depth + 1);
		}

	}

	void inOrderStack() {
		inOrderStack(_root);
	}

	void inOrderStack(NodePtr start) {
		stack<NodePtr> st;
		st.push(start);
		NodePtr curr = start->_lc;
		while (!st.empty()) {
			// curr means the right subtree waiting to be pushed
			// so push curr instead of curr->_lc, which makes things
			// awkward
			while (curr) {
				st.push(curr);
				curr = curr->_lc;
			}
			if (!st.empty())
			{
				NodePtr top = st.top();
				st.pop();
				cout << top->_data << " ";
				if (top->_rc)
					curr = top->_rc;
			}
		}
		cout << endl;
	}

	// µË¿¡»Ô×ö·¨
	void postOrderStackDeng() {
		postOrderStackDeng(_root);
	}

	void postOrderStackDeng(NodePtr start) {
		stack<NodePtr> st;
		st.push(start);
		NodePtr curr = start;
		while (!st.empty()) {
			NodePtr top = st.top();
			if (top->_lc != curr && top->_rc != curr) {
				// top node is not curr's parent, then
				// curr is left child, top is right child
				goToHLVFL(st);
				// now top node is the successor
			}
			curr = st.top();
			st.pop();
			cout << curr->_data << " ";
		}
	}

	void goToHLVFL(stack<NodePtr>& st) {
		// go to as left as possible
		while (NodePtr top = st.top()) {
			if (top->_lc) {
				if (top->_rc) {
					st.push(top->_rc);
				}
				st.push(top->_lc);
			}
			else {
				st.push(top->_rc);
			}
		}
		// exit at leaf
		st.pop();
	}

	void preCreate(T prev[], NodePtr& currNode, int& n) {
		// T must be a char
		// n is the current node
		// or pass by reference, because we need to change
		// the pointer in the next recurssion
		// for instance, lc is currently nullptr, but in the next
		// recurssion, it is assigned a new Node's address,
		// if pass by value, then the currNode's lc will still be nullptr
		// also, int n is passed by reference, so that n is incremented
		// as we traverse the prev array.
		// In a word, currNode is decided in this recurssion, as we 
		// read from the array. It is not just an information, but something
		// we need to modify.
		T curr = prev[n++];
		if (curr == ';') {
			return;
		}
		if (curr != '#') {
			// curr is not an empty node
			currNode = new Node<char>(curr);
			preCreate(prev, currNode->_lc, n);
			preCreate(prev, currNode->_rc, n);
		}
		else {
			currNode = nullptr;
		}
	}

	void preCreate(T prev[]) {
		int a = 0;
		preCreate(prev, _root, a);
	}

	void createFromPreAndInArray(T* pre, T* in, int n) {
		_root = createFromPreAndInArrayHelper(pre, in, n);
	}

	NodePtr createFromPreAndInArrayHelper(T* pre, T* in, int n) {
		if (!n) {
			return nullptr;
		}
		int ix = 0;
		while (pre[0] != in[ix]) {
			ix++;
		}
		NodePtr newNode = new Node<T>(pre[0]);
		cout << "root: " << pre[0] << endl;
		newNode->_lc = createFromPreAndInArrayHelper(pre + 1, in, ix);
		if (newNode->_lc) {
			cout << "left child of " << pre[0] << ": " << newNode->_lc->_data << endl;
		}
		else {
			cout << "left child of " << pre[0] << ": " << "null" << endl;
		}
		newNode->_rc = createFromPreAndInArrayHelper(pre + ix + 1, in + ix + 1, n - ix - 1);
		if (newNode->_rc) {
			cout << "right child of " << pre[0] << ": " << newNode->_rc->_data << endl;
		}
		else {
			cout << "right child of " << pre[0] << ": " << "null" << endl;
		}
		
		return newNode;
	}

	NodePtr createFromPostAndInArrayHelper(T* post, T* in, int n) {
		if (!n) {
			return nullptr;
		}
		Node<T>* parent = new Node<T>(post[n - 1]);
		// find parent node in inorder
		int ix = 0;
		while (in[ix] != post[n - 1]) {
			ix++;
		}
		parent->_lc = createFromPostAndInArrayHelper(post, in, ix);
		parent->_rc = createFromPostAndInArrayHelper(post + ix, in + ix + 1, n - ix - 1);
		return parent;

	}

	NodePtr createFromPostAndInArray(T* post, T* in) {
		createFromPostAndInArrayHelper(post, in, n);
	}

	
};

