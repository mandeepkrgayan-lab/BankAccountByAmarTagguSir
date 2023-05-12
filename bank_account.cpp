#include <iostream>
using namespace std;

class BankAccount{
    int account_number;
    float current_balance;
    string name;
    public:
        BankAccount(){
        account: //goto label
            cout<<"Please enter the account number: ";
            try{        //try block for account number to check if invalid character is entered or not
                if(!(cin>>account_number)){
                    throw invalid_argument("Invalid input ");
                }
                else {
                cout<<endl;
                cout<<"Please enter your initial balance : ";
                if(!(cin>>current_balance)){
                    throw invalid_argument("Invalid input ");
                }
                int option=0;
                while (option!=4){
                    cout<<"\n Please select one of the given option : (1/2/3/4)"<<endl;
                    cout<<"1.Deposit Money\n2.Withdraw Money\n3.Check Balance\n4.Exit!\n";
                    cin>>option;
                    switch (option)
                    {
                    case 1 :
                        depositMoney();
                        break;
                    case 2 :
                        withdrawMoney();
                        break;
                    case 3 :
                        checkBalance();
                        break;
                    case 4 :

                        break;
                    default:
                        cout<<"\n Error !! Please check input and re-enter !!"<<endl;
                    
                    }
                }
                }
                
            }
            catch(...){
                cin.clear();                   
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clearing the input as the wrong input provided using clear and ignore
                cout<<"\n Error ! Please check input "<<endl;
                goto account; //using goto statements to go back to account part for re-entry
            }
            return;
            
            
        }
        void depositMoney(){
            int deposit;
            cout<<"Please enter the amount to be deposited :  ";
            try{
                if(!(cin>>deposit)){  //checking if the input is invalid 
                    throw invalid_argument("Invalid input ");
                }
                else{
                    current_balance = current_balance + deposit;
                    cout<<endl;
                    checkBalance();
                    cout<<endl;
                }
            }
            catch(...){
                cin.clear();                   
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clearing the input as the wrong input provided using clear and ignore
                cout<<"\n Error ! Please check input "<<endl;
            }
        }
        void withdrawMoney(){
            int withdraw;
            cout<<"Please enter the amount to be withdrawn :  ";
            try
            {   if(!(cin>>withdraw)){
                    throw invalid_argument("Invalid input ");
                }
                if (withdraw<=current_balance){
                    current_balance = current_balance - withdraw;
                    cout<<endl;
                    checkBalance();
                    cout<<endl;
                }
                
                else if (withdraw>current_balance){
                    throw withdraw;
                }

            }
            catch(int x)
            {
                cout<<"Withdrawn amount "<<x<<" is more than current balance : "<<current_balance<<endl; 
            }
            catch(...){
                cin.clear();                   
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clearing the input as the wrong input provided using clear and ignore
                cout<<"\n Error ! Please check input"<<endl;
            }
        }
        
        void checkBalance(){
            cout<<"Current balance : "<<current_balance<<endl;
            cout<<endl;
        }
    
};







int main(){
    BankAccount Mandeep;
    BankAccount Sawan;
    
    


    
    return 0;
}