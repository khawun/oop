#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<cmath>
using namespace std;
class Product{
    private:int code;char Name[25];int qty;float price; float discount;
            static float Taxes;
    public: void input();
            void output();
            void Setid(int code){this->code=code;}
            float Getprice();
            char *Getname();
            int Getid();
            static void header();
            static void Menu();
            float Amount();
            float Discount();
            friend void Sort_pointer(Product *k[100],int n);
            friend void Sort_arr(Product t[100],int n);
            float Gettaxes();
            float Paymant();
//__________________________________________Menager function___________________________________________________
            Product();//defuald constuctor
            Product(int code,char *Name,int qty,float price,float discoun);//constructor with Parameter
            ~Product();//distructor
            Product(const Product &other);//copy constuctor
};
//_________________________________________write definition____________________________________________________
void Product::input(){
    cout<<"\tEnter code    = ";cin>>code;
    cout<<"\tEnter Name    = ";cin.sync();cin.get(Name,25);
    cout<<"\tEnter qty     = ";cin>>qty;
    cout<<"\tEnter price   = ";cin>>price;
    cout<<"\tEnter Discount= ";cin>>discount;
}
float Product::Paymant(){
    return((Amount()-Discount())+(Gettaxes()));
}
float Product::Taxes=0.50;
float Product::Gettaxes(){
    float Tax;
    if(Amount()<=300){
        Tax=Taxes;
    }
    else if(Amount()<=500){

        Tax=(Taxes+(Amount()*0.1));
    }
    else if(Amount()<=1000){
        Tax=(Taxes+(Amount()*0.05));
    }
    else{
        Tax=(Taxes+(Amount()*0.02));
    }
    return(Tax);
}
void Product::output(){
    cout<<"\t"<<code<<"\t"<<Name<<"\t"<<qty<<"\t"<<price<<"\t"<<discount<<"\t\t"<<Amount()<<"\t"<<Discount()<<"\t\t"<<Gettaxes()<<"\t"<<Paymant()<<endl;
}
void Product::header(){
    cout<<"\tCode\tName\tqty\tPrice\tDiscount\tAmount\tTotalDiscount\tTaxes\tPayment"<<endl;
}
void Product::Menu(){
    cout<<"option 1 Sort Data_____________________________"<<endl;
    cout<<"option 2 Seerch Data___________________________"<<endl;
    cout<<"option 3 Update Data___________________________"<<endl;
    cout<<"option 4 Delete Data___________________________"<<endl;
    cout<<"option 5 exit from Program_____________________"<<endl;
}
char* Product::Getname(){return(Name);}
float Product::Amount(){return((qty*price)-(qty*discount));}
float Product::Discount(){
    float ds;
    if(Amount()<=300){
        ds=(0+(discount*qty));
    }
    else if(Amount()<500){
        ds=(((Amount()-300)*0.05)+(discount*qty));
    }
    else if(Amount()<=100){
        ds=(((Amount()-500)*.1)+(discount*qty));
    }
    else{
        ds=(((Amount()-100)*0.15)+(discount*qty));
    }
    return(ds);
}
float Product::Getprice(){return(price);}
void Sort_pointer(Product *k[100],int n){
        Product *tm;
        int i,j;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(k[i]->price>k[j]->price){
                    tm=k[i];
                    k[i]=k[j];
                    k[j]=tm;
                }
        for(i=0;i<n;i++){
            k[i]->output();
        }
    }
void Sort_arr(Product t[100],int n){
        Product stor;
        int i,j;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(t[i].price>t[j].price){
                    stor=t[i];
                    t[i]=t[j];
                    t[j]=stor;
                }
        for(i=0;i<n;i++){
            t[i].output();
        }
    }
int Product::Getid(){return(code);}
//_______________________________________definition constructor_______________________________________________
Product::Product(int code,char *Name,int qty,float price,float discount){
        this->code=code;strcpy(this->Name,Name);this->qty=qty;this->price=price;this->discount=discount;
    }
Product::~Product(){}
Product::Product(const Product &other){
        code=other.code;strcpy(Name,other.Name);qty=other.qty;price=other.price;discount=other.discount;
    }
Product::Product(){
        code=1;strcpy(Name,"ddd");qty=3;price=25.3;discount=0.2;
    }
int main(){
    int n,i,j,option;
//_______________________________create list frome keyboard and n object______________________________________
    Product *ptr;
    cout<<"Enter n object = ";cin>>n;
    ptr=new Product[n];
    for(i=0;i<n;i++){
        ptr[i].input();
    }
    cout<<endl;
    getch();
    Product::header();
    for(i=0;i<n;i++){
        ptr[i].output();
    }
    cout<<endl;
    getch();
//______________________________ create 4 object using pointer with constructor ________________________________
    Product *obj[4]={
                       new Product(01,"pork",2,7,0.1),
                       new Product(02,"Apple",3,2,0.0),
                       new Product(03,"Beef",1,12,0.0),
                       new Product(04,"Coffee",2,3.1,0.3)

                    };
    Product::header();
    for(i=0;i<4;i++){
        obj[i]->output();
    }
    cout<<endl;
    getch();
//_____________________________create 5 object using array with constructor_____________________________________
    Product Array[5]={
                        Product(001,"Milk",2,2,0.2),
                        Product(002,"Toothaste",1,2.5,0.0),
                        Product(003,"Shoes",1,10,0.3),
                        Product(004,"Belt",1,25,0.5),
                        Product(005,"Tv",1,250,5),
                     };
    Product::header();
    for(i=0;i<5;i++){
        Array[i].output();
    }
    getch();
    Product::Menu();
    Product tmp;
    cout<<endl;
do{
        int del;
        int update;
        int seerch_id;
        cout<<"option = ";cin>>option;cout<<endl;
        switch(option){
            case 1:
//__________________________sort n object from keyboard_______________________________
                for(i=0;i<n;i++)
                    for(j=i+1;j<n;j++)
                        if(ptr[i].Getprice()>ptr[j].Getprice()){
                            tmp=ptr[i];
                            ptr[i]=ptr[j];
                            ptr[j]=tmp;
                        }
            Product::header();
                for(i=0;i<n;i++){
                    ptr[i].output();
                }
                    cout<<endl;
                    getch();
//________________Sort data from object use pointer with constructor___________________
                    Product::header();
                        Sort_pointer(obj,4);
                        getch();
//_________________Sort Data from obj use array with constuctor________________________
                    Product::header();
                        Sort_arr(Array,5);
                        getch();
                        cout<<endl;
            break;
            case 2:
//_________________ seerch constructor use array________________________________________
                cout<<"Seerch ID = ";cin>>seerch_id;
                for(i=0;i<5;i++){
                    if(Array[i].Getid()==seerch_id){
                        int start=0;
                        Array[i].output();
                    }
                }
                if(int start=1){
                    cout<<"seerch data in list not found"<<endl;;
                }
                getch();
//__________________seerch constructor use pointer______________________________________
                cout<<"Seerch ID = ";cin>>seerch_id;
                for(i=0;i<4;i++){
                    if(obj[i]->Getid()==seerch_id){
                        int start=0;
                        obj[i]->output();
                    }
                }
                if(int start=1){
                    cout<<"seerch data in list not found"<<endl;;
                }
                cout<<endl;
                getch();
//______________________seerch data n object an create from keyboard______________________
                cout<<"Seerch ID = ";cin>>seerch_id;
                for(i=0;i<n;i++){
                    if(ptr[i].Getid()==seerch_id){
                        int start=0;
                        ptr[i].output();
                    }
                }
                if(int start=1){
                    cout<<"seerch data in list not found"<<endl;
                }
                cout<<endl;
                getch();
            break;
            case 3:
//______________________update data an ceacte from keyboard_____________________________
                cout<<"Update ID = ";cin>>update;
                for(i=0;i<n;i++){
                    if(ptr[i].Getid()==update){
                        int start=0;
                        ptr[i].input();
                        for(i=0;i<n;i++)
                            ptr[i].output();
                    }
                    if(int start=1){
                        cout<<"not data!"<<endl;;
                    }
                }
                cout<<endl;
            getch();

            break;
            case 4:
                /*cout<<"Delete ID = ";cin>>del;
                for(i=0;i<n;i++){
                    if(ptr[i].Getid()==del){
                        int start=0;
                        ptr[i]="";
                        for(i=0;i<n;i++)
                            ptr[i].output();
                    }
                }
                if(int start=1){
                    cout<<"not found!"<<endl;;
                }*/
            break;
            case 5:
                cout<<"exit program!";
            break;
        }
    }
    while(option!=5);
    delete []obj;delete []ptr; delete []Array;
    return 0;
}
