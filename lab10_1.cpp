#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan, interest, pay;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interest;
	cout << "Enter amount you can pay per year: ";
	cin >> pay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 
	int i = 1;
	double prev_bal = loan, new_bal, t_interest, total;

	t_interest = (interest/100) * prev_bal;
	total = prev_bal + t_interest;
	if(pay > total){
		new_bal = total - total;
		cout << setw(13) << left << i; 
		cout << setw(13) << left << prev_bal;
		cout << setw(13) << left << t_interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << total;
		cout << setw(13) << left << new_bal;
	}

	else{
		while(new_bal != 0){

			t_interest = (interest/100) * prev_bal;
			total = prev_bal + t_interest;
			new_bal = total - pay;

			if(total >= pay){
				cout << setw(13) << left << i; 
				cout << setw(13) << left << prev_bal;
				cout << setw(13) << left << t_interest;
				cout << setw(13) << left << total;
				cout << setw(13) << left << pay;
				cout << setw(13) << left << new_bal;
			}
			else{
				new_bal = 0;
				cout << setw(13) << left << i; 
				cout << setw(13) << left << prev_bal;
				cout << setw(13) << left << t_interest;
				cout << setw(13) << left << total;
				cout << setw(13) << left << total;
				cout << setw(13) << left << new_bal;
			}
		prev_bal = new_bal;

		i++;
		cout << "\n";	
		}
	}
	
	return 0;
}
