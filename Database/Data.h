#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

struct UserData
{
	string id,
		   phoneNumber,
		   firstName,
		   lastName,
		   login,
		   password,
		   status;

	int yearOfBirthd;
};

struct EmployeeData
{
	string department,
		workingDays;
};

class User
{
public:

	User();
	User(UserData userData_);
	~User();
	
	pair<string, string> ClientInitialization(User* (&ClientArray), int& _amount);
	void PrintUserData(User* (&ClientArray), int& _amount);
	void UserDataEnrty(UserData userData_);
    void ClientDataReading(User* (&ClientArray), int& _amount, string fileName);

	User& operator = (User UserArray);
	UserData GetUserData() { return userData; };
protected:
	UserData userData;
};

class Employee : protected User
{
public:

	
	Employee();
	Employee(UserData userData_, EmployeeData  employeeData_);
	~Employee();
	
	pair<string, string> EmployeeInitialization(Employee* (&EmployeeArray), int& _amount);
	
	void EmployeeDataReading(Employee* (&EmployeeArray), int& _amount, string fileName);
	void EmployeeDataEnrty(UserData userData_, EmployeeData  employeeData_);
	void PrintEmployeeData(Employee* (&EmployeeArray), int& _amount);

	EmployeeData GetEmployeeData() { return employeeData; }
protected:
	EmployeeData employeeData;
};





struct ProductName // назва товару(назва виробника, назва позиції)
{
	string nameProduct,
		nameFirm;
};

struct Description // опис товару(тип, сезон, стать, кількість, ціна(грн)) 
{
	string 
		type,
		appointment, 
		clas,
		season,
		gender,
		size;
	int amount,
		cost;
};


class ProductData
{
public:
	ProductData();
	ProductData(ProductName productName_, Description description_);
	~ProductData();

	void PrintProductData(string _userStatus);
	void ProductDataEnrty(ProductName productName_, Description description_);
	void ProductDataInStorageReading(ProductData* (&ProductArrayInStorage), int& _amount, string fileName);
	void ProductDataInStorReading(ProductData* (&ProductArrayInStor), int& _amount, string fileName);
	
	void Print(ProductData* (&ProductArray), int& _amount, string _userStatus);
	void PrintProductForClient(ProductData* (&ProductArray), int& _amount, string _userStatus);

	ProductData& operator = (ProductData ProductArrayInStorage_old);
	ProductName GetTovarName() { return productName; };
	Description GetDescription() { return description; };
protected:
	ProductName productName;
	Description description;
};

struct SoldProductData
{
	int year, month, day;
};

class SoldProduct : public ProductData
{
public:
	SoldProduct();
	SoldProduct(ProductName productName_, Description description_, SoldProductData soldProductData_);
    ~SoldProduct();

	void SoldProductDataEnrty(ProductName productName_, Description description_, SoldProductData soldProductData_);
	void SoldProductReading(SoldProduct* (&SoldProductArray), int& _amount, string fileName);
	void SoldProductDataPrint(SoldProduct* (&SoldProductArray), int& _amount);
	void SoldPrint();
	void SoldProductPrint(SoldProduct* (&SoldProductArray), int& _amount);
	void SortSoldProduct(SoldProduct* SoldProductArray, int& _amount, int choice);
	void bestSellingProductPrint(SoldProduct* SoldProductArray, int& _amount, int amountPrint);
	SoldProductData GetSoldData() { return soldProductData; };
	SoldProduct& operator=(SoldProduct SoldProductArray_old);

protected:
	SoldProductData soldProductData;
};

class HistoryOfSold : public User, public SoldProduct
{
public:
	HistoryOfSold();
	HistoryOfSold(UserData userData_, ProductName productName_, Description description_, SoldProductData SoldProductData_);
	~HistoryOfSold();
	
	void HistoryOfSaleEnrty(UserData userData_, ProductName productName_, Description description_, SoldProductData SoldProductData_);
	void HistoryReading(HistoryOfSold* (&HistoryOfSoldArray), int& _amount, string fileName);
	void PrintHistoryData(HistoryOfSold* (&HistoryOfSoldArray), int& _amount, string _user);
	void PrintHistory();
	void PrintHistoryForEmployee();
private:

};

class Departament
{
public:
	Departament();
	~Departament();

private:
	int Casual,	ski, forRunning;
};

struct AvarageData
{
	int Casual,
		   Ski,
		   Run,
		   Box;

	int month;
};

class avarageOfSoldByAppointment
{
public:
	avarageOfSoldByAppointment();
	avarageOfSoldByAppointment(AvarageData avarageData_);
	~avarageOfSoldByAppointment();

	void avarageOfSoldByAppEntry(AvarageData avarageData_);
	void printAvarageOfSold(avarageOfSoldByAppointment* AvarageOfSoldArray, int _amount);
	void printAvarage();
	AvarageData GetAvarageData() { return avarageData; };
private:
	AvarageData avarageData;
};
