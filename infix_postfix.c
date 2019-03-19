/*中缀表达式变成后缀表达式
 *中缀表达式就是我们一般所见的式子 运算符在操作数之间 
 * 后缀表达式 运算符在操作数后面
 * 规则：数据结构 栈
 * 将中缀表达式转换为后缀表达式的算法思想：
   ·开始扫描；
   ·数字时，加入后缀表达式；
   ·运算符：
   a. 若为 '('，入栈；
   b. 若为 ')'，则依次把栈中的的运算符加入后缀表达式中，直到出现'('，从栈中删除'      '(' ；
   c. 若为 除括号外的其他运算符， 当其优先级高于除'('以外的栈顶运算符时，直接入    栈。否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，直到一个比它优先级低的或者遇到了一个左括号为止，然后将其自身压入栈中（先出后入）。
·当扫描的中缀表达式结束时，栈中的的所有运算符出栈；
 * 20:26
 * 两位数 三位数……不仅仅是一位数 这不是重点 忽略，以下 均以字母代替 不以数字代替
 *
 * 输入：中缀表达式
 * 输出：后缀表达式
 * 失误：后缀表达式每次需要添加，选择的数据结构不好，应该选择队列 或者数组，之类 有空再改
 */
#include<stdio.h>
#include<string.h>
#define maxsize 100
typedef struct stack
{
	char data[maxsize];
	int top;
}stack,*sta;
void judge(stack *s,char c,stack *s1);//似乎需要enum
void print(stack *s,stack *s1);
void push(stack *s,char c);
void pop(stack *s,char c,stack *s1);

void construct(char *s)
{
	stack op,postfix;
	postfix.top=-1;
	op.top=-1;
	int i;
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		printf("op:%d  postfix:%d\n",op.top,postfix.top);
		if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')')
		{
			push(&postfix,s[i]);//如果是操作数加入后缀表达式栈
			printf("push postfix:%c\n",s[i]);
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='('||s[i]==')')
		{
			if(s[i]=='(')
			{
				push(&op,s[i]);//如果是（ 入操作符栈
			}
			else if(s[i]==')')
			{
				pop(&op,s[i],&postfix);
				/*如果是)则依次把栈中运算符加入后缀表达式，直到出现(,从栈里删除(*/
				//printf("pop:v:%c\n",s[i]);
			}
			else
			{
				judge(&op,s[i],&postfix);
				/* 如果优先级高于栈顶元素则入栈，否则从栈顶开始依次弹出比当前运算符优先级高或者相等的运算符直到遇见比它优先级低的或者遇到一个左括号为止，然后将其压入栈*/
			}
		}
		//print(&postfix);
	}
	print(&postfix,&op);//
}
void judge(stack *s,char c,stack *s1)//似乎需要enum
{
	char op=s->data[s->top];
	if(op=='(')
	{
		push(s,c);
	}
	else
	{
		switch(c)
		{
			case '+':pop(s,c,s1);break;
			case '-':pop(s,c,s1);break;
			case '*':if(op=='+'||op=='-') push(s,c);
				 else pop(s,c,s1);break;
			case '/':if(op=='+'||op=='-') push(s,c);
                                 else pop(s,c,s1);break;
		}
	}
}
void print(stack *s,stack *s1)
{
	printf("后缀表达式:");
	while(s1->top>=0)
	{
		printf("%c",s1->data[s1->top]);
		s1->top--;
	}
	while(s->top>=0)
	{
		printf("%c",s->data[s->top]);
		s->top--;
	}
	//printf("tt:%c\n",s1->data[s1->top]);

}
void push(stack *s,char c)
{
	s->data[++s->top]=c;
	printf("push v:%c\n",c);
}
void pop(stack *s,char c,stack *s1)
{
	char in;
	if(c==')')
	{
		while(s->data[s->top]!='(')
		{
			push(s1,s->data[s->top]);
		        printf("pos:");
			//push(s1,in);
			s->top--;
			
		}
		printf("value:%c\n",s->data[s->top]);
		s->data[s->top--];
	}
	else// c 为 + - 没有用的op 或者 c为 * / op为* /都没用
	{
		if(s->top!=-1)
		{
		if(c=='+'||c=='-'||c=='*'||c=='/')
		{
		if(c=='+'||c=='-')
		while(s->top>=0)
		{
			printf("head:%c\n",s->data[s->top]);
			if(s->data[s->top]=='(') break;
			else
			{
			//s->data[s->top]=in;
			push(s1,s->data[s->top]);
			s->top--;
			//push(s1,in);
			}
		}
		else
		{
			while(s->top>=0)
			{
				if(s->data[s->top]=='('||s->data[s->top]=='+'||s->data[s->top]=='-') break;
				else
				{
				push(s1,s->data[s->top]);
				s->top--;
				}
				
			}
		}
		push(s,c);
		}
		}
		else
		{
			push(s,c);
		}
	}	
	
}
int main()//shit 
{
	char s[]="a+b-a*((c+d)/e-f)+g";
	construct(s);
	char s1[]="a/b+(c*d-e*f)/g";
	construct(s1);

}
