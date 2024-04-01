#include<stdio.h>
/*int bitXor(int x, int y) 
{
  int a = ~(x&~y);
  int b = ~(~x&y);
  int c=~(a&b);
  return c;
}*/
/*int isTmax(int x) {
  int item=x+1;
  x=~(x+item);
  item=!item;
  x=x+item;
  return !x;
}*/
/*int tmin(void) 
{
  /*最小的二进制数有32位，为10000000（有31个0），所以采用<<左移操作即可*/
  /*int item=1;
  return item<<31;
}*/
/*int a=0xAA+(0xAA<<8);//10101010+10101010左移八位
  a=a+(a<<16);//加上左移16位的，变成1010重复8遍
  return !((a&x)^a);*/
/*int allOddBits(int x) {
  int a_8 = 0xAA;
  int a_16 = (a_8 << 8)|(a_8);
  int a_32 = (a_16 << 16)|(a_16);
  int equal = (x & a_32) ^ a_32;//排除有偶数位是1的情况，如01010101，10101001
  return !equal;
}*/
/*int negate(int x) {
  //找相反数即二进制按位取反再+1

  return ~x+1;
}*/
/*int isAsciiDigit(int x) {
  //0x30 <= x <= 0x39 即 x-0x30>=0 x-0x39<=0
  int a=x+(~0x30+1);//x-0x30
  int b=(~x+1)+0x39;//0x39-x
  int result_a=a>>31;
  int result_b=b>>31;//如果a>0则最高位是0，result_a==0;反之result_a==-1;result_b同理;return 1 when result_a==0&&result_b==0
  return (!result_a)&(!result_b);
}*/
/*int conditional(int x, int y, int z) {
  //如果x为真则结果为y，反之结果为z，x！=0时都为真，判断时改动一下变为！！a即为1
  int a=!!x;
  int b=~a+1;//if a==1, b==-1
  int result_1=b&y;
  int result_2=(~b)&z;
  return result_1|result_2;
}*/
/*int logicalNeg(int x) {
  //x==0时 !x==0 the same;when x!=0 x和-x总有一个是负的，右移31位就是-1
  int nega_x=~x+1;
  int b=x|nega_x;
  int result=(b>>31)+1;
  return result;
}*/
/*int isLessOrEqual(int x, int y) {
  //if x<=y return 1
  int nega_x=~x+1;//-x
  int minus=y+nega_x;//y-x
  int sign_x=x>>31&1;
  int sign_y=y>>31&1;//不加&1的话可能是0(+)或者-1(-)，加了以后是0(+)或者1(-)
  int sign_minus=minus>>31&1;
  int check_xy=sign_x^sign_y;//判断x和y的符号是否相等，相等为0，反之为1
  return (!check_xy&!sign_minus)|(check_xy&sign_x);
}*/
/*int howManyBits(int x) {
  int b16,b8,b4,b2,b1,b0;
	int sign=x>>31;    //x的符号位，最后记得+1
	x = (sign&~x)|(~sign&x);
	b16 = !!(x>>16)<<4;//检查最高十六位(32-16)是否有1，如果有，则!!(x>>16)=1, (1<<4)=0000...10000=2^4=16；如果没有，则为0
	x = x>>b16;//如果有（b16=16,至少需要16位），则将x右移16位；如果没有（b16=0）,x不变
	b8 = !!(x>>8)<<3;//如果上一步移动了，则检查最高8位(32-16-8)是否有1；如果上一步没移动，则检查最高24位(32-8)是否有1
					 //如果有，b8=2^3=8；如果没有，则为0
	x = x>>b8;//如果有，x右移8位；如果没有，x不变
	b4 = !!(x>>4)<<2;
	x = x>>b4;
	b2 = !!(x>>2)<<1;
	x = x>>b2;
	b1 = !!(x>>1);
	x = x>>b1;
	b0 = x;
	return b16+b8+b4+b2+b1+b0+1;//+1表示加上符号位
}*/
 unsigned floatScale2(unsigned uf) {
  int exp = uf&0x7f800000;
  exp=exp>>23;
  int sign = uf&(1<<31);
  if(exp==0) 
  return uf<<1|sign;
  if(exp==255) 
  return uf;
  exp++;
  if(exp==255) 
  return 0x7f800000|sign;
  return (exp<<23)|(uf&0x807fffff);
}

int main()
{
  /*printf("%d\n",tmin());
  printf("%d",1<<31);
  printf("%d",isTmax(2147483647));
  
  printf("%d",negate(-6));
  printf("%d",0x39);
  printf("%d",isAsciiDigit(57));
  printf("%d",conditional(0,6,5));
  printf("%d",logicalNeg(0));
  printf("%d",isLessOrEqual(1,2));
  int x=12;
  int sign=x>>31;    //x的符号
	x=(sign&~x)|(~sign&x);
  printf("%d\n",sign);
  printf("%d\n %d\n",sign&~x,~sign&x);
  printf("%d",howManyBits(13));
  printf("%d",allOddBits(-1431655766));
  printf("%d",0x7f800000);*/
  printf("%u",floatScale2(2.6));
  return 0;
}