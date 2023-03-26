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
    }T
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
    
  
     cout << "Account 1 balance: " << account1.get_balance() << endl;
     cout << "Account 2 balance: " << account2.get_balance() << endl;
     cout << "Account 3 balance: " << account3.get_balance() << endl;
    return 0;
}
