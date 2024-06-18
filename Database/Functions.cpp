#include "Functions.h"
//Зчитування даних з файлів
void GuestMenu(ProductData* ProductArrayInStor, int _amount)
{
tryAgain:
	int clientChoice;
	cout << "[1] - Пошук товару" << endl;
	cout << "[2] - Відгуки про роботу магазину" << endl;
	cout << "[3] - Графік роботи магазину" << endl;
	cout << "[4] - Список товару" << endl;
	cout << "[5] - Реєстрація" << endl;
	cout << "[0] - Вийти" << endl;
	cout << "Вибір: ";
	cin >> clientChoice;

	while (clientChoice != 0)
	{
		switch (clientChoice)
		{
		case 1:
			system("cls");
			searchMenu(ProductArrayInStor, _amount, "Client");
			system("cls");
			goto tryAgain;
			break;
		case 2:
			system("cls");
			system("pause");
			system("cls");
			goto tryAgain;
			break;
		case 3:
			system("cls");

			system("pause");
			system("cls");
			goto tryAgain;
			break;
		case 4:
		tryAgain2:
			system("cls");
			int n;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " [1] - Сортувати за ціною(спочатку дорогі)  |      [2] - Сортувати за ціною(спочатку дешеві)       |        [5] - Сортувати за алфавітом          |         [5] - Сортувати за алфавітом          |           [0] - Назад           |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			ProductArrayInStor->PrintProductForClient(ProductArrayInStor, _amount, "Client");
			cin >> n;
			if (n > 0 && n < 3)
			{
				SortForClient(ProductArrayInStor, _amount, n);
				goto tryAgain2;
			}if (n == 0)
			{
			}
			system("cls");
			goto tryAgain;
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}

void ProductDataChange(ProductData* (&ProductArrayInStor), int& _amount)
{
	ProductName productName;
	Description description;
	int i;

	cout << "Введіть номер товару який хочете змінити:\t";
	cin >> i;
	i--;

	if (i >= 0 && i < _amount)
	{
		cout << "В пунктах які не потрідно змінювати введіть '1'" << endl;
		cout << "Назва фірми:                             ";
		cin >> productName.nameFirm;
		if (productName.nameFirm == "1") { productName.nameFirm = ProductArrayInStor[i].GetTovarName().nameFirm; }
		cout << "Назва позиції:                           ";
		cin >> productName.nameProduct;
		if (productName.nameProduct == "1") { productName.nameProduct = ProductArrayInStor[i].GetTovarName().nameProduct; }
		cout << "Тип(Верхній одяг, Нижній одяг, Взуття):  ";
		cin >> description.type;
		if (description.type == "1") { description.type = ProductArrayInStor[i].GetDescription().type; }
		cout << "Призначення:                             ";
		cin >> description.appointment;
		if (description.appointment == "1") { description.appointment = ProductArrayInStor[i].GetDescription().appointment; }
		cout << "Клас:                                    ";
		cin >> description.clas;
		if (description.clas == "1") { description.clas = ProductArrayInStor[i].GetDescription().clas; }
		cout << "Сезон:                                   ";
		cin >> description.season;
		if (description.season == "1") { description.season = ProductArrayInStor[i].GetDescription().season; }
		cout << "Стать:                                   ";
		cin >> description.gender;
		if (description.gender == "1") { description.gender = ProductArrayInStor[i].GetDescription().gender; }
		cout << "Розмір:                                  ";
		cin >> description.size;
		if (description.size == "1") { description.size = ProductArrayInStor[i].GetDescription().size; }
		cout << "Кількість:                               ";
		cin >> description.amount;
		if (description.amount == 1) { description.amount = ProductArrayInStor[i].GetDescription().amount; }
		cout << "Ціна:                                    ";
		cin >> description.cost;
		if (description.cost == 1) { description.cost = ProductArrayInStor[i].GetDescription().cost; }
		ProductArrayInStor[i].ProductDataEnrty(productName, description);
		SaveProductData(ProductArrayInStor, _amount, "TovarDataStor.txt");
	}
}

void searchByWroteName(ProductData* ProductArrayInStor, int _amount, string _userStatus)
{
	string m, x;
	
	cout << "Ввудіть назву товару" << endl;
	cin >> m;
			
			for (int i = 0; i < _amount; i++)
			{
				int n = 0;
				x = ProductArrayInStor[i].GetTovarName().nameFirm;
				
				for (int i = 0; i < m.size(); i++)
			    {
					if (m[i] > 90)
					{
						m[i] = m[i] - 32;
					}
					if (x[i] > 90)
					{
						x[i] = x[i] - 32;
					}
					if (m[i] == x[i])
					{
						n++;
					}
				}
				if (m.size() == n)
				{
					ProductArrayInStor[i].PrintProductData(_userStatus);
				}
		    }
}

void searchMenu(ProductData* ProductArrayInStor, int _amount, string _userStatus)
{
		system("cls");

		int searchMenuChoice;

		cout << "[1] - За назвою виробника" << endl;
		cout << "[2] - За сезоном" << endl;
		cout << "[3] - За типом" << endl;
		cout << "[4] - За статю" << endl;
		cout << "[5] - Розширений пошук" << endl;
		cout << "[0] - Повернутися до головного меню" << endl;
		cin >> searchMenuChoice;
		int x, n = 1;
		string firm = "";

		switch (searchMenuChoice)
		{
		case 1:
			system("cls");
			searchByNameFirm(ProductArrayInStor, _amount, _userStatus);
			system("pause");
			system("cls");
			break;
		case 2:
			int n, x;
			TryAgain1:
			system("cls");
			cout << "[1] - Літо" << endl;
			cout << "[2] - Зима" << endl;
			cout << "[3] - Демісезон" << endl;

			cin >> n;			
			
			if (0 < n && n < 4) 
			{
			TryAgain:
				system("cls");
				if (_userStatus == "Administrator")
				{

					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "[1] - Сортувати за ціною(спочатку дорогі)  |  [2] - Сортувати за ціною(спочатку дешеві)  |  [3] - Сортувати за кількістю(max -> min)  |  [4] - Сортувати за кількістю(min -> max)  |  [5] - Сортувати за алфавітом  |  [0] - Назад" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					SortForEmployee(ProductArrayInStor, _amount, x);
				}
				else
				{
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << " [1] - Сортувати за ціною(спочатку дорогі)  |      [2] - Сортувати за ціною(спочатку дешеві)       |        [5] - Сортувати за алфавітом          |         [5] - Сортувати за алфавітом          |           [0] - Назад           |" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				}

				if (n == 1)
				{
					for (int i = 0; i < _amount; i++)
					{
						if (ProductArrayInStor[i].GetDescription().season == "Літо")
						{
							ProductArrayInStor[i].PrintProductData(_userStatus);
							
						}
					}
				}
				if (n == 2)
				{
					for (int i = 0; i < _amount; i++)
					{
						if (ProductArrayInStor[i].GetDescription().season == "Зима")
						{
							ProductArrayInStor[i].PrintProductData(_userStatus);
						}
					}
				}
				if (n == 3)
				{
					for (int i = 0; i < _amount; i++)
					{
						if (ProductArrayInStor[i].GetDescription().season == "Демісезон")
						{
							ProductArrayInStor[i].PrintProductData(_userStatus);
						}
					}
				}
                cin >> x;
				
				if (_userStatus == "Administrator")
				{
					if (x > 0 && x < 6) {
						SortForEmployee(ProductArrayInStor, _amount, x);
						goto TryAgain;
					}
					if (x == 0)
					{
						goto TryAgain1;
					}
				}
				else
				{
					if (x > 0 && x < 4)
					{
						SortForClient(ProductArrayInStor, _amount, x);
						goto TryAgain;
					}
					if(x == 0)
					{
						goto TryAgain1;
					}
				}
			}
			if (n == 0)
			{

			}
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "" << endl;
			cin >> x;
			system("pause");

			break;
		case 0:
			system("cls");
			MenuForAdmin();
			
			break;
		default:
			break;
		}
}

void MenuForClient(ProductData* ProductArrayInStor, int _amount, string _user, string _userStatus)
{ 
	int historyOfSoldSize = 0;
	HistoryOfSold* HistoryOfSoldArray = new HistoryOfSold[historyOfSoldSize];
	HistoryOfSoldArray->HistoryReading(HistoryOfSoldArray, historyOfSoldSize, "HistoryOfSalle.txt");

	tryAgain:
	int clientChoice;
    cout << "[1] - Пошук товару" << endl;
    cout << "[2] - Історія покупок" << endl;
    cout << "[3] - Графік роботи магазину" << endl;
    cout << "[4] - Список товару" << endl;
    cout << "[0] - Вийти" << endl;
    cout << "Вибір: ";

	cin >> clientChoice;
	

	while (clientChoice != 0) 
	{
		switch (clientChoice)
		{
		case 1:
			system("cls");
			searchMenu(ProductArrayInStor, _amount, _userStatus);
			system("cls");
			goto tryAgain;
			break;
		case 2:
			system("cls");
			HistoryOfSoldArray->PrintHistoryData(HistoryOfSoldArray, historyOfSoldSize, _user);
			system("pause");
			system("cls");
			goto tryAgain;
			break;
		case 3:
			system("cls");
		
			system("pause");
			system("cls");
			goto tryAgain;
			break;
		case 4:
			tryAgain2:
			system("cls");
			int n;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " [1] - Сортувати за ціною(спочатку дорогі)  |      [2] - Сортувати за ціною(спочатку дешеві)       |        [5] - Сортувати за алфавітом          |         [5] - Сортувати за алфавітом          |           [0] - Назад           |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			ProductArrayInStor->PrintProductForClient(ProductArrayInStor, _amount, _userStatus);
			cin >> n;
			if (n > 0 && n < 3)
			{
			    SortForClient(ProductArrayInStor, _amount, n);
			    goto tryAgain2;
			}if(n == 0)
			{
			}
			system("cls");
			goto tryAgain;
			break;
		case 0:
			break;
		default:
			break;
		}
	}

}

void ProductDataAdd(ProductData* (&ProductArrayInStorage), int& _amount)
{
	ProductName productName;
	Description description;
	
	int n;
	cout << "                                                                                  Введіть кількість товару яку бажаєте додати:\t";
	cin >> n;

    for (int i = 0; i < n; i++)
    {
		ProductData* buffer = new ProductData[_amount];
		int amount;amount = _amount;
		int new_amount = ++_amount;

		CopyProductData(buffer, ProductArrayInStorage, amount);

		ProductArrayInStorage = new ProductData[new_amount];

		CopyProductData(ProductArrayInStorage, buffer, amount);

		cout << "                                                                                  Назва фірми:                             ";
		cin >> productName.nameFirm;
		cout << "                                                                                  Назва позиції:                           ";
		cin >> productName.nameProduct;
		cout << "                                                                                  Тип(Верхній одяг, Нижній одяг, Взуття):  ";
		cin >> description.type;
		cout << "                                                                                  Призначення:                             ";
		cin >> description.appointment;
		cout << "                                                                                  Клас:                                    ";
		cin >> description.clas;
		cout << "                                                                                  Сезон:                                   ";
		cin >> description.season;
		cout << "                                                                                  Стать:                                   ";
		cin >> description.gender;
		cout << "                                                                                  Розмір:                                  ";
		cin >> description.size;
		cout << "                                                                                  Кількість:                               ";
		cin >> description.amount;
		cout << "                                                                                  Ціна:                                    ";
		cin >> description.cost;

		ProductArrayInStorage[amount].ProductDataEnrty(productName, description);

		ProductArrayInStorage[amount].PrintProductData("Administrator");
		delete[] buffer;
		SaveProductData(ProductArrayInStorage, new_amount, "TovarDataStorage.txt");
    }


}

void searchByProductName(ProductData* ProductArrayInStor, int _amount, string _userStatus)
{
	ProductName productName;
	Description description;

	ProductData* Buffer = new ProductData[_amount];

	productName.nameFirm = ProductArrayInStor[0].GetTovarName().nameFirm;
	productName.nameProduct = ProductArrayInStor[0].GetTovarName().nameProduct;

	description.type = ProductArrayInStor[0].GetDescription().type;
	description.appointment = ProductArrayInStor[0].GetDescription().appointment;
	description.clas = ProductArrayInStor[0].GetDescription().clas;
	description.season = ProductArrayInStor[0].GetDescription().season;
	description.gender = ProductArrayInStor[0].GetDescription().gender;
	description.size = ProductArrayInStor[0].GetDescription().size;
	description.amount = ProductArrayInStor[0].GetDescription().amount;
	description.cost = ProductArrayInStor[0].GetDescription().cost;

	Buffer[0].ProductDataEnrty(productName, description);

	int n = 0;
	for (int i = 1; i < _amount; i++)
	{
		productName.nameFirm = ProductArrayInStor[i].GetTovarName().nameFirm;
		productName.nameProduct = ProductArrayInStor[i].GetTovarName().nameProduct;

		description.type = ProductArrayInStor[i].GetDescription().type;
		description.appointment = ProductArrayInStor[i].GetDescription().appointment;
		description.clas = ProductArrayInStor[i].GetDescription().clas;
		description.season = ProductArrayInStor[i].GetDescription().season;
		description.gender = ProductArrayInStor[i].GetDescription().gender;
		description.size = ProductArrayInStor[i].GetDescription().size;
		description.amount = ProductArrayInStor[i].GetDescription().amount;
		description.cost = ProductArrayInStor[i].GetDescription().cost;

		if (Buffer[n].GetTovarName().nameFirm == productName.nameFirm)
		{
			Buffer[n].ProductDataEnrty(productName, description);
		}
		else
		{
			n++;
			Buffer[n].ProductDataEnrty(productName, description);
		}
	}
}

void searchByNameFirm(ProductData* ProductArrayInStor, int _amount, string _userStatus)
{
	ProductName productName;
	Description description;

	ProductData* Buffer = new ProductData[_amount];
	SortForEmployee(ProductArrayInStor, _amount, 5);

	productName.nameFirm = ProductArrayInStor[0].GetTovarName().nameFirm;
	productName.nameProduct = ProductArrayInStor[0].GetTovarName().nameProduct;

	description.type = ProductArrayInStor[0].GetDescription().type;
	description.appointment = ProductArrayInStor[0].GetDescription().appointment;
	description.clas = ProductArrayInStor[0].GetDescription().clas;
	description.season = ProductArrayInStor[0].GetDescription().season;
	description.gender = ProductArrayInStor[0].GetDescription().gender;
	description.size = ProductArrayInStor[0].GetDescription().size;
	description.amount = ProductArrayInStor[0].GetDescription().amount;
	description.cost = ProductArrayInStor[0].GetDescription().cost;

	Buffer[0].ProductDataEnrty(productName, description);

	int choice, n = 0;
	for (int i = 1; i < _amount; i++)
	{
		productName.nameFirm = ProductArrayInStor[i].GetTovarName().nameFirm;
		productName.nameProduct = ProductArrayInStor[i].GetTovarName().nameProduct;

		description.type = ProductArrayInStor[i].GetDescription().type;
		description.appointment = ProductArrayInStor[i].GetDescription().appointment;
		description.clas = ProductArrayInStor[i].GetDescription().clas;
		description.season = ProductArrayInStor[i].GetDescription().season;
		description.gender = ProductArrayInStor[i].GetDescription().gender;
		description.size = ProductArrayInStor[i].GetDescription().size;
		description.amount = ProductArrayInStor[i].GetDescription().amount;
		description.cost = ProductArrayInStor[i].GetDescription().cost;

		if (Buffer[n].GetTovarName().nameFirm == productName.nameFirm)
		{
		}
		else
		{
			n++;
			Buffer[n].ProductDataEnrty(productName, description);
		}
	}

	for (int i = 0; i < n + 1; i++)
	{
		cout << "[" << i + 1 << "] - " << Buffer[i].GetTovarName().nameFirm << endl; 
	}

	cin >> choice;
	choice--;

	for (int i = 0; i < _amount; i++)
	{
		if (ProductArrayInStor[i].GetTovarName().nameFirm == Buffer[choice].GetTovarName().nameFirm)
		{
			ProductArrayInStor[i].PrintProductData(_userStatus);
		}
	}
}

void SaveProductData(ProductData* (&ProductArrayInStorage), int& _amount, string fileName)
{
	ofstream record(fileName);

	if (record)
	{
		record << _amount << endl;
		for (int i = 0; i < _amount; i++)
		{
			record << ProductArrayInStorage[i].GetTovarName().nameFirm << "  " << ProductArrayInStorage[i].GetTovarName().nameProduct
				<< "  " << ProductArrayInStorage[i].GetDescription().type << "  " << ProductArrayInStorage[i].GetDescription().appointment
				<< "  " << ProductArrayInStorage[i].GetDescription().clas << "  " << ProductArrayInStorage[i].GetDescription().season
				<< "  " << ProductArrayInStorage[i].GetDescription().gender << "  " << ProductArrayInStorage[i].GetDescription().size
				<< "  " << ProductArrayInStorage[i].GetDescription().amount << "  " << ProductArrayInStorage[i].GetDescription().cost;

				if (i < _amount - 1)
				{
					record << endl;
				}
		}
	}record.close();
}

void CopyProductData(ProductData* ProductArrayInStorage_new, ProductData* ProductArrayInStorage_old, int _amount) 
{
	for (int i = 0; i < _amount; i++)
	{
		ProductArrayInStorage_new[i] = ProductArrayInStorage_old[i];
	}
}

void CopySoldProductData(SoldProduct* SoldProductArray_new, SoldProduct* SoldProductArray_old, int _amount)
{
	for (int i = 0; i < _amount; i++)
	{
		SoldProductArray_new[i] = SoldProductArray_old[i];
	}
}

void SortForEmployee(ProductData* ProductArray, int& _amount, int choice)
{
	ProductName productName, productName2;
	Description description, description2;

	if (choice == 1)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;
				if (ProductArray[i].GetDescription().cost < ProductArray[i + 1].GetDescription().cost) {
					ProductArray[i].ProductDataEnrty(productName2, description2);

					ProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
	if (choice == 2)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;
				if (ProductArray[i].GetDescription().cost > ProductArray[i + 1].GetDescription().cost) {
					ProductArray[i].ProductDataEnrty(productName2, description2);

					ProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
	if (choice == 3)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;
				if (ProductArray[i].GetDescription().amount < ProductArray[i + 1].GetDescription().amount) {
					ProductArray[i].ProductDataEnrty(productName2, description2);

					ProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
	if (choice == 4)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;
				if (ProductArray[i].GetDescription().amount > ProductArray[i + 1].GetDescription().amount) {
					ProductArray[i].ProductDataEnrty(productName2, description2);

					ProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
	if (choice == 5)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;

				if (productName.nameFirm.size() < productName2.nameFirm.size() || productName.nameFirm.size() == productName2.nameFirm.size())
				{
					for (int c = 0; c < productName.nameFirm.size(); c++)
					{
						if (productName.nameFirm[c] > productName2.nameFirm[c])
						{
							ProductArray[i].ProductDataEnrty(productName2, description2);

							ProductArray[i + 1].ProductDataEnrty(productName, description);
							goto Next;
						}
						if (productName.nameFirm[c] < productName2.nameFirm[c])
						{
							ProductArray[i].ProductDataEnrty(productName, description);

							ProductArray[i + 1].ProductDataEnrty(productName2, description2);
							goto Next;
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
							ProductArray[i].ProductDataEnrty(productName2, description2);

							ProductArray[i + 1].ProductDataEnrty(productName, description);
							goto Next;
						}
						if (productName.nameFirm[c] < productName2.nameFirm[c])
						{
							ProductArray[i].ProductDataEnrty(productName, description);

							ProductArray[i + 1].ProductDataEnrty(productName2, description2);
							goto Next;
						}
						if (productName.nameFirm[c] == productName2.nameFirm[c])
						{
						}
					}
				}
			Next:;
			}
		}
	}
	if (choice == 6)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;

				if (productName.nameProduct.size() < productName2.nameProduct.size() || productName.nameProduct.size() == productName2.nameProduct.size())
				{
					for (int c = 0; c < productName.nameProduct.size(); c++)
					{
						if (productName.nameProduct[c] > productName2.nameProduct[c])
						{
							ProductArray[i].ProductDataEnrty(productName2, description2);

							ProductArray[i + 1].ProductDataEnrty(productName, description);
							goto Next1;
						}
						if (productName.nameProduct[c] < productName2.nameProduct[c])
						{
							ProductArray[i].ProductDataEnrty(productName, description);

							ProductArray[i + 1].ProductDataEnrty(productName2, description2);
							goto Next1;
						}
						if (productName.nameProduct[c] == productName2.nameProduct[c])
						{
						}
					}
				}
				if (productName.nameProduct.size() > productName2.nameProduct.size())
				{
					for (int c = 0; c < productName2.nameProduct.size(); c++)
					{
						if (productName.nameProduct[c] > productName2.nameProduct[c])
						{
							ProductArray[i].ProductDataEnrty(productName2, description2);

							ProductArray[i + 1].ProductDataEnrty(productName, description);
							goto Next1;
						}
						if (productName.nameProduct[c] < productName2.nameProduct[c])
						{
							ProductArray[i].ProductDataEnrty(productName, description);

							ProductArray[i + 1].ProductDataEnrty(productName2, description2);
							goto Next1;
						}
						if (productName.nameProduct[c] == productName2.nameProduct[c])
						{
						}
					}
				}
			Next1:;
			}
		}
	}
}

void SortSoldProduct(SoldProduct* (&SoldProductArray), int& _amount, int choice)
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

				if (productName.nameProduct.size() < productName2.nameProduct.size() || productName.nameProduct.size() == productName2.nameProduct.size())
				{
					for (int c = 0; c < productName.nameProduct.size(); c++)
					{
						if (productName.nameProduct[c] > productName2.nameProduct[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
							goto Next;
						}
						if (productName.nameProduct[c] < productName2.nameProduct[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName2, description2, soldProductData2);
							goto Next;
						}
						if (productName.nameProduct[c] == productName2.nameProduct[c])
						{
						}
					}
				}
				if (productName.nameProduct.size() > productName2.nameProduct.size())
				{
					for (int c = 0; c < productName2.nameProduct.size(); c++)
					{
						if (productName.nameProduct[c] > productName2.nameProduct[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
							goto Next;
						}
						if (productName.nameProduct[c] < productName2.nameProduct[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName2, description2, soldProductData2);
							goto Next;
						}
						if (productName.nameProduct[c] == productName2.nameProduct[c])
						{
						}
					}
				}
			Next:;
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

				if (productName.nameFirm.size() < productName2.nameFirm.size() || productName.nameFirm.size() == productName2.nameFirm.size())
				{
					for (int c = 0; c < productName.nameFirm.size(); c++)
					{
						if (productName.nameFirm[c] > productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName2, description2, soldProductData2);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName, description, soldProductData);
							goto Next1;
						}
						if (productName.nameFirm[c] < productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName2, description2, soldProductData2);
							goto Next1;
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
							goto Next1;
						}
						if (productName.nameFirm[c] < productName2.nameFirm[c])
						{
							SoldProductArray[i].SoldProductDataEnrty(productName, description, soldProductData);

							SoldProductArray[i + 1].SoldProductDataEnrty(productName2, description2, soldProductData2);
							goto Next1;
						}
						if (productName.nameFirm[c] == productName2.nameFirm[c])
						{
						}
					}
				}
			Next1:;
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

				soldProductData.day = SoldProductArray[i + 1].GetSoldData().day;
				soldProductData.month = SoldProductArray[i + 1].GetSoldData().month;
				soldProductData.year = SoldProductArray[i + 1].GetSoldData().year;
				if (SoldProductArray[i].GetDescription().amount < SoldProductArray[i + 1].GetDescription().amount) {
					SoldProductArray[i].ProductDataEnrty(productName2, description2);

					SoldProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
}

void sortSoldHistory(HistoryOfSold* HistoryOfSoldArray, int& _amount, int choice)
{
	UserData userData, userData2;
	ProductName productName, productName2;
	Description description, description2;
	SoldProductData soldProductData, soldProductData2;

	if (choice == 1)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {

				userData.id = HistoryOfSoldArray[i].GetUserData().id;
				userData.firstName = HistoryOfSoldArray[i].GetUserData().firstName;
				userData.lastName = HistoryOfSoldArray[i].GetUserData().lastName;
				userData.yearOfBirthd = HistoryOfSoldArray[i].GetUserData().yearOfBirthd;
				userData.phoneNumber = HistoryOfSoldArray[i].GetUserData().phoneNumber;

				productName.nameFirm = HistoryOfSoldArray[i].GetTovarName().nameFirm;
				productName.nameProduct = HistoryOfSoldArray[i].GetTovarName().nameProduct;

				description.type = HistoryOfSoldArray[i].GetDescription().type;
				description.appointment = HistoryOfSoldArray[i].GetDescription().appointment;
				description.clas = HistoryOfSoldArray[i].GetDescription().clas;
				description.season = HistoryOfSoldArray[i].GetDescription().season;
				description.gender = HistoryOfSoldArray[i].GetDescription().gender;
				description.size = HistoryOfSoldArray[i].GetDescription().size;
				description.amount = HistoryOfSoldArray[i].GetDescription().amount;
				description.cost = HistoryOfSoldArray[i].GetDescription().cost;

				soldProductData.day = HistoryOfSoldArray[i].GetSoldData().day;
				soldProductData.month = HistoryOfSoldArray[i].GetSoldData().month;
				soldProductData.year = HistoryOfSoldArray[i].GetSoldData().year;

				userData2.id = HistoryOfSoldArray[i + 1].GetUserData().id;
				userData2.firstName = HistoryOfSoldArray[i + 1].GetUserData().firstName;
				userData2.lastName = HistoryOfSoldArray[i + 1].GetUserData().lastName;
				userData2.yearOfBirthd = HistoryOfSoldArray[i + 1].GetUserData().yearOfBirthd;
				userData2.phoneNumber = HistoryOfSoldArray[i + 1].GetUserData().phoneNumber;

				productName2.nameFirm = HistoryOfSoldArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = HistoryOfSoldArray[i + 1].GetTovarName().nameProduct;

				description2.type = HistoryOfSoldArray[i + 1].GetDescription().type;
				description2.appointment = HistoryOfSoldArray[i + 1].GetDescription().appointment;
				description2.clas = HistoryOfSoldArray[i + 1].GetDescription().clas;
				description2.season = HistoryOfSoldArray[i + 1].GetDescription().season;
				description2.gender = HistoryOfSoldArray[i + 1].GetDescription().gender;
				description2.size = HistoryOfSoldArray[i + 1].GetDescription().size;
				description2.amount = HistoryOfSoldArray[i + 1].GetDescription().amount;
				description2.cost = HistoryOfSoldArray[i + 1].GetDescription().cost;

				soldProductData2.day = HistoryOfSoldArray[i + 1].GetSoldData().day;
				soldProductData2.month = HistoryOfSoldArray[i + 1].GetSoldData().month;
				soldProductData2.year = HistoryOfSoldArray[i + 1].GetSoldData().year;

				if (userData.id.size() < userData2.id.size() || userData.id.size() == userData2.id.size())
				{
					for (int c = 0; c < userData.id.size(); c++)
					{
						if (userData.id[c] > userData2.id[c])
						{
							HistoryOfSoldArray[i].HistoryOfSaleEnrty(userData2, productName2, description2, soldProductData2);

							HistoryOfSoldArray[i + 1].HistoryOfSaleEnrty(userData, productName, description, soldProductData);
							goto Next;
						}
						if (userData.id[c] < userData2.id[c])
						{
							HistoryOfSoldArray[i].HistoryOfSaleEnrty(userData, productName, description, soldProductData);

							HistoryOfSoldArray[i + 1].HistoryOfSaleEnrty(userData2, productName2, description2, soldProductData2);
							goto Next;
						}
						if (userData.id[c] == userData2.id[c])
						{
						}
					}
				}
				if (userData.id.size() > userData2.id.size())
				{
					for (int c = 0; c < userData2.id.size(); c++)
					{
						if (userData.id[c] > userData2.id[c])
						{
							HistoryOfSoldArray[i].HistoryOfSaleEnrty(userData2,productName2, description2, soldProductData2);

							HistoryOfSoldArray[i + 1].HistoryOfSaleEnrty(userData, productName, description, soldProductData);
							goto Next;
						}
						if (userData.id[c] < userData2.id[c])
						{
							HistoryOfSoldArray[i].HistoryOfSaleEnrty(userData, productName, description, soldProductData);

							HistoryOfSoldArray[i + 1].HistoryOfSaleEnrty(userData2, productName2, description2, soldProductData2);
							goto Next;
						}
						if (userData.id[c] == userData2.id[c])
						{
						}
					}
				}
			Next:;
			}
		}
	}
}

void SortForClient(ProductData* ProductArray, int& _amount, int choice)
{
	ProductName productName, productName2;
	Description description, description2;

	if (choice == 1)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size;
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;

				if (ProductArray[i].GetDescription().cost < ProductArray[i + 1].GetDescription().cost) {
					ProductArray[i].ProductDataEnrty(productName2, description2);

					ProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
	if (choice == 2)
	{
		for (int j = 0; j < _amount - 1; j++) {
			for (int i = 0; i < _amount - j - 1; i++) {
				productName.nameFirm = ProductArray[i].GetTovarName().nameFirm;
				productName.nameProduct = ProductArray[i].GetTovarName().nameProduct;
				description.type = ProductArray[i].GetDescription().type;
				description.appointment = ProductArray[i].GetDescription().appointment;
				description.clas = ProductArray[i].GetDescription().clas;
				description.season = ProductArray[i].GetDescription().season;
				description.gender = ProductArray[i].GetDescription().gender;
				description.size = ProductArray[i].GetDescription().size;
				description.amount = ProductArray[i].GetDescription().amount;
				description.cost = ProductArray[i].GetDescription().cost;

				productName2.nameFirm = ProductArray[i + 1].GetTovarName().nameFirm;
				productName2.nameProduct = ProductArray[i + 1].GetTovarName().nameProduct;
				description2.type = ProductArray[i + 1].GetDescription().type;
				description2.appointment = ProductArray[i + 1].GetDescription().appointment;
				description2.clas = ProductArray[i + 1].GetDescription().clas;
				description2.season = ProductArray[i + 1].GetDescription().season;
				description2.gender = ProductArray[i + 1].GetDescription().gender;
				description2.size = ProductArray[i + 1].GetDescription().size; 
				description2.amount = ProductArray[i + 1].GetDescription().amount;
				description2.cost = ProductArray[i + 1].GetDescription().cost;

				if (ProductArray[i].GetDescription().cost > ProductArray[i + 1].GetDescription().cost) {
					ProductArray[i].ProductDataEnrty(productName2, description2);

					ProductArray[i + 1].ProductDataEnrty(productName, description);
				}
			}
		}
	}
}

void productDataDelete(ProductData* (&ProductArrayInStor), int& _amount, string _userStatus)
{
	int n, y;
	ProductData* buffer = new ProductData[_amount];
	ProductArrayInStor->Print(ProductArrayInStor, _amount, _userStatus);
	cout << "Введіть номер товару який бажаєте видалити:\t:" << endl;
	cin >> n;
	n--;
	if (n >= 0 && n < _amount)
	{
		CopyProductData(buffer, ProductArrayInStor, _amount);
		int x = 0;
		_amount--;
		
		ProductArrayInStor = new ProductData[_amount];
	   
		for (int i = 0; i <= _amount; i++){
			if (i != n)
			{
				ProductArrayInStor[x] = buffer[i];
				x++; 
			}
			else
			{
				y = i;
			}
	    }
		system("cls");
		cout << setiosflags(ios::left);
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                                                                                                   Видалений товар                                                                                                   " << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |"
			<< setw(24) << "ТИП" << " |" << setw(25) << "ПРИЗНАЧЕННЯ" << " |" << setw(24) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
			<< " |" << setw(22) << "СТАТЬ" << " |" << setw(15) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		buffer[y].PrintProductData(_userStatus);
		cout << "\n\n\n" << endl;

		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                                                                                                Товар який залишився                                                                                                 " << endl;
		ProductArrayInStor->Print(ProductArrayInStor, _amount, _userStatus);
	}
	delete[] buffer;
}

void averageValueByAppointment(SoldProduct* SoldProductArray, int _amount)
{
	ProductName productName;
	Description description;
	SoldProductData soldProductData;
	AvarageData avarageData;
	avarageOfSoldByAppointment* buffer = new avarageOfSoldByAppointment[12];

	struct tm Year;
	time_t now;
	now = time(NULL);
	Year = *localtime(&now);
	int currentYear = Year.tm_year + 1900;

	
	for (int i = 0; i < _amount; i++)
	{
		avarageData.Casual = 0;
		avarageData.Ski = 0;
		avarageData.Run = 0;
		avarageData.Box = 0;

		if (SoldProductArray[i].GetSoldData().year == currentYear)
		{

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 1)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 1;
				buffer[0].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 2)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 2;
				buffer[1].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 3)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 3;
				buffer[2].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 4)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 4;
				buffer[3].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 5)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 5;
				buffer[4].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 6)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 6;
				buffer[5].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 7)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 7;
				buffer[6].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 8)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 8;
				buffer[7].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 9)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 9;
				buffer[8].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 10)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 10;
				buffer[9].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 11)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 11;
				buffer[10].avarageOfSoldByAppEntry(avarageData);

				avarageData.Casual = 0;
				avarageData.Ski = 0;
				avarageData.Run = 0;
				avarageData.Box = 0;

				for (int i = 0; i < _amount; i++)
				{
					if (SoldProductArray[i].GetSoldData().month == 12)
					{
						if (SoldProductArray[i].GetDescription().appointment == "Повсякденний")
						{
							avarageData.Casual++;
						}if (SoldProductArray[i].GetDescription().appointment == "Гірськолижний")
						{
							avarageData.Ski++;
						}if (SoldProductArray[i].GetDescription().appointment == "Біговий")
						{
							avarageData.Run++;
						}if (SoldProductArray[i].GetDescription().appointment == "Боксерський")
						{
							avarageData.Box++;
						}
					}
				}
				avarageData.month = 12;
				buffer[11].avarageOfSoldByAppEntry(avarageData);
		}
	}
	buffer->printAvarageOfSold(buffer, 12);
}

void bestSellingProduct(SoldProduct* SoldProductArray, int& _amount)
{
	ProductName productName;
	Description description;
	SoldProductData soldProductData;
	SoldProduct* buffer = new SoldProduct[_amount];

	SortSoldProduct(SoldProductArray, _amount,1);
	SortSoldProduct(SoldProductArray, _amount, 2);

	productName.nameFirm = SoldProductArray[0].GetTovarName().nameFirm;
	productName.nameProduct = SoldProductArray[0].GetTovarName().nameProduct;

	description.type = SoldProductArray[0].GetDescription().type;
	description.appointment = SoldProductArray[0].GetDescription().appointment;
	description.clas = SoldProductArray[0].GetDescription().clas;
	description.season = SoldProductArray[0].GetDescription().season;
	description.gender = SoldProductArray[0].GetDescription().gender;
	description.size = SoldProductArray[0].GetDescription().size;
	description.amount = SoldProductArray[0].GetDescription().amount;
	description.cost = SoldProductArray[0].GetDescription().cost;

	soldProductData.day = SoldProductArray[0].GetSoldData().day;
	soldProductData.month = SoldProductArray[0].GetSoldData().month;
	soldProductData.year = SoldProductArray[0].GetSoldData().year;

	buffer[0].SoldProductDataEnrty(productName, description, soldProductData);
	int n = 0;
	for (int i = 1; i < _amount; i++)
	{
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

		if(buffer[n].GetSoldData().month == soldProductData.month && buffer[n].GetTovarName().nameFirm == productName.nameFirm && buffer[n].GetTovarName().nameProduct == productName.nameProduct)
		{
			description.amount = description.amount + buffer[n].GetDescription().amount;
			buffer[n].SoldProductDataEnrty(productName, description, soldProductData);
		}
		else
		{
			n++;
			buffer[n].SoldProductDataEnrty(productName, description, soldProductData); 
		}
	}
	SortSoldProduct(buffer, n, 3);

	buffer->bestSellingProductPrint(buffer, _amount, 5);
}

void smallAmountOfProduct(ProductData* ProductArrayInStorage, int _amount, string _userStatus)
{
	int n = 0;

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|    |                     |                          |                         |                          |                         |                        |                       |                |           |                |" << endl;

	cout << "|" << setw(3) << "№" << " |" << setw(20) << "НАЗВА ФІРМИ" << " |" << setw(25) << "НАЗВА ТОВАРУ" << " |"
		<< setw(24) << "ТИП" << " |" << setw(25) << "ПРИЗНАЧЕННЯ" << " |" << setw(24) << "КЛАС" << " |" << setw(23) << "СЕЗОН"
		<< " |" << setw(22) << "СТАТЬ" << " |" << setw(15) << "РОЗМІР" << " |" << setw(10) << "КІЛЬКІСТЬ" << " |" << setw(15) << "ЦІНА" << " |" << endl;

	cout << "|    |                     |                          |                         |                          |                         |                        |                       |                |           |                |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < _amount; i++)
	{
		if(ProductArrayInStorage[i].GetDescription().amount < 15)
		{
			n++;
			cout << setiosflags(ios::right);
			cout << "|" << setw(3) << n;
			ProductArrayInStorage[i].PrintProductData(_userStatus);
		}
	}
}

void historyOfSold(HistoryOfSold* HistoryOfSoldArray, int _amount)
{
	UserData userData;

	sortSoldHistory(HistoryOfSoldArray, _amount, 1);
	cout << setiosflags(ios::left);
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                                                                                Історія покупок                                                                                                                    |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(8) << "ID" << "  |" << setw(11) << "Ім'я" << "  |" << setw(11) << "Прізвище" << "  |" << setw(8) << "Рік" << "  |" << setw(12) << "Номер" << "  |" << setw(3) << "  №" << " |" << setw(15) << "НАЗВА ФІРМИ" << " |" << setw(15) << "НАЗВА ТОВАРУ" << " |"
		 << setw(15) << "ТИП" << " |" << setw(15) << "ПРИЗНАЧЕННЯ" << " |" << setw(17) << "КЛАС" << " |" << setw(12) << "СЕЗОН"
		 << " |" << setw(10) << "СТАТЬ" << " |" << setw(7) << "РОЗМІР" << " |" << setw(9) << "КІЛЬКІСТЬ" << " |" << setw(9) << "ЦІНА" << " |" << setw(5) << "Дата" << "  " << setw(7) << "      |" << endl;
	cout << "|          |             |             |народження|телефону      |    |                |                |                |                |                  |             |           |        |          |          |             |" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                                                                                                                                   |" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

	int n = 1;
	cout << setiosflags(ios::right);
	cout << "|          |             |             |          |              |    |                |                |                |                |                  |             |           |        |          |          |             |" << endl;
	cout << "| " << setw(8) << HistoryOfSoldArray[0].GetUserData().id << " |" << setw(11) << HistoryOfSoldArray[0].GetUserData().firstName << "  |" << setw(11) << HistoryOfSoldArray[0].GetUserData().lastName << "  |" << setw(8) << HistoryOfSoldArray[0].GetUserData().yearOfBirthd << "  |" << setw(12) << HistoryOfSoldArray[0].GetUserData().phoneNumber << "  |";
	cout << setw(3) << n;
	HistoryOfSoldArray[0].PrintHistoryForEmployee();
	
	for (int i = 0; i < _amount-1; i++)
	{
		if (HistoryOfSoldArray[i].GetUserData().id == HistoryOfSoldArray[i+1].GetUserData().id)
		{
			n++;
			cout << setiosflags(ios::right);
			cout << "|          |             |             |          |              |----|----------------|----------------|----------------|----------------|------------------|-------------|-----------|--------|----------|----------|-------------|" << endl;

			cout << "|          |             |             |          |              |" << setw(3) << n;
			HistoryOfSoldArray[i + 1].PrintHistoryForEmployee();
		} 
		else
		{
			n = 1;
			cout << setiosflags(ios::right);
			cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "|                                                                                                                                                                                                                                   |" << endl;
			cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| " << setw(8) << HistoryOfSoldArray[i + 1].GetUserData().id << " |" << setw(11) << HistoryOfSoldArray[i + 1].GetUserData().firstName << "  |" << setw(11) << HistoryOfSoldArray[i + 1].GetUserData().lastName << "  |" << setw(8) << HistoryOfSoldArray[i + 1].GetUserData().yearOfBirthd << "  |" << setw(12) << HistoryOfSoldArray[i + 1].GetUserData().phoneNumber << "  |";
			cout << setw(3) << n;
			HistoryOfSoldArray[i + 1].PrintHistoryForEmployee();
		}
	}
	cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                                                                                                                                   |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}

