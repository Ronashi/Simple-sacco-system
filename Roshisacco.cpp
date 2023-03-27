#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
private:
    int id;
    string name;
    string address;
    string phone;
    string email;
public:
    Member(int member_id, string member_name, string member_address, string member_phone, string member_email) {
        id = member_id;
        name = member_name;
        address = member_address;
        phone = member_phone;
        email = member_email;
    }
    int get_id() {
        return id;
    }
    string get_name() {
        return name;
    }
    string get_address() {
        return address;
    }
    string get_phone() {
        return phone;
    }
    string get_email() {
        return email;
    }
};

class Loan {
private:
    int loan_id;
    float amount;
    float interest_rate;
    int repayment_period;
    Member borrower;
public:
    Loan(int loan_id_num, float loan_amount, float interest_rate_num, int repayment_period_num, Member borrower_member) {
        loan_id = loan_id_num;
        amount = loan_amount;
        interest_rate = interest_rate_num;
        repayment_period = repayment_period_num;
        borrower = borrower_member;
    }
    int get_loan_id() {
        return loan_id;
    }
    float get_amount() {
        return amount;
    }
    float get_interest_rate() {
        return interest_rate;
    }
    int get_repayment_period() {
        return repayment_period;
    }
    Member get_borrower() {
        return borrower;
    }
};

class Deposit {
private:
    int deposit_id;
    float amount;
    Member depositor;
    string date;
public:
    Deposit(int deposit_id_num, float deposit_amount, Member depositor_member, string deposit_date) {
        deposit_id = deposit_id_num;
        amount = deposit_amount;
        depositor = depositor_member;
        date = deposit_date;
    }
    int get_deposit_id() {
        return deposit_id;
    }
    float get_amount() {
        return amount;
    }
    Member get_depositor() {
        return depositor;
    }
    string get_date() {
        return date;
    }
};

class Account {
private:
    int account_id;
    float balance;
    Member account_owner;
    vector<Loan> loans;
    vector<Deposit> deposits;
public:
    Account(int account_id_num, float account_balance, Member account_owner_member){
        account_id = account_id_num;
        balance = account_balance;
        account_owner = account_owner_member;
    }
    int get_account_id() {
        return account_id;
    }
    float get_balance() {
        return balance;
    }
    Member get_account_owner() {
        return account_owner;
    }
    void add_loan(Loan loan) {
        loans.push_back(loan);
    }
    void add_deposit(Deposit deposit) {
        deposits.push_back(deposit);
        balance -= deposit.get_amount();
    }
    
    void print_transactions() {
        cout << "Transactions for account " << account_id << ":" << endl;
        for (int i = 0; i < deposits.size(); i++) {
            cout << deposits[i].get_date() << " - Deposit of " << deposits[i].get_amount() << endl;
        }
        for (int i = 0; i < loans.size(); i++) {
            cout << "Loan ID: " << loans[i].get_loan_id() << " - Amount: " << loans[i].get_amount() << endl;
        }
    }
};

int main() {
   
    Member member1(1, "Ronald Smiles", "Westlands, Nairobi", "079233393", "DoubleR@gmail.com");
    Member member2(2, "Marion Ythera", "Chiromo, Nairobi", "0714111439", "MarioY12@gmail.com");
    Member member3(3, "Job Newton", "Chiromo, Nairobi", "0798932947", "JobNewton@gmail.com");

    Loan loan1(1, 5000000.0, 0.05, 12, member1);
    Loan loan2(2, 1000000.0, 0.06, 24, member2);
    Loan loan3(3, 1000000.0, 0.06, 24, member3);
    
    Deposit deposit1(1, 1000.0, member1, "2023-01-01");
    Deposit deposit2(2, 2000.0, member2, "2023-03-24");
    Deposit deposit3(3, 2000.0, member3, "2023-03-22");
    
   
    Account account1(1, 0, member1);
    Account account2(2, 0, member2);
    Account account3(3, 0, member3);
    
   
    account1.add_loan(loan1);
    account1.add_deposit(deposit1);
    
    
    account2.add_loan(loan2);
    account2.add_deposit(deposit2);

    account3.add_loan(loan3);
    account3.add_deposit(deposit3);
    
  
    //  cout << "Account 1 balance: " << account1.get_balance() << endl;
    //  cout << "Account 2 balance: " << account2.get_balance() << endl;
    //  cout << "Account 3 balance: " << account3.get_balance() << endl;
    // return 0;
}

int choice;
    do {
        // Display menu and get user's choice
        cout << "1. View account balance and transactions" << endl;
        cout << "2. Make a deposit" << endl;
        cout << "3. Request a loan" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Process user's choice
        switch(choice) {
            case 1:
                // View account balance and transactions
                account1.print_transactions();
                account2.print_transactions();
                break;
            case 2:
                // Make a deposit
                float amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                Deposit deposit(account1.get_deposit_id() + 1, amount, account1.get_account_owner(), "2023-03-26");
                account1.add_deposit(deposit);
                cout << "Deposit successful" << endl;
                break;
            case 3:
                // Request a loan
                float loan_amount, interest_rate;
                int repayment_period;
                cout << "Enter loan amount: ";
                cin >> loan_amount;
                cout << "Enter interest rate: ";
                cin >> interest_rate;
                cout << "Enter repayment period (in months): ";
                cin >> repayment_period;
                Loan loan(account1.get_loan_id() + 1, loan_amount, interest_rate, repayment_period, account1.get_account_owner());
                account1.add_loan(loan);
                cout << "Loan request submitted" << endl;
                break;
            case 4:
                // Exit
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}


















// int main() {
// //     int member_id, loan_id, deposit_id, account_id;
//     string member_name, member_address, member_phone, member_email, deposit_date;
//     float loan_amount, interest_rate, deposit_amount, account_balance;
//     int repayment_period;

//     // Read member details from user input
//     cout << "Enter member ID: ";
//     cin >> member_id;
//     cout << "Enter member name: ";
//     cin.ignore();
//     getline(cin, member_name);
//     cout << "Enter member address: ";
//     getline(cin, member_address);
//     cout << "Enter member phone: ";
//     getline(cin, member_phone);
//     cout << "Enter member email: ";
//     getline(cin, member_email);

//     // Create Member object
//     Member member(member_id, member_name, member_address, member_phone, member_email);

//     // Read loan details from user input
//     cout << "Enter loan ID: ";
//     cin >> loan_id;
//     cout << "Enter loan amount: ";
//     cin >> loan_amount;
//     cout << "Enter interest rate: ";
//     cin >> interest_rate;
//     cout << "Enter repayment period: ";
//     cin >> repayment_period;

//     // Create Loan object
//     Loan loan(loan_id, loan_amount, interest_rate, repayment_period, member);

//     // Read deposit details from user input
//     cout << "Enter deposit ID: ";
//     cin >> deposit_id;
//     cout << "Enter deposit amount: ";
//     cin >> deposit_amount;
//     cout << "Enter deposit date: ";
//     cin.ignore();
//     getline(cin, deposit_date);

//     // Create Deposit object
//     Deposit deposit(deposit_id, deposit_amount, member, deposit_date);

//     // Read account details from user input
//     cout << "Enter account ID: ";
//     cin >> account_id;
//     cout << "Enter account balance: ";
//     cin >> account_balance;

//     // Create Account object
//     Account account(account_id, account_balance, member);

//     // Add loan and deposit to account
//     account.add_loan(loan);
//     account.add_deposit(deposit);

//     // Print account balance and transactions
//     cout << "Account balance: " << account.get_balance() << endl;
//     account.print_transactions();

//     return 0;
// }


