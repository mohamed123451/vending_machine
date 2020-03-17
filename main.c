#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    struct node *prv , *nxt;
    int id;
    char name[10];
    float coast;
}*start,*ende;

void intial(){
    start=ende=NULL;
}

struct node* create(int val){
    struct node *p;
    p=malloc(sizeof(struct node));
    p->id=val;
    p->prv=NULL;
    p->nxt=NULL;
    return p;
}

void insrt(struct node *e){
    struct node *temp=start;
    if(start==NULL)
    {
        start=e;
        ende=e;
    }
    else
    {
        while(temp!=NULL&&temp->id < e->id)
        {
            temp=temp->nxt;
        }
        if(temp==NULL)
            {
                e->prv=ende;
                ende->nxt=e;
                ende=e;

            }
            else if(temp==start)
            {
                e->nxt=start;
                start->prv=e;
                start=e;
            }
            else
            {
                e->prv=temp->prv;
                e->nxt=temp;
                temp->prv->nxt=e;
                temp->prv=e;
            }

    }

}

void print_list(){
    struct node *temp=start;
    if(temp==NULL)
        printf("the list is empty");
    else
    {
        for(;temp!=NULL;temp=temp->nxt)
        {
            printf("\nname  : %s",temp->name);
            printf("\nId    : %d",temp->id);
            printf("\ncoast : %f",temp->coast);
            printf("\n______\n");
        }
    }
}

void del(int val){
    struct node *s=start;
    if(val==s->id)
    {
        start=s->nxt;
        s->prv=NULL;
    }
    else
    {
        struct node *temp=s;
        while(temp!=NULL&&temp->id < val)
        {
            temp=temp->nxt;
        }
        if(temp!=NULL)
        {
            temp->prv->nxt=temp->nxt;
            temp->nxt->prv=temp->prv;
        }
        else
        printf("this element is not exist");
    }
}

int main()
{    intial();


    for(;;)
{
    int i;
    printf("\n1--->insert\n2--->del\n3--->print\n4--->end\n");
    scanf("%d",&i);
    if(i==4)
        break;
    else
    {
        switch(i){
            case(1):{
            int x;
            float y;
            printf("id : ");
            scanf("%d",&x);
            printf("coast : ");
            scanf("%f",&y);
            struct node *p=create(x);
            insrt(p);
            p->coast=y;
            printf("name : ");
            scanf("%s",p->name);
            }break;
            case(2):{
            int f;
            printf("delete id : ");
            scanf("%d",&f);
            del(f);
            }break;
            case(3):{
            print_list();
        }break;
        default:{printf("\ninvalid choise\n");}
    }
    }
}
    return 0;
}
