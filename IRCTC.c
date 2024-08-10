#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct info
{
    char name[20];
    int age;
    char gender[10];
    char src[15];
    char dest[15];
    char pnr[11];        // PNR number as a string
    char train_name[50]; // Train name
    char username[15];
    char password[20];
};

// Function prototypes
void booking(struct info *i);
void display(struct info *i);
int login(struct info *i);
int signup(struct info *i);
void generate_pnr(char *pnr);
void generate_train_name(char *train_name);

int main()
{
    int ch;
    struct info i;

    // Set default credentials
    strcpy(i.username, "Admin");
    strcpy(i.password, "1111");

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome To IRCTC\n");
    printf("----------------\n");

    while (1)
    {
        printf("1. Login\n2. Signup\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);
        getchar(); // Consume the newline character

        switch (ch)
        {
        case 1:
            if (login(&i))
            {
                printf("Successfully logged into the system!\n");
                booking(&i);
            }
            else
            {
                printf("INVALID USERNAME/PASSWORD!!\n");
                printf("1. Try Login Again\n2. Signup\n3. Exit\nEnter choice: ");
                scanf("%d", &ch);
                getchar(); // Consume the newline character

                if (ch == 2)
                {
                    if (signup(&i))
                    {
                        printf("Signup successful!\n");
                    }
                    else
                    {
                        printf("Signup failed. User already exists.\n");
                    }
                }
                else if (ch == 3)
                {
                    printf("Thank you!\n");
                    return 0;
                }
            }
            break;
        case 2:
            if (signup(&i))
            {
                printf("Signup successful!\n");
            }
            else
            {
                printf("Signup failed. User already exists.\n");
            }
            break;
        case 3:
            printf("Thank you!\n");
            return 0;
        default:
            printf("**Invalid Input**\n");
            break;
        }
    }

    return 0;
}

int login(struct info *i)
{
    char uname[15];
    char pass[20];
    printf("Enter username: ");
    scanf("%14s", uname);
    getchar();
    printf("Enter Password: ");
    scanf("%19s", pass);

    // Check credentials
    if (strcmp(uname, i->username) == 0 && strcmp(pass, i->password) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int signup(struct info *i)
{
    printf("Enter New Username: ");
    scanf("%14s", i->username);
    printf("Enter New Password: ");
    scanf("%19s", i->password);

    // For simplicity, assuming signup is always successful
    return 1;
}

void booking(struct info *i)
{
    printf("Enter name: ");
    scanf("%19s", i->name); // Read up to 19 characters (leave space for null terminator)

    printf("Enter Age: ");
    scanf("%d", &i->age);

    printf("\n!!WRITE M for Male,F for Female !!\nEnter gender-> ");
    scanf("%9s", i->gender); // Read up to 9 characters (leave space for null terminator)

    printf("Enter Source: ");
    scanf("%9s", i->src);

    printf("Enter Destination: ");
    scanf("%9s", i->dest);

    generate_pnr(i->pnr);               // Generate a random PNR number
    generate_train_name(i->train_name); // Generate a random train name

    display(i);
}

void display(struct info *i)
{
    printf("\n----------------------------------------------\n");
    printf("           INDIAN RAILWAYS              \n");
    printf("----------------------------------------------\n");
    printf("Train: %s    PNR: %s\n\n", i->train_name, i->pnr);
    printf("Source: %s    Dest: %s\n", i->src, i->dest);
    printf("----------------------------------------------\n");
    printf("Name: %s     %d-%s\n", i->name, i->age, i->gender);
    printf("----------------------------------------------\n");
    printf("          Have a Safe Journey!          \n");
    printf("----------------------------------------------\n");
}

void generate_pnr(char *pnr)
{
    for (int i = 0; i < 10; i++)
    {
        pnr[i] = '0' + rand() % 10; // Generate a random digit
    }
    pnr[10] = '\0'; // Null-terminate the string
}

void generate_train_name(char *train_name)
{
    const char *train_names[] = {
        "Mumbai Rajdhani Express",
        "Delhi Rajdhani Express",
        "Vandebharat Express",
        "Deccan Express",
        "Bhumbhaneshwar Konar Express",
        "LTT Gorakhpur Express",
        "Bhubaneswar Humsafar Express",
        "Tejas Express",
        "LTT Vishakapatnam Express",
        "Amrit bharat Express"};

    int index = rand() % 10; // Randomly select a train name
    strcpy(train_name, train_names[index]);
}
