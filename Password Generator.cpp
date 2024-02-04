#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random password
std::string generatePassword() {
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string password;
    int length = 10 + rand() % 7; // Password length should be between 10 and 16 characters

    // Generate a random password
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.length()];
    }

    return password;
}

// Function to check if a given password is valid
bool isValidPassword(const std::string& password) {
     // Check length
    if (password.length() < 10 || password.length() > 16) return false;

    bool hasDigit = false, hasUpper = false, hasLower = false;
    // Check for each character type in the password
    for (char ch : password) {
        if (isdigit(ch)) hasDigit = true;
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
    }

     // Password is valid if it contains all character types
    return hasDigit && hasUpper && hasLower;
}

void printPasswordDetails(const std::string& password) {
    std::cout << "Password: " << password << "\n";
    std::cout << "Length: " << password.length() << "\n";

    bool hasDigit = false, hasUpper = false, hasLower = false;
    for (char ch : password) {
        if (isdigit(ch)) hasDigit = true;
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
    }

    // Print whether password contains digit, uppercase and lowercase letters
    std::cout << "Contains Digit: " << (hasDigit ? "Yes" : "No") << "\n";
    std::cout << "Contains Uppercase Letter: " << (hasUpper ? "Yes" : "No") << "\n";
    std::cout << "Contains Lowercase Letter: " << (hasLower ? "Yes" : "No") << "\n";
}

int main() {
    srand(time(0)); // Initialize random seed

    // User interface for password generator and validator
    std::cout << "Password Generator and Validator\n";
    std::cout << "1. Generate Password\n";
    std::cout << "2. Verify Your Password\n";
    std::cout << "Enter choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        // Generate and print a new password
        std::string password = generatePassword();
        printPasswordDetails(password);
    } else if (choice == 2) {
        // Validate a user-entered password
        std::string userPassword;
        std::cout << "Enter your password: ";
        std::cin >> userPassword;

        if (isValidPassword(userPassword)) {
            std::cout << "Valid Password!" << std::endl;
            printPasswordDetails(userPassword);
        } else {
            std::cout << "Invalid Password. Does not meet the criteria." << std::endl;
        }
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}


