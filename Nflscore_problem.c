#include <stdio.h>

// Function to print combinations of scoring plays
void combinations(int score, int td, int fg, int safety, int td_1pt_fg, int td_2pt) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_1pt_fg, td, fg, safety);
}

// Function to find combinations of scoring plays that result in a given score
void find_combinations(int score) {
    int td; // Defining number of touchdowns
    int fg; // Defining number of field goals
    int safety; // Defining number of safety
    int td_1pt_fg; // Defining number of touchdowns and extra points
    int td_2pt;// Defining number of touchdowns and points coversion
    
    // iterates through possible combinations of scoring plays
    for (td_2pt = 0; td_2pt <= score / 8; td_2pt++) {
        for (td_1pt_fg = 0; td_1pt_fg <= score / 7; td_1pt_fg++) {
            for (td = 0; td <= score / 6; td++) {
                for (fg = 0; fg <= score / 3; fg++) {
                    for (safety = 0; safety <= score / 2; safety++) {
                        // Checking if the combination results in the given score
                        if ((td * 6 + fg * 3 + safety * 2 + td_1pt_fg * 7 + td_2pt * 8) == score) {
                            // calls the combination function to display the results
                            combinations(score, td, fg, safety, td_1pt_fg, td_2pt);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score; // Defining a varialbe to store the results 
    
    // Loop to continuously ask for input scores until user enters 0 or 1 to end the program
    while (1) {
        printf("\nEnter 0 or 1 to STOP\n"); 
        printf("Enter the NFL score: ");
        scanf("%d", &score);
         // Checking if the input score is 0 or 1, if so, end the program
        if (score <= 1) {
            printf("Program Ending.\n");
            break; // stops the while loop, hence terminating the program
        }
        // Diplays a header that notifies the user what is being printed "Possible combination"
        printf("Possible combinations of scoring plays:\n"); 
        find_combinations(score); // Calling the find_combinations(score) function to find the possible combinations that will add up to the reqiured score
    }
    
    return 0;
}