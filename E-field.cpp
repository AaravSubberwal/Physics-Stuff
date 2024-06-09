/********************************************************************************************
Program to simulate the Electric field around around any number of electric charges placed
anywhere using terminal colors kind of like a thermal camera

Author: Aarav Subberwal
date: 3/06/24

Lesss goo!

For the output to make even remote sense some specific terminal settings are required. So far
I've only tested the project in vscode.
--> Open the setting in terminal File>Preferences>settings>terminal 
--> Font size = 6 scroll to find them 
--> Line spacing = 0 --> Line height = 1.2
*********************************************************************************************/
#include <iostream>
#include <cmath>        //Preprocessors blah blah
#include <vector>
#include <iomanip>

const unsigned short int Pixheight = 70, Pixwidth = 100;    //some global variables
double k = 10000; // 8.9 * pow(10, 9);          

class Charge
{
public:
    double charge;          //Charge class
    double x, y;
};
class screen_point
{
public:            //represents a point where E strength is calculated and displayed
    double X, Y;
    double E_FieldStrength;
};

int main()
{
    std::vector<Charge> charge_list;
    Charge Placeholder_Q;   //Needed variable defining
    int charge_count = 0;
    screen_point screen[Pixwidth][Pixheight];


    std::cout << "Enter how many charges do you want: ";
    std::cin >> charge_count;

    for (int i = 1; i < charge_count + 1; i++)  //input data for charges
    {
        std::cout << "\nEnter the electric charge in coulums for Q" << i << ":";
        std::cin >> Placeholder_Q.charge;
        std::cout << "Enter the x for Q" << i << ": ";
        std::cin >> Placeholder_Q.x;
        std::cout << "Enter the y for Q" << i << ": ";
        std::cin >> Placeholder_Q.y;
        charge_list.push_back(Placeholder_Q);
    }

    std::cout << "\n";
    for (int j = 0; j < Pixheight; j++) //dual for loops to iterate thro the screen
    {
        for (int i = 0; i < Pixwidth; i++)
        {
            screen[i][j].E_FieldStrength = 0;
            for (auto &q : charge_list)
            {                                       //PHYSICS LETSS GOO
                screen[i][j].E_FieldStrength += k * q.charge / (pow(abs(i - q.x - Pixwidth / 2), 2) + pow(abs(j - q.y - Pixheight / 2), 2));
            }
            if (screen[i][j].E_FieldStrength < 3)   //color acc to strength
            {
                std::cout << "\033[92m # "; // bright green
            }
            else if (screen[i][j].E_FieldStrength < 10 && screen[i][j].E_FieldStrength > 3)
            {
                std::cout << "\033[93m # "; // bright yellow
            }
            else if (screen[i][j].E_FieldStrength < 20 && screen[i][j].E_FieldStrength > 10)
            {

                std::cout << "\033[35m # "; // magenta
            }
            else
            {

                std::cout << "\033[31m # "; // red
            }
        }

        std::cout << "\n";
    }
    return 0;
}