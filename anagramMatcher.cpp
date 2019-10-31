#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <stdio.h>


//the function takes two strings and returns true or false if the two are anagrams of each other
bool anagramMatcher(std::string word1, std::string word2)
{
    //sorting the words by their askii values so it is easier to compare the two of them
    std::sort(word1.begin(),word1.end());
    std::sort(word2.begin(),word2.end());
    //comparing the two words to see if the sorted string match and returning either true or false
    if (word1==word2){
        return true;
    }else{
        return false;
    }
}


//this function checks for correct input, this returns false is the string is not made up of only letters
bool inputChecker(std::string str){
    //iterating through the string
    for(int j=0;j<str.length();j++){
        //if any of the characters are not an alpha character return false
        if(std::isalpha(str[j]) == false){
            return false;
        }
    }
    //return true if all characters are alpha
    return true;

}


//function to turn every character in a string to lower case
std::string toLower(std::string str){
    //iterating through every character of a string
    for(int i=0;i<str.length();i++){
        //turning every character into a lowercase version of itself
        str[i]=std::tolower(str[i]);
    }
    //returning the new lowercase string
    return str;
}

//main is the main function that  runs, to start the program
int main()
{
    //this is declaring the string for if the user wants to play again, it is the contition for the do/while loop below to keep looping
    std::string playAgain;


    do{

        //declaring a boolean and making it false, this is for looping through the do/while loop below and it needs to become true before the loop is broken
        bool passCheck = false;

        //this is getting the input for two words
        std::string input1;
        std::string input2;

        //a welcome message for the user
        std::cout<<"Welcome to the anagram matcher!\n";


        //the do while loop is to make sure valid input is entered but to make sure it runs at least once and it will keep running untill valid input is entered
        do{
            //asking the user for input
            std::cout<<"please enter the two words you wish to compare: (any extra words beyond 2 are ignored)\n";


            //getting the two inputs from the user and saving them to variables input1 and input2
            std::cin>> input1;
            std::cin>>input2;


            //this calls the inputChecker function for both of the words the user input and checking if either is false
            //this is because the program will only take two strings of alpha characters only, anything else asks the user for a different input
            if(inputChecker(input1)==false||inputChecker(input2)==false){
                std::cout<<"\nplease enter valid strings, no numbers/special charaters or spaces";
            } else{
                //sets the passCheck boolean to true, this will stop the do/while loop if the input is valid
                passCheck = true;
            }


            //this is included for the user, it makes the program more visible and easier to read as opposed to one big block of text
            std::cout<<"----------------------------\n";


        }while (passCheck == false); //if the input is invalid, repeat the loop


        //calling the toLower function to make every character in the strings into lowercase
        input1 = toLower(input1);
        input2 = toLower(input2);


        //calling the anagramMatcher function and if it returns true/false running the correct output 
        if (anagramMatcher(input1,input2)==true){
            std::cout<<"the words "<<input1<<" and "<<input2<<" are anagrams of each other";
        } else{
            std::cout<<"the words "<<input1<<" and "<<input2<<" are NOT anagrams of each other";
        }

        //this is for the user, it just makes the whole game a little easier to read from their point of veiw, it stops the terminal from becoming a block of text
        std::cout<<"\n----------------------------";

        //this is for looping the game for if the user wants to keep playing
        //entering "Y" or "y" will loop the game while anything else will cause the program to end
        std::cout<<"\nWould you like to play again? (Y to confirm or any thing else to end): ";
        std::cin>>playAgain;


        //this is another part to split up the block of text, makes the program more readable for the user
        std::cout<<"----------------------------\n";


        //the condition for the do/while loop, this allows the user the option to play multiple times or just to exit
    } while (playAgain == "y"||playAgain == "Y");


    //end of the program
    return 0;
}