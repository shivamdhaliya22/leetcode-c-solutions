int missingNumber(int* nums, int numsSize) {

    // sum of nums from 0 to n
//    int expSum = (numsSize * (numsSize + 1))/2;

    // sum of elements in the array
//    int actualSum = 0;
//    for (int i=0; i<numsSize; i++) {
//        actualSum += nums[i];
//    }

    // missing num = difference 
//    return expSum - actualSum;


    // ****by XOR or Bit Manipulaton method****
     int xorSum = numsSize;

     for (int i=0; i<numsSize; i++) {
       xorSum ^= i ^ nums[i];
     }
    return xorSum;
    // int xor1 = 0, xor2 = 0;
    // int n = numsSize-1;
    // for (int i = 0; i < n; i++) {
    //     xor2 = xor2 ^ nums[i];
    //     xor1 = xor1 ^ (i+1);
    // }
   // xor1 = xor1 ^ numsSize;

    //return xor1 ^ xor2;
}