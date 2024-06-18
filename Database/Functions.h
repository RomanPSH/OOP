
#include "Data.h"

void MenuForAdmin();

void MenuForAdmin();

void GuestMenu(ProductData* ProductArrayInStor, int _amount);

void searchByWroteName(ProductData* ProductArrayInStor, int _amount, string _userStatus);

void ProductDataAdd(ProductData* (&ProductArray), int& _amount);

void searchByProductName(ProductData* ProductArrayInStor, int _amount, string _userStatus);

void searchByNameFirm(ProductData* ProductArrayInStor, int _amount, string _userStatus);

void searchMenu(ProductData* ProductArrayInStor, int _amount, string _userStatus);

void MenuForClient(ProductData* ProductArrayInStor, int _amount, string _user, string _userStatus);

void SaveProductData(ProductData* (&ProductArrayInStorage), int& _amount, string fileName);

void CopyProductData(ProductData* ProductArrayInStorage_new, ProductData* ProductArrayInStorage_old, int _amount);

void ProductDataChange(ProductData* (&ProductArrayInStorage), int& _amount);

void SortForEmployee(ProductData* ProductArray, int& _amount, int choice);

void SortForClient(ProductData* ProductArray, int& _amount, int choice);

void sortSoldHistory(HistoryOfSold* HistoryOfSoldArray, int& _amount, int choice);

void SortSoldProduct(SoldProduct* (&SoldProductArray), int& _amount, int choice);

void productDataDelete(ProductData* (&productArray), int& _amount, string _userStatus);

void averageValueByAppointment(SoldProduct* SoldProductArray, int _amount);

void bestSellingProduct(SoldProduct* SoldProductArray, int& _amount);

void smallAmountOfProduct(ProductData* ProductArrayInStorage, int _amount, string _userStatus);

void historyOfSold(HistoryOfSold* HistoryOfSoldArray, int _amount);