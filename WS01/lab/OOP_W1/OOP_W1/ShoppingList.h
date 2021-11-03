#pragma once
#ifndef SDDS_SHOPPINGLIST_H // replace with relevant names
#define SDDS_SHOPPINGLIST_H
namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif