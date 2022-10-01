#include<bits/stdc++.h>
#define lc '\n'
using namespace std;
class library{
    long int access_number,admission_number;
    string author,title,publisher,issue;

    long double price;
public:
    void accept()
    {
        cout<<"Enter the access number ";
        cin>>access_number;
        cout<<"Enter the title ";
        cin>>title;
        cout<<"Enter the author ";
        cin>>author;
        cout<<"Enter the publisher ";
        cin>>publisher;
        cout<<"Enter the price ";
        cin>>price;
        admission_number=0;
        issue="No";
    }
    void display()
    {
        cout<<"Access Number:- "<<access_number<<lc;
        cout<<"Title:- "<<title<<lc;
        cout<<"Author:- "<<author<<lc;
        cout<<"Publications:- "<<publisher<<lc;
        cout<<"Price:- "<<price<<lc;
        cout<<"Issue Status:- "<<issue<<lc;
        if(issue=="Yes")
            cout<<"Issued to Admission Number:- "<<admission_number<<lc;
    }
    long int search(long int acc)
    {
        if(acc==access_number)
            return 1;
        else
            return 0;
    }
    void issued()
    {
        if(issue=="Yes")
            cout<<"Book is already issued"<<lc;
        else
        {
            cout<<"Enter the admission Number ";
            cin>>admission_number;
            issue="Yes";
            cout<<"Book is issued "<<lc;
        }
    }
    void returnbook()
    {
        admission_number=0;
        issue="No";
        cout<<"Book is returned "<<lc;
    }
};
int main()
{
    fstream obj;
    library l;
    int choice;
    long int acc,r,c=0;
    do{
        cout<<"Main Menu"<<lc;
        cout<<"1-Add Records"<<lc;
        cout<<"2-Issue a Book"<<lc;
        cout<<"3-Return a book"<<lc;
        cout<<"4-Display all details"<<lc;
        cout<<"5-Display single detail"<<lc;
        cout<<"6-Exit"<<lc;
        cout<<"Enter your choice ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                obj.open("lib.dat",ios::binary|ios::app);
                l.accept();
                obj.write((char*)&l,sizeof(l));
                obj.close();
                break;
            case 2:
                obj.open("lib.dat",ios::binary|ios::in|ios::out);
                c=0;
                cout<<"Enter the access number ";
                cin>>acc;
                while(!obj.eof())
                {
                    obj.read((char*)&l,sizeof(l));
                    c++;
                    r=l.search(acc);
                    if(r==1)
                    {
                        l.issued();
                        obj.seekp((c-1)*sizeof(l),ios::beg);
                        obj.write((char*)&l,sizeof(l));
                        break;
                    }
                }
                if(r==0)
                    cout<<"The given book is not found"<<lc;
                obj.close();
                break;
            case 3:
                obj.open("lib.dat",ios::binary|ios::in|ios::out);
                cout<<"Enter the access number ";
                cin>>acc;
                c=0;
                while(!obj.eof())
                {
                    obj.read((char*)&l,sizeof(l));
                    c++;
                    r=l.search(acc);
                    if(r==1)
                    {
                        l.returnbook();
                        obj.seekp((c-1)*sizeof(l),ios::beg);
                        obj.write((char*)&l,sizeof(l));
                        break;
                    }
                }
                if(r==0)
                    cout<<"The given book is not found"<<lc;
                obj.close();
                break;
            case 4:
                obj.open("lib.dat",ios::binary|ios::in);
                while(!obj.eof())
                {
                    obj.read((char*)&l,sizeof(l));
                    l.display();
                }
                obj.close();
                break;
            case 5:
                obj.open("lib.dat",ios::binary|ios::in);
                cout<<"Enter the access number ";
                cin>>acc;
                while(!obj.eof())
                {
                    r=l.search(acc);
                    if(r==1)
                    {
                        l.display();
                        break;
                    }
                }
                if(r==0)
                    cout<<"The given book is not found "<<lc;
                obj.close();
                break;
            case 6:
                exit(0);
            default:
                cout<<"Wrong Choice"<<lc;
        }
    }while(1);
}
