#include <iostream>
using namespace std;

string accNums[5] = {"4810055992","4962006345","4753008741","3345256348","4954083265"}; 
string cusNames[5] = {"Tom Lara","Simon David","Ben Stacy","John Mark","Cooper Jake"};
string nics[5] = {"965622411V","931122456V","927391333V","961343267V","967591530V"};
string accTypes[5] = {"Saving","Current","Fixed","Current","Saving"};
double balance[5] = {153000.00,25000.00,85000.00,62000.00,178000.00};

void displayMenu();
void displayAccount();
void searchAccount();
void depositAmount();
void withdrawAmount();
int main() {
    displayMenu();
    return 0;
}

void displayMenu(){
    char isContinue = 'y';
    do{
        cout << "-----  Bank of Northen  ----- "<< endl;
        cout << "01 . Customer Details" << endl;
        cout << "02 . Search Account Details" << endl;
        cout << "03 . Deposit" << endl;
        cout << "04 . Withdrawal" << endl;
        cout << "05 . Interest" << endl;

        int op;
        cout << "Enter The Number That You Want Operate: ";
        cin >> op;

        switch (op)
        {
        case 1:
            displayAccount();
            break;
        case 2:
            searchAccount();
            break;
        case 3:
            depositAmount();
            break;
        case 4:
            withdrawAmount();
            break;
        
        default:
            cout << "Wrong Input!" << endl;
        }

        cout << "Would you like to use this app once more? (y or n) : ";
        cin >> isContinue;

    }while(isContinue == 'y' || isContinue == 'Y');
}

void displayAccount(){
    cout << "Account Number \t Customer Name \t NICs \t \t Balance" << endl;
    for(int i=0; i<5; i++){
        cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
    }
}

void searchAccount(){
    string userEnterdAccNum;
    cout << "Enter NIC Number : ";
    cin >> userEnterdAccNum;

    for(int i=0; i<5; i++){
        if(nics[i] == userEnterdAccNum){
            cout << "Account Number \t Customer Name \t NICs \t \t Balance" << endl;
            cout << nics[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
            return;
        }
    }
    cout << "Sorry, we don't have any account for this NIC Number." << endl;  
}

void depositAmount(){
    string userEnterdAccNum;
    cout << "Enter Account Number : ";
    cin >> userEnterdAccNum;

    for(int i=0; i<5; i++){
        if(accNums[i] == userEnterdAccNum){

            int depositAmmount;
            cout << "Enter the ammount that you want to deposit : ";
            cin >> depositAmmount;

            balance[i] += depositAmmount;

            cout << "Account Number \t Customer Name \t NICs \t \t Balance" << endl;
            cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
            return;
        }
    }
    cout << "Sorry, we don't have any account for this Account Number." << endl; 
}

void withdrawAmount(){
    string userEnterdAccNum;
    cout << "Enter Account Number : ";
    cin >> userEnterdAccNum;

    for(int i=0; i<5; i++){
        if(accNums[i] == userEnterdAccNum){

            int withdrawalAmount;
            cout << "Enter the ammount that you want to withdraw : " << endl;
            cin >> withdrawalAmount;

            if(balance[i] <= withdrawalAmount || balance[i] < 10000){
                cout << "The balance is not sufficient to withdraw";
                return;
            }

            balance[i] -= withdrawalAmount;

            cout << "Account Number \t Customer Name \t NICs \t \t Balance" << endl;
            cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
            return;
        }
    }
    cout << "Sorry, we don't have any account for this Account Number." << endl; 
} 