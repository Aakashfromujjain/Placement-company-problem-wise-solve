#include
#include

using namespace std;

int main() {
double amount;
cin >> amount;

if (amount < 0) {
cout << "Invalid Amount" << endl; // Assuming this error message based on common TCS patterns
} else {
double discount = 0;
if (amount < 1000) {
discount = 0.05;
} else if (amount <= 5000) {
discount = 0.10;
} else {
discount = 0.15;
}

double discountAmount = amount * discount;
double finalAmount = amount - discountAmount;

cout << fixed << setprecision(1) << finalAmount << endl;
}

return 0;
}
