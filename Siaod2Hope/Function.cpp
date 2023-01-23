# include "Function.hpp"
# include "Hash.hpp"

void CreateFile(std::string a_FileName)
{
	std::fstream t_File(a_FileName);
	if (t_File.is_open())
	{
		std::cout << "File with that name already created" << '\n';
		return;
	}
	else
		std::fstream a_File(a_FileName, std::fstream::out);
};

unsigned int Check(std::string a_FileName)
{
	std::fstream a_File(a_FileName);
	if (!a_File)
	{
		std::cout << "Error opening file";
		return 1;
	}
	else
	{
		std::cout << "Everything is fine\n";
		a_File.close();
		return 0;
	}
};

void FillTensFunc(std::string a_FileName)
{
	Check(a_FileName);
	srand(std::time(NULL));
	std::fstream a_File(a_FileName, std::fstream::app);
	std::cout << "File filling: ";
	for (signed int i{ 0 }; i < 15; i++)
	{
		signed int HelpVariable{ rand() % 100 };
		if ((rand() % 10) % 2 == 0)
		{
			std::cout << HelpVariable << ' ';
			a_File << HelpVariable << ' ';
		}
		else
		{
			a_File << ' ';
		}
	}
	std::cout << '\n';
	a_File << '\n';
	Good(a_File);
	a_File.close();
}
void ReadFile(std::string a_FileName)
{
	Check(a_FileName);
	std::fstream a_File(a_FileName, std::fstream::out || std::fstream::app);
	std::string a_Line;
	while (std::getline(a_File, a_Line))
	{
		std::cout << a_Line << '\n';
	}
	a_File.close();
};

void WriteLine(std::string a_FileName)
{
	Check(a_FileName);
	std::fstream a_File(a_FileName, std::fstream::app);
	std::string a_Line{};
	getline(std::cin >> std::ws, a_Line);
	a_File << a_Line << '\n';
	Good(a_File);
	a_File.close();
};

signed int ReturnValue(std::string a_FileName)
{
	Check(a_FileName);
	std::fstream a_File(a_FileName, std::fstream::out || std::fstream::app);
	unsigned int StringCapacity{ 1 }, Counter{ 0 };
	bool Statement{ 0 };
	std::string a_Line{};
	std::string* StringFile = new std::string[16];
	while (std::getline(a_File, a_Line))
	{
		StringFile[Counter] = a_Line;
		Counter++;
	}
	StringCapacity = Counter;
	Counter = 0;
	for (unsigned int j{ 0 }; j < StringCapacity; j++)
	{
		for (auto& i : StringFile[j])
		{
			if ((i == ' ' || i == '\n' || i == '\t') && (Statement == true))
			{
				Statement = false;
			}
			else if ((i == ' ' || i == '\n' || i == '\t') && Statement == false)
			{
				continue;
			}
			else if (Statement == false)
			{
				Statement = true;
				Counter++;
			}
			else
			{
				continue;
			}


		}
		Statement = 0;
	}
	delete[] StringFile;
	StringFile = nullptr;
	std::cout << "Amount of numbers = " << Counter << '\n';
	Good(a_File);
	a_File.close();
	return Counter;
};
void CountValue(std::string a_FileName)	 //remake
{
	Check(a_FileName);
	std::fstream a_File(a_FileName, std::fstream::out || std::fstream::app);
	unsigned int StringCapacity{ 1 }, Counter{ 0 }, IndexToFind{ 0 };
	std::cout << "Enter index to find by - ";
	std::cin >> IndexToFind;
	bool Statement{ 0 };
	std::string a_Line{};
	std::string* StringFile = new std::string[16];
	while (std::getline(a_File, a_Line))
	{
		StringFile[Counter] = a_Line;
		Counter++;
	}
	StringCapacity = Counter;
	Counter = 0;
	a_Line = {};
	for (unsigned int j{ 0 }; j < StringCapacity; j++)
	{
		for (auto& i : StringFile[j])
		{
			if ((i == ' ' || i == '\n' || i == '\t') && (Statement == true))
			{
				Statement = 0;
				Counter++;
				if (Counter == IndexToFind)
				{
					std::cout << std::stoi(a_Line) << '\n';
					delete[] StringFile;
					StringFile = nullptr;
					Good(a_File);
					a_File.close();
					return;
				}
				a_Line = {};

			}
			else if ((i == ' ' || i == '\n' || i == '\t') && Statement == false)
			{
				continue;
			}
			else if (Statement == false)
			{
				Statement = true;
				a_Line += i;
			}
			else if (Statement == true)
			{
				a_Line += i;
			}
		}
		if (Counter == IndexToFind)
		{
			std::cout << std::stoi(a_Line) << '\n';
			delete[] StringFile;
			StringFile = nullptr;
			Good(a_File);
			a_File.close();
			return;
		}
		a_Line = {};
		Statement = 0;
	}
	std::cout << "No such index\n";
	delete[] StringFile;
	StringFile = nullptr;
	Good(a_File);
	a_File.close();
};
void Copy7(std::string a_FileName, std::string FileName)
{
	Check(a_FileName);
	std::fstream a_File(a_FileName, std::fstream::out || std::fstream::app);
	CreateFile(FileName);
	std::fstream NewFile(FileName, std::fstream::app);
	unsigned int StringCapacity{ 1 }, Counter{ 0 };
	bool Statement{ 0 };
	std::string a_Line{};
	std::string* StringFile = new std::string[16];
	while (std::getline(a_File, a_Line))
	{
		StringFile[Counter] = a_Line;
		Counter++;
	}
	StringCapacity = Counter;
	Counter = 0;
	a_Line = {};
	for (unsigned int j{ 0 }; j < StringCapacity; j++)
	{
		for (auto& i : StringFile[j])
		{
			if ((i == ' ' || i == '\n' || i == '\t') && (Statement == true))
			{
				Statement = 0;
				if (std::stoi(a_Line) % 7 == 0)
				{
					NewFile << a_Line << ' ';
				}
				a_Line = {};

			}
			else if ((i == ' ' || i == '\n' || i == '\t') && Statement == false)
			{
				continue;
			}
			else if (Statement == 0)
			{
				Statement = 1;
				a_Line += i;
			}
			else if (Statement == 1)
			{
				a_Line += i;
			}
		}
		if (a_Line != " " && a_Line != "\n" && a_Line != "\t" && a_Line != "")
		{
			if (std::stoi(a_Line) % 7 == 0)
			{
				NewFile << a_Line << ' ';
			}
		}
		a_Line = {};
		Statement = 0;
	}
	delete[] StringFile;
	StringFile = nullptr;
	Good(a_File);
	a_File.close();
	NewFile.close();

}

void Good(std::fstream& a_File)
{
	if (a_File.good())
	{
		std::cout << "No errors\n";
	}
	else
	{
	};
};

void Convert(std::string a_FileName1, std::string a_FileName2)

{
	CreateFile(a_FileName1);
	std::ofstream a_FileDat(a_FileName1, std::fstream::binary || std::fstream::in);
	std::ifstream a_FileTxt(a_FileName2, std::fstream::out);
	std::string Buffer{};
	while (a_FileTxt >> Buffer)
	{
		a_FileDat.write((char*)&Buffer, sizeof(std::string));
	}
	a_FileDat.close();
	a_FileTxt.close();
};

void ReadDatFile(std::string a_FileName)
{
	BankNum TestNum;
	std::ifstream a_File(a_FileName, std::fstream::out || std::fstream::binary);
	a_File.read((char*)&TestNum, sizeof(BankNum));
	while (!a_File.eof())
	{
		std::cout << TestNum.Adress;
		std::cout << TestNum.Fio;
		std::cout << TestNum.Number;
		a_File.read((char*)&TestNum, sizeof(BankNum));
		std::cout << '\n';
		a_File.close();
	}
};

void WriteDatFile(std::string a_FileName)
{
	BankNum TestNum;
	CreateFile(a_FileName);
	std::ofstream a_File(a_FileName, std::fstream::in | std::fstream::binary);
	std::cin >> TestNum.Adress;
	std::cin >> TestNum.Fio;
	std::cin >> TestNum.Number;
	a_File.write((char*)&TestNum, sizeof(BankNum));
	a_File.close();

};

void SaveDatInTxt(std::string a_FileName)
{
	BankNum Buffer;
	std::cout << "Enter a new txt file name - ";
	std::string a_TxtFileName{};
	std::cin >> a_TxtFileName;
	CreateFile(a_TxtFileName);
	std::fstream a_DatFile(a_FileName, std::fstream::binary || std::fstream::out);
	std::fstream a_TxtFile(a_TxtFileName, std::fstream::in);
	a_DatFile.read((char*)&Buffer, sizeof(BankNum));
	while (!a_DatFile.eof())
	{
		a_DatFile >> Buffer.Adress;
		a_DatFile >> Buffer.Fio;
		a_DatFile >> Buffer.Number;
		a_TxtFile.write((char*)&Buffer, sizeof(BankNum));
		//a_TxtFile << std::to_string(Buffer.Adress);
		a_DatFile.read((char*)&Buffer, sizeof(BankNum));
	}
	a_DatFile.close();
	a_TxtFile.close();

};


//HashTableList::HashTableList()
//
//{
//	buffer_size = default_size;
//	size = 0;
//	arr = new Node * [buffer_size];
//	for (int i = 0; i < buffer_size; i++)arr[i] = nullptr;
//}

void ReadTxtFile(std::vector<BankNum>& Nums, std::string a_FileName) {

	std::ifstream a_File(a_FileName, std::fstream::out || std::fstream::binary);
	
	if (!a_File.is_open()) {
		std::cout << "File Number.txt do not open";
		return;
	}

	BankNum TestNum;
	while (!a_File.eof())
	{
		
		a_File >> TestNum.Adress;
		a_File >> TestNum.Fio;
		a_File >> TestNum.Number;
		Nums.push_back(TestNum);
	}

	a_File.close();
}

BankNum CreateItem()
{
	BankNum Test{};
	std::cout << "Enter Fio, Adress, Number\n";
	std::cin >> Test.Fio;
	std::cin >> Test.Adress;
	std::cin >> Test.Number;
	return Test;

}
;
