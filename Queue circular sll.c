
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

struct queue{
    NODE *tail;
    int n;
};
typedef struct queue QUEUE;



//create_queue
QUEUE *create_queue(){
    QUEUE *tmp=(QUEUE*)malloc(sizeof(QUEUE));
    tmp->tail=NULL;
    tmp->n=0;
    return tmp;
}

//is-empty
int is_empty(QUEUE *s){
    if(s->n==0) return 1;
    else return 0;
}
//enqueue
void enqueue(QUEUE *s,int data){
    if (s->n==0){
        NODE *tmp=(NODE*)malloc(sizeof(NODE));
        NODE *temp;
        tmp->data=data;
        tmp->next=tmp;
        s->tail=tmp;
        s->n+=1;
    }
    else{
        NODE *tmp;
        tmp = (NODE*) malloc(sizeof(NODE));
        tmp->data = data;
        tmp->next = s->tail->next;
        s->tail->next=tmp;
        s->tail=s->tail->next;
        s->n+=1;
    }
}

//dequeue
    int dequeue(QUEUE *s){
        if(s->n==0){
            printf("No queue\n");
            exit(0);
        }
        else if(s->n==1){
            NODE *tmp;
            tmp=s->tail->next;
            s->tail=NULL;
            s->n=0;
            return tmp->data;
        }
        else{
            NODE *tmp;
            int temp;
            tmp=s->tail->next;
            s->tail->next=tmp->next;
            temp=tmp->data;
            free(tmp);
            tmp==NULL;
            s->n-=1;
            return temp;
        }
    }
//size of queue
int queue_size(QUEUE *s){
    return s->n;
}

//front queue
int front(QUEUE *s){
    return s->tail->next->data;
}
//peek
int peek(QUEUE *s){
        return s->tail->data;
}
//print

    void print(QUEUE *s){
        if(s->n==0){
            printf("No queue\n");
        }
        else{
            NODE *tmp;
            tmp=s->tail->next;
            for(int i=0;i<s->n;i++){
                printf("%d ",tmp->data);
                tmp=tmp->next;
            }
        }
        printf("\n");
    }



int main(){
    QUEUE *s;
    s=create_queue();
    printf("is_empty: %d\n",is_empty(s));
    enqueue(s,11);
    enqueue(s,15);
    enqueue(s,16);
    enqueue(s,17);
    enqueue(s,18);
    print(s);
    dequeue(s);
    dequeue(s);
    print(s);
    printf("Queue size: %d \n",queue_size(s));
    printf("front: %d\n",front(s));
    printf("Peek: %d\n",peek(s));
    printf("is_empty: %d\n",is_empty(s));

return 0;
}
