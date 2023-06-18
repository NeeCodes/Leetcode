class Solution {
public:
    int pivotInteger(int n) {
        int sumRight = (n*(n+1)) / 2;
        int sumLeft = 0;

        int i = 1;

        while (sumRight >= sumLeft) {
            sumLeft += i;
            if (sumLeft == sumRight) return i;
            sumRight -= i;
            i++;
        }

        return -1;
    }
};
