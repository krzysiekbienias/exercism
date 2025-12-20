// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    double rate=0;
    if (balance<0) rate=3.213;
    else if (balance>=0 && balance<1000.0) rate=0.5;
    else if (balance>=1000.0 && balance<5000) rate=1.621;
    else rate=2.475;
    return rate;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {
    double rate=interest_rate(balance);
    double annualGain=balance*(1+rate/100.0);
    double interestGain=annualGain-balance;
    return interestGain;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {
    double yi= yearly_interest(balance)+balance;
    return yi;
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    int cnt=0;
    while(balance<target_balance){
        double grow= annual_balance_update(balance);
        balance= grow;
        cnt++;
    }
    return cnt;
}
