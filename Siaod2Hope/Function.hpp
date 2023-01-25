#pragma once
# include <fstream> 
# include <iostream>
# include <string>
# include <random>
# include <time.h>

class BankNum
{
public:
	signed int Number;
	std::string Fio;
	std::string Adress;

	BankNum(std::string a_Fio, std::string a_Adress, signed int a_Number)
	{
		Fio = a_Fio;
		Adress = a_Adress;
		Number = a_Number;
	};
	BankNum()
	{
		Fio = "";
		Adress = "";
		Number = 0;
	}
	~BankNum()
	{
		Fio = "";
		Adress = "";
		Number = 0;
	};
	void operator=(BankNum Object)
	{
		this->Adress = Object.Adress;
		this->Fio = Object.Fio;
		this->Number = Object.Number;
	};
	friend std::ostream& operator<<(std::ostream& os, BankNum const& Object);
	

};

void ReadTxtFile(std::vector<BankNum>& Nums, std::string a_FileName);
void CreateFile(std::string a_FileName);
unsigned int Check(std::string a_FileName);
void FillTensFunc(std::string a_FileName);
void ReadFile(std::string a_FileName);
void WriteLine(std::string a_FileName);
signed int ReturnValue(std::string a_FileName);
void CountValue(std::string a_FileName);
void Copy7(std::string a_FileName, std::string FileName);
void Good(std::fstream& a_File);
void Convert(std::string a_FileName1, std::string a_FileName2);
void ReadDatFile(std::string a_FileName);
void WriteDatFile(std::string a_FileName);
void SaveDatInTxt(std::string a_FileName);
BankNum CreateItem();

//void SearhDat(std::string a_FileName);
//void UpdateDat(std::string a_FileName);