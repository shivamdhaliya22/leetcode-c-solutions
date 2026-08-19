bool isPalindrome(int x) {

// Negative numbers are not palindrome.
// Numbers ending in 0 (except 0 itself) are not palindromes. 
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;

// Reverse the second half of the digits.
    while (x > reversedHalf) {
        reversedHalf = (reversedHalf * 10) + (x % 10);
        x /= 10;
    }

// For even-length numbers, x == reversedHalf.
// For odd-length numbers, x == reversedHalf / 10(removes the middle digit.)
    return x == reversedHalf || x == reversedHalf / 10;
}