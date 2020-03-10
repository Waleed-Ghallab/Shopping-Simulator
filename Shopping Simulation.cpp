#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
struct items
{
    int id;
    string name;
    float price;
};

struct customer
{
    int id;
    string phoneNumber;
    float amountMoney;
    float points;
};

struct orders
{
    int customerId;
    int itemId;
    int Count;
};

    vector<customer> customerVector;
    vector<items> itemVector;
    vector<orders> ordersVector;

items itemInfo(vector<items> itemVector, int id)
{
    for(int i = 0;i < itemVector.size();i++){
        if(itemVector[i].id == id) {
            return itemVector[i];
        } else {
            return {};
        }
    }
}

customer customerInfo(vector<customer> customerVector, int id)
{
    for(int i = 0;i < customerVector.size();i++){
        if(customerVector[i].id == id) {
            return customerVector[i];
        } else {
            return {};
        }
    }
}

void updateAmountMoney(vector<customer> customerVector, int id, float amountMoney)
{
    for(int i = 0;i < customerVector.size();i++){
        if(customerVector[i].id == id) {
            customerVector[i].amountMoney = amountMoney;
            //customerVector[i].amountMoney.erase(customerVector.begin(), i);
            //customerVector[i].amountMoney.insert(customerVector.begin(), i, amountMoney);
            cout<< customerVector[i].amountMoney << endl;
             for(int i = 0; i < customerVector.size();i++){
                cout<< "Customer "<< i+1 <<endl;
                cout<< "ID : "<< customerVector[i].id<< "\n"<< "phoneNumber : " << customerVector[i].phoneNumber<< "\n" << "amount Money : "<< customerVector[i].amountMoney <<endl;
            }
        }
    }
}

void updateCustomerPoints(vector<customer> customerVector, int id, float price, int Count)
{
    for(int i = 0;i < customerVector.size();i++){
        if(customerVector[i].id == id) {
            customerVector[i].points += ((Count*price)/4);
            cout<< "POints :" << customerVector[i].points<<endl;
        }
    }
}

int main()
{

    int choice;

    while(choice != 0) {
        cout<<"Which process \n 1- Add customer \n 2- Add menu item \n 3- print all customers \n 4- print all items \n 5- make order \n 6- redeem item \n 7- show the customer with the highest points \n 8- show specific Customer \n 9- sort"<<endl;
        cin>> choice;

        if(choice == 1) {
            /*c.push_back(customer());
            int Count = 1;*/
            cout<< "enter ID:"<<endl;
            customer customerObject;
            cin>> customerObject.id;
            cout<< "enter phoneNumber:"<<endl;
            cin>> customerObject.phoneNumber;
            cout<< "enter amount Money:"<<endl;
            cin>> customerObject.amountMoney;
            customerVector.push_back(customerObject);

        } else if(choice == 2) {

            items itemObject;
            cout<< "enter ID:"<<endl;

            cin>> itemObject.id;
            cout<< "enter name:"<<endl;

            cin>> itemObject.name;
            cout<< "enter price :"<<endl;

            cin>> itemObject.price;
            itemVector.push_back(itemObject);

        } else if(choice == 3) {

            for(int i = 0; i < customerVector.size();i++){
                cout<< "Customer "<< i+1 <<endl;
                cout<< "ID : "<< customerVector[i].id<<endl;
                cout<< "phoneNumber : "<< customerVector[i].phoneNumber<< endl;
                cout<< "Amount Money : "<< customerVector[i].amountMoney <<endl;
                cout<< "Points : "<< customerVector[i].points <<endl;
            }

        } else if(choice == 4) {

            for(int i = 0; i < itemVector.size();i++){
                cout<< "Item "<< i+1 <<endl;
                cout<< "ID : "<< itemVector[i].id<< "\n"<< "Name : " << itemVector[i].name<< "\n" << "Price : "<< itemVector[i].price <<endl;
            }

        } else if(choice == 5) {
            int itemId, customerId;
            items itemData;
            customer customerData;
            cout<<"Please Enter Customer ID: "<<endl;
            cin>> customerId;
            customerData = customerInfo(customerVector, customerId);
            if(customerData.id) {
                cout<<"Please Enter Item ID: "<<endl;
                cin>> itemId;
                itemData = itemInfo(itemVector, itemId);
                if(itemData.id) {
                    int Count = 1;
                    cout<<"Enter How many pieces"<<endl;
                    cin>>Count;
                    cout<< "Customer ID :" <<customerData.id <<" item ID:"<< itemData.id <<endl;
                    cout<< "Customer amountMoney before: " <<customerData.amountMoney <<" item price :"<< itemData.price <<endl;
                    //float newAmountMoney;
                    customerData.amountMoney = customerData.amountMoney - (itemData.price * Count) ;
                    cout<< customerData.amountMoney<<endl;

                    for(int i = 0;i < customerVector.size();i++){
                        if(customerVector[i].id == customerData.id) {
                            customerVector[i].amountMoney = customerData.amountMoney;
                            customerVector[i].points = (Count * itemData.price)/4;
                            //cout<< "Item Price :" <<itemData.price<<endl;
                        }
                    }

                    //updateAmountMoney(customerVector, customerData.id, customerData.amountMoney);
                    //updateCustomerPoints(customerVector, customerData.id, itemData.price, Count);

                    orders orderObject;
                    orderObject.itemId = itemData.id;
                    orderObject.Count = Count;
                    orderObject.customerId = customerData.id;
                    ordersVector.push_back(orderObject);

                } else {
                    cout<< "This Item Doesn\'t exist"<<endl;
                }
            } else {
                cout<< "This Customer Doesn\'t exist"<<endl;
            }
        } else if(choice == 6) {
            int CustomerId;
            int ItemId;
            cout<<"Enter Customer ID: "<<endl;
            cin>>CustomerId;
            cout<<"Enter Item ID: "<<endl;
            cin>>ItemId;
            customer temp;
            temp=customerInfo(customerVector, CustomerId);
            items teto;
            teto= itemInfo(itemVector,ItemId);
            if(temp.points>=teto.price*4){
                temp.points=temp.points-teto.price*4;
                cout<<"Your Points now are "<<temp.points<<endl;
            }
            else{
                cout<<"you don't have enough points"<<endl;
            }


        } else if(choice == 7) {
            float coco;
            for(int i=0;i<customerVector.size();i++){
                coco=max(customerVector[i].points,customerVector[i+1].points);

            }
            cout<<coco<<endl;


        } else if(choice == 8) {
            int CustomerId;
            customer sheko;
            cout<< "Enter Customer ID"<<endl;
            cin>>CustomerId;
            sheko=customerInfo(customerVector, CustomerId);
            cout<<sheko.id<<endl<<sheko.amountMoney<<endl<<sheko.points<<endl;


        } else if (choice == 9){
          // int n = sizeof(customerVector)/sizeof(customerVector[0]);
          for(int i=0;i<customerVector.size();i++){
            if(customerVector[i].points<customerVector[i+1].points)
                swap(customerVector[i],customerVector[i+1]);
          }
          for(int i=0;i<customerVector.size();i++){
            cout<<customerVector[i].id<<endl;

          }




        }
    }


    return 0;
}
