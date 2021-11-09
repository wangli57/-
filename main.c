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
	
//˳�򴢴��ʾ������
typedef struct{
	float coef;//ϵ������
	int expn;//ָ������ 
}ElemType;

typedef int Status;
typedef int ElemType;
typedef struct sqlist{
	ElemType Elem_array[MAX_SIZE];
	int length;
}SqList;

//��ʽ�����ʾ����
typedef struct ploy{
	float coef;//ϵ������
	int expn;//ָ������
	struct ploy *next; 
}Ploy;	
	
//˳�����Ա��ʼ��
Status Init_SqList(SqList *L){
	L->elem_array=(ElemType*)malloc(MAX_SIZE*sizeof(ElemType));
	if(!L->elem_array)return ERROR;
	else{
		L->length=0;
		return OK;
	}
}  
	
//�㷨����
Status Insert_SqList(Sqlist *L, int i, ElemType e){
	int j ;
	if( i<0||i>L->length-1)
	return ERROR ;
	if(L->length>=MAX_SIZE)
	{ printf(�����Ա����!\n��);  return ERROR ;  }
	for ( j=L->length�C1; j>=i-1; --j )
	L->Elem_array[j+1]=L->Elem_array[j];
	//i-1λ���Ժ�����н�����  
	L->Elem_array[i-1]=e;    //��i-1λ�ò����� 
	L->length++ ;
	return  OK ; 
} 
	
//�㷨����
ElemType Delete_SqList(Sqlist *L, int i){
	int K; ElemType x ;
	if(L->length==0)
	{
		printf("���Ա�LΪ�գ�\n"); return ERROR;
	}
	else if(i<1||i>L->length)
	{
		printf("Ҫɾ��������Ԫ�ز�����!\n");
		return ERROR;
	}
	else{
		x=L->Elem_array[i-1];//�������ֵ
		for(k==i; k<L->length; k++)
		L->Elem_array[k-1]=L->Elem_array[k];//iλ���Ժ�����н��ǰ��
		L->length--;return(x); 
	}
}	
	
	//�㷨����
Status Locate_Delete_SqList(Sqlist *L, ElemType x){//ɾ�����Ա�L��ֵΪX�ĵ�һ����� 
	int i=0, k ; 
	while (i<L->length){//����ֵΪX�ĵ�һ�����
	if(L->Elem_array[i]!=x) i++;
	else{
		for(k=i+1;k<L->length; k++)
		L->Elem_array[k-1]=L->Elem_array[k];
		L->length--; break;
	} 
  } 
  	if(i>L->length){
  		printf("Ҫɾ��������Ԫ�ز����ڣ�\n");
  		return ERROR;
	  }
	  return OK;
}
	
//c�������ô�ָ��Ľṹ������������
typedef struct Lnode{
	ElemType data;//�����򣬱��� ����ֵ
	struct Lnode *next; //ָ���� 
}LNode;//�������� 
	
//���ĸ�ֵ
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	p->data=20; p->next=NULL; 
	
//�㷨������
LNode *create_LinkList(void){//ͷ���뷨���������������ͷ���head��Ϊ����ֵ 
	int data;
	LNode *head, *p;
	head=(LNode *)malloc(sizeof(LNode));
	head->next=NULL;//��������ı�ͷ���head
	while(1){
		scanf("%d", &data);
		if(data==32767) break;
		(LNode *)malloc(sizeof(LNode));
		p->data=data;//������ֵ 
		p->next=head->next; head->next=p;//�������´����Ľ��������Ϊ��һ����� 
	}
	return(head); 
}	
	
//�㷨������
LNode *creat_LinkList(void){//β���뷨���������������ͷ���head��Ϊ����ֵ
	int data;
	LNode *head, *p, *q;
	head=p=(LNode *)malloc(sizeof(LNode));
	p->next=NUll;// ����������ı�ͷ���head
	while(1)
	{
		scanf("%d", &data);
		if(data==32767) break;
		q=(LNode *)malloc(sizeof(LNode));
		q->data=data;//������ֵ
		q->next=p->next;
		q->next=q;
		p=q;//�������´����Ľ��������Ϊ���һ�����
	}
	return(head);
} 

�㷨����
ElemType Get_Elem(LNode *L, int i)
{
	int j; LNode *p;
	p=L->next; j=1;//ʹpָ���һ�����
	while(p!=NULL&&j<i)
	{
		p=p->next; j++;//�ƶ�ָ��p , j����
	}
	if(j!=i) return(-32767);
	else return(p->data);// pΪNULL ��ʾi̫��;  j>i��ʾiΪ0  
 } 

//�㷨������
LNode *Locate_Node(LNode *L, int key) //����LΪͷ���ĵ������в���ֵΪkey�ĵ�һ�����
	{
		LNode *p=L->next;
		while(p!=NULL&&p->data!=key)
		p=p->next;
		if(p->data==key)
		return p;
		else
		{
			printf("��Ҫ���ҵĽ�㲻���ڣ���\n");
			return(NULL);
		}
	}
	
//�㷨����
void Insert_LNode(LNode *L, int i, ElemType e)// ����LΪͷ���ĵ�����ĵ�i��λ�ò���ֵΪe�Ľ��
	{
		int j=0; LNode *p, *q;
		p=L->next;
		while(p!=NULL&&j<i-1)
		{
			p=p->next; j++;
		}
		if(j!=i-1)
		pintf("i̫���iΪ0����\n");
		else{
			q=(LNode *)malloc(sizeof(LNode));
			q->data=e; q->next=p->next;
			p->next=q;
		}
	}
	
//�㷨����
void Delete_LinkList(LNode *L, int i)//ɾ����LΪͷ���ĵ������еĵ�i�����
	{
		int j=1; LNode *p, *q;
		p=L; q=L->next;
		while(p->next=NULL&&j<i)
		{
			p=q; q=q->next; i++;
		 } 
		 if(j!=i) printf("i̫���iΪ0����\n");
		 else{
		 	p->next=q->netx; free(q);
		 }
	 } 
	 
//�㷨����
void Delete_LinkList(LNode *L, int key)//ɾ����LΪͷ���ĵ�������ֵΪkey�ĵ�һ�����
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
		else printf("��Ҫɾ���Ľ�㲻���ڣ���\n"); 
	}
	
//�㷨����
void Delete_LinkList(LNode *L, int key)//ɾ����LΪͷ���ĵ�������ֵΪkey�ĵ�һ�����
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
	
//�㷨����
void  Delete_Node_value(LNode *L)//ɾ����LΪͷ���ĵ�����������ֵ��ͬ�Ľ��
	{
		LNode *p=L->next, *q, *ptr;
		while(p!=NULL)//������������н��
		{
			*q=p, *ptr=p->next;//�����p�����к�̽��ptr
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
	
//�㷨����
LNode  *Merge_LinkList(LNode *La�� LNode *Lb)//�ϲ���La, LbΪͷ����������������
	{
		LNode *Lc, *pa, *pb, *pc, *ptr;
		Lc=La; pc=La; pa=La->next; pb=Lb->next;
		while(pa!=NULL&&pb!=NULL)
		{
			if(pa->data<pb->data)
			{
				pc->next=pa; pc=pa; pa=pa->next;//��pa��ָ�Ľ��ϲ���paָ����һ�����
			}
			if(pa->data>pb->data)
			{
				pc->next=pb; pc=pb; pb=pb->next;//��pa��ָ�Ľ��ϲ���paָ����һ����� 
			}
			if(pa->data==pb->data)
			{
				pc->next=pa; pc=pa; pa=pa->next;
				ptr=pb; pb=pb->next; free(ptr);//��pa��ָ�Ľ��ϲ���pb��ָ���ɾ��
			}
			if(pa!=NULL) pc->next=pa;
			else pc->next=pb;//��ʣ��Ľ������
			free(Lb);
			return(Lc);
		}
	}

	
	
	
	
	
	return 0;
}
