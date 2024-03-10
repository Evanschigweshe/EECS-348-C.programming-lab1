#include <stdio.h>
#include <stdlib.h>

// Function to generate monthly sales report
void monthly_sales_report(double sales[12],char *month[12]){    
    // Diplaying header for the sales report
    printf("Monthly sales report for 2022:\n");
    printf("\nMonth\t Sales\n");
    // Iterates through each month
    for (int i=0;i<12;i++){
        // Prints the month and corresponding sales
        printf("%s\t$%.2f\n",month[i],sales[i]);
    }
    
}
// Function to display sales summary
void sales_summary(double sales[12],char *month[12]){
    // Displaying header for sales summary
    printf("\nSales summary:");
    double max=0; // Initializing maximum sales to 0
    double min=10000000000000000000000000000000000000000000000000.00; // Initializing minimum sales to a very large number
    double sum=0;  //Initializing sum of sales to 0
    // Looping through each month's sales data
    for (int i=0;i<12;i++){
        // Checking if current sales is greater than or equal to current maximum
        if (max <= sales[i]) {
            max=sales[i]; // Update maximum sales if current sales is greater
        }
        // Checking if current sales is less than or equal to current minimum
        if (sales[i]<=min){
            min=sales[i]; // Update minimum sales if current sales is lesser
        }    
        sum=sum+sales[i];// Accumulate sales for calculating total sum
        
    }
    printf("\n\nMinimun sales: $%.2f (%s)",min,month[0]);// Displaying minimum sales and corresponding month
    printf("\nMaximum sales: $%.2f (%s)",max,month[11]);// Displaying minimum sales and corresponding month
    printf("\nAverage sales: $%.2f",sum/12);  // Displaying the average sales of the 12 months
}
// Function to calculate and display the six-month moving average report
void six_month_moving_average(double sales[12],char *month[12]){
    // Displaying header for six month moving average
    printf("\n\nSix-Month Moving Average Report:\n\n");
    // Iterates through the first 6 months
    for (int i=0;i<7;i++){
        double sum=0;
        // Calculates the sum of sales for the current 6-month period
        for (int j=i;j<i+6;j++){
            sum=sum+sales[j];
            
        }
        printf("%s - %s  $%.2f\n",month[i],month[i+5],sum/6); // Print the average sales for the current 6-month period
    }
}  
 // Function to generate a sales report sorted from highest to lowest 
void sales_report(double sales[12],char *month[12]){
    // sorting the array in descending order
    for (int i=0;i<12;i++){
        for (int j=i+1;j<12;j++){
             // If sales of current month is less than sales of next month, swap them
            if (sales[i]<sales[j]){
                double sales_value=sales[i];  // Temporary variable to store sales
                sales[i]=sales[j];         // Swap sales
                sales[j]=sales_value;     // Swap sales
                char *month_value=month[i]; // Temporary variable to store month
                month[i]=month[j];   // Swap months
                month[j]=month_value; // Swap months
            }
            
        }
        
    }
    // Print the sales report in descending order
    printf("\nSales Report (Highest to Lowest):\n"); // Diplaying heading of highest to lowest
    printf("Month\tSales\n"); // Displaying heading of month and sales
    for (int i =0; i<12;i++){
        printf("%s\t%.2f\n",month[i],sales[i]); // Print the sales report in descending order
    }
    
}

// Main function
int main(){

  // Array to store sales for each month  
        double sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
          // Array to store the month names  
        char *month[12]= {"January","February","March","April","May","June","July","August","September", "October","November", "December"};
        monthly_sales_report(sales,month);  // Calling the monthly_sales_report function to generate monthly sales report
        sales_summary(sales,month);// Calling the sales_summary function to generate sales summary
        six_month_moving_average(sales,month);// Calling the six_month_moving_average function to generate six month moving average
        sales_report(sales,month);// Calling the sales_report function to generate sales report


        return 0;
}