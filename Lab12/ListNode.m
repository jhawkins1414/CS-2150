//Jared Hawkins jmh7ax 5/3/2021

#import "ListNode.h"

@implementation ListNode

-(id) value: (int) v{
  value = v;
  return self;
}

-(int) value{
  return value;
}

-(id) next: (ListNode*) n{
  next = n;
  return self;
}

-(ListNode*) next{
  return next;
}

@end
