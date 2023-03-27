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

// int main() {
   
//     Member member1(1, "Ronald Smiles", "Westlands, Nairobi", "079233393", "DoubleR@gmail.com");
//     Member member2(2, "Marion Ythera", "Chiromo, Nairobi", "0714111439", "MarioY12@gmail.com");
//     Member member3(3, "Job Newton", "Chiromo, Nairobi", "0798932947", "JobNewton@gmail.com");

//     Loan loan1(1, 5000000.0, 0.05, 12, member1);
//     Loan loan2(2, 1000000.0, 0.06, 24, member2);
//     Loan loan3(3, 1000000.0, 0.06, 24, member3);
    
//     Deposit deposit1(1, 1000.0, member1, "2023-01-01");
//     Deposit deposit2(2, 2000.0, member2, "2023-03-24");
//     Deposit deposit3(3, 2000.0, member3, "2023-03-22");
    
   
//     Account account1(1, 0, member1);
//     Account account2(2, 0, member2);
//     Account account3(3, 0, member3);
    
   
//     account1.add_loan(loan1);
//     account1.add_deposit(deposit1);
    
    
//     account2.add_loan(loan2);
//     account2.add_deposit(deposit2);

//     account3.add_loan(loan3);
//     account3.add_deposit(deposit3);
    
  
//      cout << "Account 1 balance: " << account1.get_balance() << endl;
//      cout << "Account 2 balance: " << account2.get_balance() << endl;
//      cout << "Account 3 balance: " << account3.get_balance() << endl;
//     return 0;
// }

int main() {
//     int member_id, loan_id, deposit_id, account_id;
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


switch (choice) {
    case 1:
        cout << "Enter account ID: ";
        cin >> account_id;
        cout << "Enter deposit amount: ";
        cin >> amount;
        cout << "Enter member ID: ";
        cin >> member_id;
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;
        if (find_member(members, member_id) == NULL) {
            cout << "Invalid member ID. Deposit not added." << endl;
        } else if (find_account(accounts, account_id) == NULL) {
            cout << "Invalid account ID. Deposit not added." << endl;
        } else {
            Member depositor = *find_member(members, member_id);
            Deposit deposit(deposit_counter++, amount, depositor, date);
            Account* account = find_account(accounts, account_id);
            account->add_deposit(deposit);
            cout << "Deposit added to account." << endl;
        }
        break;
    case 2:
        cout << "Enter account ID: ";
        cin >> account_id;
        cout << "Enter loan ID: ";
        cin >> loan_id;
        if (find_account(accounts, account_id) == NULL) {
            cout << "Invalid account ID. Loan not added." << endl;
        } else {
            Account* account = find_account(accounts, account_id);
            if (account->get_balance() < loan_amount) {
                cout << "Insufficient funds. Loan not added." << endl;
            } else {
                cout << "Enter loan amount: ";
                cin >> loan_amount;
                cout << "Enter interest rate: ";
                cin >> interest_rate;
                cout << "Enter repayment period: ";
                cin >> repayment_period;
                cout << "Enter member ID: ";
                cin >> member_id;
                if (find_member(members, member_id) == NULL) {
                    cout << "Invalid member ID. Loan not added." << endl;
                } else {
                    Member borrower = *find_member(members, member_id);
                    Loan loan(loan_id, loan_amount, interest_rate, repayment_period, borrower);
                    account->add_loan(loan);
                    cout << "Loan added to account." << endl;
                }
            }
        }
        break;
    case 3:
        cout << "Enter account ID: ";
        cin >> account_id;
        Account* account = find_account(accounts, account_id);
        if (account == NULL) {
            cout << "Invalid account ID. Transactions not printed." << endl;
        } else {
            account->print_transactions();
        }
        break;
    case 4:
        return 0;
    default:
        cout << "Invalid choice. Try again." << endl;
        break;
    }
}
return 0;
