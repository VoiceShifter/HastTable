
# include "Function.hpp" 
# include "Hash.hpp"
void Interface()
{
	std::string FileName{};
	signed int SwitchForCase{};
Start:;
	std::cout << "Action: \n1)Create File\n2)Check File\n3)Fill file with tens\n4)Read File\n5)Write new line to file\n6)Return amount of values\n7)Return value by index\n8)Copy numbers multiple to 7 to a new file\n9)Write dat file\n10)Read in dat file\n11)Convert from txt to dat\n12)Save dat to txt file\n 0) Exit program\n";
	std::cin >> SwitchForCase;
	switch (SwitchForCase)
	{

	case 1:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		CreateFile(FileName);
		goto Start;
	}

	case 2:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		Check(FileName);
		goto Start;
	}

	case 3:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		FillTensFunc(FileName);
		goto Start;
	}

	case 4:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		ReadFile(FileName);
		goto Start;
	}

	case 5:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		WriteLine(FileName);
		goto Start;
	}

	case 6:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		ReturnValue(FileName);
		goto Start;
	}

	case 7:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		CountValue(FileName);
		goto Start;
	}
	case 8:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		std::cout << "Enter second file name - ";
		std::string FileName2;
		std::cin >> FileName2;
		Copy7(FileName, FileName2);
		goto Start;
	}
	case 9:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		WriteDatFile(FileName);
		goto Start;
	}
	case 10:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		ReadDatFile(FileName);
		goto Start;
	}
	case 11:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		std::cout << "Enter second file name - ";
		std::string FileName2;
		std::cin >> FileName2;
		Convert(FileName, FileName2);
		goto Start;
	}
	case 12:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		SaveDatInTxt(FileName);
		goto Start;
	}
	case 13:
	{
		std::cout << "File name: ";
		std::cin >> FileName;
		std::vector<BankNum> Test{};
		ReadTxtFile(Test, FileName);
		goto Start;
	}

	case 0:
	{
		exit;
	}
	default:
		std::cout << "Incorrect input\n";
	}
}
signed int main()
{
	std::string FileName{};
	signed int SwitchForCase{};
Start:;
	std::cout << "Action: \n1 - Insert\n";
	std::cin >> SwitchForCase;
	switch (SwitchForCase)
	{

	case 1:
	{
		HashTableList HashTable{};
		BankNum aIteam{ CreateItem() };
		HashTable.Insert2(aIteam, 0);
		goto Start;
	}


	system("pause");
	return 0;
	}
}


