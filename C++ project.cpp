#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;
class Invoice
{
  public:
    void information()
    {
        int c;
     cout<<"\t\t\t Pick and Pay \n\n\n";
     cout<<"\t\t\t| Press 1 to login|"<<endl;
     cout<<"\t\t\t| press 2 to exit|"<<endl;
     cout<<"\t\t\t please enter your choice:";
     cin>>c;
     switch(c)
     {
     case 1:
         Login();
         break;
     case 2:
        cout<<" Thank you "<<endl;
        information();
     }
    }
    void Login()
    {
        string userid,password;
        cout<<"Please enter your username";
        cin>>userid;
        cout<<"Please enter your password";
        cin>>password;
        getMenu();
    }

    void getMenu()
    {
        cout<<"Name                Price              Quantity "      <<endl;
        cout<<"Pasta               RS. 70              1 kg    "     <<endl;
        cout<<"Cereal              RS. 300             1 kg    "     <<endl;
        cout<<"Honey               RS. 165             65 gram "     <<endl;
        cout<<"Ramen               RS. 120             1 packet"     <<endl;
        cout<<"Dairymilk           RS. 180             1 packet"     <<endl;
        cout<<"Salt                RS. 60              1 kg    "     <<endl;
        cout<<"Gram flour          RS. 75              1 kg    "     <<endl;
        cout<<"Facewash            RS. 200             1 piece "     <<endl;
        cout<<"Baby lotion         RS. 580             1 piece "     <<endl;
        cout<<"Handwash            RS. 220             1 piece "     <<endl;
        order();
   }
   void order()
   {
        char n[30],product[10][30];
        int choice;
        int q[20],i,a=0;
        float p[20],amount,total=0;
        ofstream outFile("order.txt");  // Creating an output file stream

    if (!outFile.is_open())
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }
         do
    {
           cout<<" Place your order  here ";
           cout<<endl;
           cout<<endl;
           cout<<" Enter product name ";
           cin>>n;
           cout<<" Enter product quantity ";
           cin>>q[a];
           cout<<"Enter price " <<endl;
           cin>>p[a];
           strcpy (product[a],n);
           amount= q[a]*p[a];
           total += amount;
           cout << " Do you want to add another product? (1 for Yes / 0 for No): ";

           cin >> choice;
           a++;
        } while (choice != 0);
        outFile.close();
         cout<<"---------------Bill--------------"<<endl;
        cout<<"Name       Quantity          Price              Total "<<endl;
        for(i=0;i<a;i++)
        {
            amount= q[i]*p[i];
            cout<<product[i]<<"\t\t"<<q[i]<<"\t\t"<<p[i]<<"\t\t"<<amount<<endl;
        }

        cout<<"                           Total:Rs. "<<total<<endl;


    }
};
int main()
 {
    Invoice i1;
    i1. information();
    return 0;
 }


