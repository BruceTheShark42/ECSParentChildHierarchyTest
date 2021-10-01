#pragma once

// Notes:
//	if parent is nullptr
//		both prev and next are nullptr
//	else
//		prev will never be nullptr
//		next is only ever nullptr if it is the end of its parent's children
//
//	parent->head->prev == tail, but parent->head->prev->next == nullptr // it only links head to tail but not vice versa

class Node
{
public:
	bool HasParent() const;
	Node* GetParent() const;
	void SetParent(Node* newParent);
	void RemoveParent();
	bool HasChildren() const;
	Node* GetFirstChild() const;
	Node* GetNextSibling() const;
	Node* GetPreviousSibling() const;
	bool IsChildOf(Node* node) const;
	bool IsSubChildOf(Node* node) const;
private:
	Node* head = nullptr; // First child
	Node* next = nullptr; // Next sibling
	Node* prev = nullptr; // Previous sibling
	Node* parent = nullptr; // Parent
};
