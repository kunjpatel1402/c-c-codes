
#include <stdio.h>
#include <iostream>
#include <time.h>
#include<stdlib.h>
char ch[3][3];
int check(char a[3][3])
{ //printf("started checking");
    a = ch;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == a[i][0] && a[i][0] == 'X')
        {
            printf(" X wins !!!!");
            return 0;
        }

        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == a[i][0] && a[i][0] == 'O')
        {
            printf(" O wins !!!!");
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[2][i] == a[0][i] && a[0][i] == 'X')
        {
            printf(" X wins !!!!");
            return 0;
        }

        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[2][i] == a[0][i] && a[0][i] == 'O')
        {
            printf(" O wins !!!!");
            return 0;
        }
    }

    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == a[2][2] && a[0][0] == 'X')
    {
        printf(" X wins !!!");
        return 0;
    }

    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == a[2][2] && a[0][0] == 'O')
    {
        printf(" O wins !!!");
        return 0;
    }
    if (a[0][2] == a[1][1] && a[1][1] == a[0][2] && a[0][2] == a[2][0] && a[2][0] == 'X')
    {
        printf(" X wins !!!");
        return 0;
    }

    if (a[0][2] == a[1][1] && a[1][1] == a[0][2] && a[0][2] == a[2][0] && a[2][0] == 'O')
    {
        printf(" O wins !!!");
        return 0;
    } //printf("checked returning 1");
    return 1;
}
void computer_turn()
{
    int r, c, flag = 0;
    char computer = 'O';

chois1:
{
    for (int i = 0; i < 3; i++)
    {
        if ((ch[i][0] == ch[i][1] && ch[i][0] == 'O') && (ch[i][2] == ' '))
        {
            ch[i][2] = 'O';
            flag = 1;
            goto label;
        }
        else if ((ch[i][0] == ch[i][2] && ch[i][0] == 'O') && (ch[i][1] == ' '))
        {
            ch[i][1] = 'O';
            flag = 1;

            goto label;
        }
        else if ((ch[i][1] == ch[i][2] && ch[i][1] == 'O') && (ch[i][0] == ' '))
        {
            ch[i][0] = 'O';
            flag = 1;

            goto label;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if ((ch[0][i] == ch[1][i] && ch[0][i] == 'O') && (ch[2][i] == ' '))
        {
            ch[2][i] = 'O';
            flag = 1;
            goto label;
        }
        else if ((ch[0][i] == ch[2][i] && ch[0][i] == 'O') && (ch[1][i] == ' '))
        {
            ch[1][i] = 'O';
            flag = 1;
            goto label;
        }
        else if ((ch[2][i] == ch[1][i] && ch[2][i] == 'O') && (ch[0][i] == ' '))
        {
            ch[0][i] = 'O';
            flag = 1;
            goto label;
        }
    }
    if ((ch[0][0] == ch[1][1] && ch[0][0] == 'O') && (ch[2][2] == ' '))
    {
        ch[2][2] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[0][0] == ch[2][2] && ch[0][0] == 'O') && (ch[1][1] == ' '))
    {
        ch[1][1] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[2][2] == ch[1][1] && ch[2][2] == 'O') && (ch[0][0] == ' '))
    {
        ch[0][0] = 'O';
        flag = 1;
        goto label;
    }

    // 2nd diagonal

    if ((ch[0][2] == ch[1][1] && ch[0][2] == 'O') && (ch[2][0] == ' '))
    {
        ch[2][0] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[2][0] == ch[0][2] && ch[2][0] == 'O') && (ch[1][1] == ' '))
    {
        ch[1][1] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[2][0] == ch[1][1] && ch[2][0] == 'O') && (ch[0][2] == ' '))
    {
        ch[0][2] = 'O';
        flag = 1;
        goto label;
    }
    // this is for preventing the user to win
    for (int i = 0; i < 3; i++)
    {
        if ((ch[i][0] == ch[i][1] && ch[i][0] == 'X') && (ch[i][2] == ' '))
        {
            ch[i][2] = 'O';
            flag = 1;
            goto label;
        }
        else if ((ch[i][0] == ch[i][2] && ch[i][0] == 'X') && (ch[i][1] == ' '))
        {
            ch[i][1] = 'O';
            flag = 1;

            goto label;
        }
        else if ((ch[i][1] == ch[i][2] && ch[i][1] == 'X') && (ch[i][0] == ' '))
        {
            ch[i][0] = 'O';
            flag = 1;

            goto label;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if ((ch[0][i] == ch[1][i] && ch[0][i] == 'X') && (ch[2][i] == ' '))
        {
            ch[2][i] = 'O';
            flag = 1;
            goto label;
        }
        else if ((ch[0][i] == ch[2][i] && ch[0][i] == 'X') && (ch[1][i] == ' '))
        {
            ch[1][i] = 'O';
            flag = 1;
            goto label;
        }
        else if ((ch[2][i] == ch[1][i] && ch[2][i] == 'X') && (ch[0][i] == ' '))
        {
            ch[0][i] = 'O';
            flag = 1;
            goto label;
        }
    }
    if ((ch[0][0] == ch[1][1] && ch[0][0] == 'X') && (ch[2][2] == ' '))
    {
        ch[2][2] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[0][0] == ch[2][2] && ch[0][0] == 'X') && (ch[1][1] == ' '))
    {
        ch[1][1] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[2][2] == ch[1][1] && ch[2][2] == 'X') && (ch[0][0] == ' '))
    {
        ch[0][0] = 'O';
        flag = 1;
        goto label;
    }

    // 2nd diagonal

    if ((ch[0][2] == ch[1][1] && ch[0][2] == 'X') && (ch[2][0] == ' '))
    {
        ch[2][0] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[2][0] == ch[0][2] && ch[2][0] == 'X') && (ch[1][1] == ' '))
    {
        ch[1][1] = 'O';
        flag = 1;
        goto label;
    }
    else if ((ch[2][0] == ch[1][1] && ch[2][0] == 'X') && (ch[0][2] == ' '))
    {
        ch[0][2] = 'O';
        flag = 1;
        goto label;
    }

    r = rand() % 3;
    c = rand() % 3;
    if (ch[r][c] == ' ')
    {
        ch[r][c] = computer;
    }
    else
    {
        goto chois1;
    }
}
label:
{
}
}

int main()
{
    srand(time(NULL));

    int count = 0;

    int running = 1, c_ = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ch[i][j] = ' ';
        }
    }
    while (running == 1 && count < 5)
    {   system("cls");
        int r, c, flag = 1;
        char user = 'X';
        char computer = 'O';

        //4printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        for (int i = 0; i < 3; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                printf("| %c |", ch[i][j]);
            }
            printf("\n---------------");
        }

    choices:
    {
        // for user only

        printf("\n ENTER ROW TO BE SELECTED:");
        scanf(" %d", &r);
        printf("\n ENTER COLUMN TO BE SELECTED:");
        scanf(" %d", &c);

        if (ch[r - 1][c - 1] == ' ')
            ch[r - 1][c - 1] = user;
        else
        {
            printf("ALREADY SELECTED PLEASE TRY AGAIN!!!!");
            goto choices;
        }
    }

        running = check(ch);
        if (running == 0)
        {
            break;
        }

        //now for computer's turn
        if (count < 4)
        {
            computer_turn();
        }

        running = check(ch);
        if (running == 0)
        {
            break;
        }
        count++;
    }
    
    

   
    if (count == 5)
    {
        system("cls");
        for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("| %c |", ch[i][j]);
        }
        printf("\n---------------");
    }
        printf("\n\nITS A DRAW");
        return 0;
    }
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("| %c |", ch[i][j]);
        }
        printf("\n---------------");
    }

    int q;
    q=check(ch);
    return 0;
}