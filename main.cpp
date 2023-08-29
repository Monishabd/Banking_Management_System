#include<bits/stdc++.h>
#include<vector>
#include<conio.h>

using namespace std;

vector<string> admin_name_list {"disha","monisha"};
vector<string> admin_pin_list {"disha11","monisha22"};

vector<string> user_name_list;
vector<string> user_pin_list;

vector<int> account_no;
vector<int> age_list;
vector<int> account_balance;
vector<string> nid_list;
vector<bool> status;

int Account_No_Track = 510;
int choice=1;
class BankAccount;


class BankGUI{
    public:
        void HomeScreen(){
            getch();
            system("cls");
            cout<<"\n\n----------Welcome------------"<<endl;
            cout<<"\n----Disha Commercial Bank----\n"<<endl;

            cout<<"\n1. Register A New User."<<endl;
            cout<<"2. Login User."<<endl;
            cout<<"3. Admin User."<<endl;
            cout<<"4. Exit."<<endl;
            cout<<"Choose an option - ";
        }

        void LoginScreen(string Role){
            cout<<"Login Screen"<<endl;
            cout<<"Dynamic Polymorphism may occur."<<endl;

        }

        void AdminScreen(string username){
            cout<<"Admin Screen"<<endl;
        }

        void UserScreen(string username){
            cout<<"User Screen";

        }
};

class Transaction{

    public:
        int deposit_amount,withdraw_amount,acc_no, receiver_account, sender_account;
        bool isFoundAccount=false;

        void deposit(){
            isFoundAccount=false;
            deposit_amount=0;

            cout<<"\n\nDeposit To Account\n\n";
            cout<<"Deposit Amount: ";
            cin>>this->deposit_amount;
            cout<<"Account No: ";
            cin>>acc_no;

            time_t now = time(0);
            char* dt = ctime(&now);
            string timestamp = dt;

            for(int i=0;i<account_no.size();i++){
                if(account_no.at(i)==acc_no){
                    account_balance.at(i)+=this->deposit_amount;
                    isFoundAccount=true;
                    cout<<"\n\nDeposit Successful..."<<endl;

                    break;
                }
            }

            if(!isFoundAccount){
                cout<<"\n\nAccount Not Found."<<endl;
            }



        }

        void withdraw(){
            isFoundAccount=false;
            withdraw_amount=0;

            cout<<"\n\nWithdraw From Account\n\n";
            cout<<"Withdraw Amount: ";
            cin>>this->withdraw_amount;
            cout<<"Account No: ";
            cin>>acc_no;

            for(int i=0;i<account_no.size();i++){
                if(account_no.at(i)==acc_no){
                    int temp_withdraw_amount = account_balance.at(i )- this->withdraw_amount;

                    if(temp_withdraw_amount>=0){
                        account_balance.at(i)-=this->withdraw_amount;
                        cout<<"\n\nWithdraw Successful..."<<endl;
                    }else{
                        cout<<"\nInsufficient Balance..."<<endl;
                    }

                    isFoundAccount=true;

                    break;
                }
            }

            if(!isFoundAccount){
                cout<<"\n\nAccount Not Found."<<endl;
            }
        }

        void transfer(){
            isFoundAccount=false;
            withdraw_amount=0;

            cout<<"\n\nTransfer Balance\n\n";
            cout<<"Amount: ";
            cin>>this->withdraw_amount;
            cout<<"Sender Account No: ";
            cin>>this->sender_account;
            cout<<"Receiver Account No: ";
            cin>>receiver_account;

            for(int i=0;i<account_no.size();i++){
                if(account_no.at(i)==sender_account){
                    int temp_withdraw_amount = account_balance.at(i )- this->withdraw_amount;

                    if(temp_withdraw_amount>=0){

                        bool isReciverFound=false;


                        for(int j=0;j<account_no.size();j++){
                             if(account_no.at(j)==receiver_account){
                                account_balance.at(i)-=this->withdraw_amount;
                                account_balance.at(j)+=this->withdraw_amount;
                                isReciverFound=true;
                                cout<<"\n\nBalance Transer Successful..."<<endl;
                                break;
                             }

                        }

                        if(!isReciverFound){
                            cout<<"\nReceiver Account Not Found."<<endl;
                        }




                    }else{
                        cout<<"\nInsufficient Balance..."<<endl;
                    }

                    isFoundAccount=true;

                    break;
                }
            }

            if(!isFoundAccount){
                cout<<"\n\nSender Account Not Found."<<endl;
            }
        }


};

class BankAdmin : public BankGUI{

    public:

        void PendingAccounts(){
            getch();
            system("cls");
            cout<<"\n\n--------Pending Accounts-------\n\n"<<endl;
            cout<<"Acc_No\tName\tPin No.\tAge\tNational ID No.\tBalance"<<endl;
            for(int i=0;i<status.size();i++){
                if(status.at(i)==false){
                    cout<<account_no.at(i)<<"\t"<<user_name_list.at(i)<<"\t"<<user_pin_list.at(i)<<"\t"<<age_list.at(i)<<"\t"<<nid_list.at(i)<<"\t"<<account_balance.at(i)<<endl;
                }
            }

            this->ApproveAccount();
        }

        void ApproveAccount(){
            int acc_no;

            cout<<"Enter Account No. To Approve: ";
            cin>>acc_no;

            for(int i=0;i<status.size();i++){
                if(account_no.at(i)==acc_no){
                    status.at(i)=true;
                    break;
                }
            }

            cout<<"\n\nAccount has been approved."<<endl;
            getch();
            system("cls");
        }

        void AccountsList(){
            getch();
            system("cls");
            cout<<"\n\n--------Pending Accounts-------\n\n"<<endl;
            cout<<"Acc_No\tName\t\tPin No.\tAge\tNational ID No.\tBalance"<<endl;
            for(int i=0;i<status.size();i++){
                if(status.at(i)==true){
                    cout<<account_no.at(i)<<"\t"<<user_name_list.at(i)<<"\t"<<user_pin_list.at(i)<<"\t"<<age_list.at(i)<<"\t"<<nid_list.at(i)<<"\t"<<account_balance.at(i)<<endl;
                }
            }


            getch();
            system("cls");
        }

        int checkLogin(string role, string user, string pin){
            bool isFound = false;

            if(role=="1"){
                isFound=false;

                for(int i=0;i<admin_name_list.size();i++){
                    if(admin_name_list.at(i)==user){
                        isFound=true;
                        if(admin_pin_list.at(i)==pin){
                            return 1;
                        }else{
                            cout<<"\n\nInvalid Pin Code."<<endl;
                        }

                        break;
                    }
                }
                if(!isFound){
                    cout<<"\nIdentity Not Found"<<endl;
                    return 0;              
                }

            }else if(role=="2"){
                isFound=false;
                for(int i=0;i<user_name_list.size();i++){
                    if(user_name_list.at(i)==user){
                        isFound=true;
                        if(user_pin_list.at(i)==pin){
                            return 2;
                        }else{
                            cout<<"\n\nInvalid Pin Code."<<endl;
                        }

                        break;
                    }
                }
                if(!isFound){
                    return 0;
                }

            }


            getch();
            system("cls");

        }

        void checkBalance(){
              bool isFound=false;
              int ac_no;
              getch();
              system("cls");

              cout<<"\n\nCheck Balance:\n\n"<<endl;
              cout<<"Enter Account No. - ";
              cin>>ac_no;

                for(int i=0;i<account_no.size();i++){
                    if(account_no.at(i)==ac_no){
                        isFound=true;
                        
                        cout<<"\n\nBalance: "<<account_balance.at(i)<<endl;
                        break;
                    }
                }
                if(!isFound){
                    cout<<"\nIdentity Not Found"<<endl;
                }

                getch();
                system("cls");

        }
       
       void checFinance(){

              getch();
              system("cls");
              int total_balance=0;


                for(int i=0;i<account_no.size();i++){
                    total_balance+=account_balance.at(i);
                }

                cout<<"Total Finance: "<<total_balance<<" tk"<<endl;

                getch();
                system("cls");

        }

};

class BankAccount : public BankAdmin, public BankGUI, public Transaction{
    public:
        string name,pincode,nid_no;
        int age;
        bool account_status=false;

        void CreateAccount(){
            getch();
            system("cls");
            cout<<"\n\n----Account Creation Form-----\n\n"<<endl;
            cout<<"Your Full Name: ";
            cin>>this->name;
            cout<<"Your a Secret Pin: ";
            cin>>this->pincode;
            cout<<"Your Age: ";
            cin>>this->age;
            cout<<"Your National ID: ";
            cin>>this->nid_no;

            account_no.push_back(++Account_No_Track);
            user_name_list.push_back(this->name);
            user_pin_list.push_back(this->pincode);
            age_list.push_back(this->age);
            nid_list.push_back(this->nid_no);
            status.push_back(false);
            account_balance.push_back(0);

            cout<<"\n\nCongrats! Your Form is Submitted. Wait for the admin approval"<<endl;
            getch();
            system("cls");
        }

        void LoginScreen(string Role){
            string user,pin;
            system("cls");
            if(Role=="1"){
                cout<<"\n\nAdmin Login!\n"<<endl;
            }else if(Role=="2"){
                cout<<"\n\nUser Login!\n"<<endl;
            }

            cout<<"\nEnter your name: ";
            cin>>user;
            cout<<"Enter pincode: ";
            cin>>pin;

            int loginStatus = this->checkLogin(Role,user,pin);
            if(loginStatus==1){
                this->AdminScreen(user);
            }else if(loginStatus==2){
                this->UserScreen(user);
            }
        }

        void AdminScreen(string username){
            getch();
            system("cls");
            int option=1;

            while(option!=0){
                getch();
                system("cls");
                cout<<"\nDisha Commercial Bank"<<endl;
                cout<<"Admin: "<<username<<endl;

                cout<<"\n\n1. Bank Finance."<<endl;
                cout<<"2. Deposit Money For User."<<endl;
                cout<<"3. Withdraw Money For User."<<endl;
                cout<<"4. Transfer Money For User."<<endl;
                cout<<"5. Approve User Account."<<endl;
                cout<<"6. User Account Lists."<<endl;
                cout<<"7. Log Out."<<endl;
                cout<<"Choose an option - ";
                cin>>option;

                switch (option)
                {
                case 1:{
                    this->checFinance();
                    break;
                }
                case 2:{
                    this->deposit();
                    break;
                }
                case 3:{
                    this->withdraw();
                    break;
                }
                case 4:{
                    this->transfer();
                    break;
                }
                case 5:{
                    this->PendingAccounts();
                    break;
                }
                case 6:{
                    this->AccountsList();
                    break;
                }
                case 7:{
                    option=0;
                    break;
                }
            
                default:{
                    cout<<"Invalid Input. Try Again..."<<endl;
                    break;
                }
                
                }

            }
        }
        
        void UserScreen(string username){
            getch();
            system("cls");
            int option=1;

            while(option!=0){
                getch();
                system("cls");
                cout<<"\nDisha Commercial Bank"<<endl;
                cout<<"Logged In as: "<<username<<endl;

                cout<<"\n\n1. Check Balance."<<endl;
                cout<<"2. Deposit Money."<<endl;
                cout<<"3. Withdraw Money."<<endl;
                cout<<"4. Transfer Money."<<endl;
                cout<<"5. Log Out."<<endl;
                cout<<"Choose an option - ";
                cin>>option;

                switch (option)
                {
                case 1:{
                    this->checkBalance();
                    break;
                }
                case 2:{
                    this->deposit();
                    break;
                }
                case 3:{
                    this->withdraw();
                    break;
                }
                case 4:{
                    this->transfer();
                    break;
                }
                case 5:{
                    option=0;
                    break;
                }
            
                default:{
                    cout<<"Invalid Input. Try Again..."<<endl;
                    break;
                }
                
                }

            }
        }
};


int main(){
    BankGUI GUI;
    BankAccount BANK_ACCOUNT;

    while(choice!=0){
        GUI.HomeScreen();
        cin>>choice;

        switch (choice)
        {
        case 1:{
            BANK_ACCOUNT.CreateAccount();
            break;
        }
        case 2:{
            BANK_ACCOUNT.LoginScreen("2");
            break;
        }
        case 3:{
            BANK_ACCOUNT.LoginScreen("1");
            break;
        }
        case 4:{
            choice=0;
            break;
        }
        default:{
            cout<<"Invalid Input. Try Again..."<<endl;
            break;
        }

        }
    }

}
