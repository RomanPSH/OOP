#include "Functions.h"

int EnterMenuChoice, AdminChoice;
int x;


void EnterMenu() 
{
	cout << "                                                                                         [1] - Ввійти в базу як клієнт" << endl;
	cout << "                                                                                         [2] - Ввійти в базу як працівник" << endl;
	cout << "                                                                                         [3] - Ввійти без авторизації" << endl;
	cout << "                                                                                         [0] - Вихід" << endl;
	cout << "\n                                                                                         Вибір: "; 
	cin >> EnterMenuChoice;
}

void MenuForAdmin()
{

	cout << "                                                                                      [1]  -  Пошук товару" << endl;
	cout << "                                                                                      [2]  -  Додавання товару" << endl;
	cout << "                                                                                      [3]  -  Зміна даних про товар" << endl;
	cout << "                                                                                      [4]  -  Видалення даних про товар" << endl;
	cout << "                                                                                      [5]  -  Cереднє число продажів товару (за призначенням) на місяць" << endl;
	cout << "                                                                                      [6]  -  Список товару" << endl;
	cout << "                                                                                      [7]  -  Список проданого товару" << endl;
	cout << "                                                                                      [8]  -  Список працівників магазину" << endl;
	cout << "                                                                                      [9]  -  Відгуки про роботу магазину" << endl;
	cout << "                                                                                      [10] -  Перелік найбільш продаваного товару" << endl;
	cout << "                                                                                      [11] -  Список товару який варто замовити" << endl;
	cout << "                                                                                      [12] -  Історія покупок клієнтів" << endl;
	cout << "                                                                                      [13] -  Касовий звіт" << endl;
	cout << "                                                                                      [14] -  Список зареєстрованих клієнтів" << endl;
	cout << "                                                                                      [0]  -  Вийти" << endl;
	cout << "\n                                                                                      Вибір: ";
	cin >> AdminChoice;
}

void returnToAdminMenu() 
{
	system("pause");
	system("cls");
	MenuForAdmin();
}

int main()
{
	int clientSize, ProductInStorSize, SoldProductSize, ProductInStorageSize, employeeSize, historyOfSoldSize;
	clientSize = ProductInStorSize = SoldProductSize = ProductInStorageSize = employeeSize = historyOfSoldSize = 0;
	
	User* ClientArray = new User[clientSize];
	Employee* EmployeeArray = new Employee[employeeSize];
	ProductData* ProductArrayInStorage = new ProductData[ProductInStorageSize];
	ProductData* ProductArrayInStor = new ProductData[ProductInStorSize];
	SoldProduct* SoldProductArray = new SoldProduct[SoldProductSize];
	HistoryOfSold* HistoryOfSoldArray = new HistoryOfSold[historyOfSoldSize];

	ClientArray->ClientDataReading(ClientArray, clientSize, "Client.txt");
	EmployeeArray->EmployeeDataReading(EmployeeArray, employeeSize, "Employee.txt");
	ProductArrayInStorage->ProductDataInStorageReading(ProductArrayInStorage, ProductInStorageSize, "TovarDataStorage.txt");
	ProductArrayInStor->ProductDataInStorReading(ProductArrayInStor, ProductInStorSize, "TovarDataStor.txt");
	SoldProductArray->SoldProductReading(SoldProductArray, SoldProductSize, "SalledTovar.txt");
	HistoryOfSoldArray->HistoryReading(HistoryOfSoldArray, historyOfSoldSize, "HistoryOfSalle.txt");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string password, user_id, userStatus;

	EnterMenu();
	
	
	if (EnterMenuChoice == 1)
	{
		system("cls");
		auto x = ClientArray->ClientInitialization(ClientArray, clientSize);
		userStatus = x.first;
		if (userStatus == "Client")
		{
			user_id = x.second;
			MenuForClient(ProductArrayInStor, ProductInStorSize, user_id, userStatus);
		}
	}
	if (EnterMenuChoice == 2)
	{
		system("cls");
		auto x = EmployeeArray->EmployeeInitialization(EmployeeArray, employeeSize);
		userStatus = x.first;
		if (userStatus == "Administrator")
		{
			user_id = x.second;
			system("cls");
			MenuForAdmin();
			while (EnterMenuChoice != 0)
	        {
	    	switch (AdminChoice)
	        	{
	        	case 1:
		    	system("cls");
	    		searchMenu(ProductArrayInStor, ProductInStorSize, userStatus);
		    	system("cls");
	        		break;
	        	case 2:
	       		system("cls");
	     		ProductDataAdd(ProductArrayInStorage, ProductInStorageSize);
				returnToAdminMenu();
		        	break;
         		case 3:
	       		system("cls");
				ProductDataChange(ProductArrayInStor, ProductInStorSize);
				returnToAdminMenu();
		        	break;
		        case 4:
			    system("cls");
				productDataDelete(ProductArrayInStor, ProductInStorSize, userStatus);
				returnToAdminMenu();
			       break;
		        case 5:
			    system("cls");
				averageValueByAppointment(SoldProductArray, SoldProductSize); 
				returnToAdminMenu();
			       break;
		        case 6:
			    system("cls");
				int printForEmployee;
				cout << "                                                                                  [1] - Кількість товару на полицях магазину" << endl;
				cout << "                                                                                  [2] - Кількість товару на складі" << endl;
				cin >> printForEmployee;
				int n;

				if (printForEmployee == 1)
				{
					TryAgain1:
					system("cls");
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "[1] - Сортувати за ціною(спочатку дорогі)  |  [2] - Сортувати за ціною(спочатку дешеві)  |  [3] - Сортувати за кількістю(max -> min)  |  [4] - Сортувати за кількістю(min -> max)  |  [5] - Сортувати за алфавітом  |  [0] - Назад" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					
					cout << "\n\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "|                                                                                                             Товар в магазині                                                                                                      |" << endl;

					ProductArrayInStor->Print(ProductArrayInStor, ProductInStorSize, userStatus);
					cin >> n;
					if (n == 0)
					{
						system("cls");
						MenuForAdmin();
					}
					if (n > 0 && n < 6 )
					{
						SortForEmployee(ProductArrayInStor, ProductInStorSize, n);
						goto TryAgain1;
					}
				}
				if (printForEmployee == 2)
				{
					TryAgain2:
					system("cls");
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "[1] - Сортувати за ціною(спочатку дорогі)  |  [2] - Сортувати за ціною(спочатку дешеві)  |  [3] - Сортувати за кількістю(max -> min)  |  [4] - Сортувати за кількістю(min -> max)  |  [5] - Сортувати за алфавітом  |  [0] - Назад" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

					cout << "\n\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "|                                                                                                              Товар на складі                                                                                                      |" << endl;

					ProductArrayInStorage->Print(ProductArrayInStorage, ProductInStorageSize, userStatus);
					cin >> n;
					if (n == 0)
					{
						system("cls");
						MenuForAdmin();
					}
					if (n > 0 && n < 6)
					{
						SortForEmployee(ProductArrayInStorage, ProductInStorageSize, n);
						goto TryAgain2;
					}
					
				}
			       break;
		        case 7:
	       		system("cls");
				SoldProductArray->SoldProductDataPrint(SoldProductArray, SoldProductSize);
				system("cls");
				MenuForAdmin();
	        		break;
        		case 8:
	        	system("cls");
				EmployeeArray->PrintEmployeeData(EmployeeArray, employeeSize);
				returnToAdminMenu();
	        		break;
				case 9:
					system("cls");
					bestSellingProduct(SoldProductArray, SoldProductSize);
					system("cls");
					MenuForAdmin();
					break;
				case 10:
					system("cls");
					bestSellingProduct(SoldProductArray, SoldProductSize);
					system("cls");
					MenuForAdmin();
					break;
				case 11:
					system("cls");
					smallAmountOfProduct(ProductArrayInStorage, ProductInStorageSize, userStatus);
					returnToAdminMenu();
					break;
				case 12:
					system("cls");
					historyOfSold(HistoryOfSoldArray, historyOfSoldSize);
					returnToAdminMenu();
					break;
				case 13:
					system("cls");
					bestSellingProduct(SoldProductArray, SoldProductSize);
					system("cls");
					MenuForAdmin();
					break;
				case 14:
					system("cls");
					bestSellingProduct(SoldProductArray, SoldProductSize);
					system("cls");
					MenuForAdmin();
					break;
        		case 0:
 	       		system("cls");
        			break;
        		default:
	         	system("cls");
	     		cout << "Такого пункту меню не існує! Спробуйте ще раз)" << endl;
	    		cout << "Натисніть будь-яку клавішу для продовження >>>\n" << endl;
				returnToAdminMenu();
	        		break;
	        	}
	        }
		}
	}
	if (EnterMenuChoice == 3)
	{
		system("cls");
		GuestMenu(ProductArrayInStor, ProductInStorSize);
	}	
}