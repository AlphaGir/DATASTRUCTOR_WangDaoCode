/*后缀表达式求值过程
 *输入：已经转换好的后缀表达式
 *输出：结果
 *利用栈
 *如果是操作数 入栈 
 *如果是操作符 出栈计算最近两个操作数值入栈
 * 沙雕如我总是觉得减去的是'\0'而不是'0'
 * 例如 中缀表达式：1+2*(4-3)-6/5; 后缀表达式：1 2 3 4 - × + 5 6 / -
 * 失误:负数+'0' 不能解决负数问题，需要再写个东西 不想写
 */
#include<stdio.h>
#include<string.h>
#define maxsize 20
typedef struct stack
{
	int top;
	char data[maxsize];
}stack,*sta;
void push(stack *sta,char c)
{
	sta->data[++sta->top]=c;
	if(sta->top==maxsize)
		printf("stack over flow\n");
}
int pop(stack *sta,char c)
{
	int sum;
	if(sta->top>0)
	{
		//printf("要被计算的是:%c %c top:%d\n",sta->data[sta->top],sta->data[sta->top--],sta->top);
		int  x1=(sta->data[sta->top])-'0';
		int  x2=(sta->data[--sta->top])-'0';
		//printf("x1 =%c x2 =%c\n",x1,x2);
		//printf("top:%d\n",sta->top);
		//printf("x1=%d x2=%d\n",x1,x2);
		switch(c)
		{
			case '+':sum=x1+x2;break;
			case '-':sum=x2-x1;break;
			case '*':sum=x2*x1;break;
			case '/':sum=x2/x1;break;
		}
		//printf("sum:%d\n",sum);
		//sum=x1+x2;
		sta->top--;
		push(sta,sum+'0');
	}
	else
		printf("栈已空\n");
	return sum;
}
int caculate(char *s)
{
	int i,t;
	t=0;
	stack st;
	st.top=0;
	sta *p;
	p=&st;
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			t=pop(p,s[i]);
		}
		else
	        	push(p,s[i]);
	}
	return t;
}

int main()
{
	char a[]="1243-*+65/-";
	int ret=caculate(a);
	printf("result:%d\n",ret);
}

