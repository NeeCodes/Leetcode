int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int trap(int *height, int heightSize) {
    int *left = (int*) malloc (heightSize * sizeof(int));
    int *right = (int*) malloc (heightSize * sizeof(int));

    int prevLeftMax = -1;
    int prevRightMax = -1;

    for (int i = 0; i < heightSize; i++) {
        if (height[i] > prevLeftMax)
            prevLeftMax = height[i];

        left[i] = prevLeftMax;
    }

    for (int i = heightSize-1; i >= 0; i--) {
        if (height[i] > prevRightMax)
            prevRightMax = height[i];

        right[i] = prevRightMax;
    }

    int trappedWater = 0;

    for (int i = 0; i < heightSize; i++)
         trappedWater += (min(left[i], right[i]) - height[i]);
 
    free(left);
    free(right);

    return trappedWater;
}
