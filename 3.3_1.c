/*栈在括号匹配中的应用
 *如果匹配成功输出true 否则false
 *匹配规则：
 *        次序性
 *        数据结构：栈 如果是左括号入栈 如果是右括号 出栈
 *        如果到最后栈不为空 则返回false 
 *	  自增 自减  是有意义的。。。。。
 *	  栈这种数据结构很优美
 */
#include<stdio.h>
#include<string.h>
#define maxsize 100
#define True 1
#define False 0
typedef struct stack
{
	char data[maxsize];
	int top;
}stack,*sta;

void push(stack *s,char c);
int pop(stack *s,char c);
int match(char *s)
{
	stack s1;
	sta q;
	q=&s1;
	s1.top=0;
	int i,j,len,t,t1;
	t1=0;
	len=strlen(s);
	if(len%2!=0)
		return False;
	else
	{
	i=j=0;
	for(i=0;i<len;i++)
	{
		if(s[i]=='['||s[i]=='('||s[i]=='{')
		{

			if(i==len-1)
				return False;
			push(q,s[i]);
		}
		else
		{
			t=pop(q,s[i]);
			if(t==0)
				return False;
		}

	}
	}
	return True;
}
void push(stack *s,char c)
{
	s->data[++s->top]=c;
}
int pop(stack *s,char c)
{
	if(s->data[s->top]=='['&&c==']'||s->data[s->top]=='('&&c==')'||s->data[s->top]=='{'&&c=='}')
	{
		s->data[s->top--];
		return 1;
	}
	else
		return 0;
	
}

int main()
{
	char *s="{[";
	int ret=match(s);
	printf("answer:%d",ret);
}
