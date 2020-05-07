//Noorain Baig
//Project 1 
//CSCI 2270/Data Structures
//Section 310

#include <iostream>
using namespace std;


bool isitDigit(string name) {
  if(name[0] == '1' || name[0] == '2' || name[0] == '3' || name[0] == '4' || name[0] == '5' || name[0] == '6' || name[0] == '7' || name[0] == '8' || name[0] == '9')
    return false;
  else{
    return true;
  }
}


double split(string str, char c, string array_of_string[], int length){ //this is a split function we wrote in 1300
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c; 
    for (int i = 0; i < str.length(); i++) 
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue; {
            j++;
            word = "";
        	}
        } 
        else {
            word = word + str[i];
            array_of_string[j] = word;
        }
    }
    return j;
}  

string Menu() {
    string input;
    cout << "======" << "+MAIN MENU+" << "======\n";
    cout << "1. Print Vertices\n";
    cout << "2. Find districts \n";
    cout << "3. Find shortest unweighted path \n";
    cout << "4. Find shortest weighted path \n";
    cout << "5. Zombie infection! \n";
    cout << "6. Extra Credit Option \n";
    cout << "7. Quit\n"; 
    cout << "8. Clear Previous\n";
    cout << "Which option would you like to choose?" << endl;
    getline(cin, input);
    return input;
}


