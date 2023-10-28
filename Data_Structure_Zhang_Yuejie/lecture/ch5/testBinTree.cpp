#include <iostream>
#include "BinTree.h"

using namespace std;

int main(void) {
	char pre[] = "ABC##DE#G##F###";
	BinTree<char> bt;
	bt.preCreate(pre);
	cout << "preorder traversal:" << endl;
	bt.preOrderRecur();
	cout << "inorder traversal: " << endl;
	bt.inOrderRecur();

	cout << "\n\nCopy assignment constructor, copy from above" << endl;
	BinTree<char> another(bt);
	cout << "Another tree: " << endl;
	another.preOrderRecur();

	cout << "\n\nPreorder traversal with stack" << endl;
	bt.preOrderStack();

	cout << "Level order traversal" << endl;
	bt.levelOrder();

	cout << "Inorder traversal with stack" << endl;
	bt.inOrderStack();

	cout << "\n\nPostorder stack by Junhui Deng" << endl;
	bt.postOrderStackDeng();

	cout << "\n\nCreate from two arrays: preorder array and inorder array" << endl;
	char pre2[] = "ABHFDECKG";
	char in[] = "HBDFAEKCG";
	bt.createFromPreAndInArray(pre2, in, 9);
	bt.preOrderRecur();

	return 0;
}