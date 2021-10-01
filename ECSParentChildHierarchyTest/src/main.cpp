#include <iostream>
#include "Node.h"

int main()
{
	Node* root = new Node();

	Node* child1 = new Node();
	child1->SetParent(root);
	Node* child2 = new Node();
	child2->SetParent(root);
	Node* child3 = new Node();
	child3->SetParent(root);

	Node* subChild1 = new Node();
	subChild1->SetParent(child2);

	Node* subSubChild1 = new Node();
	subSubChild1->SetParent(subChild1);
	Node* subSubChild2 = new Node();
	subSubChild2->SetParent(subChild1);


	std::cout << "HasParent():" << '\n';
	std::cout << " root: " << root->HasParent() << '\n';
	std::cout << "  child1: " << child1->HasParent() << '\n';
	std::cout << "  child2: " << child2->HasParent() << '\n';
	std::cout << "   subChild1: " << subChild1->HasParent() << '\n';
	std::cout << "    subSubChild1: " << subSubChild1->HasParent() << '\n';
	std::cout << "    subSubChild2: " << subSubChild2->HasParent() << '\n';
	std::cout << "  child3: " << child3->HasParent() << '\n';

	std::cout << "\nHasChildren():" << '\n';
	std::cout << " root: " << root->HasChildren() << '\n';
	std::cout << "  child1: " << child1->HasChildren() << '\n';
	std::cout << "  child2: " << child2->HasChildren() << '\n';
	std::cout << "   subChild1: " << subChild1->HasChildren() << '\n';
	std::cout << "    subSubChild1: " << subSubChild1->HasChildren() << '\n';
	std::cout << "    subSubChild2: " << subSubChild2->HasChildren() << '\n';
	std::cout << "  child3: " << child3->HasChildren() << '\n';

	std::cout << "\nIsChildOf(root):" << '\n';
	std::cout << " root: " << root->IsChildOf(root) << '\n';
	std::cout << "  child1: " << child1->IsChildOf(root) << '\n';
	std::cout << "  child2: " << child2->IsChildOf(root) << '\n';
	std::cout << "   subChild1: " << subChild1->IsChildOf(root) << '\n';
	std::cout << "    subSubChild1: " << subSubChild1->IsChildOf(root) << '\n';
	std::cout << "    subSubChild2: " << subSubChild2->IsChildOf(root) << '\n';
	std::cout << "  child3: " << child3->IsChildOf(root) << '\n';

	std::cout << "\nIsSubChildOf(root):" << '\n';
	std::cout << " root: " << root->IsSubChildOf(root) << '\n';
	std::cout << "  child1: " << child1->IsSubChildOf(root) << '\n';
	std::cout << "  child2: " << child2->IsSubChildOf(root) << '\n';
	std::cout << "   subChild1: " << subChild1->IsSubChildOf(root) << '\n';
	std::cout << "    subSubChild1: " << subSubChild1->IsSubChildOf(root) << '\n';
	std::cout << "    subSubChild2: " << subSubChild2->IsSubChildOf(root) << '\n';
	std::cout << "  child3: " << child3->IsSubChildOf(root) << '\n';


	subSubChild2->RemoveParent();
	delete subSubChild2;
	subSubChild1->RemoveParent();
	delete subSubChild1;

	subChild1->RemoveParent();
	delete subChild1;

	child2->RemoveParent();
	delete child2;
	child3->RemoveParent();
	delete child3;
	child1->RemoveParent();
	delete child1;

	delete root;

	std::cout << "\nPress any key to continue...";
	std::cin.get();
	return 0;
}
