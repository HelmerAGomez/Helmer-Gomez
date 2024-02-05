/*
 Helmer Gomez                     CS 141        

 This program will give the user the option to display original art or be
 given the chance to display a hot air balloon of the size they choose.    

*/


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int size;
    int loopCount = 0; // used the same variable for all of my loops
                       //   assignning a new value when being used in a
                       //   different loop
    int userChoice;

    cout << "Program 1: Hot Air Balloons" << endl;
    cout << "Which option would you like?" << endl;
    cout << "  1. Display original graphic" << endl;
    cout << "  2. Display Hot Air Balloon" << endl;
    cout << "Your choice: ";

    cin >> userChoice;


    switch (userChoice) {
        case 2: 
            cout << "What is the size of the hot air balloon? ";
            cin >> size;
            cout << endl;
            
            // outputing the top of the balloon
            //     ex: size = 2, 
            //               12345678
            //    output:         ____
            //  the total lenght outputed will be 6. In total it would be
            //    8 including the "\" at the end
            //    the top would bee size * 2 not including the begining '/'
            //       and ending '\'
            while (loopCount <= size){

                if(loopCount == 0){
                    cout << setw(size) << " ";
                    cout << setfill('_') << setw((2 * size)) << '_' << endl;
                }
                else {
                    // Since we are starting from the center and going to
                    //   the ends I add size and subtract loopcount which
                    //   is incremented every iteration so I get the cone look
                    cout << setfill(' ');
                    cout << setw((size - loopCount) + 1) << '/';
                    // setw(2* size) adds the center spaces and 
                    //  (2 * loopcount) accounts for the subtraction from
                    //  the first setw() that adds the '/'
                    cout << setw((2 * size) + (2 * loopCount) - 1) << '\\' << endl;
                }
                loopCount++;
            }

            // Outputing the middle section of the balloon
            //     ex: size = 2,
            //                12345678
            //     output:       |      |
            //                   |      |
            // total of 8 lenght including the '|'. Having size * 4 will
            // have the toal lenght

            loopCount = 0; // set back to 0
            // if size is less than 5 UIC wont be included inside.
            if (size < 5) {
                while (loopCount < size){
                    // subtract one because of the first '|' is apart of the total
                    
                    cout << '|' << setw(4 * size - 1) << '|' << endl;
                    loopCount++;
                }
            }
            else {
                // This else statement outputs the "UIC" in the middle
                while (loopCount < size){ 
                    // subtracted 2 because of I and C. For "UIC" to be in
                    //   the middle i would need to subtract the other 2 letters
                    // size - (size / 2)) is basically roudning up (size /2)
                    if (((size - (size / 2)) - 2) == loopCount) {
                        // Outputing the middle section of the balloon
                        //     ex: size = 6,          
                        //                123456789012345678901234
                        //     output:       |                      |
                        //                   |          U           |
                        // total lenght of 24.
                        // To output the 'U' and the other letters I used 
                        //   setw(size + size - 1) subtracting one because
                        //   of the first '|' which ouputs the letter in
                        //   the middle 
                        cout << '|' << setw(size + size - 1) << 'U';
                        cout << setw(size + size) << '|' << endl;

                        cout << '|' << setw(size + size - 1) << 'I';
                        cout << setw(size + size) << '|' << endl;

                        cout << '|' << setw(size + size - 1) << 'C';
                        cout << setw(size + size) << '|' << endl;

                        loopCount += 3;
                    }
                    else {
                        // This outputs the remaining middle outputs
                        //   not include the "UIC" letters.
                        cout << '|' << setw(4 * size - 1) << '|' << endl;
                        loopCount++;
                        }
                }
            }
    

            loopCount = 0; // set back to 0

            while (loopCount <= size){
                // Similar to the loop when outputing the top instead its
                //   the opposite now starting with the sides '\' and '/'
                if(loopCount == size){
                    cout << setw(size) << " ";
                    cout << setfill('=') << setw((2 * size)) << '=' << endl;
                    cout << setfill(' ');
                    loopCount++;
                }
                else {
                    // Since loopcount is now 0 when when first outputing
                    //   the sides. We are now going from the outter to
                    //   the middle.
                    //
                    loopCount++;
                    // setw(loopCount) incrementing loopCount we are
                    //   adding whitespace every loop which will have the
                    //   output of  \ / until it reaches the middle
                    cout << setw(loopCount) << '\\';
                    // since we are now going from the sides to the middle
                    //  setw(2 * size) adds the center and 
                    //  (size - loopCount) * 2 accounts for the increment
                    //  of one by the first stew(loopCount)
                    cout << setw((2 * size ) + (((size - loopCount) * 2)) + 1) << "/" << endl;
                    
                }
            }

            // This is the output for the connection of the basket to the
            //   balloon. 
            // setw((size + size - 1) calculates the center of
            //   the of the balloon subtracting one beacuse of the four
            cout << setw(size + size - 1) << '\\' << '|' << '|' << '/' << endl;
            // adds the second part bu this time not subtracting one
            cout << setw(size + size) << '|' << '|' << endl;

            loopCount = 0; // set back to 0

            while(loopCount < size){
                // outputs the 2 * size by size rectangle
                cout << setw(size + 1) << '#';
                cout << setfill('#') << setw((2 * size) - 1) << '#' << endl;
                cout << setfill(' ');
                loopCount++;
            }
            break;
        case 1:
            loopCount = 0; // set back to 0

            cout << endl;
            cout << "                   / \\\n";
            cout << "                  /   \\\n";
            cout << "                 /     \\\n";
            cout << "                /       \\\n";
            cout << "               /         \\\n";
            // outputs the middle structure of the house three times.
            while (loopCount < 3) {
                cout << "===++===   =++=============++=\n";
                cout << "   ||       || |+|  |  |+| ||\n";
                loopCount++;
            }
            cout << "   ||      =++=============++=\n";
            cout << "   ||       ||     |||     ||\n";
            break;
    }
    return 0;
}
