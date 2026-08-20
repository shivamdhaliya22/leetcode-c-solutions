int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    int firstTerm = 0;
    int secondTerm = 1;
    int thirdTerm = 1;

    for (int i = 3; i <= n; i++) {
        int fourthTerm = firstTerm + secondTerm + thirdTerm;

        firstTerm = secondTerm;
        secondTerm = thirdTerm;
        thirdTerm = fourthTerm;
    }

    return thirdTerm;
}