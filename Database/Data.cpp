#include "Data.h"



///////////////////
///////Товар///////
///////////////////



ProductData::ProductData()
{
	productName.nameFirm = "";
	productName.nameProduct = "";

	description.type = "";
	description.appointment = "";
	description.clas = "";
	description.season = "";
	description.gender = "";
	description.size = "";
	description.amount = 0;
	description.cost = 0;
	
}

ProductData::ProductData(ProductName productName_, Description description_)
{
	productName.nameFirm = productName_.nameFirm;
	productName.nameProduct = productName_.nameProduct;
	
	description.type = description_.type;
	description.appointment = description_.appointment;
	description.clas = description_.clas;
	description.season = description_.season;
	description.gender = description_.gender;
	description.size = description_.size;
	description.amount = description_.amount;
	description.cost = description_.cost;
}

ProductData::~ProductData()
{
}

void ProductData::PrintProductData(string _userStatus)
{
		if (_userStatus == "Administrator")
		{
			cout << " |" << setw(20) << productName.nameFirm << " |" << setw(25) << productName.nameProduct << " |" << setw(24) << description.type
				<< " |" << setw(25) << description.appointment << " |" << setw(24) << description.clas << " |" << setw(23) << description.season
				<< " |" << setw(22) << description.gender << " |" << setw(15) << description.size << " |" << setw(10) << description.amount << " |" << setw(15) << description.cost << " |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}if (_userStatus == "Client")
		{
			cout << " |" << setw(22) << productName.nameFirm << " |" << setw(27) << productName.nameProduct << " |" << setw(27) << description.type
				<< " |" << setw(25) << description.appointment << " |" << setw(27) << description.clas << " |" << setw(23) << description.season
				<< " |" << setw(22) << description.gender << " |" << setw(15) << description.size << " |" << setw(17) << description.cost << " |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
}

void ProductData::Print(ProductData* (&ProductArray), int& _amount, string _userStatus)
{
	cout << setiosflags(ios::left);
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|    |                     |                          |                         |                          |                         |                        |                       |                |           |                |" << endl;
	
	cout << "|" << setw(3) << "№" << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |" 
		 << setw(24) << "ТИП"  << " |" << setw(25) << "ПРИЗНАЧЕННЯ" << " |" << setw(24) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
		 << " |" << setw(22) << "СТАТЬ" << " |" << setw(15) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << endl;
	
	cout << "|    |                     |                          |                         |                          |                         |                        |                       |                |           |                |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < _amount; i++)
	{
		cout << setiosflags(ios::right);
		cout << "|" << setw(3) << i + 1;
		ProductArray[i].PrintProductData(_userStatus);
	}
}

void ProductData::PrintProductForClient(ProductData* (&ProductArray), int& _amount, string _userStatus)
{
	cout << setiosflags(ios::left);
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|    |                       |                            |                            |                          |                            |                        |                       |                |                  |" << endl;

	cout << "|" << setw(3) << "№" << " |" << setw(22) << "НАЗВА ФІРМИ" << " |" << setw(27) << "НАЗВА ТОВАРУ" << " |"
		<< setw(27) << "ТИП" << " |" << setw(25) << "ПРИЗНАЧЕННЯ" << " |" << setw(27) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
		<< " |" << setw(22) << "СТАТЬ" << " |" << setw(15) << "РОЗМІР" << " |" << setw(17) << "ЦІНА" << " |" << endl;

	cout << "|    |                       |                            |                            |                          |                            |                        |                       |                |                  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < _amount; i++)
	{
		cout << setiosflags(ios::right);
		cout << "|" << setw(3) << i + 1;
		ProductArray[i].PrintProductData(_userStatus);
	}
}

void ProductData::ProductDataEnrty(ProductName productName_, Description description_)
{
	productName.nameFirm = productName_.nameFirm;
	productName.nameProduct = productName_.nameProduct;

	description.type = description_.type;
	description.appointment = description_.appointment;
	description.clas = description_.clas;
	description.season = description_.season;
	description.gender = description_.gender;
	description.size = description_.size;
	description.amount = description_.amount;
	description.cost = description_.cost;
}

void ProductData::ProductDataInStorageReading(ProductData* (&ProductArrayInStorage), int& _amount, string fileName)
{
	ProductName productName;
	Description description;
	ifstream reading(fileName);
	if (reading)
	{
		reading >> _amount;
		ProductArrayInStorage = new ProductData[_amount];
		for (int i = 0; i < _amount; i++)
		{
			reading >> productName.nameFirm >> productName.nameProduct >> description.type
				    >>  description.appointment >> description.clas >> description.season 
				    >> description.gender >> description.size >> description.amount >> description.cost;
			ProductArrayInStorage[i].ProductDataEnrty(productName, description);
		}
	}reading.close();
}

void ProductData::ProductDataInStorReading(ProductData* (&ProductArrayInStor), int& _amount, string fileName)
{
	ProductName productName;
	Description description;
	ifstream reading(fileName);
	if (reading)
	{
		reading >> _amount;
		ProductArrayInStor = new ProductData[_amount];
		for (int i = 0; i < _amount; i++)
		{
			reading >> productName.nameFirm >> productName.nameProduct >> description.type
				>> description.appointment >> description.clas >> description.season
				>> description.gender >> description.size >> description.amount >> description.cost;
			ProductArrayInStor[i].ProductDataEnrty(productName, description);
		}
	}reading.close();
}

ProductData& ProductData::operator=(ProductData ProductArrayInStorage_old)
{
	this->productName.nameFirm = ProductArrayInStorage_old.productName.nameFirm;
	this->productName.nameProduct = ProductArrayInStorage_old.productName.nameProduct;

	this->description.type = ProductArrayInStorage_old.description.type;
	this->description.appointment = ProductArrayInStorage_old.description.appointment;
	this->description.clas = ProductArrayInStorage_old.description.clas;
	this->description.season = ProductArrayInStorage_old.description.season;
	this->description.gender = ProductArrayInStorage_old.description.gender;
	this->description.size = ProductArrayInStorage_old.description.size;
	this->description.amount = ProductArrayInStorage_old.description.amount;
	this->description.cost = ProductArrayInStorage_old.description.cost;

	return *this;
}



////////////////////////////
///////Проданий товар///////
////////////////////////////



SoldProduct::SoldProduct()
{
	soldProductData.year = 0;
	soldProductData.month = 0;
	soldProductData.day = 0;
}

SoldProduct::SoldProduct(ProductName productName_, Description description_, SoldProductData selledProductData_)
{
	productName.nameFirm = productName_.nameFirm;
	productName.nameProduct = productName_.nameProduct;

	description.type = description_.type;
	description.appointment = description_.appointment;
	description.clas = description_.clas;
	description.season = description_.season;
	description.gender = description_.gender;
	description.size = description_.size;
	description.amount = description_.amount;
	description.cost = description_.cost;

	soldProductData.year = selledProductData_.year;
	soldProductData.month = selledProductData_.month;
	soldProductData.day = selledProductData_.day;
}

SoldProduct::~SoldProduct(){}

void SoldProduct::SoldProductDataEnrty(ProductName productName_, Description description_, SoldProductData soldProductData_)
{
	productName.nameFirm = productName_.nameFirm;
	productName.nameProduct = productName_.nameProduct;

	description.type = description_.type;
	description.appointment = description_.appointment;
	description.clas = description_.clas;
	description.season = description_.season;
	description.gender = description_.gender;
	description.size = description_.size;
	description.amount = description_.amount;
	description.cost = description_.cost;

	soldProductData.day = soldProductData_.day;
	soldProductData.month = soldProductData_.month;
	soldProductData.year = soldProductData_.year;
}

void SoldProduct::SoldProductReading(SoldProduct* (&SoldProductArray), int& _amount, string fileName)
{
	ProductName productName;
	Description description;
	SoldProductData soldProductData;
	ifstream reading(fileName); 
	if (reading)
	{
		reading >> _amount;
		SoldProductArray = new SoldProduct[_amount];
		for (int i = 0; i < _amount; i++)
		{
			reading >> productName.nameFirm >> productName.nameProduct >> description.type
				>> description.appointment >> description.clas >> description.season
				>> description.gender >> description.size >> description.amount >> description.cost 
				>> soldProductData.day >> soldProductData.month >> soldProductData.year;
			SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);
		}
	}reading.close();
}

void SoldProduct::SoldProductDataPrint(SoldProduct* (&SoldProductArray), int& _amount)
{
	int n, m;
	struct tm Year;
	time_t now;
	now = time(NULL);
	Year =*localtime(&now);
	int currentYear = Year.tm_year + 1900;
tryAgain:
	
	cout << "                                                                                                        [1] - Січень" << endl;
	cout << "                                                                                                        [2] - Лютий" << endl;
	cout << "                                                                                                        [3] - Березень" << endl;
	cout << "                                                                                                        [4] - Квітень" << endl;
	cout << "                                                                                                        [5] - Травень" << endl;
	cout << "                                                                                                        [6] - Червень" << endl;
	cout << "                                                                                                        [7] - Липень" << endl;
	cout << "                                                                                                        [8] - Серпень" << endl;
	cout << "                                                                                                        [9] - Вересень" << endl;
	cout << "                                                                                                        [10] - Жовтень" << endl;
	cout << "                                                                                                        [11] - Листопад" << endl;
	cout << "                                                                                                        [12] - Грудень" << endl;
	cout << "                                                                                                        [13] - За весь рік" << endl;
	cout << "                                                                                                        [0] - Вихід" << endl;
	cin >> n;

	system("cls");
	
	if (n > 0 && n < 13)
	{
	TryAgain1:
		cout << "                                                                              [1] - Сортувати за ціною(спочатку дорогі)" << endl;
		cout << "                                                                              [2] - Сортувати за ціною(спочатку дешеві)" << endl;
		cout << "                                                                              [3] - Сортувати за алфавітом(A -> Z)" << endl;
		cout << "                                                                              [0] - Назад" << endl;

		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		if (n == 1) { cout << "|                                                                                                       Історія продажів за Січень                                                                                                  |" << endl; }
		if (n == 2) { cout << "|                                                                                                       Історія продажів за Лютий                                                                                                   |" << endl; }
		if (n == 3) { cout << "|                                                                                                       Історія продажів за Березень                                                                                                |" << endl; }
		if (n == 4) { cout << "|                                                                                                       Історія продажів за Квітень                                                                                                 |" << endl; }
		if (n == 5) { cout << "|                                                                                                       Історія продажів за Травень                                                                                                 |" << endl; }
		if (n == 6) { cout << "|                                                                                                       Історія продажів за Червень                                                                                                 |" << endl; }
		if (n == 7) { cout << "|                                                                                                       Історія продажів за Липень                                                                                                  |" << endl; }
		if (n == 8) { cout << "|                                                                                                       Історія продажів за Серпень                                                                                                 |" << endl; }
		if (n == 9) { cout << "|                                                                                                       Історія продажів за Вересень                                                                                                |" << endl; }
		if (n == 10) { cout << "|                                                                                                       Історія продажів за Жовтень                                                                                                 |" << endl; }
		if (n == 11) { cout << "|                                                                                                       Історія продажів за Листопад                                                                                                |" << endl; }
		if (n == 12) { cout << "|                                                                                                       Історія продажів за Грудень                                                                                                 |" << endl; }


		cout << setiosflags(ios::left);
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;

		cout << "|" << setw(3) << "№" << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |"
			<< setw(21) << "ТИП" << " |" << setw(22) << "ПРИЗНАЧЕННЯ" << " |" << setw(21) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
			<< " |" << setw(17) << "СТАТЬ" << " |" << setw(14) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << setw(5) << "Дата" << "  " << setw(8) << "       |" << endl;

		cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		int x = 0;
		for (int i = 0; i < _amount; i++)
	    {
			
		  if(SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == n && SoldProductArray[i].GetSoldData().day < 32)
		  {
			cout << setiosflags(ios::right);
			cout << "|" << setw(3) << i + 1 - x;
			SoldProductArray[i].SoldPrint();
		  }
		  else {
			  x++;
		  }
	    }
		cin >> m;

		if (m == 0)
		{
			system("cls");
			goto tryAgain;
		}
		if (m > 0 && m < 6)
		{
			system("cls");
			SoldProductArray->SortSoldProduct(SoldProductArray, _amount, m);
			goto TryAgain1;
		}
	}
	if (n == 13)
	{
		TryAgain2:
		cout << "                                                                              [1] - Сортувати за ціною(спочатку дорогі)" << endl;
		cout << "                                                                              [2] - Сортувати за ціною(спочатку дешеві)" << endl;
		cout << "                                                                              [3] - Сортувати за алфавітом(A -> Z)" << endl;
		cout << "                                                                              [0] - Назад" << endl;
		
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                                                       Історія продажів за Весь рік                                                                                                |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                      Січень                                                                                                                                                                                                       |" << endl;
	    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	    for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 1)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Лютий                                                                                                                                                                                                        |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 2)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Березень                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 3)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Квітень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 4)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Травень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 5)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Червень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 6)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Липень                                                                                                                                                                                                       |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 7)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                                                                                                               Серпень                                                                                                             |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 8)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Вересень                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 9)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Жовтеннь                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 10)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cout << "|                      Листопад                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 11)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		
		cout << "|                      Грудень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 12)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1;
				SoldProductArray[i].SoldPrint();
			}
		}
		cin >> m;

		if (m == 0)
		{
			system("cls");
			goto tryAgain;
		}
		if (m > 0 && m < 6)
		{
			system("cls");
			SoldProductArray->SortSoldProduct(SoldProductArray, _amount, m);
			goto TryAgain2;
		}
	}
	if (n != 0 || n > 13)
	{
		cout << "Такого пункту меню не існує!" << endl;
		system("cls");
		goto tryAgain;
	}
	if (n == 0)
	{
	}

}

void SoldProduct::SoldPrint()
{
	cout << " |" << setw(20) << productName.nameFirm << " |" << setw(25) << productName.nameProduct << " |" << setw(21) << description.type
		<< " |" << setw(22) << description.appointment << " |" << setw(21) << description.clas << " |" << setw(23) << description.season
		<< " |" << setw(17) << description.gender << " |" << setw(14) << description.size << " |" << setw(10) << description.amount
		<< " |" << setw(15) << description.cost << " |" << setw(6) << soldProductData.day << "." << soldProductData.month
		<< "." << soldProductData.year << " |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void SoldProduct::SoldProductPrint(SoldProduct* (&SoldProductArray), int& _amount)
{
	cout << setiosflags(ios::left);

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;

	cout << "|" << setw(3) << "№" << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |"
		<< setw(21) << "ТИП" << " |" << setw(22) << "ПРИЗНАЧЕННЯ" << " |" << setw(21) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
		<< " |" << setw(17) << "СТАТЬ" << " |" << setw(14) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << setw(5) << "Дата" << "  " << setw(8) << "       |" << endl;

	cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < _amount; i++)
	{
		cout << setiosflags(ios::right);
		cout << "|" << setw(3) << i + 1;
		SoldProductArray[i].SoldPrint();
	}
}

void SoldProduct::SortSoldProduct(SoldProduct* SoldProductArray, int& _amount, int choice)
{
	ProductName productName, productName2;
	Description description, description2;
	SoldProductData soldProductData, soldProductData2;

	if (choice == 1)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = SoldProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = SoldProductArray[i].GetTovarName().nameProduct;
				description.type = SoldProductArray[i].GetDescription().type;
				description.appointment = SoldProductArray[i].GetDescription().appointment;
				description.clas = SoldProductArray[i].GetDescription().clas;
				description.season = SoldProductArray[i].GetDescription().season;
				description.gender = SoldProductArray[i].GetDescription().gender;
				description.size = SoldProductArray[i].GetDescription().size;
				description.amount = SoldProductArray[i].GetDescription().amount;
				description.cost = SoldProductArray[i].GetDescription().cost;
				soldProductData.day = SoldProductArray[i].GetSoldData().day;
				soldProductData.month = SoldProductArray[i].GetSoldData().month;
				soldProductData.year = SoldProductArray[i].GetSoldData().year;

				productName2.nameFirm = SoldProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = SoldProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = SoldProductArray[i + 1].GetDescription().type;
				description2.appointment = SoldProductArray[i + 1].GetDescription().appointment;
				description2.clas = SoldProductArray[i + 1].GetDescription().clas;
				description2.season = SoldProductArray[i + 1].GetDescription().season;
				description2.gender = SoldProductArray[i + 1].GetDescription().gender;
				description2.size = SoldProductArray[i + 1].GetDescription().size;
				description2.amount = SoldProductArray[i + 1].GetDescription().amount;
				description2.cost = SoldProductArray[i + 1].GetDescription().cost;
				soldProductData2.day = SoldProductArray[i + 1].GetSoldData().day;
				soldProductData2.month = SoldProductArray[i + 1].GetSoldData().month;
				soldProductData2.year = SoldProductArray[i + 1].GetSoldData().year;
				if (SoldProductArray[i].GetDescription().cost < SoldProductArray[i + 1].GetDescription().cost) {
					SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

					SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
				}
			}
		}
	}
	if (choice == 2)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = SoldProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = SoldProductArray[i].GetTovarName().nameProduct;
				description.type = SoldProductArray[i].GetDescription().type;
				description.appointment = SoldProductArray[i].GetDescription().appointment;
				description.clas = SoldProductArray[i].GetDescription().clas;
				description.season = SoldProductArray[i].GetDescription().season;
				description.gender = SoldProductArray[i].GetDescription().gender;
				description.size = SoldProductArray[i].GetDescription().size;
				description.amount = SoldProductArray[i].GetDescription().amount;
				description.cost = SoldProductArray[i].GetDescription().cost;
				soldProductData.day = SoldProductArray[i].GetSoldData().day;
				soldProductData.month = SoldProductArray[i].GetSoldData().month;
				soldProductData.year = SoldProductArray[i].GetSoldData().year;

				productName2.nameFirm = SoldProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = SoldProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = SoldProductArray[i + 1].GetDescription().type;
				description2.appointment = SoldProductArray[i + 1].GetDescription().appointment;
				description2.clas = SoldProductArray[i + 1].GetDescription().clas;
				description2.season = SoldProductArray[i + 1].GetDescription().season;
				description2.gender = SoldProductArray[i + 1].GetDescription().gender;
				description2.size = SoldProductArray[i + 1].GetDescription().size;
				description2.amount = SoldProductArray[i + 1].GetDescription().amount;
				description2.cost = SoldProductArray[i + 1].GetDescription().cost;
				soldProductData2.day = SoldProductArray[i + 1].GetSoldData().day;
				soldProductData2.month = SoldProductArray[i + 1].GetSoldData().month;
				soldProductData2.year = SoldProductArray[i + 1].GetSoldData().year;
				if (SoldProductArray[i].GetDescription().cost > SoldProductArray[i + 1].GetDescription().cost) {
					SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

					SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
				}
			}
		}
	}
	if (choice == 3)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = SoldProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = SoldProductArray[i].GetTovarName().nameProduct;
				description.type = SoldProductArray[i].GetDescription().type;
				description.appointment = SoldProductArray[i].GetDescription().appointment;
				description.clas = SoldProductArray[i].GetDescription().clas;
				description.season = SoldProductArray[i].GetDescription().season;
				description.gender = SoldProductArray[i].GetDescription().gender;
				description.size = SoldProductArray[i].GetDescription().size;
				description.amount = SoldProductArray[i].GetDescription().amount;
				description.cost = SoldProductArray[i].GetDescription().cost;
				soldProductData.day = SoldProductArray[i].GetSoldData().day;
				soldProductData.month = SoldProductArray[i].GetSoldData().month;
				soldProductData.year = SoldProductArray[i].GetSoldData().year;

				productName2.nameFirm = SoldProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = SoldProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = SoldProductArray[i + 1].GetDescription().type;
				description2.appointment = SoldProductArray[i + 1].GetDescription().appointment;
				description2.clas = SoldProductArray[i + 1].GetDescription().clas;
				description2.season = SoldProductArray[i + 1].GetDescription().season;
				description2.gender = SoldProductArray[i + 1].GetDescription().gender;
				description2.size = SoldProductArray[i + 1].GetDescription().size;
				description2.amount = SoldProductArray[i + 1].GetDescription().amount;
				description2.cost = SoldProductArray[i + 1].GetDescription().cost;
				soldProductData2.day = SoldProductArray[i + 1].GetSoldData().day;
				soldProductData2.month = SoldProductArray[i + 1].GetSoldData().month;
				soldProductData2.year = SoldProductArray[i + 1].GetSoldData().year;

				if (productName.nameFirm.size() < productName2.nameFirm.size() || productName.nameFirm.size() == productName2.nameFirm.size())
				{
					for (int c = 0; c < productName.nameFirm.size(); c++)
					{
						if (productName.nameFirm[c] > productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
							goto Next3;
						}
						if (productName.nameFirm[c] < productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName2, description2, soldProductData2);
							goto Next3;
						}
						if (productName.nameFirm[c] == productName2.nameFirm[c])
						{
						}
					}
				}
				if (productName.nameFirm.size() > productName2.nameFirm.size())
				{
					for (int c = 0; c < productName2.nameFirm.size(); c++)
					{
						if (productName.nameFirm[c] > productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
							goto Next3;
						}
						if (productName.nameFirm[c] < productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName2, description2, soldProductData2);
							goto Next3;
						}
						if (productName.nameFirm[c] == productName2.nameFirm[c])
						{
						}
					}
				}
			Next3:;
			}
		}
	}
}

void SoldProduct::bestSellingProductPrint(SoldProduct* SoldProductArray, int& _amount, int amountPrint)
{
	int n, m, c, p;
	struct tm Year;
	time_t now;
	now = time(NULL);
	Year = *localtime(&now);
	int currentYear = Year.tm_year + 1900;
tryAgain:

	cout << "                                                                                                        [1] - Січень" << endl;
	cout << "                                                                                                        [2] - Лютий" << endl;
	cout << "                                                                                                        [3] - Березень" << endl;
	cout << "                                                                                                        [4] - Квітень" << endl;
	cout << "                                                                                                        [5] - Травень" << endl;
	cout << "                                                                                                        [6] - Червень" << endl;
	cout << "                                                                                                        [7] - Липень" << endl;
	cout << "                                                                                                        [8] - Серпень" << endl;
	cout << "                                                                                                        [9] - Вересень" << endl;
	cout << "                                                                                                        [10] - Жовтень" << endl;
	cout << "                                                                                                        [11] - Листопад" << endl;
	cout << "                                                                                                        [12] - Грудень" << endl;
	cout << "                                                                                                        [13] - За весь рік" << endl;
	cout << "                                                                                                        [0] - Вихід" << endl;
	cin >> n;

	system("cls");
    c = p = 0; 
	if (n > 0 && n < 13)
	{
	TryAgain1:
		cout << "                                                                              [1] - Сортувати за ціною(спочатку дорогі)" << endl;
		cout << "                                                                              [2] - Сортувати за ціною(спочатку дешеві)" << endl;
		cout << "                                                                              [3] - Сортувати за алфавітом(A -> Z)" << endl;
		cout << "                                                                              [0] - Назад" << endl;

		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		if (n == 1) { cout << "|                                                                                                       Історія продажів за Січень                                                                                                  |" << endl; }
		if (n == 2) { cout << "|                                                                                                       Історія продажів за Лютий                                                                                                   |" << endl; }
		if (n == 3) { cout << "|                                                                                                       Історія продажів за Березень                                                                                                |" << endl; }
		if (n == 4) { cout << "|                                                                                                       Історія продажів за Квітень                                                                                                 |" << endl; }
		if (n == 5) { cout << "|                                                                                                       Історія продажів за Травень                                                                                                 |" << endl; }
		if (n == 6) { cout << "|                                                                                                       Історія продажів за Червень                                                                                                 |" << endl; }
		if (n == 7) { cout << "|                                                                                                       Історія продажів за Липень                                                                                                  |" << endl; }
		if (n == 8) { cout << "|                                                                                                       Історія продажів за Серпень                                                                                                 |" << endl; }
		if (n == 9) { cout << "|                                                                                                       Історія продажів за Вересень                                                                                                |" << endl; }
		if (n == 10) { cout << "|                                                                                                       Історія продажів за Жовтень                                                                                                 |" << endl; }
		if (n == 11) { cout << "|                                                                                                       Історія продажів за Листопад                                                                                                |" << endl; }
		if (n == 12) { cout << "|                                                                                                       Історія продажів за Грудень                                                                                                 |" << endl; }


		cout << setiosflags(ios::left);
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;

		cout << "|" << setw(3) << "№" << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |"
			<< setw(21) << "ТИП" << " |" << setw(22) << "ПРИЗНАЧЕННЯ" << " |" << setw(21) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
			<< " |" << setw(17) << "СТАТЬ" << " |" << setw(14) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << setw(5) << "Дата" << "  " << setw(8) << "       |" << endl;

		cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		int x = 0;
		
		for (int i = 0; i < _amount; i++)
		{

			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == n && SoldProductArray[i].GetSoldData().day < 32)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c; 
				SoldProductArray[i].SoldPrint();
				p++;
			}
			else {
				x++;
			}
			if(p == amountPrint)
			{
				break;
			}
			
		}
		cin >> m;

		if (m == 0)
		{
			system("cls");
			goto tryAgain;
		}
		if (m > 0 && m < 6)
		{
			system("cls");
			SoldProductArray->SortSoldProduct(SoldProductArray, _amount, m);
			goto TryAgain1;
		}
	}
	if (n == 13)
	{
	TryAgain2:
		cout << "                                                                              [1] - Сортувати за ціною(спочатку дорогі)" << endl;
		cout << "                                                                              [2] - Сортувати за ціною(спочатку дешеві)" << endl;
		cout << "                                                                              [3] - Сортувати за алфавітом(A -> Z)" << endl;
		cout << "                                                                              [0] - Назад" << endl;

		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                                                       Історія продажів за Весь рік                                                                                                |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                      Січень                                                                                                                                                                                                       |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 1)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++; 
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Лютий                                                                                                                                                                                                        |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		
		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 2)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Березень                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 3)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Квітень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 4)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Травень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 5)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Червень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 6)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Липень                                                                                                                                                                                                       |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 7)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                                                                                                               Серпень                                                                                                             |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 8)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Вересень                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 9)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Жовтеннь                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 10)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Листопад                                                                                                                                                                                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 11)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cout << "|                      Грудень                                                                                                                                                                                                      |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		c = p = 0;
		for (int i = 0; i < _amount; i++)
		{
			if (SoldProductArray[i].GetSoldData().year == currentYear && SoldProductArray[i].GetSoldData().month == 12)
			{
				c++;
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << c;
				SoldProductArray[i].SoldPrint();
				p++;
			}
			if (p == amountPrint)
			{
				break;
			}
		}
		cin >> m;

		if (m == 0)
		{
			system("cls");
			goto tryAgain;
		}
		if (m > 0 && m < 6)
		{
			system("cls");
			SoldProductArray->SortSoldProduct(SoldProductArray, _amount, m);
			goto TryAgain2;
		}
	}
	if (n != 0 || n > 13)
	{
		cout << "Такого пункту меню не існує!" << endl;
		system("cls");
		goto tryAgain;
	}
	if (n == 0)
	{
	}
}

SoldProduct& SoldProduct::operator=(SoldProduct SoldProductArray_old)
{
	this->productName.nameFirm = SoldProductArray_old.productName.nameFirm;
	this->productName.nameProduct = SoldProductArray_old.productName.nameProduct;

	this->description.type = SoldProductArray_old.description.type;
	this->description.appointment = SoldProductArray_old.description.appointment;
	this->description.clas = SoldProductArray_old.description.clas;
	this->description.season = SoldProductArray_old.description.season;
	this->description.gender = SoldProductArray_old.description.gender;
	this->description.size = SoldProductArray_old.description.size;
	this->description.amount = SoldProductArray_old.description.amount;
	this->description.cost = SoldProductArray_old.description.cost;

	return *this;
}
///////////////////////////////
///////Історія продажів////////
///////////////////////////////



HistoryOfSold::HistoryOfSold()
{
	userData.id = "";
	userData.firstName = "";
	userData.lastName = "";
	userData.yearOfBirthd = 0;
	userData.phoneNumber = "";

	productName.nameFirm = "";
	productName.nameProduct = "";

	description.type = "";
	description.appointment = "";
	description.clas = "";
	description.season = "";
	description.gender = "";
	description.size = "";
	description.amount = 0;
	description.cost = 0;

	soldProductData.year = 0;
	soldProductData.month = 0;
	soldProductData.day = 0;
}

HistoryOfSold::HistoryOfSold(UserData userData_, ProductName productName_, Description description_, SoldProductData soldProductData_)
{
	userData.id = userData_.id;
	userData.firstName = userData_.firstName;
	userData.lastName = userData_.lastName;
	userData.yearOfBirthd = userData_.yearOfBirthd;
	userData.phoneNumber = userData_.phoneNumber;

	productName.nameFirm = productName_.nameFirm;
	productName.nameProduct = productName_.nameProduct;

	description.type = description_.type;
	description.appointment = description_.appointment;
	description.clas = description_.clas;
	description.season = description_.season;
	description.gender = description_.gender;
	description.size = description_.size;
	description.amount = description_.amount;
	description.cost = description_.cost;

	soldProductData.day = soldProductData_.day;
	soldProductData.month = soldProductData_.month;
	soldProductData.year = soldProductData_.year;
}

HistoryOfSold::~HistoryOfSold()
{
}

void HistoryOfSold::HistoryOfSaleEnrty(UserData userData_, ProductName productName_, Description description_, SoldProductData soldProductData_)
{
	userData.id = userData_.id;
	userData.firstName = userData_.firstName;
	userData.lastName = userData_.lastName;
	userData.yearOfBirthd = userData_.yearOfBirthd;
	userData.phoneNumber = userData_.phoneNumber;

	productName.nameFirm = productName_.nameFirm;
	productName.nameProduct = productName_.nameProduct;

	description.type = description_.type;
	description.appointment = description_.appointment;
	description.clas = description_.clas;
	description.season = description_.season;
	description.gender = description_.gender;
	description.size = description_.size;
	description.amount = description_.amount;
	description.cost = description_.cost;

	soldProductData.day = soldProductData_.day;
	soldProductData.month = soldProductData_.month;
	soldProductData.year = soldProductData_.year;
}

void HistoryOfSold::HistoryReading(HistoryOfSold* (&HistoryOfSoldArray), int& _amount, string fileName)
{
	UserData userData;
	ProductName productName;
	Description description;
	SoldProductData selledProductData;

	ifstream reading(fileName);
	if (reading)
	{
		reading >> _amount;
		HistoryOfSoldArray = new HistoryOfSold[_amount];
		for (int i = 0; i < _amount; i++)
		{
			reading >> userData.id >> userData.lastName >> userData.firstName  >> userData.phoneNumber >> userData.yearOfBirthd 
				>> productName.nameFirm >> productName.nameProduct >> description.type >> description.appointment 
				>> description.clas >> description.season >> description.gender >> description.size >> description.amount 
				>> description.cost >> selledProductData.day >> selledProductData.month >> selledProductData.year;
			HistoryOfSoldArray[i].HistoryOfSaleEnrty(userData, productName, description, selledProductData);
		}
	}reading.close();
}

void HistoryOfSold::PrintHistoryData(HistoryOfSold* (&HistoryOfSoldArray), int& _amount, string _user)
{
		cout << setiosflags(ios::left);
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                                                Історія покупок                                                                                                                    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;

		cout << "|" << setw(3) << "№" << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |"
			<< setw(21) << "ТИП" << " |" << setw(22) << "ПРИЗНАЧЕННЯ" << " |" << setw(21) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
			<< " |" << setw(17) << "СТАТЬ" << " |" << setw(14) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << setw(5) << "Дата" << "  " << setw(8) << "       |" << endl;

		cout << "|    |                     |                          |                      |                       |                      |                        |                  |               |           |                |              |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		
		int n = 0;
		for (int i = 0; i < _amount; i++)
		{
			
			if (HistoryOfSoldArray[i].GetUserData().id == _user)
			{
				cout << setiosflags(ios::right);
				cout << "|" << setw(3) << i + 1 - n ;
				HistoryOfSoldArray[i].PrintHistory();
			}
			else
			{
				n++;
			}
		}
}

void HistoryOfSold::PrintHistory()
{
	cout << " |" << setw(20) << productName.nameFirm << " |" << setw(25) << productName.nameProduct << " |" << setw(21) << description.type
		<< " |" << setw(22) << description.appointment << " |" << setw(21) << description.clas << " |" << setw(23) << description.season
		<< " |" << setw(17) << description.gender << " |" << setw(14) << description.size << " |" << setw(10) << description.amount
		<< " |" << setw(15) << description.cost << " |" << setw(6) << soldProductData.day << "." << soldProductData.month
		<< "." << soldProductData.year << " |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}

void HistoryOfSold::PrintHistoryForEmployee()
{
	cout << " |" << setw(15) << productName.nameFirm << " |" << setw(15) << productName.nameProduct << " |" << setw(15) << description.type
		<< " |" << setw(15) << description.appointment << " |" << setw(17) << description.clas << " |" << setw(12) << description.season
		<< " |" << setw(10) << description.gender << " |" << setw(7) << description.size << " |" << setw(9) << description.amount
		<< " |" << setw(9) << description.cost << " |" << setw(5) << soldProductData.day << "." << soldProductData.month
		<< "." << soldProductData.year << " |" << endl;
}


avarageOfSoldByAppointment::avarageOfSoldByAppointment()
{
	avarageData.Casual = 0;
	avarageData.Ski = 0;
	avarageData.Run = 0;
	avarageData.Box = 0;
	avarageData.month = 0;
}

avarageOfSoldByAppointment::avarageOfSoldByAppointment(AvarageData avarageData_)
{
	avarageData.Casual = avarageData_.Casual;
	avarageData.Ski = avarageData_.Ski;
	avarageData.Run = avarageData_.Run;
	avarageData.Box = avarageData_.Box;
	avarageData.month = avarageData_.month;
}

avarageOfSoldByAppointment::~avarageOfSoldByAppointment()
{
}

void avarageOfSoldByAppointment::avarageOfSoldByAppEntry(AvarageData avarageData_)
{
	avarageData.Casual = avarageData_.Casual;
	avarageData.Ski = avarageData_.Ski;
	avarageData.Run = avarageData_.Run;
	avarageData.Box = avarageData_.Box;
	avarageData.month = avarageData_.month;
}

void avarageOfSoldByAppointment::printAvarageOfSold(avarageOfSoldByAppointment* AvarageOfSoldArray, int _amount)
{
	int n, m;
	struct tm Year;
	time_t now;
	now = time(NULL);
	Year = *localtime(&now);
	int currentYear = Year.tm_year + 1900;
tryAgain:

	cout << "                                                                                                        [1] - Січень" << endl;
	cout << "                                                                                                        [2] - Лютий" << endl;
	cout << "                                                                                                        [3] - Березень" << endl;
	cout << "                                                                                                        [4] - Квітень" << endl;
	cout << "                                                                                                        [5] - Травень" << endl;
	cout << "                                                                                                        [6] - Червень" << endl;
	cout << "                                                                                                        [7] - Липень" << endl;
	cout << "                                                                                                        [8] - Серпень" << endl;
	cout << "                                                                                                        [9] - Вересень" << endl;
	cout << "                                                                                                        [10] - Жовтень" << endl;
	cout << "                                                                                                        [11] - Листопад" << endl;
	cout << "                                                                                                        [12] - Грудень" << endl;
	cout << "                                                                                                        [13] - За весь рік" << endl;
	cout << "                                                                                                        [0] - Вихід" << endl;
	cin >> n;

	system("cls");

	if (n > 0 && n < 13)
	{
		cout << "[0] - Назад" << endl;

		cout << "                                                                                    ------------------------------------------------------------                                                                                     " << endl;
		if (n == 1) { cout << "                                                                                    |                         Січень                           |                                                                                     " << endl; }
		if (n == 2) { cout << "                                                                                    |                           Лютий                          |                                                                                     " << endl; }
		if (n == 3) { cout << "                                                                                    |                          Березень                        |                                                                                     " << endl; }
		if (n == 4) { cout << "                                                                                    |                           Квітень                        |                                                                                     " << endl; }
		if (n == 5) { cout << "                                                                                    |                          Травень                         |                                                                                     " << endl; }
		if (n == 6) { cout << "                                                                                    |                          Червень                         |                                                                                     " << endl; }
		if (n == 7) { cout << "                                                                                    |                           Липень                         |                                                                                     " << endl; }
		if (n == 8) { cout << "                                                                                    |                          Серпень                         |                                                                                     " << endl; }
		if (n == 9) { cout << "                                                                                    |                          Вересень                        |                                                                                     " << endl; }
		if (n == 10) { cout << "                                                                                    |                          Жовтень                         |                                                                                     " << endl; }
		if (n == 11) { cout << "                                                                                    |                         Листопад                         |                                                                                     " << endl; }
		if (n == 12) { cout << "                                                                                    |                          Грудень                         |                                                                                     " << endl; }
		cout << "                                                                                    ------------------------------------------------------------                                                                                     " << endl;

		for (int i = 0; i < _amount; i++)
		{

			if (AvarageOfSoldArray[i].GetAvarageData().month == n)
			{
				cout << setiosflags(ios::right);
				AvarageOfSoldArray[i].printAvarage();
			}
		}
		cin >> m;
		if (m == 0)
		{
			system("cls");
			goto tryAgain;
		}
		if (n != 0 || n > 13)
		{
			cout << "Такого пункту меню не існує!" << endl;
			system("cls");
			goto tryAgain;
		}
	}
	if (n == 13)
	{
		cout << "[0] - Назад" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                                                                                                                                                                                   |" << endl;
		cout << "|                                                                                                       Історія продажів за Весь рік                                                                                                |" << endl;
		cout << "|                                                                                                                                                                                                                                   |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|              Січень                 |              Лютий                  |              Березень               |              Квітень                |               Травень               |               Червень               |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;

		cout << "|" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[0].GetAvarageData().Casual << "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[1].GetAvarageData().Casual
			<< "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[2].GetAvarageData().Casual << "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[3].GetAvarageData().Casual
			<< "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[4].GetAvarageData().Casual << "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[5].GetAvarageData().Casual << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[0].GetAvarageData().Ski << "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[1].GetAvarageData().Ski
			<< "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[2].GetAvarageData().Ski << "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[3].GetAvarageData().Ski
			<< "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[4].GetAvarageData().Ski << "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[5].GetAvarageData().Ski << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[0].GetAvarageData().Run << "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[1].GetAvarageData().Run
			<< "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[2].GetAvarageData().Run << "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[3].GetAvarageData().Run
			<< "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[4].GetAvarageData().Run << "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[5].GetAvarageData().Run << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[0].GetAvarageData().Box << "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[1].GetAvarageData().Box
			<< "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[2].GetAvarageData().Box << "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[3].GetAvarageData().Box
			<< "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[4].GetAvarageData().Box << "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[5].GetAvarageData().Box << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                                                                                                                                                                                   |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|              Липень                 |              Серпень                |              Вересень               |              Жовтень                |              Листопад               |               Грудень               |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[6].GetAvarageData().Casual << "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[7].GetAvarageData().Casual
			<< "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[8].GetAvarageData().Casual << "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[9].GetAvarageData().Casual
			<< "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[10].GetAvarageData().Casual << "         |" << setw(15) << "Повсякденний:" << setw(13) << AvarageOfSoldArray[11].GetAvarageData().Casual << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[6].GetAvarageData().Ski << "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[7].GetAvarageData().Ski
			<< "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[8].GetAvarageData().Ski << "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[9].GetAvarageData().Ski
			<< "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[10].GetAvarageData().Ski << "         |" << setw(15) << "Гірськолижний:" << setw(13) << AvarageOfSoldArray[11].GetAvarageData().Ski << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[6].GetAvarageData().Run << "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[7].GetAvarageData().Run
			<< "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[8].GetAvarageData().Run << "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[9].GetAvarageData().Run
			<< "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[10].GetAvarageData().Run << "         |" << setw(15) << "Біговий:" << setw(13) << AvarageOfSoldArray[11].GetAvarageData().Run << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "|" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[6].GetAvarageData().Box << "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[7].GetAvarageData().Box
			<< "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[8].GetAvarageData().Box << "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[9].GetAvarageData().Box
			<< "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[10].GetAvarageData().Box << "         |" << setw(15) << "Боксерський:" << setw(13) << AvarageOfSoldArray[11].GetAvarageData().Box << "         |" << endl;
		cout << "|                                     |                                     |                                     |                                     |                                     |                                     |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		cin >> m;
		if (m == 0)
		{
			system("cls");
			goto tryAgain;
		}
		if (n != 0 || n > 13)
		{
			cout << "Такого пункту меню не існує!" << endl;
			system("cls");
			goto tryAgain;
		}
	}
	if (n == 0) 
	{
	}
}

void avarageOfSoldByAppointment::printAvarage()
{
	cout << setw(85) << "|" << setw(59) << "|" << endl;
	cout << setw(85) << "|" << setw(22) << "Повсякденний:" << setw(22) << avarageData.Casual << setw(15) << "|" << endl;
	cout << setw(85) << "|" << setw(59) << "|" << endl;
	cout << setw(85) << "|" << setw(22) << "Гірськолижний:" << setw(22) << avarageData.Ski << setw(15) << "|" << endl;
	cout << setw(85) << "|" << setw(59) << "|" << endl;
	cout << setw(85) << "|" << setw(22) << "Біговий:" << setw(22) << avarageData.Run << setw(15) << "|" << endl;
	cout << setw(85) << "|" << setw(59) << "|" << endl;
	cout << setw(85) << "|" << setw(22) << "Боксерський:" << setw(22) << avarageData.Box << setw(15) << "|" << endl;
	cout << setw(85) << "|" << setw(59) << "|" << endl;
	cout << "                                                                                    ------------------------------------------------------------" << endl;

}


////////////////////////
///////Користвач////////
////////////////////////  



User::User()
{
	userData.id = "";
	userData.firstName = "";
	userData.lastName = "";
	userData.yearOfBirthd = 0;
	userData.phoneNumber = "";
	userData.status = "";
	userData.login = "";
	userData.password = "";
}

User::User(UserData userData_)
{
	userData.id = userData_.id;
	userData.firstName = userData_.firstName;
	userData.lastName = userData_.lastName;
	userData.yearOfBirthd = userData_.yearOfBirthd;
	userData.phoneNumber = userData_.phoneNumber;
	userData.status = userData_.status;
	userData.login = userData_.login;
	userData.password = userData_.password;
}

User::~User()
{
}


void User::PrintUserData(User* (&ClientArray), int& _amount)
{
	for (int i = 0; i < _amount; i++)
	{
		cout << setiosflags(ios::right);
		cout << "|" << setw(3) << i + 1;
		cout << userData.id << setw(33) << userData.firstName << setw(33) << userData.lastName << setw(25) << userData.yearOfBirthd << setw(27) << userData.phoneNumber << setw(27) << userData.phoneNumber << setw(27) << userData.status << setw(25) << userData.login << setw(25) << userData.password << endl;
	    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

void User::UserDataEnrty(UserData userData_)
{
	userData.id = userData_.id;
	userData.firstName = userData_.firstName;
	userData.lastName = userData_.lastName;
	userData.yearOfBirthd = userData_.yearOfBirthd;
	userData.phoneNumber = userData_.phoneNumber;
	userData.status = userData_.status;
	userData.login = userData_.login;
	userData.password = userData_.password;
}

void User::ClientDataReading(User* (&ClientArray), int& _amount, string fileName)
{
	UserData userData;
	ifstream reading(fileName);
	if (reading)
	{
		reading >> _amount;
		ClientArray = new User[_amount];
		for (int i = 0; i < _amount; i++)
		{
			reading >> userData.id >> userData.firstName >> userData.lastName >> userData.yearOfBirthd >> userData.phoneNumber >> userData.status >> userData.login >> userData.password;
			ClientArray[i].UserDataEnrty(userData);
		}
	}reading.close();
}

pair <string, string> User::ClientInitialization(User* (&ClientArray), int& _amount)
{
tryAgain:
	system("cls");
	string password, login, usr;
	int n = 0;

	cout << "Введіть логін: \t" << endl;
	cin >> login;
	cout << "Введіть пароль:\t" << endl;
	cin >> password;

	for (int i = 0; i < _amount; i++)
	{
		if (login == ClientArray[i].GetUserData().login && password == ClientArray[i].GetUserData().password)
		{
			string userStatus = "Client";
			usr = ClientArray[i].GetUserData().id;
			system("cls");
			cout << ClientArray[i].GetUserData().firstName << endl;
			return pair<string, string>(userStatus,usr); 
		}
		else
		{
			++n;
		}
	}
	if (n == _amount) 
	{
		system("cls"); 
		cout << "Не правильний логін або пароль!\n      Спробуйте знову" << endl;
		goto tryAgain;
	}
}

User& User::operator=(User UserArray) 
{
	this->userData.id = UserArray.userData.id;
	this->userData.firstName = UserArray.userData.firstName;
	this->userData.lastName = UserArray.userData.lastName;
	this->userData.yearOfBirthd = UserArray.userData.yearOfBirthd;
	this->userData.phoneNumber = UserArray.userData.phoneNumber;
	this->userData.status = UserArray.userData.status;
	this->userData.login = UserArray.userData.login;
	this->userData.password = UserArray.userData.password;

	return *this;
}



////////////////////////
///////Працівник////////
//////////////////////// 



Employee::Employee()
{
	employeeData.department = "";
	employeeData.workingDays = "";
};

Employee::Employee(UserData userData_, EmployeeData  employeeData_)
{
	userData.id = userData_.id;
	userData.firstName = userData_.firstName;
	userData.lastName = userData_.lastName;
	userData.yearOfBirthd = userData_.yearOfBirthd;
	userData.phoneNumber = userData_.phoneNumber;
	userData.status = userData_.status;
	userData.login = userData_.login;
	userData.password = userData_.password;

	employeeData.department = employeeData_.department;
	employeeData.workingDays = employeeData_.workingDays;
};

Employee::~Employee()
{
};

void Employee::EmployeeDataEnrty(UserData userData_, EmployeeData  employeeData_)
{
	userData.id = userData_.id;
	userData.firstName = userData_.firstName;
	userData.lastName = userData_.lastName;
	userData.yearOfBirthd = userData_.yearOfBirthd;
	userData.phoneNumber = userData_.phoneNumber;
	userData.status = userData_.status;
	userData.login = userData_.login;
	userData.password = userData_.password;

	employeeData.department = employeeData_.department;
	employeeData.workingDays = employeeData_.workingDays;
}

pair<string, string> Employee::EmployeeInitialization(Employee* (&EmployeeArray), int& _amount)
{
tryAgain:
	system("cls");
	string password, login, usr;
	int n = 0;

	cout << "                                                                                                   Введіть логін: \t" << endl;
	cout << "                                                                                                   ";
	cin >> login;
	cout << "                                                                                                   Введіть пароль:\t" << endl;
	cout << "                                                                                                   ";
	cin >> password;

	for (int i = 0; i < _amount; i++)
	{
		if (login == EmployeeArray[i].GetUserData().login && password == EmployeeArray[i].GetUserData().password)
		{
			string userStatus = "Administrator";
			usr = EmployeeArray[i].GetUserData().id;
			system("cls");
			cout << EmployeeArray[i].GetUserData().firstName << endl;
			return pair<string, string>(userStatus, usr);
		}
		else
		{
			++n;
		}
	}
	if (n == _amount)
	{
		system("cls");
		cout << "Не правильний логін або пароль!\n      Спробуйте знову" << endl;
		goto tryAgain;
	}
}

void Employee::EmployeeDataReading(Employee* (&EmployeeArray), int& _amount, string fileName)
{
	UserData userData;
	EmployeeData employeeData;

	ifstream reading(fileName);
	if (reading)
	{
		reading >> _amount;
		EmployeeArray = new Employee[_amount];
		for (int i = 0; i < _amount; i++)
		{
			reading >> userData.id >> userData.firstName >> userData.lastName >> userData.yearOfBirthd >> userData.phoneNumber >> userData.status >> userData.login >> userData.password >> employeeData.department >> employeeData.workingDays;
			EmployeeArray[i].EmployeeDataEnrty(userData, employeeData);
		}
	}reading.close();
}

void Employee::PrintEmployeeData(Employee* (&EmployeeArray), int& _amount) 
{
	for (int i = 0; i < _amount; i++)
	{
		cout << setiosflags(ios::right);
		
		cout << "|" << setw(3) << i + 1 << setw(17) << userData.id << setw(23) << userData.firstName << setw(23) << userData.lastName << setw(17) << userData.yearOfBirthd
			 << setw(23) << userData.phoneNumber << setw(23) << userData.status << setw(23) << userData.login << setw(23) 
			 << userData.password << setw(23) << employeeData.department << setw(23) << employeeData.workingDays << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}





Departament::Departament()
{
}

Departament::~Departament()
{
}






