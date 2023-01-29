#include <iostream>
#include <vector>
#include <math.h>
#include <limits>


using namespace std;

vector<double> values;
unsigned int numberValues; 

/**
 Calculate the mean of a vector of floating point numbers
 **/
float mean(vector<float> values) {
    float sum = 0;
    float mean = 0;

        // using formula from lab 2 to get mean
         for (int i = 0; i < numberValues; i++) {
         sum+=values[i];
     }
    // returning the sum devided by number entered by user. 
     return sum/numberValues;
}

/**
 Calculate the standard deviation from a vector of floating point numbers
 **/
float standard_deviation(vector<float> values) {
    float varin = 0;
    float stanDev;

    // setting variable means to mean function. Can use "means" in standard formula for the mean. 
    float means = mean(values);

        // using formula from lab 2 to get standard deviation
         for (int x = 0; x < numberValues; x++) {
         varin += (values[x] - means) * (values[x] - means);
 
     }
     varin /= (numberValues - 1);
     // square root of variance is stnadard deviation. We are returning that. 
     return sqrt(varin);
}

/**
 Main
 **/
int main()
{
    /**
     Prompt the user and get the number of values to enter
     **/

     // wrapping loop around prompting the user. Will check if the right input is entered.    
     while (true) {
        cout << "Enter number of values" << endl;
        if (cin >> numberValues) {
            break;
        } else {
            cout << "ERROR: please enter a valid number \n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
     }
    
    /**
     Get the values from the user
     **/
     // allows us to use the above functions
     vector<float> values;
     // using code from lab2 to get values from user. Wrapped in loop to check if correct input is entered. 
     for (unsigned int count = 0; count < numberValues; count++) {
         double value;
         while (true) {
         cout << "Enter value " << count << ":" << " ";
            if (cin >> value) {
            values.push_back(value);
            break;
            } else {
                cout << "ERROR: please enter a valid number \n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
         }
    }
    
    /**
     Display the mean and standard deviation
     **/
     // display mean
     cout << "The mean is: " << mean(values) << "\n";
     // display standard deviation
     cout << "The standard deviation is: " << standard_deviation(values) << "\n";
    
    return 0;
}
