#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Dynamic Array로 Stack 구현
struct DynArrayStack;
//Linked List로 Stack 구현 
struct ListNode;
struct LnkListStack;

//Element Functions 
int pnpnDnstk(int in);        //1
void pnpnDnstk_measure(int in); //2
void Dnstk10M();              //3
int p1p1RotateDnstk(int in);  //4

int pnpnLnstk(int in);        //1
void pnpnLnstk_measure(int in); //2
int p1p1RotateLnstk(int in);  //4


//Functions for Main()
void pnpnTime();              //1
void p1p1Time();              //2
void doublingTime();          //3
void p1p1RotateTime();        //4

//Functions of Stack made of Dynamic Array
struct DynArrayStack* CreateArrStack(int cap);
int IsFullArrStack(struct DynArrayStack* S);
void DoubleArrStack(struct DynArrayStack* S);
void PushArrStack(struct DynArrayStack* S, int x); 
int IsEmptyArrStack(struct DynArrayStack* S);
int TopArrStack(struct DynArrayStack* S);
int PopArrStack(struct DynArrayStack* S);
void DeleteArrStack(struct DynArrayStack* S);

//Functions of Stack made of Linked List
struct LnkListStack* CreateLnkStack();
void PushLnkStack(struct LnkListStack* stk, int data);
int IsEmptyLnkStack(struct LnkListStack* stk);
int PopLnkStack(struct LnkListStack* stk);
int TopLnkStack(struct LnkListStack* stk);
void DeleteLnkStack(struct LnkListStack* stk);
