// declare this globally
mt19937 rng;

// write this in starting of main 
rng = mt19937 (chrono::steady_clock::now().time_since_epoch().count());

// for a number of range 0,n-1 do 
int reqnumber = rng() % n ;