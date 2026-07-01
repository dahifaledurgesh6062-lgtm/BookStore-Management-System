#include<iostream>
using namespace std;

class BookStore {
public:
    string name;
    string type;
    float price;
    int quantity;
} mybook[100];

int size;
int sp = -1;

void BookTypes() {
    cout << "\nAvailable Book Types:\n";
    cout << "1. Story\n";
    cout << "2. Love\n";
    cout << "3. Educational\n";
    cout << "Enter your choice for book type (1/2/3): ";
}

void push() {
    if (sp + 1 >= size) {
        cout << "Book Store is full, cannot add more books.\n";
        cout << "*************************************************\n";
        return;
    }
    sp++;
    BookTypes();
    int bookTypeChoice;
    cin >> bookTypeChoice;
    switch (bookTypeChoice) {
        case 1: mybook[sp].type = "Story"; break;
        case 2: mybook[sp].type = "Love"; break;
        case 3: mybook[sp].type = "Educational"; break;
        default:
            cout << "Enter correct choice\n";
            sp--;
            return;
    }
    cout << "Enter book name: ";
    cin >> mybook[sp].name;
    cout << "Enter book price: ";
    cin >> mybook[sp].price;
    cout << "Enter book quantity: ";
    cin >> mybook[sp].quantity;
    cout << "Book added successfully.\n";
    cout << "*************************************************\n";
}

void pop() {
    if (sp == -1) {
        cout << "Book Store is empty, cannot purchase any book.\n";
        cout << "*************************************************\n";
        return;
    }
    string bookName;
    cout << "Enter the name of the book you want to purchase: ";
    cin >> bookName;
    for (int i = 0; i <= sp; i++) {
        if (mybook[i].name == bookName) {
            cout << "Book Found: " << mybook[i].name << " (Available Quantity: " << mybook[i].quantity << ")\n";
            int qty;
            cout << "Enter quantity to purchase: ";
            cin >> qty;
            if (qty <= 0) {
                cout << "Invalid quantity entered.\n";
                return;
            }
            if (qty > mybook[i].quantity) {
                cout << "Only " << mybook[i].quantity << " copies are available.\n";
                return;
            }
            mybook[i].quantity -= qty;
            float total = qty * mybook[i].price;
            cout << "Purchase successful! Total price: " << total << "\n";
            if (mybook[i].quantity == 0) {
                for (int j = i; j < sp; j++) {
                    mybook[j] = mybook[j + 1];
                }
                sp--;
                cout << "Book " << bookName << " is now out of stock and removed from the store.\n";
            }
            cout << "*************************************************\n";
            return;
        }
    }
    cout << "Book not found in the store.\n";
    cout << "*************************************************\n";
}

void display() {
    if (sp == -1) {
        cout << "Book Store is empty\n";
        cout << "*************************************************\n";
        return;
    }
    for (int i = sp; i >= 0; i--) {
        cout << "\n*************************************************\n";
        cout << "Book " << i + 1 << ":\n";
        cout << "Name: " << mybook[i].name << "\n";
        cout << "Price: " << mybook[i].price << "\n";
        cout << "Quantity: " << mybook[i].quantity << "\n";
        cout << "Type: " << mybook[i].type << "\n";
        cout << "-----------------------------\n";
    }
}

void sortStack() {
    if (sp == -1) {
        cout << "Book Store is empty, nothing to sort.\n";
        cout << "*************************************************\n";
        return;
    }
    for (int i = 0; i <= sp; i++) {
        for (int j = 0; j < sp - i; j++) {
            if (mybook[j].name > mybook[j + 1].name) {
                swap(mybook[j], mybook[j + 1]);
            }
        }
    }
    cout << "Sorted Book Store by name:\n";
    for (int i = sp; i >= 0; i--) {
        cout << "Name: " << mybook[i].name << "\n";
        cout << "Price: " << mybook[i].price << "\n";
        cout << "Quantity: " << mybook[i].quantity << "\n";
        cout << "Type: " << mybook[i].type << "\n";
        cout << "-----------------------------\n";
    }
    cout << "*************************************************\n";
}

void updateBook() {
    string bookName;
    cout << "\n*************************************************\n";
    cout << "Enter the name of the book to update: ";
    cin >> bookName;
    for (int i = 0; i <= sp; i++) {
        if (mybook[i].name == bookName) {
            cout << "Book found. Enter new details:\n";
            cout << "New Name: ";
            cin >> mybook[i].name;
            cout << "New Price: ";
            cin >> mybook[i].price;
            cout << "New Quantity: ";
            cin >> mybook[i].quantity;
            BookTypes();
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: mybook[i].type = "Story"; break;
                case 2: mybook[i].type = "Love"; break;
                case 3: mybook[i].type = "Educational"; break;
                default: cout << "Invalid type\n"; break;
            }
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchBook() {
    BookStore check_book;
    cout << "Enter the name want to search: ";
    cin >> check_book.name;
    for (int i = 0; i <= sp; i++) {
        if (mybook[i].name == check_book.name) {
            cout << "Book Found:\n";
            cout << "Name: " << mybook[i].name << "\n";
            cout << "Price: " << mybook[i].price << "\n";
            cout << "Quantity: " << mybook[i].quantity << "\n";
            cout << "Type: " << mybook[i].type << "\n";
            cout << "-----------------------------\n";
            return;
        }
    }
    cout << "Book not found in the store.\n";
    cout << "-----------------------------\n";
}

void countBooks() {
    cout << "\nTotal number of books in the store: " << sp + 1 << "\n";
    cout << "*************************************************\n";
}

void calculation() {
    float Price = 0;
    for (int i = 0; i <= sp; i++) {
        Price += mybook[i].price * mybook[i].quantity;
    }
    cout << "Total price of all books in store: " << Price << "\n";
}

int main() {
    cout << "Enter maximum size of Book Store: ";
    cin >> size;
    int ch;
    while (true) {
        cout << "\n===== Book Store Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Purchase Book\n";
        cout << "3. Sort Book\n";
        cout << "4. Display Book\n";
        cout << "5. Update Book\n";
        cout << "6. Search Book\n";
        cout << "7. Count Books\n";
        cout << "8. Total Amount of Books\n";
        cout << "Your choice is: ";
        cin >> ch;
        switch (ch) {
             case 1: 
             push(); 
             break;
             case 2: 
             pop(); 
             break;
             case 3:  
             sortStack(); 
             break;
             case 4: 
             display(); 
             break;
             case 5: 
             updateBook(); 
             break;
             case 6: 
             searchBook(); 
             break;
             case 7: 
             countBooks(); 
             break;
             case 8: 
             calculation(); 
             break;
             default: cout << "Enter correct choice\n"; break;
        }
    }
}

