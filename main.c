#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define MAX_SIZE 100


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	typedef struct Dulnode{
		ElemType data;
		struct Dulnod *prior,*next;
	};DulNode;
	
//顺序储存表示的类型
typedef struct{
	float coef;//系数部分
	int expn;//指数部分 
}ElemType;

typedef int Status;
typedef int ElemType;
typedef struct sqlist{
	ElemType Elem_array[MAX_SIZE];
	int length;
}SqList;

//链式储存表示类型
typedef struct ploy{
	float coef;//系数部分
	int expn;//指数部分
	struct ploy *next; 
}Ploy;	
	
//顺序线性表初始化
Status Init_SqList(SqList *L){
	L->elem_array=(ElemType*)malloc(MAX_SIZE*sizeof(ElemType));
	if(!L->elem_array)return ERROR;
	else{
		L->length=0;
		return OK;
	}
}  
	
//算法描述
Status Insert_SqList(Sqlist *L, int i, ElemType e){
	int j ;
	if( i<0||i>L->length-1)
	return ERROR ;
	if(L->length>=MAX_SIZE)
	{ printf(“线性表溢出!\n”);  return ERROR ;  }
	for ( j=L->length–1; j>=i-1; --j )
	L->Elem_array[j+1]=L->Elem_array[j];
	//i-1位置以后的所有结点后移  
	L->Elem_array[i-1]=e;    //在i-1位置插入结点 
	L->length++ ;
	return  OK ; 
} 
	
//算法描述
ElemType Delete_SqList(Sqlist *L, int i){
	int K; ElemType x ;
	if(L->length==0)
	{
		printf("线性表L为空！\n"); return ERROR;
	}
	else if(i<1||i>L->length)
	{
		printf("要删除的数据元素不存在!\n");
		return ERROR;
	}
	else{
		x=L->Elem_array[i-1];//保存结点的值
		for(k==i; k<L->length; k++)
		L->Elem_array[k-1]=L->Elem_array[k];//i位置以后的所有结点前移
		L->length--;return(x); 
	}
}	
	
	//算法描述
Status Locate_Delete_SqList(Sqlist *L, ElemType x){//删除线性表L中值为X的第一个结点 
	int i=0, k ; 
	while (i<L->length){//查找值为X的第一个结点
	if(L->Elem_array[i]!=x) i++;
	else{
		for(k=i+1;k<L->length; k++)
		L->Elem_array[k-1]=L->Elem_array[k];
		L->length--; break;
	} 
  } 
  	if(i>L->length){
  		printf("要删除的数据元素不存在！\n");
  		return ERROR;
	  }
	  return OK;
}
	
//c语言中用带指针的结构体类型来描述
typedef struct Lnode{
	ElemType data;//数据域，保存 结点的值
	struct Lnode *next; //指针域 
}LNode;//结点的类型 
	
//结点的赋值
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	p->data=20; p->next=NULL; 
	
//算法的描述
LNode *create_LinkList(void){//头插入法创建单链表，链表的头结点head作为返回值 
	int data;
	LNode *head, *p;
	head=(LNode *)malloc(sizeof(LNode));
	head->next=NULL;//创建链表的表头结点head
	while(1){
		scanf("%d", &data);
		if(data==32767) break;
		(LNode *)malloc(sizeof(LNode));
		p->data=data;//数据域赋值 
		p->next=head->next; head->next=p;//钩链，新创建的结点总是作为第一个结点 
	}
	return(head); 
}	
	
//算法的描述
LNode *creat_LinkList(void){//尾插入法创建单链表，链表的头结点head作为返回值
	int data;
	LNode *head, *p, *q;
	head=p=(LNode *)malloc(sizeof(LNode));
	p->next=NUll;// 创建单链表的表头结点head
	while(1)
	{
		scanf("%d", &data);
		if(data==32767) break;
		q=(LNode *)malloc(sizeof(LNode));
		q->data=data;//数据域赋值
		q->next=p->next;
		q->next=q;
		p=q;//钩链，新创建的结点总是作为最后一个结点
	}
	return(head);
} 

算法描述
ElemType Get_Elem(LNode *L, int i)
{
	int j; LNode *p;
	p=L->next; j=1;//使p指向第一个结点
	while(p!=NULL&&j<i)
	{
		p=p->next; j++;//移动指针p , j计数
	}
	if(j!=i) return(-32767);
	else return(p->data);// p为NULL 表示i太大;  j>i表示i为0  
 } 

//算法的描述
LNode *Locate_Node(LNode *L, int key) //在以L为头结点的单链表中查找值为key的第一个结点
	{
		LNode *p=L->next;
		while(p!=NULL&&p->data!=key)
		p=p->next;
		if(p->data==key)
		return p;
		else
		{
			printf("所要查找的结点不存在！！\n");
			return(NULL);
		}
	}
	
//算法描述
void Insert_LNode(LNode *L, int i, ElemType e)// 在以L为头结点的单链表的第i个位置插入值为e的结点
	{
		int j=0; LNode *p, *q;
		p=L->next;
		while(p!=NULL&&j<i-1)
		{
			p=p->next; j++;
		}
		if(j!=i-1)
		pintf("i太大或i为0！！\n");
		else{
			q=(LNode *)malloc(sizeof(LNode));
			q->data=e; q->next=p->next;
			p->next=q;
		}
	}
	
//算法描述
void Delete_LinkList(LNode *L, int i)//删除以L为头结点的单链表中的第i个结点
	{
		int j=1; LNode *p, *q;
		p=L; q=L->next;
		while(p->next=NULL&&j<i)
		{
			p=q; q=q->next; i++;
		 } 
		 if(j!=i) printf("i太大或i为0！！\n");
		 else{
		 	p->next=q->netx; free(q);
		 }
	 } 
	 
//算法描述
void Delete_LinkList(LNode *L, int key)//删除以L为头结点的单链表中值为key的第一个结点
	{
		LNode *p=L, *q=L->next;
		while(q!=NULL&&q->data!=key)
		{
			p=q; q=q->next;
		}
		if(q->data==key)
		{
			p->next=q->next; free(q);
		}
		else printf("所要删除的结点不存在！！\n"); 
	}
	
//算法描述
void Delete_LinkList(LNode *L, int key)//删除以L为头结点的单链表中值为key的第一个结点
	{
		LNode *p=L, *q=L->next;
		while(q!=NULL)
		{
			if(q->data==key)
			{
				p->next=q->next; free(q);
				q=p->next;
			}
			else
			{
				p=q; q=q->next;
			}
		}
	}
	
//算法描述
void  Delete_Node_value(LNode *L)//删除以L为头结点的单链表中所有值相同的结点
	{
		LNode *p=L->next, *q, *ptr;
		while(p!=NULL)//检查链表中所有结点
		{
			*q=p, *ptr=p->next;//检查结点p的所有后继结点ptr
			while(ptr!=NULL)
			{
				if(ptr->data==p->data)
				{
					q->next=ptr->next; free(ptr);
					ptr=q->next;
				}
				else{
					q=ptr; ptr=ptr->next;
				}
			}
		p=p->next;	
		}
	}
	
//算法描述
LNode  *Merge_LinkList(LNode *La， LNode *Lb)//合并以La, Lb为头结点的两个有序单链表
	{
		LNode *Lc, *pa, *pb, *pc, *ptr;
		Lc=La; pc=La; pa=La->next; pb=Lb->next;
		while(pa!=NULL&&pb!=NULL)
		{
			if(pa->data<pb->data)
			{
				pc->next=pa; pc=pa; pa=pa->next;//将pa所指的结点合并，pa指向下一个结点
			}
			if(pa->data>pb->data)
			{
				pc->next=pb; pc=pb; pb=pb->next;//将pa所指的结点合并，pa指向下一个结点 
			}
			if(pa->data==pb->data)
			{
				pc->next=pa; pc=pa; pa=pa->next;
				ptr=pb; pb=pb->next; free(ptr);//将pa所指的结点合并，pb所指结点删除
			}
			if(pa!=NULL) pc->next=pa;
			else pc->next=pb;//将剩余的结点链上
			free(Lb);
			return(Lc);
		}
	}

	
	
	
	
	
	return 0;
}
