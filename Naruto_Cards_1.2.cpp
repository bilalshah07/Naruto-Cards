#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <cmath>
using namespace std;

// DECLARATION OF ALL THE FUNCTIONS TO BE USED.

// Main Body Function
int  main_menu();

// Function to Print the Character List.
void char_list();

// Screen and Sound When You Exit the Game.
void bye();

// Screen If Match Was a Draw.
void draw();

// Winner Screen For Player 1.
void player1_wins();

// Winner Screen For Player 2.
void player2_wins();

// Function to Print Instructions.
void print_instructions();

// Function To get white spaces for each attack name to be printed.
void getspace (string attack);

// Function to Ask Players for their Choice of Cards.
int  get_character_demand(int choice, int& char1, int& char2);

// Function to choose who gets the First Turn.
void cointoss (string char_name1, string char_name2, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
               int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p );

// Function To Execute Player1's Attacks And Update Player2's HP.
void player1_attack (string char_name1, string char_name2, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
                     int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p);

//Function To Execute Player2's Attacks And Update Player1's HP.
void player2_attack (string char_name1, string char_name2, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
                     int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p);

// Function That Assigns Values To variables co-responding to Each Character.
void getdata (int& chara, int& charp, string& char_name, string& char_att1, string& char_att2, int& char_att1p, int& char_att2p);

// Function to Print The Cards.
void print_cards (string char_name1, string char_name2, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
                  int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p );

// Array Containing Character Names.
string chararr[] =
    {
        " Naruto Uzumaki  ",
        "  Sasuke Uchiha  ",
        " Kakashi Hatake  ",
        "  Itachi Uchiha  ",
        "   Hinata Huga   ",
        "  Madara Uchiha  ",
        "      Pain       ",
        "  Tsunade Senju  ",
        " Minato Namikaze ",
        "      Gaara      ",
        "   Orochimaru    ",
        "  Sakura Haruno  ",
        "   Obito Uchiha  ",
        "      Jiraya     ",
        "    Rock Lee     ",
        " Shikamaru Nara  ",
        "    Neji Huga    ",
        "     Diedara     ",
        "  Ino Yamanaka   ",
        " Hashirama Senju ",
        "     Sasori      ",
        "     TenTen      ",
        "      Konan      ",
        "     Temari      ",
        "      Haku       ",
        "Kisame Hoshigaki ",
        "Hiruzen Sarutobi ",
        "  Kiba Inuzuka   ",
        "  Shino Aburame  ",
        "      Hidan      ",
        "  Zabuza Momochi ",
        "     Kakuzu      ",
        " Tobirama Senju  ",
        "   Konohamaru    ",
        "   Mei Terumi    ",
        " Kabuto Yakushi  ",
        "    Suigetsu     ",
        " Choji Akimichi  ",
        " Asuma Sarutobi  ",
        "    Might Guy    ",
        "       Sai       ",
        "     Yamato      ",
        "      Danzo      ",
        "     Kankuro     ",
        "   Killer Bee    ",
        "      Darui      ",
        "      Oniki      ",
        "  Forth Raikage  ",
        "      Hanzo      ",
        "   Yugito Nii    ",
        "Yagura Karitishi ",
        "      Roshi      ",
        "       Han       ",
        "     Utakata     ",
        "       Fu        "
    };

// Array Containing HPs For Each Character.
int powers[] = {1300, 1250, 950, 1350, 620, 1310, 1000, 930, 1410, 790, 900, 750, 1050, 850, 740, 710, 800, 850, 560, 1460, 810, 530, 850, 800, 510, 900, 1130, 620,
                810, 830, 760, 920, 1320, 500, 930, 740, 960, 700, 780, 1140, 720, 810, 800, 730, 960, 670, 940, 980, 930, 800, 790, 870, 820, 830, 810};

// Main Body Function
int main()
{
    PlaySound("Shippuden.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);          // Sound Playing Command.
    system("COLOR e0");                                                         // CLear Screen Command.

    // Variables Declared.
    string char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2;
    int char1, char2, char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p, coin, choice;

    choice = main_menu();           // Function Called.

    system("cls");

    get_character_demand(choice, char1, char2);             // Function Called.
    if (choice == 3)
    {
        return 0;
    }
    getdata(char1, char1p, char1_name, char1_att1, char1_att2, char1_att1p, char1_att2p);               // Function Called.
    getdata(char2, char2p, char2_name, char2_att1, char2_att2, char2_att1p, char2_att2p);               // Function Called.

    system("cls");

    print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,                // Function Called.
                 char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );

    cointoss (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,                   // Function Called.
              char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p);

}


// Function To get white spaces for each attack name to be printed.
void getspace(string attack)
{
    string space = "", additional_space = " ";
    int a = attack.length();

    for (a; a<17; a++)
    {
        space += additional_space;
    }

    cout << space;
}

// Function to print the Main Menu of the game and input First Choice.
int main_menu()
{
    int choice;
    cout << "###################################################################                                               \n";
    cout << "#                                                                 #                                               \n";
    cout << "#   ||\\    || |||||||| ||||||  ||    || |||||||||| ||||||||  ||   #                                              \n";
    cout << "#   ||\\\\   || ||    || ||   || ||    ||     ||     ||    ||  ||   #                                             \n";
    cout << "#   || \\\\  || ||____|| ||   || ||    ||     ||     ||    ||  ||   #                                //////////   \n";
    cout << "#   ||  \\\\ || ||----|| ||||||  ||    ||     ||     ||    ||  ||   #    ///// ////// /////  ///// //             \n";
    cout << "#   ||   \\\\|| ||    || ||  ||  ||    ||     ||     ||    ||       #   //    //__// //__// //  // //////         \n";
    cout << "#   ||    \\\\| ||    || ||   || ||||||||     ||     ||||||||  ||   #  ///// //  // //  \\\\ /////        //      \n";
    cout << "#                                                                 #                       ////////////            \n";
    cout << "###################################################################\t\t\t\t\t V1.2                                    \n";
    cout << "\nEnter 1 : Start Game\nEnter 2 : Instructions\nEnter 3 : Exit\n";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 3)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Input. Try Again!" << endl;
        cin >> choice;
    }
    return choice;
}

// Function to Print the Character List.
void char_list()
{
    cout << "Please Choose a Character Each:\n";

    for (int i=0; i<55; i++)
    {
        if ((i+1)%3 == 0)
        {
            if (i<9)
            {
                cout << i+1 << "." << chararr[i] << "  " << powers[i] <<endl;
            }
            else
            {
                cout << i+1 << "." << chararr[i] << " " << powers[i] <<endl;
            }
        }
        else
        {
             if (i<9)
            {
                cout << i+1 << "." << chararr[i] << "  " << powers[i] << "\t";
            }
            else
            {
                cout << i+1 << "." << chararr[i] << " " << powers[i] << "\t";
            }
        }
    }

    cout << "\nEnter the Respective Number for the Character You Want to Choose OR Enter 56 For Random Assignment:\n";
}

// Function to Print The Cards.
void print_cards (string char_name1, string char_name2, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
                  int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p )
{
    cout << "     Player 1:                          Player 2:      " << endl;
    cout << " _________________                  _________________  " << endl;
    cout << "|                 |                |                 | " << endl;
    cout << "|" << char_name1 << "|\t\t   |" << char_name2 << "|\n";
    cout << "|                 |                |                 | " << endl;
    cout << "| HP:" << setw(12) << char1p << " |\t\t   | HP:" << setw(12) << char2p << " |\n";
    cout << "|                 |                |                 | " << endl;
    cout << "|-----------------|                |-----------------| " << endl;
    cout << "| Attacks         |                | Attacks         | " << endl;
    cout << "|                 |                |                 | " << endl;
    cout << "|Attack 1\t  |\t\t   |Attack 1\t     |" << endl;
    cout << "|" << char1_att1; getspace(char1_att1); cout << "|\t\t   |" << char2_att1; getspace(char2_att1); cout << "|" << endl;
    cout << "|                 |                |                 | " << endl;
    cout << "|Attack 2\t  |\t\t   |Attack 2\t     |" << endl;
    cout << "|" << char1_att2; getspace(char1_att2); cout << "|\t\t   |" << char2_att2; getspace(char2_att2); cout << "|" << endl;
    cout << "|_________________|                |_________________| \n" << endl;
}

// Function to choose who gets the First Turn.
void cointoss (string char1_name, string char2_name, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
               int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p )
{
    srand(time(0));
    int coin = rand()%2;

    cout << "\nCoin Tossed!\n";

    if (coin == 1)
    {
        cout << "Player 1 wins the Toss!";
        player1_attack (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,             //Function Called For Fist Attack.
                        char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
    }

    else
    {
        cout << "Player 2 wins the Toss!";
        player2_attack (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,             //Function Called For First Attack.
                        char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
    }

}

// Function to Ask Players for their Choice of Cards.
int get_character_demand(int choice, int& char1, int& char2)
{
    int continueit;
    if (choice == 1)
    {
        char_list();                //Function Called

        cout << "Player 1: ";
        cin  >>  char1;

        while (cin.fail() || char1 < 1 || char1 > 56)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid Input. Try Again!\nPlayer 1: ";
            cin >> char1;
        }

        if (char1 == 56)
        {
            srand(time(0));
            char1 = (rand()%55) + 1;
        }



        cout << "Player 2: ";
        cin  >>  char2;

        while (cin.fail() || char2 < 1 || char2 > 56)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid Input. Try Again!\nPlayer 2: ";
            cin >> char2;
        }

        if (char2 == 56)
        {
            srand(time(0));
            char2 = (rand()%55) + 1;
        }


    }
    else if (choice == 2)
    {
        print_instructions();
        cout << "Enter Any Key To Continue: ";
        cin >> continueit;
        system("cls");
        main();
    }
    else if (choice == 3)
    {
        bye();                  //Function Called
    }
    else
    {
        cout << "Invalid Input. Try Again!";
    }
}

// Function To Execute Player1's Attacks And Update Player2's HP.
void player1_attack (string char1_name, string char2_name, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
                     int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p)
{
    int attack, attackp;
    cout << "\nPlayer 1's Turn\nEnter The Number of Attack You Want To Do: ";
    cin  >> attack;
    while (cin.fail() || attack < 1 || attack > 2)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Input. Try Again!" << endl;
        cin >> attack;
    }

    //Assessing The Attack And Randomize Its Value A Bit.
    if (attack == 1)
    {
        attackp = char1_att1p;
        if(char1_att1p < 350)
        {
            char2p = char2p - (char1_att1p-(((rand()%60)/10)*10));
        }
        else
        {
            char2p = char2p - (char1_att1p-(((rand()%110)/10)*10));
        }
    }
    else if(attack == 2)
    {
        attackp = char1_att2p;
        if(char1_att2p < 350)
        {
            char2p = char2p - (char1_att2p-(((rand()%60)/10)*10));
        }
        else
        {
            char2p = char2p - (char1_att2p-(((rand()%110)/10)*10));
        }
    }

    // Condition For Night Guy.
    if(attackp == 1000)
    {
        if (char2p > 0)
        {
            int continueit;
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,        //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            cout << "IT WAS A SUICIDE ATTACK!\n\n";
            cout << "Enter any key to continue:";
            cin  >> continueit;
            player2_wins();         //Function Called
            cin  >> continueit;
            system("cls");
            main();                 //Function Called
        }
        else
        {
            int continueit;
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,        //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            cout << "IT WAS A SUICIDE ATTACK!\n\n";
            cout << "Enter any key to continue:";
            cin  >> continueit;
            draw();                 //Function Called
            cin  >> continueit;
            system("cls");
            main();                 //Function Called
        }
    }
    else
    {
        if (char2p > 0)
        {
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,        //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            player2_attack (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,     //Function Called
                            char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
        }
        else if (char2p <= 0)
        {
            int continueit;
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,        //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            cout << "Enter any key to continue:";
            cin  >> continueit;
            player1_wins();         //Function Called
            cin  >> continueit;
            system("cls");
            main();                 //Function Called
        }
    }

}

// Function To Execute Player2's Attacks And Update Player1's HP.
void player2_attack (string char1_name, string char2_name, string char1_att1, string char1_att2, string char2_att1, string char2_att2,
                     int char1p, int char2p, int char1_att1p, int char1_att2p, int char2_att1p, int char2_att2p )
{
    srand(time(0));
    int attack, attackp;
    cout << "\nPlayer 2's Turn\nEnter The Number of Attack You Want To Do: ";
    cin >> attack;
    while (cin.fail() || attack < 1 || attack > 2)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Input. Try Again!" << endl;
        cin >> attack;
    }

    //Assessing The Attack And Randomize Its Value A Bit.
    if (attack == 1)
    {
        attackp = char2_att1p;
        if(char2_att1p < 350)
        {
            char1p = char1p - (char2_att1p-(((rand()%60)/10)*10));
        }
        else
        {
            char1p = char1p - (char2_att1p-(((rand()%110)/10)*10));
        }
    }
    else if(attack == 2)
    {
        attackp = char2_att2p;
        if(char2_att2p < 350)
        {
            char1p = char1p - (char2_att2p-(((rand()%60)/10)*10));
        }
        else
        {
            char1p = char1p - (char2_att2p-(((rand()%110)/10)*10));
        }
    }

    // Condition For Night Guy.
    if(attackp == 1000)
    {
        if (char1p > 0)
        {
            int continueit;
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,          //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            cout << "IT WAS A SUICIDE ATTACK!\n\n";
            cout << "Enter any key to continue:";
            cin  >> continueit;
            player1_wins();                 //Function Called
            cin  >> continueit;
            system("cls");
            main();                         //Function Called
        }
        else
        {
            int continueit;
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,          //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            cout << "IT WAS A SUICIDE ATTACK!\n\n";
            cout << "Enter any key to continue:";
            cin  >> continueit;
            draw();                 //Function Called
            cin  >> continueit;
            system("cls");
            main();                 //Function Called
        }
    }
    else
    {
        if (char1p > 0)
        {
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,            //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            player1_attack (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,         //Function Called
                            char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
        }
        else if (char1p <= 0)
        {
            int continueit;
            system("cls");
            print_cards (char1_name, char2_name, char1_att1, char1_att2, char2_att1, char2_att2,        //Function Called
                         char1p, char2p, char1_att1p, char1_att2p, char2_att1p, char2_att2p );
            cout << "Enter any key to continue:";
            cin  >> continueit;
            player2_wins();             //Function Called
            cin  >> continueit;
            system("cls");
            main();                     //Function Called
        }
    }

}

// Winner Screen For Player 1.
void player1_wins()
{
    system("cls");
        cout << "__________.__                               ____   __      __.__                \n";
        cout << "\\______   \\  | _____  ___.__. ___________  /_   | /  \\    /  \\__| ____   ______ \n";
        cout << " |     ___/  | \\__  \\<   |  |/ __ \\_  __ \\  |   | \\   \\/\\/   /  |/    \\ /  ___/ \n";
        cout << " |    |   |  |__/ __ \\\\___  \\  ___/|  | \\/  |   |  \\        /|  |   |  \\\\___ \\  \n";
        cout << " |____|   |____(____  / ____|\\___  >__|     |___|   \\__/\\  / |__|___|  /____  > \n";
        cout << "                    \\/\\/         \\/                      \\/          \\/     \\/  \n\n";
        cout << "Enter any key to continue: ";
}

// Winner Screen For Player 2.
void player2_wins()
{
        system("cls");
        cout << "__________.__                              ________    __      __.__               \n";
        cout << "\\______   \\  | _____  ___.__. ___________  \\_____  \\  /  \\    /  \\__| ____   ______\n";
        cout << " |     ___/  | \\__  \\<   |  |/ __ \\_  __ \\  /  ____/  \\   \\/\\/   /  |/    \\ /  ___/\n";
        cout << " |    |   |  |__/ __ \\\\___  \\  ___/|  | \\/ /       \\   \\        /|  |   |  \\\\___ \\ \n";
        cout << " |____|   |____(____  / ____|\\___  >__|    \\_______ \\   \\__/\\  / |__|___|  /____  >\n";
        cout << "                    \\/\\/         \\/                \\/        \\/          \\/     \\/ \n\n";
        cout << "Enter any key to continue: ";
}

// Screen If Match Was a Draw.
void draw()
{
    system("cls");
    cout << "._____________/\\_________     _____     ________ __________    _____  __      __._.\n";
    cout << "|   \\__    ___)/   _____/    /  _  \\    \\______ \\\\______   \\  /  _  \\/  \\    /  \\ |\n";
    cout << "|   | |    |   \\_____  \\    /  /_\\  \\    |    |  \\|       _/ /  /_\\  \\   \\/\\/   / |\n";
    cout << "|   | |    |   /        \\  /    |    \\   |    `   \\    |   \\/    |    \\        / \\|\n";
    cout << "|___| |____|  /_______  /  \\____|__  /  /_______  /____|_  /\\____|__  /\\__/\\  /  __\n";
    cout << "                      \\/           \\/           \\/       \\/         \\/      \\/   \\/ \n\n";
    cout << "Enter any key to continue:";
}

// Screen and Sound When You Exit the Game.
void bye()
{
 cout << "   ____  _  _  ____  _   \n";
 cout << "  (  _ \\( \\/ )(  __)/ \\  \n";
 cout << "   ) _ ( )  /  ) _) \\_/  \n";
 cout << "  (____/(__/  (____)(_)  ";
      PlaySound(TEXT("goodbye.wav"),NULL,SND_SYNC);
}

// Function to Print Instructions.
void print_instructions()
{
    cout << "INSTRUCTIONS\n\n"
         << "1. Each Player Selects a Character to Fight.\n"
         << "2. The Powers Mentioned With Each Player Is The Max Power A Character Can Have And May Vary.\n"
         << "3. While The First Attack Is The Strongest Attack, It May Not Always Be The Case.\n"
         << "4. The Attack Damage Can Vary a Bit Each Time. Depends On How Well Did The Character Execute His/Her Attack.\n"
         << "5. Coin Will Be Tossed To Decide Who Gets The First Turn.\n"
         << "6. Use Your Turn Effectively And Deplete Other Player's Energy To WIN!\n"
         << "7. Play Game More And More to Explore Each Character And Their Attacks To Master The Game.\n"
         << "8. To Best Master The Game, Go To : www.crunchyroll.com, Subscribe And Enjoy The Complete Anime To Become The True Master!!!.\n\n"
         << "GOOD LUCK!\n\n\n" ;
}


// Function That Assigns Values To variables co-responding to Each Character.
void getdata (int& chara, int& charp, string& char_name, string& char_att1, string& char_att2, int& char_att1p, int& char_att2p)
{
    srand(time(0));

    if(chara == 1)
    {
        char_name  = chararr[0];
        charp = powers[0] - (((rand()%260)/10)*10);
        char_att1  = "Rasen Shuriken   ";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 430;
        char_att2p = 350;
    }
    if(chara == 2)
    {
        char_name  = chararr[1];
        charp = powers[1] - (((rand()%260)/10)*10);
        char_att1  = "Kirin";
        char_att2  = "Susano";
        char_att1p = 300;
        char_att2p = 460;
    }
    if(chara == 3)
    {
        char_name  = chararr[2];
        charp = powers[2] - (((rand()%160)/10)*10);
        char_att1  = "Kamui";
        char_att2  = "Chidori";
        char_att1p = 360;
        char_att2p = 280;
    }
    if(chara == 4)
    {
        char_name  = chararr[3];
        charp = powers[3] - (((rand()%260)/10)*10);
        char_att1  = "Amaterasu";
        char_att2  = "Genjutsu";
        char_att1p = 420;
        char_att2p = 380;
    }
    if(chara == 5)
    {
        char_name  = chararr[4];
        charp = powers[4] - (((rand()%160)/10)*10);
        char_att1  = "Twin Lion";
        char_att2  = "Gentle Fist";
        char_att1p = 190;
        char_att2p = 110;
    }
    if(chara == 6)
    {
        char_name  = chararr[5];
        charp = powers[5] - (((rand()%260)/10)*10);
        char_att1  = "Light Fang";
        char_att2  = "Susano!";
        char_att1p = 450;
        char_att2p = 300;
    }
    if(chara == 7)
    {
        char_name  = chararr[6];
        charp = powers[6] - (((rand()%160)/10)*10);
        char_att1  = "Almighty Push";
        char_att2  = "Rinegan Summoning";
        char_att1p = 160;
        char_att2p = 270;
    }
    if(chara == 8)
    {
        char_name  = chararr[7];
        charp = powers[7] - (((rand()%160)/10)*10);
        char_att1  = "Heaven Spear Kick";
        char_att2  = "Yin-Release Punch";
        char_att1p = 300;
        char_att2p = 300;
    }
    if(chara == 9)
    {
        char_name  = chararr[8];
        charp = powers[8] - (((rand()%260)/10)*10);
        char_att1  = "Flying Thunder";
        char_att2  = "Rasengan";
        char_att1p = 400;
        char_att2p = 300;
    }
    if(chara == 10)
    {
        char_name  = chararr[9];
        charp = powers[9] - (((rand()%160)/10)*10);
        char_att1  = "Sand Arm";
        char_att2  = "SandFall Funeral";
        char_att1p = 250;
        char_att2p = 310;
    }
     if(chara == 11)
    {
        char_name  = chararr[10];
        charp = powers[10] - (((rand()%160)/10)*10);
        char_att1  = "Summon Rashumon";
        char_att2  = "Binding Snake";
        char_att1p = 300;
        char_att2p = 190;
    }
    if(chara == 12)
    {
        char_name  = chararr[11];
        charp = powers[11] - (((rand()%160)/10)*10);
        char_att1  = "100 Seal Strenght";
        char_att2  = "Cherry Blossom";
        char_att1p = 200;
        char_att2p = 260;
    }
    if(chara == 13)
    {
        char_name  = chararr[12];
        charp = powers[12] - (((rand()%260)/10)*10);
        char_att1  = "Kamui";
        char_att2  = "Flame Formation";
        char_att1p = 400;
        char_att2p = 300;
    }
    if(chara == 14)
    {
        char_name  = chararr[13];
        charp = powers[13] - (((rand()%160)/10)*10);
        char_att1  = "Crushing Toad";
        char_att2  = "Needle Jizo";
        char_att1p = 300;
        char_att2p = 200;
    }
    if(chara == 15)
    {
        char_name  = chararr[14];
        charp = powers[14] - (((rand()%160)/10)*10);
        char_att1  = "6 Chakra Gates";
        char_att2  = "Leaf Gale";
        char_att1p = 300;
        char_att2p = 200;
    }
    if(chara == 16)
    {
        char_name  = chararr[15];
        charp = powers[15] - (((rand()%160)/10)*10);
        char_att1  = "Shadow Sewing";
        char_att2  = "Human Yo-Yo!";
        char_att1p = 200;
        char_att2p = 220;
    }
    if(chara == 17)
    {
        char_name  = chararr[16];
        charp = powers[16] - (((rand()%160)/10)*10);
        char_att1  = "128 Palms";
        char_att2  = "Heavenly Spin";
        char_att1p = 250;
        char_att2p = 200;
    }
    if(chara == 18)
    {
        char_name  = chararr[17];
        charp = powers[17] - (((rand()%160)/10)*10);
        char_att1  = "Clay Explosion";
        char_att2  = "C4";
        char_att1p = 200;
        char_att2p = 300;
    }
    if(chara == 19)
    {
        char_name  = chararr[18];
        charp = powers[18] - (((rand()%160)/10)*10);
        char_att1  = "Chakra Hair Trap";
        char_att2  = "Human Yo-Yo!";
        char_att1p = 120;
        char_att2p = 200;
    }
    if(chara == 20)
    {
        char_name  = chararr[19];
        charp = powers[19] - (((rand()%260)/10)*10);
        char_att1  = "Darkness Bringer";
        char_att2  = "Summon Budha";
        char_att1p = 500;
        char_att2p = 300;
    }
    if(chara == 21)
    {
        char_name  = chararr[20];
        charp = powers[20] - (((rand()%160)/10)*10);
        char_att1  = "IronSand Drizzle";
        char_att2  = "Puppet String";
        char_att1p = 200;
        char_att2p = 120;
    }
    if(chara == 22)
    {
        char_name  = chararr[21];
        charp = powers[21] - (((rand()%160)/10)*10);
        char_att1  = "Dragon Strike";
        char_att2  = "Coil of Wind";
        char_att1p = 150;
        char_att2p = 100;
    }
    if(chara == 23)
    {
        char_name  = chararr[22];
        charp = powers[22] - (((rand()%160)/10)*10);
        char_att1  = "Paper Chakron";
        char_att2  = "Shikigami Dance";
        char_att1p = 250;
        char_att2p = 200;
    }
    if(chara == 24)
    {
        char_name  = chararr[23];
        charp = powers[23] - (((rand()%160)/10)*10);
        char_att1  = "Dragon's Task";
        char_att2  = "Flashing Firework";
        char_att1p = 200;
        char_att2p = 200;
    }
    if(chara == 25)
    {
        char_name  = chararr[24];
        charp = powers[24] - (((rand()%160)/10)*10);
        char_att1  = "Ice Spears";
        char_att2  = "Demon-Ice Mirrors";
        char_att1p = 100;
        char_att2p = 150;
    }
    if(chara == 26)
    {
        char_name  = chararr[25];
        charp = powers[25] - (((rand()%160)/10)*10);
        char_att1  = "Shark Bullet";
        char_att2  = "Water Prison";
        char_att1p = 200;
        char_att2p = 300;
    }
    if(chara == 27)
    {
        char_name  = chararr[26];
        charp = powers[26] - (((rand()%160)/10)*10);
        char_att1  = "Phoenix SageFire";
        char_att2  = "EarthFlow River";
        char_att1p = 350;
        char_att2p = 250;
    }
    if(chara == 28)
    {
        char_name  = chararr[27];
        charp = powers[27] - (((rand()%160)/10)*10);
        char_att1  = "Beast-Human Clone";
        char_att2  = "Fang";
        char_att1p = 180;
        char_att2p = 100;
    }
    if(chara == 29)
    {
        char_name  = chararr[28];
        charp = powers[28] - (((rand()%160)/10)*10);
        char_att1  = "Parasite kill";
        char_att2  = "Insect Tornado";
        char_att1p = 200;
        char_att2p = 130;
    }
    if(chara == 30)
    {
        char_name  = chararr[29];
        charp = powers[29] - (((rand()%160)/10)*10);
        char_att1  = "Curse";
        char_att2  = "Death Control";
        char_att1p = 140;
        char_att2p = 230;
    }
    if(chara == 31)
    {
        char_name  = chararr[30];
        charp = powers[30] - (((rand()%160)/10)*10);
        char_att1  = "Water Dragon";
        char_att2  = "Hidden Mist";
        char_att1p = 200;
        char_att2p = 160;
    }
    if(chara == 32)
    {
        char_name  = chararr[31];
        charp = powers[31] - (((rand()%160)/10)*10);
        char_att1  = "Lightening Cutter";
        char_att2  = "Earth Grudge Fear";
        char_att1p = 220;
        char_att2p = 200;
    }
    if(chara == 33)
    {
        char_name  = chararr[32];
        charp = powers[32] - (((rand()%260)/10)*10);
        char_att1  = "Heavenly Weeping";
        char_att2  = "Shadow Clone";
        char_att1p = 350;
        char_att2p = 420;
    }
    if(chara == 34)
    {
        char_name  = chararr[33];
        charp = powers[33] - (((rand()%160)/10)*10);
        char_att1  = "Ash-pile Burning";
        char_att2  = "Rasengan";
        char_att1p = 100;
        char_att2p = 130;
    }
    if(chara == 35)
    {
        char_name  = chararr[34];
        charp = powers[34] - (((rand()%160)/10)*10);
        char_att1  = "Melting Ghost";
        char_att2  = "Boil Release";
        char_att1p = 300;
        char_att2p = 300;
    }
    if(chara == 36)
    {
        char_name  = chararr[35];
        charp = powers[35] - (((rand()%160)/10)*10);
        char_att1  = "Clone Snakes";
        char_att2  = "Twin Demon";
        char_att1p = 200;
        char_att2p = 110;
    }
    if(chara == 37)
    {
        char_name  = chararr[36];
        charp = powers[36] - (((rand()%160)/10)*10);
        char_att1  = "Tate Eboshi";
        char_att2  = "Water Arm";
        char_att1p = 240;
        char_att2p = 180;
    }
    if(chara == 38)
    {
        char_name  = chararr[37];
        charp = powers[37] - (((rand()%160)/10)*10);
        char_att1  = "Spiked Human";
        char_att2  = "Chubby Drive";
        char_att1p = 200;
        char_att2p = 140;
    }
    if(chara == 39)
    {
        char_name  = chararr[38];
        charp = powers[38] - (((rand()%160)/10)*10);
        char_att1  = "Flying Swallow";
        char_att2  = "Thousand Murders";
        char_att1p = 160;
        char_att2p = 220;
    }
    if(chara == 40)
    {
        char_name  = chararr[39];
        charp = powers[39] - (((rand()%160)/10)*10);
        char_att1  = "Night Guy!";
        char_att2  = "Daytime Tiger";
        char_att1p = 1000;
        char_att2p = 370;
    }
    if(chara == 41)
    {
        char_name  = chararr[40];
        charp = powers[40] - (((rand()%160)/10)*10);
        char_att1  = "Ink Mist";
        char_att2  = "Super Ink-Beast";
        char_att1p = 200;
        char_att2p = 160;
    }
    if(chara == 42)
    {
        char_name  = chararr[41];
        charp = powers[41] - (((rand()%160)/10)*10);
        char_att1  = "Typhoon Vortex";
        char_att2  = "Tearing Torrent";
        char_att1p = 200;
        char_att2p = 200;
    }
    if(chara == 43)
    {
        char_name  = chararr[42];
        charp = powers[42] - (((rand()%160)/10)*10);
        char_att1  = "Izanagi";
        char_att2  = "Vacuum Blade";
        char_att1p = 220;
        char_att2p = 140;
    }
    if(chara == 44)
    {
        char_name  = chararr[43];
        charp = powers[43] - (((rand()%160)/10)*10);
        char_att1  = "Poison-Mist Hell";
        char_att2  = "Black Salamander";
        char_att1p = 230;
        char_att2p = 150;
    }
    if(chara == 45)
    {
        char_name  = chararr[44];
        charp = powers[44] - (((rand()%160)/10)*10);
        char_att1  = "Tailed Beast Bomb";
        char_att2  = "Eight Twists";
        char_att1p = 300;
        char_att2p = 300;
    }
    if(chara == 46)
    {
        char_name  = chararr[45];
        charp = powers[45] - (((rand()%160)/10)*10);
        char_att1  = "Black Panther";
        char_att2  = "Laser Circus";
        char_att1p = 200;
        char_att2p = 150;
    }
    if(chara == 47)
    {
        char_name  = chararr[46];
        charp = powers[46] - (((rand()%160)/10)*10);
        char_att1  = "Dust Release";
        char_att2  = "Massive Fist";
        char_att1p = 300;
        char_att2p = 220;
    }
    if(chara == 48)
    {
        char_name  = chararr[47];
        charp = powers[47] - (((rand()%160)/10)*10);
        char_att1  = "Iron Claw";
        char_att2  = "Lightning Strike";
        char_att1p = 350;
        char_att2p = 250;
    }
    if(chara == 49)
    {
        char_name  = chararr[48];
        charp = powers[48] - (((rand()%160)/10)*10);
        char_att1  = "Exploding Flame";
        char_att2  = "Summon Salamander";
        char_att1p = 200;
        char_att2p = 300;
    }
    if(chara == 50)
    {
        char_name  = chararr[49];
        charp = powers[49] - (((rand()%160)/10)*10);
        char_att1  = "Claw Creation";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 200;
        char_att2p = 300;
    }
    if(chara == 51)
    {
        char_name  = chararr[50];
        charp = powers[50] - (((rand()%160)/10)*10);
        char_att1  = "Coral Pollen";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 200;
        char_att2p = 300;
    }
    if(chara == 52)
    {
        char_name  = chararr[51];
        charp = powers[51] - (((rand()%160)/10)*10);
        char_att1  = "Lava Release";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 300;
        char_att2p = 300;
    }
    if(chara == 53)
    {
        char_name  = chararr[52];
        charp = powers[52] - (((rand()%160)/10)*10);
        char_att1  = "Horn Breaking";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 150;
        char_att2p = 300;
    }
    if(chara == 54)
    {
        char_name  = chararr[53];
        charp = powers[53] - (((rand()%160)/10)*10);
        char_att1  = "Bubble Dome";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 200;
        char_att2p = 300;
    }
    if(chara == 55)
    {
        char_name  = chararr[54];
        charp = powers[54] - (((rand()%160)/10)*10);
        char_att1  = "Wave Transmission";
        char_att2  = "Tailed Beast Bomb";
        char_att1p = 200;
        char_att2p = 300;
    }

}
