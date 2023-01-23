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
	bool Deleted{ false };
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
	//	//деструктор
	//	~HashTableList();
	//	//хеш - функция
	//	int hash(int key1);
	//	//вставить ключ в таблицу
	bool Insert(BankNum& const a_Item, int a_Key);
	bool Insert2(BankNum& const a_Item, int a_Key);
	void DeleteItem(BankNum& const a_Item);
	unsigned long Seach(BankNum& const a_Item);
	//	void vivodlista(Node* L); //вывод списка
	//	void vivodHesTable();
	//	void Rehash(); // функция рехеширования
	//	// Метод Find
	//	int Find(int key);//возвращает указатель на запись с ключом в файле
	//	//Метод Delete
	//	void Delete(int key); //удаление ключа из таблицы
	//};
	//
	//HashTableList::HashTableList()
	//
	//{
	//	Buffer_Size = Default_Size;
	//	Size = 0;
	//	Array = new Node * [Buffer_Size];
	//	for (int i = 0; i < Buffer_Size; i++)
	//	{
	//		Array[i] = nullptr;
	//	}
	//
	//}
	//
	//void HashTableList::delList(Node*& L) {
	//
	//	Node* q = L, * q1;
	//	while (q != 0) {
	//		q1 = q->Next;
	//		delete q;
	//		q = q1;
	//	}
	//	L = 0;
	//
	//}
	//
	////HashTableList::~HashTableList()
	////{
	////	for (int i = 0; i < size; i++)
	////		if (Array[i] != 0) delList(Array[i]);
	////	delete[]Array;
	////
	////}
	//
	//int HashTableList::hash(int key1)
	//{
	//	return key1 % Buffer_Size;
	//}
	//
	////bool HashTableList::Insert(const int ptr1, int key1)
	////{
	////	/*
	////
	////	if ((size + 1) / Buffer_Size > 0.75) {
	////
	////	Rehash();
	////
	////	}
	////
	////	*/
	////
	////	int i = hash(key1);
	////
	////	//Добавить ключ в список по индексу i в начало списка
	////
	////	Node* ptr = new Node;//создание элемента списка
	////
	////	ptr->key = key1;
	////
	////	ptr->ptr = ptr1;
	////
	////	ptr->Next = Array[i];
	////
	////	Array[i] = ptr;
	////
	////	return false;
	////
	////}
	//
	////void HashTableList::vivodlista(Node* L)
	////
	////{
	////
	////	if (L != 0)
	////
	////	{
	////
	////		Node* ptr = L;
	////
	////		while (ptr != 0) {
	////
	////			std::cout << " " << ptr->key << ' ' << ptr->ptr;
	////
	////			ptr = ptr->Next;
	////
	////		}
	////
	////	}
	////
	////}
	//
	//void HashTableList::vivodHesTable()
	//
	//{
	//
	//	for (int i = 0; i < Buffer_Size; i++) {
	//
	//		std::cout << "i=" << i;
	//
	//		if (Array[i] == 0)
	//
	//			std::cout << " 0";
	//
	//		else
	//
	//			vivodlista(Array[i]);
	//
	//		std::cout << "\n";
	//
	//	}
	//
	//}
	//
	//int HashTableList::Find(int key)
	//
	//{
	//
	//	return 0;
	//
	//}
};
