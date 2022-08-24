#include <iostream>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
using namespace std;
void customer_detail(int);
void bill(int);
int row, total_bill;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*******
CLASS SHOP
*******/
class product_detail
{

    int product_code, product_quantity;
    string product_name;
    double product_price;
    /******
    FUNCTION TO GET INFORMATION
    ******/
public:
    void get_info()
    {
        gotoxy(100, 50);
        cout << "\n\t\tENTER PRODUCT DETAILS";
        gotoxy(100, 90);
        cout << "\n\tEnter product code: ";
        cin >> product_code;
        gotoxy(100, 130);
        cout << "\n\tEnter product name: ";
        cin >> product_name;
        gotoxy(100, 170);
        cout << "\n\tEnter quantity of product: ";
        cin >> product_quantity;
        gotoxy(100, 210);
        cout << "\n\tEnter price of product: ";
        cin >> product_price;
        // taxation();
    }
    /******
    FUNCTION TO SHOW INFORMATION
    ******/

    /******
    FUNCTION TO MODIFY INFORMATION
    ******/
    void modify_info()
    {
        gotoxy(100, 300);
        cout << "\n\tENTER NEW PRODUCT DETAILS";
        gotoxy(100, 300);
        cout << "\n\tNew Product Code: ";
        cin >> product_code;
        gotoxy(100, 360);
        cout << "\n\tNew product name: ";
        cin >> product_name;
        gotoxy(100, 400);
        cout << "\n\tNew quantity of product: ";
        cin >> product_quantity;
        gotoxy(100, 440);
        cout << "\n\tNew price of product:";
        cin >> product_price;
        // taxation();
    }
    /******
    FUNCTION TO SHOW ALL INFORMATION
    ******/
    void show_info()
    {
        gotoxy(5, row);
        cout << product_code;
        gotoxy(20, row);
        cout << product_name;
        gotoxy(37, row);
        cout << product_quantity;
        gotoxy(52, row);
        cout << product_price;
        row++;
    }
    /****** FUNCTION TO RETURN PRODUCT CODE
    ******/
    inline int return_product_code()
    {
        return product_code;
    }
    /******
    FUNCTION TO RETURN PRODUCT NAME
    ******/
    inline string return_product_name()
    {
        return product_name;
    }
    inline int return_product_quantity()
    {
        return product_quantity;
    }
    inline void set_product_quantity(int a)
    {
        product_quantity -= a;
    }
    inline int return_product_price()
    {
        return product_price;
    }
} shop;
class customer
{
    string first_name, last_name, phone_no, state, city;
    int id, pin_code;

public:
    void detail()
    {
        gotoxy(100, 50);
        cout << "\n\t\tFirst name:";
        cin >> first_name;
        gotoxy(100, 90);
        cout << "\n\t\tLast name: ";
        cin >> last_name;
        gotoxy(100, 130);
        cout << "\n\t\tPhone number: ";
        cin >> phone_no;
        address();
        srand(time(0));
        id = rand() % 10000;
    }
    void address()
    {
        gotoxy(100, 170);
        cout << "\n\t\t\tADDRESS DETAIL";
        gotoxy(100, 210);
        cout << "\n\t\tEnter state: ";
        cin >> state;
        gotoxy(100, 240);
        cout << "\n\t\tEnter city: ";
        cin >> city;
        gotoxy(100, 270);
        cout << "\n\t\tEnter pin code: ";
        cin >> pin_code;
    }
    void show_info()
    {
        gotoxy(0, row);
        cout << id;
        gotoxy(7, row);
        cout << first_name;
        gotoxy(25, row);
        cout << phone_no;
        gotoxy(47, row);
        cout << state;
        gotoxy(61, row);
        cout << city;
        gotoxy(74, row);
        cout << pin_code;
        row++;
    }
    int inline return_id()
    {
        return id;
    }
} cus_det;
class password
{
    string user_name, password;
    int id;

public:
    void write_password(int c)
    {
        cout << "\n\tusername:";
        cin >> user_name;
        cout << "\n\tPassword(6 character):";
        cin >> password;
        id = c;
    }
    inline string return_user_name()
    {
        return user_name;
    }
    inline string return_password()
    {
        return password;
    }
    inline int return_customer_id()
    {
        return id;
    }
} PASS;
class order_detail
{
    int order_code, order_quantity, order_price, flag = 0, customer_id;
    string order_name;

public:
    fstream f1;

    int getorder(int c, int i, int q, string n, int p)
    {
        customer_id = c;
        order_name = n;
        order_code = i;
        order_price = p;
        order_quantity = q;
    }
    void showorder()
    {
        gotoxy(5, row);
        cout << order_code;
        gotoxy(20, row);
        cout << order_name;
        gotoxy(37, row);
        cout << order_quantity;
        gotoxy(52, row);
        cout << order_price;
        row++;
        total_bill += order_quantity * order_price;
    }
    int inline return_order_code()
    {
        return order_code;
    }
    int inline return_order_quantity()
    {
        return order_quantity;
    }
    int inline return_customer_id()
    {
        return customer_id;
    }
} Order;
/*******
WELCOME
*******/
void welcome()
{
    system("CLS");
    gotoxy(45, 200);
    cout << "AAYSRI SUPERMARKET";
    getch();
}
/*******
CREDITS
*******/
void intro()
{
    system("CLS");
    gotoxy(100, 50);
    cout << "Developed by:";
    gotoxy(100, 200);
    cout << "group 9";
    getch();
}
void customer_menu()
{
to:
    system("CLS");
    int flag = 0, cid;
    char go, ch;
    string User_Name, User_Password;
    fstream c1;
    cout << "\n\t1.LOGIN";
    cout << "\n\t2.CREATE ACCOUNT";
    cout << "\n\tEnter your choice:";
    cin >> go;
    switch (go)
    {
    case '1':
        system("CLS");
        gotoxy(100, 0);
        cout << "\n\tEnter username:";
        cin >> User_Name;
        gotoxy(100, 70);
        cout << "\n\tEnter password:";
        cin >> User_Password;
        c1.open("pass.txt", ios::binary | ios::in);
        while (c1.read((char *)&PASS, sizeof(password)))
        {
            if (User_Name == PASS.return_user_name() && User_Password == PASS.return_password())
            {
                cout << "\n\tWELCOME BACK";
                flag = 1;
                cid = PASS.return_customer_id();
                getch();
                system("CLS");
                c1.close();
                customer_detail(cid);
            }
        }
        if (flag == 0)
        {
            system("CLS");
            gotoxy(100, 0);
            cout << "\n\tYou entered wrong password or username";
            gotoxy(100, 10);
            cout << "\n\t Please try again";
            getche();
            goto to;
        }
        break;
    case '2':
        system("CLS");
        c1.open("customer_detail.txt", ios::binary | ios::out | ios::app);
        cus_det.detail();
        cid = cus_det.return_id();
        c1.write((char *)&cus_det, sizeof(customer));
        c1.close();
        system("CLS");
        cout << "\n\t\t\tNow create username and Password:";
        c1.open("pass.txt", ios::binary | ios::out | ios::app);
        PASS.write_password(cid);
        c1.write((char *)&PASS, sizeof(password));
        c1.close();
        goto to;
        break;
    default:
        cout << "\n\tInvalid Choice!!";
        getche();
        goto to;
    }
}
void customer_detail(int id)
{

to:
    system("CLS");
    row = 8;
    fstream f1;
    int choice, flag = 0, product_code, product_quantity, product_price;
    char go, search_char;
    string product_name;

    system("CLS");
    cout << "\n\t1.Account Detail";
    cout << "\n\t2.Show all the products";
    cout << "\n\t3.Check for product availability";
    cout << "\n\t4.Place order";
    cout << "\n\t5.Exit";
    cout << "\n\tEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("CLS");
        cout.setf(ios::left);
        cout << "\n\n***** CUSTOMER DETAIL ****";
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\nID NAME PHONE NUMBER STATE CITY PINCODE ";
        f1.open("customer_detail.txt", ios::binary | ios::in);
        while (f1.read((char *)&cus_det, sizeof(customer)))
        {
            if (cus_det.return_id() == id)
                cus_det.show_info();
        }
        f1.close();
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n Press any key to go operations menu";
        go = getche();
        goto to;
        break;
    case 2:
        system("CLS");
        cout.setf(ios::left);
        cout << "\n\n***** PRODUCT LIST ****";
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n PRODUCT_CODE   PRODUCT_NAME   PRODUCT_QUANTITY   PRODUCT_PRICE ";
        f1.open("SHOP.txt", ios::binary | ios::in);
        while (f1.read((char *)&shop, sizeof(product_detail)))
        {
            shop.show_info();
        }
        f1.close();
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n Press any key to go operations menu";
        go = getche();
        goto to;
        break;
    /*******
    CHECK FOR PRODUCT AVAILABILITY
    ******/
    case 3:
        system("CLS");
        cout << "\nHow do you want to search the product ('C' for code,'N' for name): ";
        cin>>search_char;
        system("CLS");
        if (search_char == 'C' || search_char == 'c')
        {
            gotoxy(100, 55);
            cout << "\n\tEnter the code of product to be searched for: ";
            cin >> product_code;
        }
        else if (search_char == 'N' || search_char == 'n')
        {
            gotoxy(100, 55);
            cout << "\n\tEnter the name of product to be searched for: ";
            cin >> product_name;
        }
        else
        {
            cout << "\n\tInvalid Choice";
            getche();
            goto to;
        }
        system("CLS");
        cout.setf(ios::left);
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n PRODUCT_CODE   PRODUCT_NAME   PRODUCT_QUANTITY   PRODUCT_PRICE ";
        row = 6;
        f1.open("SHOP.txt", ios::binary | ios::in);
        while (f1.read((char *)&shop, sizeof(product_detail)))
        {
            if (search_char == 'C' || search_char == 'c')
            {
                if (shop.return_product_code() == product_code)
                {
                    shop.show_info();
                    flag = 1;
                }
            }
            else if (search_char == 'N' || search_char == 'n')
            {
                if (shop.return_product_name() == product_name)
                {
                    shop.show_info();
                    flag = 1;
                }
            }
        }
        f1.close();
        if (flag == 0)
        {
            gotoxy(100, 200);
            cout << "\n\tProduct does not exist!!";
        }
        gotoxy(100, 280);
        cout << "\n Press any key to go operations menu";
        go = getche();
        goto to;
        break;
    case 4:
        
        // string product_name;
        system("CLS");
        cout << "\n\nEnter The product code Of The Item: \n";
        cin >> product_code;
        cout << "\nQuantity in number: \n";
        cin >> product_quantity;
        f1.open("SHOP.txt", ios::binary | ios::in | ios::out);
        while (f1.read((char *)&shop, sizeof(product_detail)))
        {
            if (shop.return_product_code() == product_code && Order.return_order_quantity() >= product_quantity)
            {
                product_price = shop.return_product_price();
                // strcpy(shop.name, product_name);
                product_name=shop.return_product_name();
                flag = 1;
                Order.getorder(id, product_code, product_quantity, product_name, product_price);
                
                shop.set_product_quantity(Order.return_order_quantity());
                int pos = (-1) * sizeof(product_detail);
                f1.seekp(pos, ios::cur);
                break;
            }
        }
        f1.close();
        if (flag == 1)
        {
            cout << "\n\nThank You For Placing The Order";
            f1.open("order.txt", ios::binary | ios::out | ios::app);
            f1.write((char *)&Order, sizeof(order_detail));
            f1.close();
            getch();
            bill(id);
        }
        else
        {
            cout << "This product is out of stack ";
        }
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "you enter wrong choice";
        getch();
        goto to;
    }
}
void Admin_menu()
{
// system("CLS");
// welcome();
// intro();
// pass();
to:
    row = 8;
    system("CLS");
    int choice;
    char go;
    fstream f1, f2;
    char ch, ch1;
    int co, flag = 0;
    string product_name;
    float pr;
    /******
    MENU
    ******/
    gotoxy(100, 0);
    cout << "\n\t\tMANAGER MENU ";
    gotoxy(100, 70);
    cout << "\n\t1.Add a new product";
    gotoxy(100, 100);
    cout << "\n\t2.Show all the products";
    gotoxy(100, 130);
    cout << "\n\t3.Check for product availability";
    gotoxy(100, 160);
    cout << "\n\t4.Modify a product";
    gotoxy(100, 190);
    cout << "\n\t5.Delete a product";
    gotoxy(100, 220);
    cout << "\n\t6.Exit";
    gotoxy(100, 280);
    cout << "\nSelect an option (1/2/3/4/5/6):";
    cin >> choice;
    switch (choice)
    {
    /*******
    ADD A NEW PRODUCT
    ******/
    case 1:
    TO1:
        system("CLS");
        f1.open("SHOP.txt", ios::binary | ios::out | ios::app);
        shop.get_info();
        f1.write((char *)&shop, sizeof(product_detail));
        f1.close();
        gotoxy(100, 260);
        cout << "\n\tProduct successfully entered!";
        gotoxy(100, 280);
        cout << "\n\tDo you want to add more products(Y/N):";
        go = getche();
        if (go == 'Y' || go == 'y')
        {
            goto TO1;
        }
        else
        {
            goto to;
        }
    /*******
    SHOW ALL PRODUCTS
    ******/
    case 2:
        system("CLS");
        cout.setf(ios::left);
        cout << "\n\n***** PRODUCT LIST ****";
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n PRODUCT_CODE   PRODUCT_NAME   PRODUCT_QUANTITY   PRODUCT_PRICE ";
        f1.open("SHOP.txt", ios::binary | ios::in);
        while (f1.read((char *)&shop, sizeof(product_detail)))
        {
            shop.show_info();
        }
        f1.close();
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n Press any key to go operations menu";
        go = getche();
        goto to;
        break;
    /*******
    CHECK FOR PRODUCT AVAILABILITY
    ******/
    case 3:
        system("CLS");
        cout << "\nHow do you want to search the product ('C' for code,'N' for name): ";
        ch = getche();
        system("CLS");
        if (ch == 'C' || ch == 'c')
        {
            gotoxy(100, 55);
            cout << "\n\tEnter the code of product to be searched for: ";
            cin >> co;
        }
        else if (ch == 'N' || ch == 'n')
        {
            gotoxy(100, 55);
            cout << "\n\tEnter the name of product to be searched for: ";
            cin >> product_name;
        }
        else
        {
            cout << "\n\tInvalid Choice";
            getche();
            goto to;
        }
        system("CLS");
        cout.setf(ios::left);
        cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
        cout << "\n PRODUCT_CODE   PRODUCT_NAME   PRODUCT_QUANTITY   PRODUCT_PRICE ";
        row = 6;
        f1.open("SHOP.txt", ios::binary | ios::in);
        while (f1.read((char *)&shop, sizeof(product_detail)))
        {
            if (ch == 'C' || ch == 'c')
            {
                if (shop.return_product_code() == co)
                {
                    shop.show_info();
                    flag = 1;
                }
            }
            else if (ch == 'N' || ch == 'n')
            {
                if (product_name == shop.return_product_name())
                {
                    shop.show_info();
                    flag = 1;
                }
            }
        }
        f1.close();
        if (flag == 0)
        {
            gotoxy(100, 200);
            cout << "\n\tProduct does not exist!!";
        }
        gotoxy(100, 280);
        cout << "\n Press any key to go operations menu";
        go = getche();
        goto to;
        break;
    /*******
    MODIFY A PRODUCT
    ******/
    case 4:
    TO4:
        system("CLS");
        row = 4;
        cout << "\nHow do you want to search the product ('C' for code,'N' for name):";
        ch = getche();
        system("CLS");
        if (ch == 'C' || ch == 'c')
        {
            cout << "\n\tEnter the code of product to be searched for: ";
            cin >> co;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\tEnter the name of product to be searched for: ";
            cin >> product_name;
        }
        else
        {
            cout << "\n\tInvalid Choice";
            getche();
            goto to;
        }
        f1.open("SHOP.txt", ios::binary | ios::in | ios::out);
        cout << "\n PRODUCT_CODE   PRODUCT_NAME   PRODUCT_QUANTITY   PRODUCT_PRICE ";
        while (f1.read((char *)&shop, sizeof(product_detail)) && flag == 0)
        {
            if (ch == 'C' || ch == 'c')
            {
                if (shop.return_product_code() == co)
                {
                    shop.show_info();
                    gotoxy(100, 280);
                    shop.modify_info();
                    int pos = (-1) * sizeof(product_detail);
                    f1.seekp(pos, ios::cur);
                    f1.write((char *)&shop, sizeof(product_detail));
                    gotoxy(100, 450);
                    cout << "\n\tProduct Modified!";
                    flag = 1;
                }
            }
            else if (ch == 'N' || ch == 'n')
            {
                if (product_name == shop.return_product_name())
                {
                    shop.show_info();
                    gotoxy(100, 280);
                    shop.modify_info();
                    int pos = (-1) * sizeof(product_detail);
                    f1.seekp(pos, ios::cur);
                    f1.write((char *)&shop, sizeof(product_detail));
                    gotoxy(100, 450);
                    cout << "\n\tProduct Modified!";
                    flag = 1;
                }
            }
        }
        f1.close();
        if (flag == 0)
        {
            gotoxy(100, 450);
            cout << "\n\tProduct not found!!";
        }
        else
        {
            gotoxy(100, 460);
            cout << "\nDo you want to modify more products(Y/N)";
        }
        cin >> go;
        if (go == 'Y' || go == 'y')
            goto TO4;
        else
            goto to;
    /*******
    DELETE A PRODUCT
    ******/
    case 5:
    TO5:
        system("CLS");
        cout << "\nHow do you want to search the product ('C' for code,'N' for name)";
        ch = getche();
        system("CLS");
        if (ch == 'C' || ch == 'c')
        {
            cout << "\n\tEnter the code of product to be searched for: ";
            cin >> co;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\tEnter the name of product to be searched for: ";
            cin >> product_name;
        }
        else
        {
            cout << "\n\tInvalid Choice!!";
            getche();
            goto to;
        }
        f1.open("SHOP.txt", ios::binary | ios::in);
        f2.open("TEMP.txt", ios::binary | ios::out);
        f1.seekg(0, ios::beg);
        while (f1.read((char *)&shop, sizeof(product_detail)))
        {
            if (ch == 'C' || ch == 'c')
            {
                if (shop.return_product_code() != co)
                {
                    f2.write((char *)&shop, sizeof(product_detail));
                }
            }
            else if (ch == 'N' || ch == 'n')
            {
                if (product_name == shop.return_product_name())
                {
                    f2.write((char *)&shop, sizeof(product_detail));
                }
            }
        }
        f2.close();
        f1.close();
        remove("SHOP.txt");
        rename("TEMP.txt", "SHOP.txt");
        gotoxy(100, 80);
        cout << "\n\tProduct deleted!";
        gotoxy(100, 110);
        cout << "\n\tDo you want to delete more products(Y/N)";
        cin >> go;
        if (go == 'Y' || go == 'y')
            goto TO5;
        else
            goto to;
    /*******
    EXIT
    ******/
    case 6:
        system("CLS");
        gotoxy(45, 200);
        cout << "\n\tThanks for visiting!";
        getch();
        exit(0);
    default:
        system("CLS");
        gotoxy(45, 200);
        cout << "\n\tWrong Choice!!";
        gotoxy(45, 300);
        cout << "\n\tDo you want to try again?(Y/N)";
        cin >> go;
        if (go == 'Y' || go == 'y')
            goto to;
        else
            break;
    }
    getch();
}
void bill(int c)
{
    row = 8;
    system("CLS");
    fstream f1;
    cout.setf(ios::left);
    cout << "\n\n CUSTOMER DETAIL";
    cout << "\n\n\n==================== ================================ == == == == == == == == == == == == === ";
    cout << "\nUSER_ID  USER_NAME   PHONE_NUMBER   STATE   CITY   PINCODE ";
    f1.open("customer_detail.txt", ios::binary | ios::in);
    while (f1.read((char *)&cus_det, sizeof(customer)))
    {
        if (cus_det.return_id() == c)
            cus_det.show_info();
    }
    f1.close();
    cout << "\n\n\n PRODUCT DETAIL ";
    cout << "\n PRODUCT_CODE   PRODUCT_NAME   PRODUCT_QUANTITY   PRODUCT_PRICE ";
    row = 14;
    total_bill = 0;
    f1.open("order.txt", ios::binary | ios::in);
    while (f1.read((char *)&Order, sizeof(order_detail)))
    {
        if (Order.return_order_code() == c)
            Order.showorder();
    }
    cout << "\n\n\t\t\t\tTOTAL BILL: Rs." << total_bill << "/=";
}
int main()
{
    system("CLS");
    int choice;
    cout << "\n\t1.Customer:";
    cout << "\n\t2.Admin:";
    cout << "\n\tSelect your role:";
    cin >> choice;
    switch (choice)
    {
    case 1:
        customer_menu();
        break;
    case 2:
        Admin_menu();
        break;
    }
}