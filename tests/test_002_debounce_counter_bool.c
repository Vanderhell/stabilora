#include "pc_debounce_counter_bool.h"
#include <assert.h>
#include <stdint.h>
int main(void){uint32_t t,c;for(t=1;t<=32u;++t)for(c=0;c<t;++c)for(uint32_t sb=0;sb<2u;++sb)for(uint32_t xb=0;xb<2u;++xb){bool s=sb!=0u,x=xb!=0u;uint32_t nc=c;bool ns=s;bool expected=x!=s&&c==t-1u;assert(pc_debounce_counter_bool(x,t,&nc,&ns));if(expected){assert(ns==x&&nc==0);}else if(x==s){assert(ns==s&&nc==0);}else{assert(ns==s&&nc==c+1u);}}
 {uint32_t c=0;bool s=false;assert(pc_debounce_counter_bool(true,1,&c,&s)&&c==0&&s);c=UINT32_MAX-1u;s=false;assert(pc_debounce_counter_bool(true,UINT32_MAX,&c,&s)&&c==0&&s);c=4;s=true;assert(pc_debounce_counter_bool(true,5,&c,&s)&&c==0&&s);c=4;s=false;assert(pc_debounce_counter_bool(true,5,&c,&s)&&c==0&&s);}
 {uint32_t c=0;bool s=false;assert(!pc_debounce_counter_bool(true,0,&c,&s)&&c==0&&!s);c=3;s=false;assert(!pc_debounce_counter_bool(true,3,&c,&s)&&c==3&&!s);assert(!pc_debounce_counter_bool(true,2,0,&s));assert(!pc_debounce_counter_bool(true,2,&c,0));}
 return 0;}
