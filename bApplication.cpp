#include <iostream>
#include<conio.h>
using namespace std;

int userscount=0;
int farmersCount = 0;
int prodCount = 0;
int eqpCount =0;

const int farmersArrSize = 100;
const int userArrSize=100;
const int prodArrSize=100;
const int eqpArrSize=100;
string names[userArrSize];
string passwords[userArrSize];
string roles[userArrSize];
string farmerNames[farmersArrSize];
string f_City[farmersArrSize];
string f_Field[farmersArrSize];
string p_Name[prodArrSize];
string p_Quantity[prodArrSize];
string p_Price[prodArrSize];
string e_Name[eqpArrSize];
string e_Numbers[eqpArrSize];
string e_Price[eqpArrSize];

string sign_In(string name,string password,string role);
bool sign_Up(string name, string password, string role);
string add_Farmer();
string update_Farmer(string name,string updateCity,string updateField);
void Header();
void main_Menu();
int loginMenu();
void admin_Menu();
void view_Farmer();
string remove_Farmer();
void update_Farmer();
void update_Name();
void update_City();
void update_Field();
void farmer_Menu();
void subMenuBeforMainMenu(string submenu);
void subMenu(string submenu);
void clearScreen();
string input_AgriculturalProducts();
void view_AgriculturalProducts();
string remove_AgriculturalProducts();
void update_ProductDetails();
void update_ProductName();
void update_ProductQuantity();
void update_ProductPrice();
string input_AgriculturalEquipment();
string remove_AgriculturalEquipment();
void view_AgriculturalEquipment();
void update_EquipmentDetails();
void update_eqpName();
void update_eqpNumbers();
void update_eqpPrice();
void viewStock();
void customer_Menu();
main()
{
    int loginOption=0;
    int num;
    string name;
    string password;
    string role;
    string city;
    string field;
    string updateCity;
    string updateField;
    string updateName;
    string prodName;
    string prodQuantity;
    string prodPrice;
    string updateProduct;
    string updateQuantity;
    string updatePrice;
    string eqpName;
    string eqpNumbers;
    string eqpPrice;
    string updateEqp;
    string updateNum;
    string updateEqpPrice;
    while(true)
    {
        Header();
        main_Menu();
        loginOption = loginMenu();
        if(loginOption == 1)
        { 
            system("cls");
            Header();
            main_Menu();
            subMenuBeforMainMenu("sign_Up");
            cout << "ENTER NAME : ";
            cin >> name;
            cout << "ENTER PASSWORD : ";
            cin >> password;
            cout << "ENTER ROLE (Admin or Customer) : ";
            cin >> role;
            if (role == "Admin" || role == "Customer")
            {
            bool isValid=sign_Up(name,password,role);
            if (isValid)
            {
                cout << "SUCCESSFULLY SIGNUP!" << endl;
            }
            else
            {
                cout << "ERROR. CAN'T SIGNUP" << endl;
            }    
            }
            else
            {
                cout << "ERROR. INVALID ROLE "<<endl;
                continue;
            }
            
        }
        else if(loginOption == 2)
        {
            system("cls");
            Header();
            main_Menu();
            subMenuBeforMainMenu("sign_In");
            cout << "ENTER USERNAME : " << endl;
            cin >> name;
            cout << "ENTER PASSWORD : " << endl;
            cin >> password;
            role=sign_In(name,password,role);
            if (role == "Admin")
            {
                clearScreen();
                while(true)
                {  
                Header(); 
                admin_Menu();
                loginOption = loginMenu();
                if(loginOption == 1)
                {
                    system("cls");
                    add_Farmer();
                }
                if(loginOption == 2)
                {
                    system("cls");
                    remove_Farmer();
                }
                if(loginOption == 3)
                {
                    system("cls");
                    view_Farmer();
                    cout << "Press any key to continue";
                    getch();
                }
                if(loginOption == 4)
                {
                    system("cls");
                    update_Farmer();
                    loginOption = loginMenu();
                    if (loginOption == 1)
                    {
                        system("cls");
                        view_Farmer();
                        update_Name();
                    }
                    if (loginOption == 2)
                    {
                        system("cls");
                        view_Farmer();
                        update_City();
                    }
                    if (loginOption == 3)
                    {
                        view_Farmer();
                        update_Field();
                    }
                }
                if (loginOption == 6)
                {
                    break;
                }
                clearScreen();
                }
            }
            if (role == "Farmer")
            {
                clearScreen();
                while(true)
                {
                Header();
                main_Menu();
                subMenuBeforMainMenu("sign_In"); 
                farmer_Menu();
                loginOption = loginMenu();
                if (loginOption == 1)
                {
                    system("cls");
                    input_AgriculturalProducts();
                }
                if (loginOption == 2)
                {
                    system("cls");
                    view_AgriculturalProducts();
                }
                if (loginOption == 3)
                {
                    system("cls");
                    remove_AgriculturalProducts();
                }
                if (loginOption == 4)
                {
                    system("cls");
                    update_ProductDetails();
                    loginOption = loginMenu();
                    if (loginOption == 1)
                    {
                        system("cls");
                        view_AgriculturalProducts();
                        update_ProductName();
                    }
                    if (loginOption == 2)
                    {
                        system("cls");
                        view_AgriculturalProducts();
                        update_ProductQuantity();
                    }
                    if (loginOption == 3)
                    {
                        view_AgriculturalProducts();
                        update_ProductPrice();
                    }
                }
                if (loginOption == 5)
                {
                    system("cls");
                    input_AgriculturalEquipment();
                }
                if (loginOption == 6)
                {
                    system("cls");
                    remove_AgriculturalEquipment();
                }
                if (loginOption == 7)
                {
                    system("cls");
                    view_AgriculturalEquipment();
                }
                if (loginOption == 8)
                {
                    system("cls");
                    update_EquipmentDetails();
                    loginOption = loginMenu();
                    if (loginOption == 1)
                    {
                        system("cls");
                        view_AgriculturalEquipment();
                        update_eqpName();
                    }
                    if (loginOption == 2)
                    {
                        system("cls");
                        view_AgriculturalEquipment();
                        update_eqpNumbers();
                    }
                    if (loginOption == 3)
                    {
                        system("cls");
                        view_AgriculturalEquipment();
                        update_eqpPrice();
                    }    
                }
                if (loginOption == 9)
                {
                    system("cls");
                    viewStock();
                }
                if(loginOption == 10)
                {
                    break;
                }
                clearScreen();
                }
            }
        }
        else if(loginOption == 3)
        {
            break;
        }
    }
}
string sign_In(string name,string password,string role)
{   
    
    for(int idx=0; idx<userscount; idx++)
    {
        if(name == names[idx]  && password == passwords[idx])
        {
            role=roles[idx];
            cout<< "SUCCESSFULLY SIGNED IN AS " + roles[idx] << endl;
            return role;
        }
    }
    cout << "ERROR. INVALID USERNAME AND PASSWORD"<<endl;
    return "none";
}
bool sign_Up(string name, string password, string role)
{
    bool flag = false;
    for (int i=0; i < userscount; i++)
    {
        if(names[i] == name)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        return false;
    }
    if (flag == false)
    {
        names[userscount]= name;
        passwords[userscount]= password;
        roles[userscount]= role;
        userscount++;
        if(role == "Farmer")
        {
            farmersCount++;
        }
        return true;
    }
}
void subMenuBeforMainMenu(string submenu)
{
    string message = submenu + "Menu" ;
    cout << message << endl;
    cout << endl;
    cout << "********************************" << endl;
}
void clearScreen()
{
    cout << "Press Any Key to Continue..." << endl;
    getch();
    system("cls");
}
void Header()
{
    cout << "**************************************************" << endl;
    cout << "*               A FARMER'S TOUCH                 *" << endl;
    cout << "**************************************************" << endl;
}
void main_Menu()
{
    cout << "1.CREATE A NEW ACCOUNT:" << endl;
    cout << "2.LOGIN TO YOUR ACCOUNT:" << endl;
    cout << "3.EXIT" << endl << endl;
}
int loginMenu()
{
    int loginOption=0;
    cout << "SELECT ANY OF THE ABOVE OPTION....";
    cin >> loginOption;
    return loginOption;
}
void admin_Menu()
{
    cout << "Admin                                 "<< endl;
    cout << "**************************************"<< endl;
    cout << "                                      "<< endl;
    cout << "   MENU                               "<< endl;
    cout << "                                      "<< endl;
    cout << " 1. Add Farmers                       "<< endl;
    cout << " 2. Remove Farmers                    "<< endl;
    cout << " 3. View Farmers                      "<< endl;
    cout << " 4. Update Farmers                    "<< endl;
    cout << " 5. Exit                              "<< endl;
}
string add_Farmer()
{
    string name;
    string password;
    string role;
    string field;
    string city;
    cout << "Admin                                 "<< endl;
    cout << "**************************************"<< endl;
    cout << "                                      "<< endl;
    cout << "ADD FARMER:                           "<< endl;
    cout << "                                      "<< endl;
    cout << "FARMER'S NAME : " << endl;
    cin  >> name;
    cout << "FARMER'S PASSWORD : " << endl;
    cin  >> password;
    cout << "FARMER'S CITY : " << endl;
    cin  >> city;
    cout << "FARMER'S FIELD AREA : "<< endl;
    cin  >> field;
    role="Farmer";
    farmerNames[farmersCount] = name;
    f_City[farmersCount]= city;
    f_Field[farmersCount]= field;
    sign_Up(name,password,role);
}
void view_Farmer()
{
    cout << "Index\tName\tCity\tFieldArea" << endl;
    for(int i=0; i < farmersCount; i++)
    {
       cout << i << "\t" << farmerNames[i] << "\t" << f_City[i] << "\t" << f_Field[i] << endl;
       cout << endl;
    }
}
string remove_Farmer()
{
    int num;
    cout << "Index\tName\tCity\tFieldArea" << endl;
    for(int i=0; i < farmersCount; i++)
    {
       cout << i << "\t" << farmerNames[i] << "\t"<< f_City[i] << "\t" << f_Field[i] << endl;
    }
    cout << "FARMER TO REMOVE : ";
    cin >> num;
    if (num == farmersCount - 1)
    {
        farmerNames[num] = " ";
        f_Field[num] = " ";
        f_City[num] = " ";
        farmersCount --;
    }
    else
    {
        for (int i=num; i<farmersCount-1; i++)
        {
            i=i+1;
            farmerNames[i+1] = farmerNames[i];
            f_City[i+1] = f_City[i];
            f_Field[i+1] = f_Field[i];
            farmersCount--;
        }
        return "SUCCESSFULLY REMOVED";
    }
    return "NOT FOUND";
}
void update_Farmer()
{
    cout << "1.UPDATE FARMER'S NAME " << endl;
    cout << "2.UPDATE FARMER'S CITY " << endl;
    cout << "3.UPDATE FARMER'S FIELD " << endl;
}
void update_Name()
{
    int num;
    string updateName;
    cout << "FARMER'S INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "FARMER'S NAME TO UPDATE : " << endl;
    cin >> updateName;
    for(int i=0; i<userscount; i++)
    {
    if(farmerNames[num] == names[i])
    {
       names[i]=updateName;
    }
    }
}
void update_City()
{
    int num;
    string updateCity;
    cout << "FARMER'S INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "FARMER'S CITY TO UPDATE : " << endl;
    cin >> updateCity;
    for (int i=0; i<farmersCount; i++)
    {
        if (i == num)
        {
            f_City[i] = updateCity;
            break;
        }
    }    
}
void update_Field()
{
    int num;
    string updateField;
    cout << "FARMER'S INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "FARMER'S FIELD TO UPDATE : " << endl;
    cin >> updateField;
    for (int i=0; i<farmersCount; i++)
    {
        if (i == num)
        {
            f_Field[i]=updateField;
            break;
        }
    }    
} 
void farmer_Menu()
{
    cout << "Farmer                                "<< endl;
    cout << "**************************************"<< endl;
    cout << "                                      "<< endl;
    cout << "   MENU                               "<< endl;
    cout << "                                      "<< endl;
    cout << " 1. Add Products                      "<< endl;
    cout << " 2. View Products                     "<< endl;
    cout << " 3. Remove Products                   "<< endl;
    cout << " 4. Update Products                   "<< endl;
    cout << " 5. Add Equipments                    "<< endl;
    cout << " 6. Remove Equipments                 "<< endl;
    cout << " 7. View Equipments                   "<< endl;
    cout << " 8. Update Equipments                 "<< endl;
    cout << " 9. View Total Stock                  "<< endl;
    cout << "10. Exit                              "<< endl;
}
string input_AgriculturalProducts()
{
    string prodName;
    string prodQuantity;
    string prodPrice;
    cout << "Farmer                                " << endl;
    cout << "**************************************" << endl;
    cout << "                                      " << endl;
    cout << "INPUT PRODUCT:                        " << endl;
    cout << "                                      " << endl;
    cout << "NAME OF PRODUCT : " << endl;
    cin >> prodName;
    cout << "QUANTITY TO BE ADDED (in KGs) : " << endl;
    cin >> prodQuantity;
    cout << "PRICE OF PRODUCT : " << endl;
    cin >> prodPrice; 

    p_Name[prodCount]=prodName;
    p_Quantity[prodCount]=prodQuantity;
    p_Price[prodCount]=prodPrice;
    prodCount++;
}
void view_AgriculturalProducts()
{
    cout << "INDEX\tNAME\tQUANTITY\tPRICE" << endl;
    for(int i=0; i < prodCount; i++)
    {
       cout << i << "\t" << p_Name[i] << "\t" << p_Quantity[i] << "\t" << p_Price[i] << endl;
       cout << endl;
    }
}
string remove_AgriculturalProducts()
{
    int num;
    cout << "INDEX\tNAME\tQUANTITY\tPRICE" << endl;
    for(int i=0; i < prodCount; i++)
    {
       cout << i << "\t" << p_Name[i] << "\t" << p_Quantity[i] << "\t" << p_Price[i] << endl;
       cout << endl;
    }
    cout << "PRODUCT TO REMOVE : ";
    cin >> num;
    if (num == prodCount - 1)
    {
        p_Name[num] = " ";
        p_Quantity[num] = " ";
        p_Price[num] = " ";
        prodCount --;
    }
    else
    {
        for (int i=num; i<prodCount-1; i++)
        {
            i=i+1;
            p_Name[i+1] = p_Name[i];
            p_Quantity[i+1] = p_Quantity[i];
            p_Price[i+1] = p_Price[i];
            prodCount--;
        }
        return "SUCCESSFULLY REMOVED";
    }
    return "NOT FOUND";
}
void update_ProductDetails()
{
    cout << "1.UPDATE PRODUCT'S NAME     " << endl;
    cout << "2.UPDATE PRODUCT'S QUANTITY " << endl;
    cout << "3.UPDATE PRODUCT'S PRICE    " << endl;
}
void update_ProductName()
{
    int num;
    string updateProduct;
    cout << "PRODUCT'S INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "PRODUCT'S NAME TO UPDATE : " << endl;
    cin >> updateProduct;
    for (int i=0; i<prodCount; i++)
    {
        if (i == num)
        {
            p_Name[i] = updateProduct;
            break;
        }
    }    
}
void update_ProductQuantity()
{
    int num;
    string updateQuantity;
    cout << "PRODUCT'S INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "PRODUCT'S QUANTITY TO UPDATE : " << endl;
    cin >> updateQuantity;
    for (int i=0; i<prodCount; i++)
    {
        if (i == num)
        {
            p_Quantity[i] = updateQuantity;
            break;
        }
    }    
}
void update_ProductPrice()
{
    int num;
    string updatePrice;
    cout << "PRODUCT'S INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "PRODUCT'S PRICE TO UPDATE : " << endl;
    cin >> updatePrice;
    for (int i=0; i<prodCount; i++)
    {
        if (i == num)
        {
            p_Price[i]=updatePrice;
            break;
        }
    }    
}    
string input_AgriculturalEquipment()
{
    string eqpName;
    string eqpNumbers;
    string eqpPrice;
    cout << "Farmer                                " << endl;
    cout << "**************************************" << endl;
    cout << "                                      " << endl;
    cout << "INPUT EQUIPMENT:                      " << endl;
    cout << "                                      " << endl;
    cout << "NAME OF EQUIPMENT : " << endl;
    cin >> eqpName;
    cout << "NUMBER OF EQUIPMENTS TO BE ADDED : " << endl;
    cin >> eqpNumbers;
    cout << "PRICE OF EQUIPMENT : " << endl;
    cin >> eqpPrice; 

    e_Name[eqpCount]=eqpName;
    e_Numbers[eqpCount]=eqpNumbers;
    e_Price[eqpCount]=eqpPrice;
    eqpCount++;
}
void view_AgriculturalEquipment()
{
    cout << "INDEX\tNAME\tNUMBERS\tPRICE" << endl;
    for(int i=0; i < eqpCount; i++)
    {
       cout << i << "\t" << e_Name[i] << "\t" << e_Numbers[i] << "\t" << e_Price[i] << endl;
       cout << endl;
    }
}
string remove_AgriculturalEquipment()
{
    int num;
    cout << "INDEX\tNAME\tNUMBERS\tPRICE" << endl;
    for(int i=0; i < eqpCount; i++)
    {
       cout << i << "\t" << e_Name[i] << "\t" << e_Numbers[i] << "\t" << e_Price[i] << endl;
       cout << endl;
    }
    cout << "EQUIPMENT TO REMOVE : ";
    cin >> num;
    if (num == eqpCount - 1)
    {
        e_Name[num] = " ";
        e_Numbers[num] = " ";
        e_Price[num] = " ";
        eqpCount --;
    }
    else
    {
        for (int i=num; i<eqpCount-1; i++)
        {
            i=i+1;
            e_Name[i+1] = e_Name[i];
            e_Numbers[i+1] = e_Numbers[i];
            e_Price[i+1] = e_Price[i];
            eqpCount--;
        }
        return "SUCCESSFULLY REMOVED";
    }
    return "NOT FOUND";
}
void update_EquipmentDetails()
{
    cout << "1.UPDATE EQUIPMENT'S NAME     " << endl;
    cout << "2.UPDATE EQUIPMENT'S QUANTITY " << endl;
    cout << "3.UPDATE EQUIPMENT'S PRICE    " << endl;
}
void update_eqpName()
{
    int num;
    string updateEqp;
    cout << "EQUIPMENT INDEX TO UPDATE : "<< endl;
    cin >> num;
    cout << "EQUIPMENT'S NAME TO UPDATE : " << endl;
    cin >> updateEqp;
    for (int i=0; i<eqpCount; i++)
    {
        if (i == num)
        {
            e_Name[i] = updateEqp;
            break;
        }
    }    
}
void update_eqpNumbers()
{
    int num;
    string updateNum;
    cout << "EQUIPMENT INDEX TO UPDATE : "<< endl;
    cin >> num;
    cout << "EQUIPMENT'S NUMBERS TO UPDATE : " << endl;
    cin >> updateNum;
    for (int i=0; i<eqpCount; i++)
    {
        if (i == num)
        {
            e_Numbers[i] = updateNum;
            break;
        }
    }    
}
void update_eqpPrice()
{
    int num;
    string updateEqpPrice;
    cout << "EQUIPMENT INDEX TO UPDATE : " << endl;
    cin >> num;
    cout << "EQUIPMENT'S PRICE TO UPDATE : " << endl;
    cin >> updateEqpPrice;
    for (int i=0; i<eqpCount; i++)
    {
        if (i == num)
        {
            e_Price[i]=updateEqpPrice;
            break;
        }
    }    
}
void viewStock()
{
    int num;
    cout << "INDEX\tNAME\tQUANTITY OR NUMBERS\tPRICE" << endl;
    for(int i=0; i < prodCount; i++)
    {
       cout << i << "\t" << p_Name[i] << "\t" << p_Quantity[i] << "\t" << "\t" << p_Price[i] << endl;
       cout << endl;
    }
    for(int i=0; i < eqpCount; i++)
    {
       cout << i << "\t" << e_Name[i] << "\t" << e_Numbers[i] << "\t" << "\t" << e_Price[i] << endl;
       cout << endl;
    }
}
void customer_Menu()
{
    cout << "Customer                              "<< endl;
    cout << "**************************************"<< endl;
    cout << "                                      "<< endl;
    cout << "   MENU                               "<< endl;
    cout << "                                      "<< endl;
    cout << " 1. Order Products                    "<< endl;
    cout << " 2. View Ordered Products             "<< endl;
    cout << " 3. Remove Products                   "<< endl;
    cout << " 4. Update Products                   "<< endl;
    cout << " 5. Order Equipments                  "<< endl;
    cout << " 6. Remove Equipments                 "<< endl;
    cout << " 7. View Ordered Equipments           "<< endl;
    cout << " 8. Update Equipments                 "<< endl;
    cout << " 9. Total Bill                        "<< endl;
    cout << "10. Exit                              "<< endl;
}
