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



bool HashTableList::Insert(BankNum const& a_Item, int a_Key)		//open adress
{
	unsigned long Buffer{ Hash_Function(a_Item) };
	if (this->Table[Buffer] = nullptr)
	{
		this->Table[Buffer] = new Node{};
		this->Table[Buffer]->Item.Adress = a_Item.Adress;
		this->Table[Buffer]->Item.Fio = a_Item.Fio;
		this->Table[Buffer]->Item.Number = a_Item.Number;
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




bool HashTableList::Insert2(BankNum const& a_Item, int a_Key)      //цепочка
{
	unsigned long Buffer{ Hash_Function(a_Item) };

	if (this->Table[Buffer] == nullptr)
	{
		this->Table[Buffer] = new Node{};
		this->Table[Buffer]->Item.Adress = a_Item.Adress;
		this->Table[Buffer]->Item.Fio = a_Item.Fio;
		this->Table[Buffer]->Item.Number = a_Item.Number;
		return true;
	}


	Node* BufferNode(this->Table[Buffer]);
	while (BufferNode->Next != nullptr)
	{
		BufferNode = BufferNode->Next;
	}
	BufferNode->Next = new Node{};
	BufferNode->Next->Item = a_Item;

}



void HashTableList::DeleteItem(BankNum const& a_Item)
{
	unsigned long Buffer{ Hash_Function(a_Item) };
	if (this->Table[Buffer]->Item.Number == a_Item.Number)
	{
		this->Table[Buffer]->Deleted = true;
	}
	Node* BufferNode(this->Table[Buffer]);
	while (BufferNode->Next->Item.Number != a_Item.Number)
	{
		BufferNode = BufferNode->Next;
	}
	BufferNode->Next->Deleted = true;
};



unsigned long HashTableList::Seach(BankNum const& a_Item)
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


void HashTableList::DisplayHashTable()
{
	for (size_t Index{}; Index < this->Buffer_Size; Index++)
	{
		if (this->Table[Index] == nullptr)
		{	
			continue;
		}
		std::cout << "Index - " << Index << " " << this->Table[Index]->Item << '\n';
		if (this->Table[Index]->Next != nullptr)
		{
			size_t InnerCounter{ 1 };			//лучше ли один раз проверить условие, чем 2 раза создавать переменные?
			Node* BufferNode(this->Table[Index]);
			while (BufferNode->Next != nullptr)
			{
				std::cout << "Index - " << Index << " " << "Chain part - " << InnerCounter << " / " << BufferNode->Item << '\n';
				BufferNode = BufferNode->Next;
			}
		}
		
	}
}