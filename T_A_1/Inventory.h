#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include <map>

#include "Item.h"

extern std::vector<Item> inventory;

extern int inventoryMaximum;

void getitem(Item& item);

void checkInventory();

std::map<std::string, int> getUsableItems();

#endif