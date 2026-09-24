#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int get_positive_int(const char *prompt)
{
    int in_buffer;
    while(1)
    {
        printf("%s", prompt);
        if(scanf("%d", &in_buffer) == 1 && in_buffer > 0)
        {
            return in_buffer;
        } int c;
        while ((c = getchar()) != '\n') { } 
        printf("Invalid input, please re-enter.\n");
    }
}


int rollDie(int sides) 
{
    return (rand() % sides) + 1;
}

int find_sum(const int *buffer, int no_rolls)
{
    int sum = 0;
    for(int i = 0; i < no_rolls; i++)
    {
        sum += buffer[i];
    }
    return sum;
}

double find_average(int no_rolls, int sum)
{
    double average = (double) sum / no_rolls;
    return average;
}

void find_frequencies(const int *buffer, int no_rolls, int no_faces, int freq[])
{
    for (int i = 0; i < no_faces; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < no_rolls; i++)
    {
        int face = buffer[i];
        if (face >= 1 && face <= no_faces)
        {
            freq[face - 1]++;
        }
    }
}

int choice()
{
    while(1)
    {
        char ch;
        printf("Enter Q/q to Quit and C/c to continue : ");
        if(scanf(" %c", &ch) == 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            if(ch == 'Q' || ch == 'q')
            {
                return 0;
            } else if(ch == 'C' || ch == 'c')
            {
                return 1;
            }
        } printf("Invalid Input,please re-enter.\n");
    }
}

int main()
{
    srand(time(NULL));

    while(1)
    {
        printf(" ==== DICE ROLL ====\n");
        
        int no_faces;
        while(1)
        {
            no_faces = get_positive_int("Enter the number of faces(sides) on the die (e.g., 6):");
            if(no_faces < 50)
            {
                break;
            } printf("number of faces must be less than %d\n", 50);
            printf("Please re-enter the number of faces.\n");
        }
        int no_rolls = get_positive_int("Enter number of rolls (positive number) : ");

        int *roll_result = (int*)malloc(no_rolls * sizeof(int));
        if (roll_result == NULL) 
        {
            printf("Memory allocation failed! Exiting...\n");
            return 1;   
        }


        for(int i = 0; i < no_rolls; i++)
        {
            roll_result[i] = rollDie(no_faces);
        }

        int sum = find_sum(roll_result, no_rolls);
        double average = find_average(no_rolls, sum);

        int *frequency = (int*)malloc(no_faces * sizeof(int));
        if (frequency == NULL) 
        {
            printf("Memory allocation failed! Exiting...\n");
            return 1; 
        }

        find_frequencies(roll_result, no_rolls, no_faces, frequency);

        printf("\n=========== RESULTS ===========\n");
        printf("\nSum: %d\n", sum);
        printf("Average: %.2f\n", average);
        printf("Frequencies:\n");
        for (int i = 0; i < no_faces; i++)
        {
            printf("%-10d: %d\n", i + 1, frequency[i]);
        }
        printf("\n");
        
        free(roll_result);
        free(frequency);
        int flag = choice();
        if(flag == 0)
        {
            printf("Q/q is selected Exiting the program....");
            return 0;
        }
    }


}