#pragma once
# include <iostream>
# include <vector>
# include "Function.hpp"
using namespace std;

struct Node
{
	long int Key;
	BankNum Item;
	Node* Next;
	bool Deleted;
	Node()
	{
		this->Next = nullptr;
	}
};


class HashTableList
{
	static const int Default_Size = 7;
	constexpr static const double Rehash_Size = 0.75;

	std::vector<Node*> Table{};
	int Size;
	int Buffer_Size;
	

public:

	HashTableList();
	void DeliteList();
	
	unsigned long Hash_Function(BankNum Item);
	bool Insert(BankNum const &a_Item, int a_Key);
	bool Insert2(BankNum const &a_Item, int a_Key);
	void DeleteItem(BankNum const& a_Item);
	unsigned long Seach(BankNum const& a_Item);
	void DisplayHashTable();
	
};
