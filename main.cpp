  // A calculator that can
  // perform basic functions via pass by reference
  // functions
 
 #include <iostream>

  using namespace std;
  
  // Desc: adds the input
  // Pre: Nothing 
  // Post: prints the new total
  void add(double& total, double operand);

  // Desc: subtracts the input
  // Pre: Nothing
  // Post: prints the new total
  void subtract(double& total, double operand);

  // Desc: multiplies the input
  // Pre: Nothing
  // Post: prints the new total
  void multiply(double& total, double operand);

  // Desc: divides the input
  // Pre: The number cannot be 0
  // Post: prints the new total
  void divide(double& total, double operand);

  // Desc: Shows last operation performed
  // Pre: Nothing
  // Post: Prints the last operation performed
  void print_last_operation(char& last_op);

  // Desc: Clears the input
  // Pre: nothing
  // Post: Sets the variable 'total' to 0.0
  void clear(double& total, char& last_op);

  // Desc: Stops the loop, displays
  // the total, and exits the program
  // Pre: nothing
  // Post: Prints the value of 'total' and exits
  void exit(double total);

  int main() {
    double total = 0.0;
    char last_op = '\0';
    char choice;
    double operand;

    cout << "Choose an operation: " << endl; // Displays calculator menu 
    cout << "a - add" << endl;
    cout << "s - subtract" << endl;
    cout << "m - multiply" << endl;
    cout << "d - divide" << endl;
    cout << "p - print last operation performed" << endl;
    cout << "c - clear" << endl;
    cout << "x - exit" << endl;
    cout << "'operation number' format please" << endl;
    do {
        cout << "Current total: " << total << endl;
        cout << "Enter the choice and operand: ";
        cin >> choice;
        if (choice != 'c' && choice != 'x' && choice != 'p') { //Operand isn't needed for these operations
            cin >> operand;
        }

        switch (choice) { // Switch-case statements
            case 'a':
                add(total, operand);
                last_op = 'a';
                break;
            case 's':
                subtract(total, operand);
                last_op = 's';
                break;
            case 'm':
                multiply(total, operand);
                last_op = 'm';
                break;
            case 'd':
                divide(total, operand);
                last_op = 'd';
                break;
            case 'p':
                print_last_operation(last_op);
                break;
            case 'c':
                clear(total, last_op);
                break;
            case 'x':
                exit(total);
                return 0;
            default:
                cout << "Invalid choice." << endl; // If the 'operation number' format isn't followed
        }
    } while (true);

    return 0;
  }

  void add(double& total, double operand) {
    total += operand;
  }

  void subtract(double& total, double operand) {
    total -= operand;
  }

  void multiply(double& total, double operand) {
    total *= operand;
  }

  void divide(double& total, double operand) {
    if (operand != 0) { // Can't divide by 0
        total /= operand;
    } else {
        cout << "Error: division by zero." << endl;
    }
  }

  void print_last_operation(char& last_op) {
    if (last_op == '\0') {
        cout << "No operations performed yet." << endl;
    } else {
        cout << "Last operation performed: " << last_op << endl;
    }
  }

  void clear(double& total, char& last_op) {
    total = 0.0;
    last_op = '\0';
    cout << "Total and last operation cleared." << endl;
  }

  void exit(double total) {
    cout << "Total: " << total << endl;
    cout << "Exiting..." << endl;
  }
