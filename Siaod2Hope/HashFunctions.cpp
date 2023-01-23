# include "Hash.hpp"
# include "Function.hpp"
const int CONSTDEL = 700;
HashTableList::HashTableList()
{
	Buffer_Size = CONSTDEL;
	Size = 0;
	for (int i = 0; i < Buffer_Size; i++)
	{
		this->Table.push_back(nullptr);
	}
}
void HashTableList::DeliteList()
{
	Buffer_Size = Default_Size;
	Size = 0;
	for (int i = 0; i < Buffer_Size; i++)
	{
		Table[i] = nullptr;
	}
}

unsigned long HashTableList::Hash_Function(BankNum Item)
{
	unsigned long Hash{  };
	Hash += Item.Number;
	for (size_t Index{ 0 }; Index < Item.Adress.length(); Index++)
	{
		Hash += Item.Adress[Index];
	}
	for (size_t Index{ 0 }; Index < Item.Fio.length(); Index++)
	{
		Hash += Item.Fio[Index];
	}
	return Hash % CONSTDEL;
};


bool HashTableList::Insert(BankNum& a_Item, int a_Key)			//open adress
{
	unsigned long Buffer{ Hash_Function(a_Item) };
	if (this->Table[Buffer] = nullptr)
	{
		this->Table[Buffer]->Item = a_Item;
		return true;

	}
	for (Buffer; this->Table[Buffer] != nullptr && Buffer < CONSTDEL; Buffer++) {};
	if (Buffer == CONSTDEL)
	{
		std::cout << "out of bouce" << '\n';
		return false;
	}
	this->Table[Buffer]->Item = a_Item;
	return true;

};
bool HashTableList::Insert2(BankNum& a_Item, int a_Key)	      //цепочка
{
	unsigned long Buffer{ Hash_Function(a_Item) };

	if (this->Table[Buffer] == nullptr)
	{
		this->Table[Buffer]->Item = a_Item;
		return true;
	}

	Node* BufferNode(this->Table[Buffer]);
	while (BufferNode->Next != nullptr)
	{
		BufferNode = BufferNode->Next;
	}
	BufferNode->Next->Item = a_Item;

}
void HashTableList::DeleteItem(BankNum& a_Item)
{
	unsigned long Buffer{ Hash_Function(a_Item) };
	if (this->Table[Buffer]->Item.Number == a_Item.Number)
	{
		this->Table[Buffer]->Deleted=true;
	}
	Node* BufferNode(this->Table[Buffer]);
	while (BufferNode->Next->Item.Number != a_Item.Number)
	{
		BufferNode = BufferNode->Next;
	}
	BufferNode->Next->Deleted = true;
};
unsigned long HashTableList::Seach(BankNum& a_Item)
{
	unsigned long Buffer{ Hash_Function(a_Item) };
	if (this->Table[Buffer]->Item.Number == a_Item.Number)
	{
		return Buffer;
	}
	Node* BufferNode(this->Table[Buffer]);
	while (BufferNode->Next->Item.Number != a_Item.Number)
	{
		BufferNode = BufferNode->Next;
	}
	return Buffer;
}

