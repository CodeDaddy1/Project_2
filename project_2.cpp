#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

// Variable to store PI constant.
float const PI = 3.14;

// Function to validate input as an integer.
bool isInteger(const std::string& input) {
	std::istringstream iss(input);
	int value; 
	return iss >> value && iss.eof();
}

// Function to validate input as a double.
bool isDouble(const std::string& input) {
	std::istringstream iss(input);
	double value; 
	return iss >> value && iss.eof();
}

// Function that prompts the menu.
void promptMenu(){

std::cout << "Please select from the following: " << std::endl;
std::cout << "1: Calculate the area of a circle " << std::endl;
std::cout << "2: Calculate the tax based on item price and tax rate " << std::endl;
std::cout << "3: Convert pound to kilogram " << std::endl;
std::cout << "4: Quit program " << std::endl;
std::cout << std::endl;
}

// Function that calculates the area of a circle and output name of user and area.
void calculateCircleArea(){
    std::string name;
    double radius;

    std::cout << std::fixed << std::setprecision(2) << std::endl;
    std::cout << "What is your name? " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << std::endl;

    std::cout << "What is the radius of the circle? " << std::endl; 
    std::cin >> radius;

    std::cout << std::endl;
    double area = (radius * radius) * PI;

    std::cout << "Your name is " << name << "." << std::endl;
    std::cout << std::endl;
    std::cout << "Aread of the circle is " << area << "." << std::endl;
    std::cout << std::endl;

}

// Function that calculates tax of an item, output name and tax amount.
void calculateTax(){
    std::string name;
    std::string itemPriceStr;
    std::string taxRateStr;
    double itemPrice;
    double taxRate;

    std::cout << std::fixed << std::setprecision(2) << std::endl;
    std::cout << "What is your name? " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);

    do{

    std::cout << "What is the price of the item? " << std::endl;
    std::getline(std::cin , itemPriceStr);

        if(isDouble(itemPriceStr)){
            itemPrice = std::stod(itemPriceStr);
            if(itemPrice > 0){
                break;
            }
        }
        else {
                std::cout << "Invalid choice please enter a dollar amount value. " << std::endl;
            }

    }while(true);
    std::cout << std::endl;

    do{
    std::cout << "What is the tax rate? " << std::endl;
    std::getline(std::cin , taxRateStr);

        if(isDouble(taxRateStr)){
            taxRate = std::stod(taxRateStr);
            if(taxRate > 0){
                break;
            }
        }
        else {
                std::cout << "Invalid choice please enter a tax amount value. " << std::endl;
            }
    }while(true);
    std::cout << std::endl;
    double taxAmount = (itemPrice * taxRate) / 100;

    std::cout << "Your name is " << name << "." << std::endl;
    std::cout << std::endl;
    std::cout << "Your tax amount is $" << taxAmount << std::endl;
    std::cout << std::endl;
}

// Function that converts user's weight from pounds to kilograms.
void poundToKilogram(){
    std::string name;
    std::string userPoundsStr;
    double userPounds;

    std::cout << std::fixed << std::setprecision(2) << std::endl;
    std::cout << "What is your name ?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    do{
    std::cout << "What is your weight in pounds? " << std::endl;
    std::getline(std::cin, userPoundsStr);
        if(isDouble(userPoundsStr)){
            userPounds = std::stod(userPoundsStr);
            if(userPounds >= 0){
                break;
            }
        }
        else {
            std::cout << "Invalid input, please enter a numerical value representing weight in pounds. " << std::endl;
        }
    }while(true);    
    std::cout << std::endl;
    double userKilograms = userPounds / 2.2046;

    std::cout << "Your name is " << name << "." << std::endl;
    std::cout << std::endl;
    std::cout << "Your weight in kilograms is " << userKilograms << "kg " << std::endl;
    std::cout << std::endl;

}
// Function that terminates the program
int terminateProgram(){
    return 0;
}


int main(){

std::string repeatProgram;
int programChoice;
std::string programChoiceStr;

// Loops until true, validating the input of the user to the menu choices 1-4.
do{
promptMenu();

std::getline(std::cin, programChoiceStr);
        
		if (isInteger(programChoiceStr)) {
			programChoice = std::stoi(programChoiceStr);
			if (programChoice >= 1 && programChoice <= 4) {
				break;
            }
        }
else {
    std::cout << "You have chosen an invalid selection, please try again. " << std::endl;
    
}

}while(true);

// Switch representing the menu for the user's selection.
    switch(programChoice){
    
        case 1:
        calculateCircleArea();
        break;

        case 2:
        calculateTax();
        break;

        case 3:
        poundToKilogram();
        break;

        case 4:
        terminateProgram();

        break;

        default: std::cout << "Invalid choice, please try again." << std::endl;
    }   

// Loop allowing the user to be prompted to repeat the program or to end.
do{
std::cout << "Would you like to repeat the program? " << std::endl;
std::cout << "y or Y to continue. " << std::endl;
std::cout << std::endl;

std::cin >> repeatProgram;

    if(repeatProgram == "y" || repeatProgram == "Y"){
        promptMenu();

        std::cin >> programChoice;

    switch(programChoice){
    
        case 1:
       calculateCircleArea();
        break;

        case 2:
        calculateTax();
        break;

        case 3:
        poundToKilogram();
        break;

        case 4:
        terminateProgram();

        break;

        default: std::cout << "Invalid choice, please try again." << std::endl;
    }   

    }
    else if(repeatProgram == "n" || repeatProgram == "N"){
        std::cout << "You have chosen to end the program. Goodbye! " << std::endl;
        return 0;
    }
    else {
        std::cout << "Invalid choice, please try again. " << std:: endl;
        std::cout << std::endl;
    }
}while(true);
    return 0;
}

