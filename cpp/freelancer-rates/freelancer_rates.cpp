#include <cmath>
// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    // TODO: Implement a function to calculate the daily rate given an hourly
    double dailyRate=8*hourly_rate;
    return dailyRate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double afterDiscount=before_discount-before_discount*discount/100;
    return afterDiscount;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double beforeDiscount=hourly_rate*8*22;
    double afterDiscount=std::ceil(beforeDiscount-beforeDiscount*discount/100.0);

    return (int) afterDiscount;
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    int days=0;
    while (budget>=0) {
        double dailyRate=daily_rate(hourly_rate);
        double dailyWithDiscount=dailyRate-dailyRate*discount/100.0;
        budget-=(int)dailyWithDiscount;
        if (budget>=0) days++;
    }
    return days;
}
