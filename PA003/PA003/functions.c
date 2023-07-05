#include "functions.h"

clock_t start;
clock_t end;

struct DynArrayStack {
    int top;
    int capacity;
    int* array;
};

struct ListNode {
	int data;
	struct ListNode* next;
};

struct LnkListStack {
	struct ListNode* top;
};

//Stack made of Dynamic Array
int pnpnDnstk(int in) {
    struct DynArrayStack* Dnstk = CreateArrStack(1);
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PushArrStack(Dnstk, i);
    }
    for (int i = 0; i < in * 1000000; i++) {
        PopArrStack(Dnstk);
    }
    end = clock();
    DeleteArrStack(Dnstk);
    return end - start;
}

int p1p1RotateDnstk(int in) {
    struct DynArrayStack* Dnstk = CreateArrStack(1);
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PushArrStack(Dnstk, i);
        PopArrStack(Dnstk);
    }
    end = clock();
    DeleteArrStack(Dnstk);
    return end - start;
}

void Dnstk10M() {
    struct DynArrayStack* Dnstk_Dynamic = CreateArrStack(1);
    for (int i = 0; i < 10000000; i++) {
        if (i >= 8388598 && i <= 8388618) {
            start = clock();
            PushArrStack(Dnstk_Dynamic, i);
            end = clock();
            printf("\n%d insert, 걸린 시간: %d ms ", i, end - start);
        }
        else {
            PushArrStack(Dnstk_Dynamic, i);
        }
    }
}
void pnpnDnstk_measure(int in) {
    struct DynArrayStack* Dnstk = CreateArrStack(1);
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PushArrStack(Dnstk, i);
    }
    end = clock();
    printf("\n%d00000번 Push 수행 시간 평균: %lf", in, (double)(end - start) / (in * 1000000));
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PopArrStack(Dnstk);
    }
    end = clock();
    printf("\n%d00000번 Pop 수행 시간 평균: %lf", in, (double)(end - start) / (in * 1000000));
    DeleteArrStack(Dnstk);
}

int pnpnLnstk(int in) {
    struct LnkListStack* Lnstk = CreateLnkStack();
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PushLnkStack(Lnstk, i);
    }
    for (int i = 0; i < in * 1000000; i++) {
        PopLnkStack(Lnstk);
    }
    end = clock();
    DeleteLnkStack(Lnstk);
    return end - start;
}

int p1p1RotateLnstk(int in) {
    struct LnkListStack* Lnstk = CreateLnkStack();
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PushLnkStack(Lnstk, i);
        PopLnkStack(Lnstk);
    }
    end = clock();
    DeleteLnkStack(Lnstk);
    return end - start;
}

void pnpnLnstk_measure(int in) {
    struct LnkListStack* Lnstk = CreateLnkStack();
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PushLnkStack(Lnstk, i);
    }
    end = clock();
    printf("\n%d00000번 Push 수행 시간 평균: %lf", in, (double)(end - start) / (in * 1000000));
    start = clock();
    for (int i = 0; i < in * 1000000; i++) {
        PopLnkStack(Lnstk);
    }
    end = clock();
    printf("\n%d00000번 Pop 수행 시간 평균: %lf", in, (double)(end - start) / (in * 1000000));
    DeleteLnkStack(Lnstk);
}

//Dynamic array로 구현된 Stack
struct DynArrayStack* CreateArrStack(int cap) {
    struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
    if (!S)   return NULL;
    S->capacity = cap;  // parameter로 입력받아서 초기 값을 조절
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if (!S->array) {
        return NULL;
    }
    return S;
}

int IsFullArrStack(struct DynArrayStack* S) {
    return (S->top == S->capacity - 1);
}

void DoubleArrStack(struct DynArrayStack* S) {
    S->capacity *= 2;
    S->array = (int*)realloc(S->array, S->capacity * sizeof(int));
}
void PushArrStack(struct DynArrayStack* S, int x) {
    if (IsFullArrStack(S))
        //printf("\n%d, %d", S->capacity, x);
        DoubleArrStack(S);
    S->array[++S->top] = x;
}

int IsEmptyArrStack(struct DynArrayStack* S) {
    return (S->top == -1);
}

int TopArrStack(struct DynArrayStack* S) {
    if (IsEmptyArrStack(S))
        return INT_MIN;
    return S->array[S->top];
}
int PopArrStack(struct DynArrayStack* S) {
    if (IsEmptyArrStack(S))
        return INT_MIN;
    return (S->array[S->top--]);
}
void DeleteArrStack(struct DynArrayStack* S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}

//Linked List로 구현된 Stack
struct LnkListStack* CreateLnkStack() {
    struct LnkListStack* stk;
    stk = (struct LnkListStack*)malloc(sizeof(struct LnkListStack));
    stk->top = NULL;
    return stk;
}
void PushLnkStack(struct LnkListStack* stk, int data) {
    struct ListNode* temp;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!temp)
        return;
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}
int IsEmptyLnkStack(struct LnkListStack* stk) {
    return (stk->top == NULL);
}

int PopLnkStack(struct LnkListStack* stk) {
    int data;
    struct ListNode* temp;
    if (IsEmptyLnkStack(stk))
        return INT_MIN;
    temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free(temp);
    return data;
}

int TopLnkStack(struct LnkListStack* stk) {
    if (IsEmptyLnkStack(stk))
        return INT_MIN;
    return stk->top->data;
}

void DeleteLnkStack(struct LnkListStack* stk) {
    struct ListNode* temp, * p;
    p = stk->top;
    while (p) {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(stk);
}

