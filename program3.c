#Develop a C program to simulate producer-consumer problem using semaphores.

#include<stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3, x = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d",x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d",x);
    x--;
    ++mutex;
}

int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
#pragma omp critical
    for (i = 1; i > 0; i++)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        // Switch Cases
        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                {
                    producer();
                }
                else
                {
                    printf("Buffer is full!");
                }
                break;
            case 2:
                if ((mutex == 1)&& (full != 0))
                {
                    consumer();
                }
                else
                {
                    printf("Buffer is empty!");
                }
                break;
            case 3:
                exit(0);
                break;
        }
    }
}



# TEST CASES:

# 1. Press 1 for Producer
# 2. Press 2 for Consumer
# 3. Press 3 for Exit
# Enter your choice:1
# Producer produces item 1
# Enter your choice:1
# Producer produces item 2
# Enter your choice:1
# Producer produces item 3
# Enter your choice:1
# Buffer is full!
# Enter your choice:2
# Consumer consumes item 3
# Enter your choice:2
# Consumer consumes item 2
# Enter your choice:2
# Consumer consumes item 1
# Enter your choice:2
# Buffer is empty!
# Enter your choice:3