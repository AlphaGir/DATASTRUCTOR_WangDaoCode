/* 二叉树创建 遍历
 * 前缀表达式 中缀表达式 后缀表达式 对应 先序遍历 中序遍历 后序遍历 
 * P121-123
 * ------------
 *  递归函数在递归过程中，不同层次的同名变量在赋值的时候会产生相互影响吗？是一定会，还是有可能会？ 不会。
 *  在子函数内部 malloc 内存情况 当malloc指向的指针已经有内存的时候
 *  递归函数里两个递归语句执行顺序 第一个递归执行完 和我想的一样 是这个垃圾书有问题
 *  二叉树深度问题，递归确实可以解决很多问题，，，，除了不会写 没有毛病
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
typedef struct binode
{
	struct binode *left;
	struct binode *right;
	int data;
}binode,*bino;
typedef struct stack
{
	int top;
	bino da[maxsize];
}stack,*sta;
typedef struct
{
	bino t;
	int tag;
}stack1;
typedef struct queue
{
	int front;
	int rear;
	bino da[maxsize];
}queue,*que;
// 层次遍历找到结点最多的那一层 21:50
typedef struct
{
	bino data[maxsize];
	int level[maxsize];
	int front,rear;
}qu;
int width(bino b)
{
	bino p=(bino)malloc(sizeof(binode));
	int k,max,i,n;
	qu qu;
	qu.front=qu.rear=-1;
	qu.rear++;
	qu.data[qu.rear]=b;
	qu.level[qu.rear]=-1;
	while(qu.front<qu.rear)
	{
		qu.front++;
		p=qu.data[qu.front];
		k=qu.level[qu.front];
		if(p->left!=0)
		{
			qu.rear++;
			qu.data[qu.rear]=p->left;
			qu.level[qu.rear]=k+1;
		}
		if(p->right!=0)
		{
			qu.rear++;
			qu.data[qu.rear]=p->right;
			qu.level[qu.rear]=k+1;
		}
	}
	max=0;i=0;
	k=1;
	while(i<=qu.rear)
	{
		n=0;
		while(i<=qu.rear&&qu.level[i]==k)
		{
			n++;
			i++;
		}
		k=qu.level[i];
		if(n>max) max=n;
	}
	return max;
}
void enqueue(que q,bino p)
{
	q->da[++q->rear]=p;
}
bino dequeue(que q,bino p)
{
	p=q->da[++q->front];
	return p;
}

bino createBi();//递归创建二叉树
void search_Mid(bino B);//中序递归遍历二叉树
void push(sta p,bino d);
bino pop(sta p,bino d);
void search_hierarchy(bino B)//二叉树层次遍历 1.构建一个顺序队列 将元素依次入
{
	queue qu;
	que q=&qu;
	q->front=-1;
	q->rear=-1;
	if(!B) return ;
	bino p=(bino)malloc(sizeof(binode));
	enqueue(q,B);
	do{
		p=dequeue(q,p);	
		printf("value:%d\n",p->data);
		if(p->left)
			enqueue(q,p->left);
		if(p->right)
			enqueue(q,p->right);
	  }while(q->front!=q->rear);
}
void search_reverse_hierarchy(bino B)//从下到上 从右到左遍历二叉树。构建队列 栈。
{
	queue qu;
        que q=&qu;
        q->front=-1;
        q->rear=-1;
	 stack t;
        sta s;
        s=&t;
        t.top=-1;
        if(!B) return ;
        bino p=(bino)malloc(sizeof(binode));
        enqueue(q,B);
        do{
                p=dequeue(q,p);
		push(s,p);
    //            printf("value:%d\n",p->data);
                if(p->left)
                        enqueue(q,p->left);
                if(p->right)
                        enqueue(q,p->right);
          }while(q->front!=q->rear);
	while(s->top!=-1)
	{
		p=pop(s,p);
		printf("value:%d",p->data);
	}

}
 /*       stack t;
        sta s;
        s=&t;
    	t.top=-1;
*/
void postorder(int pre[],int in[],int length)//由前序和中序得出后序
{
	if(length<1) return;
	int i=0;
	while(in[i]!=pre[0]) ++i;
	postorder(pre+1,in,i);
	postorder(pre+i+1,in+1+i,length-i-1);
	//push(s,pre[0]);存入栈。
	/*
	 *push(s,pre[0]); 输出
	 */
}
bino find_leave(bino B)
{
	queue qu;
	que q=&qu;
	q->rear=-1;
	q->front=-1;
	if(B==0) printf("无叶子节点");
	enqueue(q,B);
	bino p=(bino)malloc(sizeof(binode));
	bino t,head;
	head=(bino)malloc(sizeof(binode));
	t=(bino)malloc(sizeof(binode));
	head->left=0;
	head->right=0;
	bino r=(bino)malloc(sizeof(binode));
	r=head;
	while(q->front!=q->rear)
	{
		p=dequeue(q,p);
		if(p->left)
			enqueue(q,p->left);
		if(p->right)
			enqueue(q,p->right);
		if(p->left==0&&p->right==0)
		{
			r->right=p;
			r=p;
		}
	}
	return head;	
}


int num=0;
int double_node(bino B)
{
	if(B==0) return 0;
	else if(B->left!=0&&B->right!=0)
		return double_node(B->left)+double_node(B->right)+1;
	else
		return double_node(B->left)+double_node(B->right);
}
void preorder(int post[],int in[],int length)
{
	if(length<1) return;
	int i=0;
	while(in[i]!=post[length-1]) ++i;
	//push(s,post[length-1]);
	preorder(post,in,i);
	preorder(post+i,in+i+1,length-i-1);
}
void delete_x(bino B)
{
	if(B)
	{

		delete_x(B->left);
		delete_x(B->right);
		free(B);
	}
}
int similar(bino B,bino B1)
{
	int lefts,rights;
	if(B==0&&B1==0)
	   return 1;
	else if(B==0||B1==0)
		return 0;
	else
	{
		lefts=similar(B->left,B1->left);
		rights=similar(B->right,B1->right);
		return lefts&&rights;
	}
}
/*
 *在中序线索二叉树里，求指定节点p在后序下的前驱节点
 *
 */
bino inpostpre(bino t,bino p)
{
	bino q=(bino)malloc(sizeof(binode));
	if(p->rtag==0)
		q=p->right;
	else if(p->ltag==0)
		q=p->left;
	else if(p->left==0)
		q=0;
	else
	{
		while(p->ltag==1&&p->left!=0)
			p=p->left;
		if(p->ltag==0)
			q=p->left;
		else q=0;
	}
	return q;
}
bino search_x(bino B,int x)
{
	queue qu;
        que q=&qu;
        q->front=-1;
        q->rear=-1;
	bino p=(bino)malloc(sizeof(binode));
	if(B)
	{
		if(B->data==x)
		{
			delete_x(B);
		        exit(0);
		}
	
	enqueue(q,B);
	do
	{
		p=dequeue(q,p);
		if(p->left)
		{
			if(p->left->data==x)
			{
				delete_x(p->left);
				p->left=0;
			}
			else
				enqueue(q,p->left);
		}
		if(p->right)
		{
			if(p->right->data==x)
			{
				delete_x(p->right);
				p->right=0;
			}
			else
				enqueue(q,p->right);
		}
	}while(q->front!=q->rear);
	}
	return B;
}
void find_ancestor(bino B,int x)
{
	stack1 s[10];
	int top=0;
	while(B!=0||top!=0)
	{
		while(B!=0&&B->data!=x)
		{
			s[++top].t=B;
			s[top].tag=0;
			B=B->left;
		}
		if(B->data==x)
		{
			int i;
			for(i=1;i<=top;i++)
				printf("%d",s[i].t->data);
			exit(1);
		}
		while(top!=0&&s[top].tag==1)
			top--;
		if(top!=0)
		{
			s[top].tag=1;
			B=s[top].t->right;
		}
	}
} 
void pretopost(int pre[],int start1,int end1,int post[],int start2,int end2)
{
	int half;
	if(end1>=start1)
	{
		post[end2]=pre[start1];
		half=(end1-start1)/2;
		pretopost(pre,start1+1,start1+half,post,start2,start2+half-1);
		//将pre左子树转换成post左子树 end start均为下标对照pre post下标思考 不断对半。
		pretopost(pre,start1+half+1,end1,post,start2+half,end2-1);
		//将pre右子树转换成post右子树
	}
}
int count_hierarchy(bino B)//非递归记录二叉树层次  
{
	queue qu;
	que q=&qu;
	q->front=-1;
	q->rear=-1;
	int leavel=0;
	int last=0;
	bino p=(bino)malloc(sizeof(binode));
	if(!B) return 0;
	enqueue(q,B);
    do
    {
	p=dequeue(q,p);
	if(p->left)
		enqueue(q,p->left);
	if(p->right)
		enqueue(q,p->right);
	if(q->front==last)
	{
		leavel++;
		last=q->rear;
	}
    }while(q->front<q->rear);
    return leavel;
}
	
int iscomplete(bino T)//判断二叉树是不是完全二叉树
{
	queue qu;
	que q=&qu;
	q->front=-1;
	q->rear=-1;
	if(!T) return 1;
	bino p=(bino)malloc(sizeof(binode));
	p=T;
	enqueue(q,p);
	do
	{
		p=dequeue(q,p);
		if(p)
		{
			enqueue(q,p->left);
			enqueue(q,p->right);
		}
		else
		{
			do
			{
				p=dequeue(q,p);
				if(p)
					return 0;
			}while(q->front!=q->rear);
		}
	}while(q->front!=q->rear);
	return 1;
}
bino copy(bino B,bino B1)
{
	if(B)
	{
		//B1->data=B->data;
		B1=(bino)malloc(sizeof(binode));
		B1->data=B->data;
		B1->left=copy(B->left,B1->left);
                B1->right=copy(B->right,B1->right);
	}
	return B1;
}
int depth(bino B)//二叉树深度
{
	int m,n;
	 n=0;
	if(B==0) return 0;
	else
	{
		m=depth(B->left);
		n=depth(B->right);
		if(m>n) return m+1;
		else  return n+1;
	}	
}
int count(bino B)//统计二叉树结点个数
{
	int sum=0;
	if(B==0) return 0;
	else
        return count(B->left)+count(B->right)+1;
}

bino createBi()//递归创建二叉树 
{
	char ch;
	bino B;
	scanf("%d",&ch);
	if(ch==-1) B=NULL;
	else
	{
		B=(bino)malloc(sizeof(binode));//
		B->data=ch;
		B->left=createBi();
		B->right=createBi();
	}
	return B;
}

bino swap(bino B)
{
	if(B)
	{
		bino t=(bino)malloc(sizeof(binode));
		t=B->left;
		B->left=B->right;
		B->right=t;
		swap(B->left);
		swap(B->right);
	}
	return B;
}
bino swap1(bino B)
{
	if(B)
	{
		bino t=(bino)malloc(sizeof(binode));
		swap(B->left);
		swap(B->right);
		t=B->left;
		B->left=B->right;
		B->right=t;
	}
	return B;
}
//int static i=1;
void search_pre(bino B,int k)
{
	//int a;
	if(B)
	{
		k--;
		if(k==0) 
		{
			printf("%d",B->data);
			//return B->data;
			exit(0);
		}
		search_pre(B->left,k);
		search_pre(B->right,k);
		
	}
}
void search_Mid(bino B)//中序递归遍历二叉树
{
	if(B)
	{
		search_Mid(B->left);
		printf("%d ",B->data);
		search_Mid(B->right);
	}
        //printf("%d ",B->data);
	//printf("------------------------------\n");
}
void push(sta p,bino d)
{
	p->da[++p->top]=d;
}
bino pop(sta p,bino d)
{
	d=p->da[p->top--];
	return d;
}
bino top(sta p)
{
	return p->da[p->top];
}
void search_Mid_no(bino B)
{
	stack t;
	sta s;
	s=&t;
	t.top=-1;
	bino p,q,p1;
        p=B;
	binode b;
	q=(bino)malloc(sizeof(binode));
	while(p||s->top>-1)
	{
		if(p)
		{
			push(s,p);
			p=p->left;
		}	
		else
		{
			p1=pop(s,q);
			printf("value:%d",p1->data);
			p=p1->right;
		}
	}
}
void search_post(bino B)//后序非递归遍历
{
	stack t;
	sta s=&t;
	t.top=-1;
	bino p,r,p1;
	p=B;
	r=(bino)malloc(sizeof(binode));
	r=0;
	p1=(bino)malloc(sizeof(binode));

	while(p||s->top>-1)
	{
		if(p)
		{
			push(s,p);
			p=p->left;
		}
		else
		{
			p=top(s);
			if(p->right&&p->right!=r)
			{
			  p=p->right;
	  		  push(s,p);
			  p=p->left;
			}
      			else
			{
			 p=pop(s,p1);
 			 printf("value:%d",p->data);
			 r=p;
			 p=0;
			}
		}
	}
}	

int main()
{
	binode B;
	bino p,p2;
	p=createBi();//先序创建二叉树
	//int ret=double_node(p);
	//p2=search_x(p,3);
	//search_x(p,4);
	//printf("\n");
	//search_reverse_hierarchy(p);
	//p2=delete_x(p,3);
	//search_post(p2);
	//printf("ret:%d \n",ret);
	//p2=swap(p);
	p2=find_leave(p);
	while(p2!=0)
	{
		printf("value:%d\n",p2->data);
		p2=p2->right;
	}
	 //search_Mid(p2);

	//search_Mid(p2);
	//int h=depth(B);
	//prin("\n");
	//printf("中序遍历为:\n");
	//search_Mid(p);
	//printf(":\n");
	//search_Mid_no(p);
	//p2=copy(p,&B);
	//search_Mid(p2);
	//int sum=count(p);
	//printf("sum:%d\n",sum);
}
