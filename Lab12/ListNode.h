//Jared Hawkins jmh7ax 5/3/2021

#import <Foundation/NSObject.h>

@interface ListNode : NSObject{
  @private
    int value;
    ListNode* next;
}

-(id) value: (int) v;
-(int) value;
-(id) next: (ListNode*) n;
-(ListNode*) next;

@end
  
