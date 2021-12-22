//Jared Hawkins jmh7ax 5/3/2021

#import <Foundation/NSObject.h>
#import <stdio.h>

@interface linkedlist : NSObject{
  @private
    int value;
    linkedlist* next;
}

-(id) setValue: (int) v;
-(int) value;
-(id) setNext: (linkedlist*) n;
-(linkedlist*) next;

@end

@implementation linkedlist

-(id) setValue: (int) v{
  value = v;
  return self;
}

-(int) value{
  return value;
}

-(id) setNext: (linkedlist*) n{
  next = n;
  return self;
}

-(linkedlist*) next{
  return next;
}

@end

int main(void){
  int num = 0;
  printf("Enter how many values to input: ");
  scanf("%d", &num);
  //printf("\n");

  linkedlist* root;
  root = [[linkedlist alloc] init];
  printf("Enter value 1: ");
  int initial = 0;
  scanf("%d", &initial);
  root.value = initial;
  linkedlist* chain;
  chain = [[linkedlist alloc] init];
  chain = root;
  

  for(int i = 1; i < num; i++){
    printf("Enter value ");
    printf("%d", i + 1);
    printf(": ");
    int duh = 0;
    scanf("%d", &duh);
    linkedlist* temp;
    temp = [[linkedlist alloc] init];
    temp.value = duh;
    chain.next = temp;
    chain = temp;
  }

  for(int i = 0; i < num -1; i++){
    printf("%d", root.value);
    printf("\n");
    root = root.next;
  }

  printf("%d", root.value);
  printf("\n");
    
    root = nil;
  
  return 0;
}
