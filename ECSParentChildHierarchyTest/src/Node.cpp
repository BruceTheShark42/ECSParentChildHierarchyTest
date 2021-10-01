#include "Node.h"

bool Node::HasParent() const
{
	return parent != nullptr;
}

Node* Node::GetParent() const
{
	return parent;
}

void Node::SetParent(Node* newParent)
{
	if (parent == newParent)
		return;
	RemoveParent();
	if (newParent == nullptr)
		return;

	if (newParent->head == nullptr)
	{
		newParent->head = this;
		prev = this;
	}
	else
	{
		newParent->head->prev->next = this;
		prev = newParent->head->prev;
		newParent->head->prev = this;
	}

	parent = newParent;
}

void Node::RemoveParent()
{
	if (parent == nullptr)
		return;

	// only child
	if (prev->next == nullptr && next == nullptr)
	{
		parent->head = nullptr;
	}
	// only next sibling, this == parent->head
	else if (prev->next == nullptr)
	{
		parent->head = next;
		next->prev = prev;
		next = nullptr;
	}
	// only prev sibling, this == tail
	else if (next == nullptr)
	{
		parent->head->prev = prev;
		prev->next = nullptr;
	}
	// both prev and next siblings
	else
	{
		prev->next = next;
		next->prev = prev;
		next = nullptr;
	}

	parent = nullptr;
	prev = nullptr;
}

bool Node::HasChildren() const
{
	return head != nullptr;
}

Node* Node::GetFirstChild() const
{
	return head;
}

Node* Node::GetNextSibling() const
{
	return next;
}

Node* Node::GetPreviousSibling() const
{
	return prev;
}

bool Node::IsChildOf(Node* node) const
{
	return parent == node;
}

bool Node::IsSubChildOf(Node* node) const
{
	if (parent == nullptr)
		return false;
	if (parent == node)
		return true;
	return parent->IsSubChildOf(node);
}
