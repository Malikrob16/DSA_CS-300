// Malik Robinson
// 02/20/2024
// This program will give users the choice to search for course and its information with it.

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int Request_user_file(string user_File) {

    // Create variable for file to be opened.
    fstream ABCU_course;

    // Request user file.
    std::cout << "Please enter file name. \n";

    std::cin >> user_File;

    // loop till user file matches course file.
    while (user_File != "ABCU_Course_information") {

        std::cout << "File with that name was not found. Please re-enter file name. \n";

        std::cin >> user_File;

        std::cin.clear();

    }

    if (user_File == "ABCU_Course_information") {

        // Open file.
        ABCU_course.open("ABCU_Course_information.txt", ios::in);

    }

    return 0;
}

int Display_Courses() {

    fstream ABCU_course;

    string line;

    if (ABCU_course.is_open()) {

        // Get lines from file till at end of file.
        while (std::getline(ABCU_course, line)) {

            std::cout << line << " \n";

        }

        std::cout << " \n";

        // If end of file is reached display end message.
        if (ABCU_course.eof()) {

            std::cout << "End of file reached. \n";

        }

    }
    return 0;
}

int Display_Menu() {

    //Display menu and user options.
    std::cout << "Welcome to the course planner. \n";

    //Display whitespace
    std::cout << " \n";

    std::cout << "Please Select one of the four options. Format: Enter number of option. \n";

    std::cout << " \n";

    std::cout << "Option 1: Load Data Structure. \n";
    std::cout << "Option 2: Print Course List. \n";
    std::cout << "Option 3: Print Course. \n";
    std::cout << "Option 9: Exit. \n";

    return 0;
}

int main()
{
    // Create variable for file to be opened.
    fstream ABCU_course;

    // Create variable for lines in file.
    string line;

    // Create variable to for user's file input.
    string user_File;

    // Create variable for user's course input.
    string user_Search;

    // Create variable for user's choice.
    int user_Choice;

    // Call display menu method.
    Display_Menu();

    // Request user choice.
    std::cin >> user_Choice;

    // Loop till user choice is equal to one of the options.
    while (user_Choice != 1 && user_Choice != 2 && user_Choice != 3 && user_Choice != 9) {

        // Display invalid option message and request input again.
        std::cout << user_Choice << " is an invalid option entered. Please enter valid option. \n";

        std::cin >> user_Choice;

        std::cin.clear();

    }

    // Loop till user exits program.
    while (user_Choice != 9) {


            // Load data structure.
        if (user_Choice == 1) {
            //FIXME Set up hashtable structure to load in file data.
            
            //Call method to request and check user file input.
            Request_user_file(user_File);

            // Open file.
            ABCU_course.open("ABCU_Course_information.txt", ios::in);
        }

            // Display course list from file.
        if (user_Choice == 2) {
            Display_Courses();

            if (ABCU_course.is_open()) {

                // Get lines from file till at end of file.
                while (std::getline(ABCU_course, line)) {

                    std::cout << line << " \n";

                }

                std::cout << " \n";

                // If end of file is reached display end message.
                if (ABCU_course.eof()) {

                    std::cout << "End of file reached. \n";

                }

            }
        }

        // request user course to find and display course with all information.
        if (user_Choice == 3) {

            // Request user's course to use in search.
            std::cout << "Please enter the Course number you are searching for. \n";

            std::cin >> user_Search;

            while (std::getline(ABCU_course, line)) {

                // if user search is equal to line searched display found message.
                if (user_Search == line) {


                    std::cout << line[0, 7] << " has been found. \n";

                    std::cout << line;

                }
                // Display user search not found message and request input again.
                else {

                    std::cout << user_Search << " was not found. \n";
                }

                std::cout << "What other course would you like to search for? \n";
                std::cin >> user_Search;
            }
        }
            // Exit program.
        if (user_Choice == 9) {

            // Close course file.
            std::cout << "Now closing ABCU_Course_information \n";
            ABCU_course.close();

            // Display whitespace.
            std::cout << " \n";

            // Display exit message and end program.
            std::cout << "Now exiting program thank you. \n";
            break;
        }
        

        // Display whitespace.
        std::cout << " \n";

        // Loop to start of menu and request option input.
        Display_Menu();

        std::cin >> user_Choice;

    }
}
