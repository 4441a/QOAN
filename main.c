#include "QOAN.h"
#include <stdio.h>
#include <math.h>

int isOblong(long long int n) {
    // Check if the number is oblong (rectangular) based on its factors
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && n / i != i) {
            printf("%lld is oblong as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is oblong
        }
    }

    // If no such pair found, it is not oblong
    return 0;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int isPrime(long long int n) {
    if (n < 2) return 0;  // Numbers less than 2 are not prime

    // Special case for 2
    if (n == 2) return 1;

    // Even numbers are not prime
    if (n % 2 == 0) return 0;

    // Check odd divisors up to the square root of n
    for (long long int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }

    // If no divisor found, it's a prime number
    return 1;
}

int isComposite(long long int n) {
    if (n < 4) return 0;  // Numbers less than 4 are not composite

    // Check for divisors up to half of the number
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return 1;  // It has a divisor, so it's composite
    }

    // If no divisor found, it's not a composite number
    return 0;
}

int isPlanar(long long int n) {
    // Check if the number is a product of two numbers
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && n / i != 1) {
            printf("%lld is planar as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is planar
        }
    }
    
    // If no such pair found, it is not planar
    return 0;
}

int isSolid(long long int n) {
    // Check if the number is a product of three numbers
    for (long long int i = 2; i <= n / 3; i++) {
        if (n % i == 0) {
            long long int remaining = n / i;
            for (long long int j = i + 1; j <= remaining / 2; j++) {
                if (remaining % j == 0) {
                    printf("%lld is solid as a product of %lld, %lld, and %lld.\n", n, i, j, remaining / j);
                    return 1;  // It is solid
                }
            }
        }
    }

    // If no such triplet found, it is not solid
    return 0;
}

int isPeripheral(long long int n) {
    // Check if the number is a multiplication of a number from one and the other type
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && n / i != 1 && n / i != i) {
            printf("%lld is peripheral as a multiplication of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is peripheral
        }
    }

    // If no such pair found, it is not peripheral
    return 0;
}

int isEvenlyEven(long long int n) {
    // Check if the number is created by two even numbers multiplied by each other
    for (long long int i = 2; i <= n / 2; i += 2) {
        if (n % i == 0 && (n / i) % 2 == 0) {
            printf("%lld is evenly even as a product of %lld and %lld.\n", n, i, n / i);

            // Check if all parts are even down to the final unit
            long long int remaining = n / i;
            while (remaining % 2 == 0) {
                remaining /= 2;
            }
            if (remaining == 1) {
                printf("All parts are even down to the final unit.\n");

                // Check if none of its parts is homonymous to the odd number
                if (i % 2 != 0 && (n / i) % 2 != 0) {
                    printf("None of its parts is homonymous to the odd number.\n");
                    return 1;  // It is evenly even
                }
            }
        }
    }

    // If no such pair found, it is not evenly even
    return 0;
}

int isEvenlyOdd(long long int n) {
    // Check if the number is created by an even number multiplied by an odd number
    for (long long int i = 2; i <= n / 2; i += 2) {
        if (n % i == 0 && (n / i) % 2 != 0) {
            printf("%lld is evenly-odd as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is evenly-odd
        }
    }

    // If no such pair found, it is not evenly-odd
    return 0;
}

int isOddlyEven(long long int n) {
    // Check if the number is created by an odd number multiplied by an even number
    for (long long int i = 3; i <= n / 2; i += 2) {
        if (n % i == 0 && (n / i) % 2 == 0) {
            printf("%lld is oddly-even as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is oddly-even
        }
    }

    // If no such pair found, it is not oddly-even
    return 0;
}

int isEquallyEqual(long long int n) {
    // Check if the number is created by two equal numbers multiplied by each other
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && n / i == i) {
            printf("%lld is equally-equal as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is equally-equal
        }
    }

    // If no such pair found, it is not equally-equal
    return 0;
}

int isUnequilateral(long long int n) {
    // Check if the number is not created by two equal numbers multiplied by each other
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && n / i == i) {
            printf("%lld is equilateral as a product of %lld and %lld.\n", n, i, n / i);
            return 0;  // It is not unequilateral
        }
    }

    // If no such pair found, it is unequilateral
    printf("%lld is unequilateral.\n", n);
    return 1;
}

int isParallelogramic(long long int n) {
    // Check if the number is created by two different numbers
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && n / i != i) {
            printf("%lld is parallelogramic as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is parallelogramic
        }
    }

    // If no such pair found, it is not parallelogramic
    return 0;
}

int isTriangular(long long int n) {
    // Check if the number is a triangular number
    // A number is triangular if 8n + 1 is a perfect square
    long long int test = 8 * n + 1;
    long long int sqrtTest = (long long int)sqrt(test);
    
    if (sqrtTest * sqrtTest == test) {
        printf("%lld is triangular.\n", n);
        return 1;  // It is triangular
    }

    // If not a perfect square, it is not triangular
    return 0;
}

int isPolygonal(long long int n) {
    // Check if the number is a polygonal number and return the number of sides
    for (int sides = 3; sides <= 100; sides++) {  // Assume polygons with sides up to 100
        // Formula to check if n is a polygonal number with 'sides' sides
        long long int test = (sides - 2) * n - (sides - 4) * (sides - 2) / 2;
        if (test > 0 && test % (sides - 1) == 0) {
            printf("%lld is a %d-gonal number with %d sides.\n", n, sides, sides);
            return sides;  // Return the number of sides
        }
    }

    // If not a polygonal number, return 0
    return 0;
}

int isDiagonal(long long int n) {
    // Check if the number is diagonal
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && (n / i) % 2 == 0) {
            printf("%lld is diagonal as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is diagonal
        }
    }

    // If no such pair found, it is not diagonal
    return 0;
}

int isLateral(long long int n) {
    // Check if the number is lateral
    for (long long int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && (n / i) % 2 == 1) {
            printf("%lld is lateral as a product of %lld and %lld.\n", n, i, n / i);
            return 1;  // It is lateral
        }
    }

    // If no such pair found, it is not lateral
    return 0;
}

int isPerfect(long long int n) {
    // Check if the number is a perfect number
    long long int sum = 1;
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    if (sum == n) {
        printf("%lld is a perfect number.\n", n);
        return 1;  // It is perfect
    }

    // If the sum is not equal to the number, it is not perfect
    return 0;
}

int isAbundant(long long int n) {
    // Check if the number is an abundant number
    long long int sum = 1;
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    if (sum > n) {
        printf("%lld is an abundant number.\n", n);
        return 1;  // It is abundant
    }

    // If the sum is not greater than the number, it is not abundant
    return 0;
}

int isDeficient(long long int n) {
    // Check if the number is a deficient number
    long long int sum = 1;
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    if (sum < n) {
        printf("%lld is a deficient number.\n", n);
        return 1;  // It is deficient
    }

    // If the sum is not less than the number, it is not deficient
    return 0;
}

int main() {
    long long int num;
    
    // Input
    printf("Enter an integer under 2^63: ");
    scanf("%lld", &num);
    
    
    if (isEvenlyOdd(num)) {
        printf("%lld is evenly-odd.\n", num);
    } else {
        printf("%lld is not evenly-odd.\n", num);
    }
    if (isEvenlyEven(num)) {
        printf("%lld is evenly even.\n", num);
    } else {
        printf("%lld is not evenly even.\n", num);
    }
    isPlanar(num);
    isSolid(num);
    isPeripheral(num);
    if (isPrime(num)) {
        printf("%lld is a prime number.\n", num);
    } else {
        printf("%lld is not a prime number.\n", num);
    }
    if (isComposite(num)) {
        printf("%lld is a composite number.\n", num);
    } else {
        printf("%lld is not a composite number.\n", num);
    }
    if (isOddlyEven(num)) {
        printf("%lld is oddly-even.\n", num);
    } else {
        printf("%lld is not oddly-even.\n", num);
    }
    isEquallyEqual(num);
    isUnequilateral(num);
    isParallelogramic(num);
        isLateral(num);
    isDiagonal(num);
    isPerfect(num);
    isAbundant(num);
    isDeficient(num);
        isOblong(num);
    isTriangular(num);
    int sides = isPolygonal(num);


    if (sides == 0) {
        printf("%lld is not a polygonal number.\n", num);
    }
    return 0;
}
