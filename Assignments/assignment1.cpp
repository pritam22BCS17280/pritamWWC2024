#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Item {
public:
    int id;
    string name;
    int quantity;
    int reorderLevel;

    Item(int id, string name, int quantity, int reorderLevel)
        : id(id), name(name), quantity(quantity), reorderLevel(reorderLevel) {}
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(int id, string name, int quantity, int reorderLevel) {
        items.emplace_back(id, name, quantity, reorderLevel);
        cout << "Item added.\n";
    }

    void updateStock(int id, int quantity) {
        for (auto& item : items) {
            if (item.id == id) {
                item.quantity += quantity;
                cout << "Stock updated.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void viewInventory() {
        cout << "Inventory:\n";
        for (const auto& item : items) {
            cout << "ID: " << item.id << ", Name: " << item.name 
                 << ", Quantity: " << item.quantity 
                 << ", Reorder Level: " << item.reorderLevel << endl;
            if (item.quantity < item.reorderLevel) {
                cout << "ALERT: Low stock for " << item.name << "!\n";
            }
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n1. Add Item\n2. Update Stock\n3. View Inventory\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity, reorderLevel;
                string name;
                cout << "Enter Item ID, Name, Quantity, Reorder Level: ";
                cin >> id >> name >> quantity >> reorderLevel;
                inventory.addItem(id, name, quantity, reorderLevel);
                break;
            }
            case 2: {
                int id, quantity;
                cout << "Enter Item ID and quantity to add: ";
                cin >> id >> quantity;
                inventory.updateStock(id, quantity);
                break;
            }
            case 3:
                inventory.viewInventory();
                break;
            case 4:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}




/*   OUTPUT:

1. Add Item
2. Update Stock
3. View Inventory
4. Exit

Enter your choice: 1
Enter Item ID, Name, Quantity, Reorder Level:
12345
BAT
60
2
Item added.

1. Add Item
2. Update Stock
3. View Inventory
4. Exit

Enter your choice: 3
Inventory:
ID: 12345, Name: BAT, Quantity: 60, Reorder Level: 2

1. Add Item
2. Update Stock
3. View Inventory
4. Exit

Enter your choice: 4
Exiting.




**************************************PROCEDURE*******************************************************************

Class InventoryItem:

Represents an inventory item with properties like ID, name, category, quantity, and reorder level.
Has a display method to print item details.
Class InventoryManagementSystem:

Manages the inventory using a vector of InventoryItem objects.
Key methods:
addItem: Adds a new item to the inventory.
updateStock: Updates the stock quantity of an existing item.
viewInventory: Displays all items and alerts for low stock.
searchItem: Searches for an item by name.
exportInventory: Saves inventory data to a file.
menu Method:

Displays a menu with options to:
Add Item
Update Stock
View Inventory
Search Item
Export Inventory
Exit
Executes the selected operation in a loop until "Exit" is chosen.
Main Function:

Creates an instance of InventoryManagementSystem.
Starts the application by calling the menu.
*/














