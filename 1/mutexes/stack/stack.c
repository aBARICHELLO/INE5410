#include "stack.h"

mystack_t* stack_alloc(int max_size) {
    mystack_t* s = (mystack_t*)malloc(sizeof(mystack_t));

    s->max_size = max_size;
    s->data = (int*)malloc(sizeof(int)* max_size);
    s->top = 0;

    return s;
}

void stack_free(mystack_t* s) {
    pthread_mutex_destroy(&s->mutex);
    free(s->data);
    free(s);
}

int stack_isempty(mystack_t* s) {
    if (s->top == 0)
        return 1;
    return 0;
}

int stack_isfull(mystack_t* s) {
    if (s->top == s->max_size)
        return 1;
    return 0;
}

int stack_pop(mystack_t* s, int* ret) {
    if (!stack_isempty(s)) {
        pthread_mutex_lock(&s->mutex);
        *ret = s->data[--s->top];
        printf("%s %d |\n", "Pop Data:", *ret);
        pthread_mutex_unlock(&s->mutex);
        return 1;
    }
    return 0;
}

int stack_push(mystack_t* s, int data) {
    if (!stack_isfull(s)) {
        pthread_mutex_lock(&s->mutex);
        s->data[s->top++] = data;
        printf("%s %d |\n", "Push Data:", data);
        pthread_mutex_unlock(&s->mutex);
        return 1;
    }
    return 0;
}
