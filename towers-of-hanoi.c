# include <stdlib.h>
# include <stdio.h>

void hanoi(int n, char start, char end, char other) {
    // Function which solves the problem for n discs starting on peg called start and finishing on a peg called end

    // Do this recursively
    // Assume we have a function that can move n-1 to a peg

    if (n == 1) {
        printf("Move disk %d from %c to %c\n", n, start, end);
    }
    else {
        // Want to move n-1 discs from start to other
        hanoi(n-1, start, other, end);
        // Now move biggest disc to end
        printf("Move disk %d from %c to %c\n", n, start, end);
        // Now move n-1 discs from other to end
        hanoi(n-1, other, end, start);
    }
}

int main() {
    hanoi(4, 'A', 'B', 'C');
}