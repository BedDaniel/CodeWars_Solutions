/*
Description:
You are given a node that is the beginning of a linked list. This list contains a dangling piece and a loop. Your objective is to determine the length of the loop.

For example in the following picture the size of the dangling piece is 3 and the loop size is 12:
A->B->C-> 1->2->...->12->1->...

// Use the `getNext()` method to get the following node.
nodePtr->getNext()

Notes:
	do NOT mutate the nodes!
	in some cases there may be only a loop, with no dangling piece
*/

int getLoopSize(Node* startNode)
{
	Node* slow = startnode;
	Node* fast = startNode;

	while (fast and fast->getNext())
	{
		slow = slow->getNext();
		fast = fast->getNext()->getNext();

		if (slow == fast) { break; }
	}

	if (slow != fast) { return 0; }

	int length = 1;
	slow = slow->getNext();
	while (slow != fast)
	{
		slow = slow->getNext();
		length++;
	}

	return length;
}
/* Test examples:
Describe(ExampleTests)
{
	It(FourNodesWithLoopSize3)
	{
		Node n1, n2, n3, n4;

		n1.setNext(&n2);
		n2.setNext(&n3);
		n3.setNext(&n4);
		n4.setNext(&n2);

		int actual = getLoopSize(&n1);
		Assert::That(actual, Equals(3), ExtraMessage("Incorrect answer for 4 nodes: tail of 1 node, and a loop of 3 nodes"));
	}
	It(NoTail)
	{
		Node n1, n2, n3, n4;

		n1.setNext(&n2);
		n2.setNext(&n3);
		n3.setNext(&n4);
		n4.setNext(&n1);

		Node* startNode = &n1;
		int actual = getLoopSize(startNode);
		Assert::That(actual, Equals(4), ExtraMessage("Incorrect answer for 4 nodes: no tail, and a loop of 4 nodes"));
	}
	It(TinyLoop)
	{
		Node n1, n2, n3, n4;

		n1.setNext(&n2);
		n2.setNext(&n3);
		n3.setNext(&n4);
		n4.setNext(&n4);

		Node* startNode = &n1;
		int actual = getLoopSize(startNode);
		Assert::That(actual, Equals(1), ExtraMessage("Incorrect answer for 4 nodes: tail of 3 nodes, and a tiny loop of 1 nodes"));
	}
	It(SingleNode) {
	  Node n;
	  n.setNext(&n);
	  int actual = getLoopSize(&n);
	  Assert::That(actual, Equals(1), ExtraMessage("Incorrect answer for a loop with a single node pointing to itself"));
	}
};

*/


/* Most clever solutions:

#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>

int getLoopSize(Node *startNode)
{
  std::vector<Node *> addrs;
  while (std::find(addrs.begin(), addrs.end(), startNode) == addrs.end())
  {
	addrs.push_back(startNode);
	startNode = startNode->getNext();
  }
  return addrs.size() - std::distance(addrs.begin(), std::find(addrs.begin(), addrs.end(), startNode));
}

*/