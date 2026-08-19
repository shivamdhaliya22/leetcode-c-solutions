bool isPalindrome(int x) {

// Negative numbers are not palindrome.
// Numbers ending in 0 (except 0 itself) are not palindromes. 
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revNum = 0;

// Reverse the second half of the digits.
    while (x > revNum) {
        revNum = (revNum * 10) + (x % 10);
        x /= 10;
    }

// For even-length numbers, x == revNum.
// For odd-length numbers, x == revNum / 10(removes the middle digit.)
    return x == revNum || x == revNum / 10;
}