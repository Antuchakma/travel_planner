#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>



using namespace std;

void menu();

class ManageMenu
{

public:


    ManageMenu()
    {
        system("color 0A"); //change terminal color
        menu();
    }

    ~ManageMenu(){}
};

class Customer
{
public:
    string name, gender, address;
    int age, mobileNo, menuBack;
    static int cusID;
    char all[999];

    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app); //opening file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();

    }
    void showDetails() //function to show old customer records
    {
        ifstream in("old-customers.txt");
        {
            if(!in)
            {
                cout << "File Error!" << endl;
            }
            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }

};

int Customer::cusID;

class Cabs
{
public:
    int cabChoice;
    int days;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {

        cout << "-----------ABC Cabs-----------\n" << endl;
        cout << "1. Rent a Standard Cab -  tk 1200 for 1 day" << endl;
        cout << "2. Rent a Luxury Cab - tk 1500 per day" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter days you have to travel: ";
        cin >> days;

        int hireCab;

        if(cabChoice == 1){
            cabCost = days * 1200;
            cout << "\nYour tour will cost " << cabCost << " tk for a standard cab" << endl;
            cout << "Press 1 to hire this cab: or "<<endl;
            cout << "Press 2 to select another cab: "<<endl;
            cout<<"Press any other button to cancel cab and go to menu"<<endl;
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2){
                cabDetails();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                menu();
            }
        }
        else if(cabChoice == 2){
            cabCost = days * 1500;
            cout << "\nYour tour will cost " << cabCost << " tk for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or "<<endl;
            cout << "Press 2 to select another cab: "<<endl;
            cout<<" Press any other button to cancel cab and go to menu";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2){
                cabDetails();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if(hireCab == 1){
            menu();
        }
        else{
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    int dayss;
    static float hotelCost;
    static float restaurant_cost;
    int resbook;

    void hotels()
    {
        string hotelNo[] = {"DIBA-NISHI", "CASTLE SALAM", "OMOR FARUQ"};


        for(int a = 0; a < 3; a++)
        {
            cout << (a+1) <<". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently we collaborated with above hotels!" << endl;

        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL DIBA-NISHI-------\n" << endl;


            cout << "Packages offered by DIBA-NISHI:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: tk 5000.00 per night" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: tk 10000.00 per night" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at DIBA-NISHI: tk 15000.00 per night" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                    cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;
                hotelCost = dayss*5000.00;
                cout << "\nYou have successfully booked Standard Pack at DIBA-NISHI" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                          cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;
                hotelCost = dayss*10000.00;
                cout << "\nYou have successfully booked Premium Pack at DIBA-NISHI" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                      cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;
                hotelCost = dayss*15000.00;
                cout << "\nYou have successfully booked Luxury Pack at DIBA-NISHI" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to direct to restaurant page: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                restaurant();
            }
            else{
                restaurant();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL CASTLE SALAM-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by CASTLE SALAM:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                          cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;

                hotelCost = dayss*15000.00;
                cout << "You have successfully booked Family Pack at CASTLE SALAM" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){

                      cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;
                hotelCost = dayss* 10000.00;

                cout << "You have successfully booked Couple Pack at CASTLE SALAM" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                          cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;
                hotelCost = dayss* 5000.00;
                cout << "You have successfully booked Single Pack at CASTLE SALAM" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to direct to restaurant page: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                restaurant();
            }
            else{
                restaurant();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL OMOR FARUQ-------\n" << endl;

            cout << "\nAmazing offer in this summer: TK 5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                            cout<<"For how many nights you want to book ?"<<endl;
            cin>>dayss;

                hotelCost = dayss*5000.00;
                cout << "You have successfully booked OMOR FARUQ Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to direct RESTAURANT PAGE: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                restaurant();
            }
            else{
                restaurant();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }


    void restaurant()
    {
        int cuis;
        int person;
        int go;


         string Restaurant[]= {"golapi", "sada-kalo", "babu"};

         for(int i=0;i<3;i++)
         {
            cout<<i+1<<". "<<Restaurant[i]<<endl;
         }

         cout<<"we have these restaurants nearby. You can book these reastuarants and get 20% off"<<endl;
         cout<<"type the number of restaurant you want to book"<<endl;

         cin>>resbook;


         if(resbook==1)
         {
            cout<<"___________GOLAPI RESTAURANT__________"<<endl<<endl<<"these are the offers we provide: "<<endl;
            cout<<" 1. BANGLADESHI CUISINE  :   tk 250 per head"<<endl<<"2. INDIAN CUSINE :   tk 300 per head"<<endl;
            cout<<" 3. CHINESE CUSINE :    tk 350 per head"<<endl<<endl<<"Enter the cuisine you want to book for"<<endl;

            cin>>cuis;

            if(cuis==1)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*250;
            }


              else if(cuis==2)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*300;;
            }


               else if(cuis==3)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*350;
            }

            else
            {
                cout<<"invalid choice "<<endl;
                cout<<"redirecting to the restuarant page"<<endl;
                Sleep(110);
                system("CLS");
                restaurant();
            }


            cout<<"you have successfully booked a restaurant for a meal"<<endl;

            cout<<"press the button 1 to enter the main menu: "<<endl;
            cin>>go;
            system("CLS");

            if(go==1)
            {
                menu();
            }

            else
            {
                cout<<"invalid input   redirecting to the main menu"<<endl;
                Sleep(110);
                system("CLS");
                menu();
            }


         }

         if(resbook==2)
         {
             cout<<"___________SHADA-KALO RESTAURANT__________"<<endl<<endl<<"these are the offers we provide: "<<endl;
            cout<<" 1. ENGLISH CUISINE  :   tk 450 per head"<<endl<<"2. AFRICAN CUSINE :   tk 300 per head"<<endl;
            cout<<" 3. JAPANESE CUSINE :    tk 550 per head"<<endl<<endl<<"Enter the cuisine you want to book for"<<endl;

            cin>>cuis;

            if(cuis==1)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*450;
            }


              else if(cuis==2)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*300;;
            }

            else if(cuis == 3)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*550;
            }


               else if(cuis==1)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*550;
            }

            else
            {
                cout<<"invalid choice "<<endl;
                cout<<"redirecting to the restuarant page"<<endl;
                Sleep(110);
                system("CLS");
                restaurant();
            }


            cout<<"you have successfully booked a restaurant for a meal"<<endl;

            cout<<"press the button 1 to enter the main menu: "<<endl;
            cin>>go;
            system("CLS");

            if(go==1)
            {
                menu();
            }

            else
            {
                cout<<"invalid input   redirecting to the main menu"<<endl;
                Sleep(110);
                system("CLS");
                menu();
            }


         }


         else if(resbook==3)
         {
             cout<<"___________BABU RESTAURANT__________"<<endl<<endl<<"these are the offers we provide: "<<endl;
            cout<<" 1. RAJSHAHI CUISINE  :   tk 250 per head"<<endl<<"2. CHITTAGONG CUSINE :   tk 300 per head"<<endl;
            cout<<" 3. SYLHET CUSINE :    tk 350 per head"<<endl<<endl<<"Enter the cuisine you want to book for"<<endl;

            cin>>cuis;

            if(cuis==1)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*250;
            }


              else if(cuis==2)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*300;;
            }


               else if(cuis==3)
            {
                cout<<"for how many person? "<<endl;
                cin>>person;

                restaurant_cost=person*350;
            }

            else
            {
                cout<<"invalid choice "<<endl;
                cout<<"redirecting to the restuarant page"<<endl;
                Sleep(110);
                system("CLS");
                restaurant();
            }


            cout<<"you have successfully booked a restaurant for a meal"<<endl;

            cout<<"press the button 1 to enter the main menu: "<<endl;
            cin>>go;
            system("CLS");

            if(go==1)
            {
                menu();
            }

            else
            {
                cout<<"invalid input   redirecting to the main menu"<<endl;
                Sleep(110);
                system("CLS");
                menu();
            }


         }
         }


};

float Booking::hotelCost;
float Booking::restaurant_cost;

class Chargers : public Booking, Cabs, Customer //Multiple Inheritance of some other classes to Chargers
{

public:

    void printBill()
    {
        ofstream outf("receipt.txt"); //receipt for bought items
        {
            outf << "--------A&N Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "rest. cost:\t\t " << fixed << setprecision(2) << Booking::restaurant_cost<< endl;
            outf << "_________________________________" << endl;

            outf <<" rest discount:\t" << fixed << setprecision(2) << Booking::restaurant_cost*(.2)<<endl;

            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastCabCost+Booking::restaurant_cost-(Booking::restaurant_cost*.2) << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        //cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout << "File Error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};



void menu() //menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t    * A&N Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "\t|\t\t\t\t\t\t|" << endl;

    cout << "\t|\tCustomer Management    : 1\t\t|" << endl;
    cout << "\t|\tCabs Management        : 2\t\t|" << endl;
    cout << "\t|\tBookings Management    : 3\t\t|" << endl;
    cout << "\t|\tCharges & Bill         : 4\t\t|" << endl;
    cout << "\t|\tshow nearby restaurants: 5\t\t|" << endl;
    cout << "\t|\tExit                   : 6\t\t|" << endl;
    cout << "\t|\t\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; //creating objects
    Cabs a3;
    Booking a4;
    Chargers a5;


    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice == 2){
        a3.cabDetails();
    }
    else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }


    else if(mainChoice == 5)
    {
        a4.restaurant();
    }


    else if(mainChoice == 6){
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;
 
}

