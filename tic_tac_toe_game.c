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

/* func that check if was a win. */
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

int main()
{
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char turn_of = 'x'; // x is start in the game
    int pointer; // user input
    int table_chnages = 0; // Some changes were made

    while(game_continue == 0)
    {
        print_x_o_table(table);
        printf("Now is turn of: %c, choose a slot between 1 - 9: ", turn_of);
        scanf("%d", &pointer);

        // checking if user input is a number it the ranage.
        if (pointer < 0 || pointer > 9) //|| table[pointer / 3][pointer % 3 - 1] != ' ')
        {
            printf("This number out of range!\n");
            continue;
        }
        if (table[pointer / 3][pointer % 3 - 1] == ' ')
        {
            table[pointer / 3][pointer % 3 - 1] = turn_of;
            table_chnages += 1;
            if (table_chnages == 9)
            {
                printf("EQUAL GAME!\n");
                game_continue = 1; //Game over
            }
        }
        else
        {
            continue;
        }

        // change turn user
        if (turn_of == 'x')
            {
                turn_of = 'o';
            }
        else
            {
                turn_of = 'x';
            }

        // // checking if was a win
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
    return 0;
}