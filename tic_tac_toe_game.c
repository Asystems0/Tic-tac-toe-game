#include <stdio.h>

int game_continue = 0; // If the number will change the game will over

/* Print the table game*/
void print_x_o_table(char loc[3][3])
{
    printf(" %c | %c | %c\n", loc[0][0], loc[0][1], loc[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", loc[1][0], loc[1][1], loc[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", loc[2][0], loc[2][1], loc[2][2]);

}

/* Func that check if was a win. */
char win(char a, char b, char c)
{
    if (a != ' ' && b != ' ' && c != ' ')
    {
        if (a == 'x' && b == 'x' && c == 'x')
        {
            printf("X is WIN!\n");
            game_continue = 1; //Game over
        }

        if (a == 'o' && b == 'o' && c == 'o')
        {
            printf("O is WIN!\n");
            game_continue = 1; //Game over
        }   
    }
}

/* Checking if was 9 steps in the game and wasn't win */
void equal(int a)
{
    if (a == 9)
    {
        printf("EQUAL GAME!\n");
        game_continue = 1; //Game over
    }
}

/* Checking who turn and Change turn */
char who_turn(char turn)
{
    if (turn == 'x')
        {
            return 'o';
        }
    else
        {
            return 'x';
        }
}

int is_a_number()
{
    int user_input;
    if (scanf("%d", &user_input) == 1) //checking if user input is a number.
    {
        return user_input;
    }
}

int main()
{
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char turn_of = 'x'; // x is start in the game
    int table_chnages = 0; // Some changes were made

    while(game_continue == 0)
    {
        print_x_o_table(table);
        printf("\nNow is turn of: %c, choose a slot between 1 - 9: ", turn_of);

        // if (scanf("%d", &user_input) == 1) //checking if user input is a number.
        // {
            int user_input = is_a_number(); // user input
            if (0 < user_input && user_input < 10) // checking if user input is a number it the ranage.
            {
                if (table[user_input / 3][user_input % 3 - 1] == ' ')
                {
                    table[user_input / 3][user_input % 3 - 1] = turn_of;
                    table_chnages += 1; // If table_change == 9 the game will wover' that mean was 9 turn.
                    turn_of = who_turn(turn_of); // change user turn
                }
                else
                {
                    printf("\nChoose another number, this slot is occupied.\n");
                    // continue;
                }
            }
            else
            {
                printf("\nThis number out of the range!\n");
                // continue;
            }
        /*}


        if user // If user input is not a number.
        {
            printf("\nPlease enter number only.\n");
        }
        */


        /* Checking if game equal */
        equal(table_chnages);

        /* Checking if was a win */
        win(table[0][0], table[0][1], table[0][2]); // line number 1 is equal.
        win(table[1][0], table[1][1], table[1][2]); // line number 2 is equal.
        win(table[2][0], table[2][1], table[2][2]); // line number 3 is equal.

        win(table[0][0], table[1][0], table[2][0]); // column number 1 is equal.
        win(table[0][1], table[1][1], table[2][1]); // column number 2 is equal.
        win(table[0][2], table[1][2], table[2][2]); // column number 3 is equal.

        win(table[0][0], table[1][1], table[2][2]); // slant right to left.
        win(table[2][0], table[1][1], table[0][2]); // slant left to right.
    }

    print_x_o_table(table); // Print table when game over.
    getch();
    return 0;
}