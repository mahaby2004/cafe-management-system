#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

// Global Variable
float amount = 0; // To calculate the total amount.
int totalItems = 0; // Total Items Added to Order
string username; // User's username

// Structure to store the ordered items & generate bill
struct Items
{
    int id;
    char item[20];
    int qty;
    float rate;
    float amt;
} I[20];

// Function Prototyping
void drawLine(); // Function to draw lines for presentation
void Header(); // Display Heading in Invoice
void menu(); // Displaying Menu of Items
void showBill(); // Displaying Invoice
void registerUser(); // Function to register a new user
bool login(); // Function to login

void drawLine()
{
    for (int i = 1; i < 70; i++)
        cout << "=";
    cout << endl;
}

void Header()
{
    cout << setw(10) << "I.D."
        << setw(20) << "Item Name"
        << setw(10) << "Qty."
        << setw(10) << "Rate"
        << setw(10) << "Amount"
        << endl;
}

void showBill()
{
    system("cls");
    drawLine();
    cout << "\t\t\tITEMIZED INVOICE\n";
    drawLine();
    Header();
    drawLine();
    for (int i = 0; i < totalItems; i++)
    {
        cout << setw(10) << I[i].id
            << setw(20) << I[i].item
            << setw(10) << I[i].qty
            << setw(10) << I[i].rate
            << setw(10) << I[i].amt
            << endl;
    }
    cout << endl;
    cout << setw(50) << "Total Amount : "
        << setw(10) << amount << endl;
    drawLine();
}

void menu()
{
    drawLine();
    cout << "\t\t\t\tMenu\n";
    drawLine();
    cout << "Items Available" << setw(50) << "Rate\n";
    drawLine();
    cout << "| 1.| Pasta" << setw(60) << "|50.00  | \n";
    cout << "| 2.| Sandwich" << setw(56) << "|30.00  |\n";
    cout << "| 3.| Coffee" << setw(58) << "|20.00  |\n";
    cout << "| 4.| Bun" << setw(61) << "|100.00 |\n";
    cout << "| 5.| Juice" << setw(59) << "|200.00 |\n";
    drawLine();
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

bool login()
{
    string password;

    ifstream file("users.txt");
    if (!file.is_open()) {
        cerr << "Failed to open users file." << endl;
        return false;
    }

    bool authenticated = false;
    string fileUsername, filePassword;

    cout << "Enter your Username: ";
    cin >> username;

    cout << "\n\nEnter your Password: ";
    cin >> password;

    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            authenticated = true;
            break;
        }
    }

    file.close();

    if (authenticated) {
        system("cls");
        cout << "Login successful!" << endl;
        return true;
    }
    else {
        cout << "Invalid Username or Password!" << endl;
        return false;
    }
}

void registerUser()
{
    string newUsername, newPassword;

    cout << "Enter a new username: ";
    cin >> newUsername;
    cout << "Enter a new password: ";
    cin >> newPassword;

    // Open the file in append mode
    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open users file." << endl;
        return;
    }

    // Write the new username and password to the file
    file << newUsername << " " << newPassword << endl;

    // Close the file
    file.close();

    cout << "Registration successful." << endl;
}

int main()
{
    system("color 70");
    cout << "              _______________________" << endl;
    cout << "             / \\                    / \\" << endl;
    cout << "            /   \\                  /   \\" << endl;
    cout << "           /     \\                /     \\" << endl;
    cout << "          /       \\   __________ /       \\" << endl;
    cout << "         /_________\\_/         \\   _______\\     " << endl;
    cout << "        /|         |  |         | |       |\\ " << endl;
    cout << "       / |         |  |         | |       | \\" << endl;
    cout << "      /  |         |  |  CAFE   | |       |  \\" << endl;
    cout << "     /   |||||||||||  ||||||||||| |||||||||   \\" << endl;
    cout << "    /                                          \\   " << endl;
    cout << "   |                                            |" << endl;
    cout << "   |                                            |" << endl;
    cout << "   |                                            |" << endl;
    cout << "   |                   ______                   |" << endl;
    cout << "   |                  /      \\                  |" << endl;
    cout << "   |                 /        \\                 |" << endl;
    cout << "   |                 ||      ||                 |" << endl;
    cout << "   |________________ ||      ||________________ | " << endl;

    cout << "\n" << endl;

    cout << " W   W  EEEEE  L      CCCCC  OOOOO  M   M  EEEEE\n";
    cout << " W   W  E      L      C      O   O  MM MM  E    \n";
    cout << " W W W  EEEE   L      C      O   O  M M M  EEEE \n";
    cout << " W W W  E      L      C      O   O  M   M  E    \n";
    cout << "  W W   EEEEE  LLLLL  CCCCC  OOOOO  M   M  EEEEE\n";

    cout << "\n" << endl;

    int loginChoice;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "Enter your choice: ";
        cin >> loginChoice;

        switch (loginChoice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            if (login()) {
                loggedIn = true;
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    int ch;
    char choice = 'n';

    do
    {
        system("cls");
        menu();
        cin >> ch;
        switch (ch)
        {
        case 0:
            break;
        case 1:
            cout << "Pasta Qty: ";
            cin >> I[totalItems].qty;
            I[totalItems].id = totalItems + 1;
            strcpy_s(I[totalItems].item, "Pasta");
            I[totalItems].rate = 50;
            I[totalItems].amt = I[totalItems].qty * I[totalItems].rate;
            amount += I[totalItems].amt;
            totalItems++;
            break;
        case 2:
            cout << "No. of Sandwiches: ";
            cin >> I[totalItems].qty;
            I[totalItems].id = totalItems + 1;
            strcpy_s(I[totalItems].item, "Sandwich");
            I[totalItems].rate = 30;
            I[totalItems].amt = I[totalItems].qty * I[totalItems].rate;
            amount += I[totalItems].amt;
            totalItems++;
            break;
        case 3:
            cout << "How many cups of coffee: ";
            cin >> I[totalItems].qty;
            I[totalItems].id = totalItems + 1;
            strcpy_s(I[totalItems].item, "Coffee");
            I[totalItems].rate = 20;
            I[totalItems].amt = I[totalItems].qty * I[totalItems].rate;
            amount += I[totalItems].amt;
            totalItems++;
            break;
        case 4:
            cout << "No. of Buns: ";
            cin >> I[totalItems].qty;
            I[totalItems].id = totalItems + 1;
            strcpy_s(I[totalItems].item, "Bun's");
            I[totalItems].rate = 100;
            I[totalItems].amt = I[totalItems].qty * I[totalItems].rate;
            amount += I[totalItems].amt;
            totalItems++;
            break;
        case 5:
            cout << "No. of Juices: ";
            cin >> I[totalItems].qty;
            I[totalItems].id = totalItems + 1;
            strcpy_s(I[totalItems].item, "Juice");
            I[totalItems].rate = 200;
            I[totalItems].amt = I[totalItems].qty * I[totalItems].rate;
            amount += I[totalItems].amt;
            totalItems++;
            break;
        default:
            cout << "Invalid choice. Please choose a valid item from the menu." << endl;
            break;
        }

        if (ch != 0)
        {
            cout << "\nDo You Want to Add More (Y/N)? ";
            cin >> choice;
        }
        else
        {
            choice = 'n';
        }

    } while (choice == 'Y' || choice == 'y');

    if (amount > 0) {
        showBill();
        _getche();
    }
    else {
        cout << "\nNo Order Placed Yet...\n";
        system("pause");
    }

    return 0;
}