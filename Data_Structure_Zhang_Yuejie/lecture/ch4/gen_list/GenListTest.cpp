#include <iostream>
#include "GenList.h"

using namespace std;

int main(void) {
	//GenListNode<int> node;
	GenList<int> lst;
	GenListNode<int> firstNode = lst.front();

	return 0;
}