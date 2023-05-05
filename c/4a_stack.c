#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
} element;

void push(element *ptr, int temp, int *top, int n)
{
    if ((*top) >= n - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    ptr[++(*top)].key = temp;
}

int pop(element *ptr, int *top)
{
    if ((*top) == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return ptr[(*top)--].key;
    }
}
void display(element *ptr, int top)
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", ptr[i].key);
    }
}

element *dble(element *ptr, int *n)
{
    element *p = (element *)realloc(ptr, ((*n) * 2 * sizeof(element)));
    (*n) = (*n) * 2;
    return p;
}

int main()
{
    int n, top,sign,ele;
    char entry;
    element *stack;

    printf("Enter size of stack\n");
    scanf("%d", &n);
    stack = (element *)malloc(sizeof(element) * n);
    top = -1;
    while (1)
    {
        printf("\n\t1-Push 2-Pop 3-Display 4-Reallocate Memory 5-Exit\n");
        scanf("%d", &sign);
        switch (sign)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &ele);
            push(stack, ele, &top, n);
            break;
        case 2:
            printf("Popped Element = ", pop(stack, &top));
            break;

        case 3:
            display(stack, top);
            break;
        case 4:
            printf("Old size = %d\n", n);
            stack = dble(stack, &n);
            printf("New size = %d\n", n);
            break;
        default:
            exit(0);
        }
    }
free(stack);
return 0;
}