int reverse(int x){
    long long revNum = 0; // 64-bit integer holds much larger values safely
    
    while (x != 0) {

        int lastDigit = x % 10;

    // check for positive overflow
        if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && lastDigit > 7)) {
            return 0;
        }

    // check for negative overflow
        if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && lastDigit < -8)) {
            return 0;
        }
    
        revNum = (revNum * 10) + lastDigit;
        x /= 10;
        
    } 
    return revNum;
}