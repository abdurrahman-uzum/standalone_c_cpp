#include <stdio.h>

int a, b, c, holder, i, check;

int nums[3];

int main() {

    printf("Please enter three integer values: ");
    scanf("%d%d%d", &nums[0], &nums[1], &nums[2]);

    for (i=0; check < 3; i++) {
            i=i%2;
            if (nums[i] > nums[i+1]) {
                    holder = nums[i+1];
                    nums[i+1] = nums[i];
                    nums[i] = holder;
                    check = 0;
                    continue;
            }
            check++;
    }

    if ( nums[2] <= nums[0]+nums[1] && nums[0] >= nums[1]-nums[2] ) {
            printf("%d,%d and %d can form sides of a triangle.\n", nums[0],nums[1],nums[2]);

            if ( nums[2]*nums[2] == nums[1]*nums[1] + nums[0]*nums[0] ) {
                    printf("That triangle is a right triangle.\n");
            }
    }
    else {
            printf("%d,%d and %d can not form sides of a triangle.\n", nums[0],nums[1],nums[2]);
    }









    return 0;
}
