#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <stdio.h>
#include <string.h>

typedef struct player
{
    char name[10];
    int happy;
    int sleepy;
    int hungry;
}Pet;

void loadingScreen(); 
void menu();
void endScreen();
void pet();
void newGame();
void loadGame();
void playGame();
void sort();
void search();
void history();

Pet yourpet;

int main()
{
    unsigned short option;
    loadingScreen();

    do              
    {
        menu();
        scanf("%hu", &option);
        getchar();

        switch(option)
        {
            case 1:
                system(clear);
                newGame();
                break;

            case 2:
                system(clear);
                loadGame();
                break;

            case 3:
                system(clear);
                history();
                break;
        }

    } while(option != 0);

    endScreen();

    return 0;
}

void loadingScreen() 
{
    system(clear);
    printf("===========================\n");
    printf("--=      Welcome To     =--\n");
    printf("--=    Tamagochi Game   =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=      Loading.       =--\n");
    printf("===========================\n");
    sleep(1);
    system(clear);
    printf("===========================\n");
    printf("--=      Welcome To     =--\n");
    printf("--=    Tamagochi Game   =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=      Loading..      =--\n");
    printf("===========================\n");
    sleep(1);
    system(clear);
    printf("===========================\n");
    printf("--=      Welcome To     =--\n");
    printf("--=    Tamagochi Game   =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=      Loading...     =--\n");
    printf("===========================\n");
    sleep(1);
    system(clear);
    printf("===========================\n");
    printf("--=      Welcome To     =--\n");
    printf("--=    Tamagochi Game   =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=                     =--\n");
    printf("--=      Loading....    =--\n");
    printf("===========================\n");
    sleep(1);
}

void menu() 
{
    system(clear);
    printf("============\n");
    printf("=---Menu---=\n");
    printf("============\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. History\n");
    printf("0. Exit Game \n");
    printf("============\n");
    printf("Select Option: ");
}

void endScreen() 
{
    system(clear);
    char temp[100];

    FILE *pf = fopen("love.txt", "r"); 

    while(fgets(temp, 100, pf) != NULL)
    {
        printf("%s", temp);
    }

    fclose(pf);
}

void pet() 
{
    char temp[100];

    FILE *pf = fopen("animal.txt", "r"); 

    while(fgets(temp, 100, pf) != NULL)
    {
        printf("%s", temp);
    }
    printf("\n");

    fclose(pf);
}

void newGame() 
{
    do
    {
        if(strlen(yourpet.name) >= 10) 
        {
            printf("Name cannot be longer\n");
            printf("than 10 characters!!!\n\n");
        }

        printf("This is your pet\n\n");
        pet();

        printf("\nInput your pet name: ");
        scanf("%[^\n]s", yourpet.name);
        getchar();

        system(clear);
        
    } while(strlen(yourpet.name) >= 10);

    yourpet.happy = 10, yourpet.sleepy = 10, yourpet.hungry = 10;

    FILE *pf = fopen("player.data", "w");

    fprintf(pf, "%s#%d#%d#%d\n", yourpet.name, yourpet.happy, yourpet.hungry, yourpet.sleepy);

    fclose(pf);

    playGame();

}

void loadGame()
{
    FILE *pf = fopen("player.data", "r");

    if(pf == NULL)  
    {
        printf("File not found!\n\n");
        system("pause");
    }
    else
    {
        fscanf(pf, "%[^#]#%d#%d#%d\n", yourpet.name, &yourpet.happy, &yourpet.hungry, &yourpet.sleepy);
        playGame();
    }

    fclose(pf);
}

void playGame() 
{
    system(clear);
    unsigned short option;

    do 
    {
        system(clear);
        printf("Pet name: %s\n\n", yourpet.name);
        printf("Hapiness level : %d\n", yourpet.happy);
        printf("Hunger level   : %d\n", yourpet.hungry);
        printf("Sleepy level   : %d\n\n", yourpet.sleepy);

        pet();

        if(yourpet.happy < 5 || yourpet.hungry < 5 || yourpet.sleepy < 5) 
        {
            if(yourpet.happy < 5)
            {
                printf("\nI'm bored :(");
            }
            if(yourpet.hungry < 5)
            {
                printf("\nI'm hungry :(");
            }
            if(yourpet.sleepy < 5)
            {
                printf("\nI'm sleepy :(");
            }
        }
        else
        {
            printf("\nI'm so happy :)");
        }

        printf("\n\n======================\n");
        printf("1. Play with your pet\n");
        printf("2. Feed your pet\n");
        printf("3. Sleep with your pet\n");
        printf("0. Exit\n");
        printf("======================\n");
        printf("Select Option: ");
        scanf("%hu", &option);
        getchar();

        switch(option) 
        {
            case 1:
                if(yourpet.happy > 0 && yourpet.hungry > 0 && yourpet.sleepy > 0)
                {
                    yourpet.happy = yourpet.happy + 4;
                    yourpet.hungry = yourpet.hungry - 3;
                    yourpet.sleepy = yourpet.sleepy - 1;

                    if(yourpet.happy < 0)
                    {
                        yourpet.happy = 0;  
                    }
                    if(yourpet.hungry < 0)
                    {
                        yourpet.hungry = 0;  
                    }
                    if(yourpet.sleepy < 0)
                    {
                        yourpet.sleepy = 0;  
                    }
                }
                else
                {
                    printf("\nYour pet die\n");
                    printf("Create new game!\n\n");
                    system("pause");
                }
                break;

            case 2:
                if(yourpet.happy > 0 && yourpet.hungry > 0 && yourpet.sleepy > 0)
                {
                    yourpet.happy = yourpet.happy - 1;
                    yourpet.hungry = yourpet.hungry + 2;
                    yourpet.sleepy = yourpet.sleepy - 1;

                    if(yourpet.happy < 0)
                    {
                        yourpet.happy = 0;  
                    }
                    if(yourpet.hungry < 0)
                    {
                        yourpet.hungry = 0;  
                    }
                    if(yourpet.sleepy < 0)
                    {
                        yourpet.sleepy = 0;  
                    }
                }
                else
                {
                    printf("\nYour pet die\n");
                    printf("Create new game!\n\n");
                    system("pause");
                }
                break;

            case 3:
                if(yourpet.happy > 0 && yourpet.hungry > 0 && yourpet.sleepy > 0)
                {
                    yourpet.happy = yourpet.happy - 2;
                    yourpet.hungry = yourpet.hungry - 3;
                    yourpet.sleepy = yourpet.sleepy + 4;

                    if(yourpet.happy < 0)
                    {
                        yourpet.happy = 0;  
                    }
                    if(yourpet.hungry < 0)
                    {
                        yourpet.hungry = 0;  
                    }
                    if(yourpet.sleepy < 0)
                    {
                        yourpet.sleepy = 0;  
                    }
                }
                else
                {
                    printf("\nYour pet die\n");
                    printf("Create new game!\n\n");
                    system("pause");
                }
                break;
        }

    } while(option != 0);

    FILE *pf = fopen("player.data", "w"); 

    fprintf(pf, "%s#%d#%d#%d\n", yourpet.name, yourpet.happy, yourpet.hungry, yourpet.sleepy);

    fclose(pf);
}

void sort(int a, int b) 
{
    if(a <= b)
    {
        printf("Hapiness level : %d\n", yourpet.happy);
        printf("Hunger level   : %d\n\n", yourpet.hungry);
    }
    else if(a > b)
    {
        printf("Hunger level   : %d\n", yourpet.hungry);  
        printf("Hapiness level : %d\n\n", yourpet.happy);
    }
}

void search(int b)
{
    int a;
    printf("Input your sleepy level: ");
    scanf("%d", &a);
    getchar();

    if(a == b)
    {
        printf("Correct!!!\n\n");
    }
    else
    {
        printf("Incorrect!!!\n\n");
    }
}

void history()
{
   FILE *pf = fopen("player.data", "r");

    if(pf == NULL) 
    {
        printf("File not found!\n\n");
        system("pause");
    }
    else
    {
        fscanf(pf, "%[^#]#%d#%d#%d\n", yourpet.name, &yourpet.happy, &yourpet.hungry, &yourpet.sleepy);
        sort(yourpet.happy, yourpet.hungry);
        search(yourpet.sleepy);
        system("pause");
    }

    fclose(pf); 
}