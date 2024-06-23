#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
int select;
int op;
int op1;
int val;
void main_maseg()
{
    cout<<"What Do You Want To Represent? \n\n";
    cout<<"  1: Stack \n";
    cout<<"  2: Queue \n";
    cout<<"  3: Linked List \n";
    cout<<"  4: Double List \n\n";
    cout<<"Enter The Transaction Number-> ";
}
///////////////////////liner queue///////////////////////////
struct liner_q
{
 int liner_q_data;
 liner_q *liner_q_next;
};
liner_q *liner_q_head=NULL,*liner_q_tail=NULL,*liner_q_np=NULL;
int liner_q_isempty()
{
    if (liner_q_head == NULL)
        return 0;
    else
        return 1;
}
void liner_q_push(int x)
{
    liner_q_np = new liner_q;
    liner_q_np->liner_q_data = x;
    liner_q_np->liner_q_next = NULL;
    if (liner_q_head == NULL)
        liner_q_head = liner_q_tail = liner_q_np;
    else
    {
        liner_q_tail->liner_q_next = liner_q_np;
        liner_q_tail = liner_q_np;
    }
}
void liner_q_pop()
{
    if (liner_q_isempty())
    {
        liner_q *p = liner_q_head;
        cout <<"delete-> "<<liner_q_head->liner_q_data << endl<< endl;
        liner_q_head = liner_q_head->liner_q_next;
        delete p;
    }
    else
        cout << "queue is empty\n";
        system("pause");
}
void liner_q_op_menu()
{
    cout<<"    ---Liner Queue---\n";
    cout<<"Enter the transaction number\n\n";
    cout<<"  1->Push\n";
    cout<<"  2->Pop\n\n";
    cout<<"Press 0 to Main Menu\n\n";
}
void liner_q_print()
{
    liner_q *temp = liner_q_head;
    while (temp != NULL)
    {
        cout <<"|"<< temp->liner_q_data << "|";
        temp = temp->liner_q_next;
    }
    cout << "\n\n";
}
///////////////////////stack///////////////////////////
struct stack1
{
    int stack_data;
    stack1 *stack_last;
};
stack1 *top=NULL , *stack_np=NULL;
int stack_isempty()
{
    if(top == NULL)
        return 0;
    else
        return 1;
}
int stack_push (int val)
{
    stack_np=new stack1;
    stack_np->stack_data = val;
    stack_np->stack_last = NULL;

    if(top != NULL)
        stack_np->stack_last = top;

    top = stack_np;
}
void stack_pop ()
{
    if(stack_isempty())
    {
        top = stack_np->stack_last;
        cout<<"delete-> "<<stack_np->stack_data<<"\n"<< endl;
        delete stack_np;
        stack_np = top;
    }
    else
        cout<<"stack is empty\n";
        system("pause");
}
void stack_print()
{
    stack1 *temp = top;
    while (temp != NULL)
    {
        cout <<"    |"<< temp->stack_data << "|\n";
        temp = temp->stack_last;
    }
        cout << "\n\n";

}
void stack_maseg()
{
    cout<<"    ---Stack---\n";
    cout<<"Enter the transaction number\n\n";
    cout<<"  1->Push\n";
    cout<<"  2->Pop\n\n";
    cout<<"Press 0 to Main Menu\n\n";

}
///////////////////////////Linked List///////////////////////////////
struct node
{
 int data;
 node *next;
};
node *np=NULL,*head=NULL,*tail=NULL, *l_tail;
void create_node()
{
    np=new node;
    cout<<"input data:";
    cin>>np->data;
    np->next=NULL;
    cout<<"******************\n";
}
void create_list()
{
             np=new node;
             cout<<"input data:";
             cin>>np->data;
             np->next=NULL;
        if(head==NULL)
             head=tail=np;
         else
         {
             tail->next=np;
             tail=np;
         }
}
void print_list()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << "\n\n";
}
void add_last()
{
 create_list();
 tail=head;
 while(tail->next !=NULL)
    tail=tail->next;

 tail->next=np;
 tail=np;
}
void del_first()
{
 tail=head;
 head=head->next;
 delete tail;
}
void del_last()
{
 tail=head;
 node *c=NULL;
 while(tail->next !=NULL)
 {
     c=tail;
     tail=tail->next;
 }
 delete tail;
 c->next=NULL;
}
void add_first()
{
create_node();
np->next=head;
head=np;
}
int Search_list()
{
cout<<"input search the num of data:";
cin>>val;
tail=head;
int p=0;
while(tail !=NULL)
{
    if(tail->data==val)
    {
        p=1;
        break;
    }
l_tail=tail;
tail=tail->next;
}
return p;
}
void add_after()
{
if(Search_list())
{
    create_node();
    np->next=tail->next;
    tail->next=np;
}
else
    cout<<"not found";
}
void add_before()
{
    if(Search_list())
    {
        if(head==tail)
        {
            add_first();
        }
        else
        {
            create_node();
            l_tail->next=np;
            np->next=tail;
        }
    }
    else
        cout<<"not found\n";
}
void del_any()
{
    if(Search_list())
    {
        if(tail==head)
        {
            head=head->next;
            delete tail;
        }
        else
        {
            l_tail->next=tail->next;
            delete tail;
        }
    }
    else
    cout<<"not found\n";
}
void sort_list()
{
    tail=head;
    while(tail !=NULL)
    {
        node *c=tail->next;
        while(c!=NULL)
        {
            if(c->data < tail->data)
            swap(c->data,tail->data);
            c=c->next;
        }
        tail=tail->next;
    }
}
void linked_list_op_menu()
{
    cout<<"    ---Linked List---\n";
    cout<<"Enter the transaction number\n\n";
    cout<<"  1->Create list\n";
    cout<<"  2->Add Last\n";
    cout<<"  3->Add First\n";
    cout<<"  4->Add After\n";
    cout<<"  5->Add Before\n";
    cout<<"  6->Del First\n";
    cout<<"  7->Del Last\n";
    cout<<"  8->Del Any\n\n";
    cout<<"Press 0 to Main Menu\n\n";
}
/////////////////////////////double list///////////////////////////////
struct d_node
{
 int d_data;
 d_node *d_next,*d_last;
};
d_node *d_np=NULL,*d_head=NULL,*d_tail=NULL;
void d_create_node()
{
     cout<<"input new node:";
     d_np=new d_node;
     cin>>d_np->d_data;
     d_np->d_next=NULL;
     d_np->d_last=NULL;
}
void d_create_list()
{
     d_np=new d_node;
     cout<<"input data:";
     cin>>val;
     d_np->d_data=val;
     d_np->d_next=NULL;
     d_np->d_last=NULL;
     if(d_head==NULL)
         d_head=d_tail=d_np;
     else
     {
         d_tail->d_next=d_np;
         d_np->d_last=d_tail;
         d_tail=d_np;
     }
}
void d_print_list()
{
    d_node *d_temp = d_head;
    while (d_temp != NULL)
    {
        cout << d_temp->d_data << "  ";
        d_temp = d_temp->d_next;
    if(d_temp==d_head)
        break;
    }
    cout << "\n\n";
}
void d_add_first()
{
    d_create_node();

    if (d_head == NULL) {
        d_head = d_tail = d_np;
    } else {
        d_np->d_next = d_head;
        d_head->d_last = d_np;
        d_head = d_np;
    }
}
void d_add_last()
{
     d_create_node();
     d_head->d_last->d_next=d_np;
     d_np->d_last=d_head->d_last;
     d_np->d_next=d_head;
     d_head->d_last=d_np;
}
void d_del_first()
{
    if (d_head == NULL) {
        cout << "Empty list, nothing to delete.\n\n";
        system("pause");

        return;
    }

    d_node *d_c = d_head;

    if (d_head == d_tail) {
        d_head = d_tail = NULL;
    } else {
        d_head = d_head->d_next;
        d_head->d_last = NULL;
        d_tail->d_next = d_head;
    }

    delete d_c;
}
void d_del_last()
{
    if (d_head == NULL)
    {
        cout << "Empty list, nothing to delete.\n\n";
        system("pause");
        return;
    }

    if (d_head == d_tail)
    {
        delete d_head;
        d_head = d_tail = NULL;
    }
    else
    {
        d_node *temp = d_tail;
        d_tail = d_tail->d_last;
        d_tail->d_next = NULL;
        delete temp;
    }
}
int d_search_list()
{
     int value,p=0;
     cout<<"input search value:";
     cin>>value;
     d_tail=d_head;
     while(d_tail !=NULL)
     {
        if(d_tail->d_data==value)
         {
             p=1;
             break;
         }
        d_tail=d_tail->d_next;
     }
     return p;
}
void d_del_any()
{
     if(d_search_list())
     {
         if(d_tail==d_head)
         {
            d_del_first();
         }
         else if(d_tail->d_next==NULL)
         {
            d_del_last();
         }
         else
         {
             d_tail->d_last->d_next=d_tail->d_next;
             d_tail->d_next->d_last=d_tail->d_last;
             delete d_tail;
         }
     }
     else
        cout<<"not found\n";
}
void d_add_after()
{
     if(d_search_list())
     {
         if(d_tail->d_next==NULL)
         {
            d_add_last();
         }
         else
         {
             d_create_node();
             d_np->d_next=d_tail->d_next;
             d_tail->d_next->d_last=d_np;
             d_tail->d_next=d_np;
             d_np->d_last=d_tail;
         }
     }
     else
        cout<<"not found\n";
}
void d_add_before()
{
     if(d_search_list())
     {
         if(d_tail==d_head)
         {
            d_add_first();
         }
         else
         {
            d_create_node();
            d_tail->d_last->d_next=d_np;
            d_np->d_last=d_tail->d_last;
            d_np->d_next=d_tail;
            d_tail->d_last=d_np;
         }
     }
     else
        cout<<"not found\n";
}
void d_update_node()
{
     if(d_search_list())
     {
         int new_data;
         cout<<"input new data:";
         cin>>new_data;
         d_tail->d_data=new_data;
     }
     else
        cout<<"not found\n";
}
void d_sort_list()
{
     d_tail=d_head;
     while(d_tail !=NULL)
     {
        d_node *d_c=d_tail->d_next;
         while(d_c !=NULL)
         {
            if(d_c->d_data < d_tail->d_data)
                swap(d_c->d_data,d_tail->d_data);
                d_c=d_c->d_next;
         }
                d_tail=d_tail->d_next;
     }
}
void d_list_op_menu()
{
     cout<<"    ---Double List---\n";
    cout<<"Enter the transaction number\n\n";
    cout<<"  1->Create list\n";
    cout<<"  2->Add Last\n";
    cout<<"  3->Add First\n";
    cout<<"  4->Add After\n";
    cout<<"  5->Add Before\n";
    cout<<"  6->Del First\n";
    cout<<"  7->Del Last\n";
    cout<<"  8->Del Any\n";
    cout<<"  9->Update Node\n";
    cout<<"  10->Sort List\n\n";
    cout<<"Press 0 to Main Menu\n\n";
}
///////////////////////////Main//////////////////////////////
int main()
{
    while(1)
    {
        system("cls");
        main_maseg();
        cin>>select;
        system("cls");

        if(select == 1)
        {
            stack_print();
            stack_maseg();
            cout<<"->";
            cin>>op;
            cout<<"\n";
            system("cls");
              while(1)
                {
                        switch(op)
                        {
                        case 1:
                            cout<<"insert the value : ";
                            cin>> val;
                            stack_push(val);
                            cout<<"\n";
                            break;

                        case 2:
                            stack_pop();
                            cout<<"\n";
                            break;
                        case 0:
                            main();
                            break;
                        }
                        system("cls");
                        stack_print();
                        stack_maseg();
                        cout<<"->";
                        cin>>op;
                        cout<<"\n";
                }
        }

//////////////////////////////////////////////////////////////////////

        else if(select == 2)
        {
            liner_q_print();
            liner_q_op_menu();
            cout<<"->";
            cin>>op;
            cout<<"\n";
            system("cls");
            while(1)
            {

                    switch(op)
                    {
                        case 1:
                            cout<<"insert the value : ";
                            cin>> val;
                            liner_q_push(val);
                            cout<<"\n";
                            break;

                        case 2:
                            liner_q_pop();
                            cout<<"\n";
                            break;
                        case 0:
                            main();
                    }
                        system("cls");
                        liner_q_print();
                        liner_q_op_menu();
                        cout<<"->";
                        cin>>op;
                        cout<<"\n";
            }

        }

//////////////////////////////////////////////////////////////////////

        else if(select == 3)
        {
            print_list();
            linked_list_op_menu();
            cout<<"->";
            cin>>op;
            cout<<"\n";
            system("cls");
            while(1)
                {
                        switch(op)
                        {
                        case 1:
                            create_list();
                            break;

                        case 2:
                            create_list();
                            break;
                        case 3:
                            add_first();
                            break;
                        case 4:
                            add_after();
                            break;
                        case 5:
                            add_before();
                            break;
                        case 6:
                            del_first();
                            break;
                        case 7:
                            del_last();
                            break;
                        case 8:
                            del_any();
                            break;
                        case 0:
                            main();


                        }
                        system("cls");
                        print_list();
                        linked_list_op_menu();
                        cout<<"->";
                        cin>>op;
                        cout<<"\n";
                }
        }

/////////////////////////////////////////////////////////////////////

        else if(select == 4)
        {
            d_print_list();
            d_list_op_menu();
            cout<<"->";
            cin>>op;
            cout<<"\n";
            system("cls");
            while(1)
                {
                        switch(op)
                        {
                        case 1:
                            d_create_list();
                            break;

                        case 2:
                            d_create_list();
                            break;
                        case 3:
                            d_add_first();
                            break;
                        case 4:
                            d_add_after();
                            break;
                        case 5:
                            d_add_before();
                            break;
                        case 6:
                            d_del_first();
                            break;
                        case 7:
                            d_del_last();
                            break;
                        case 8:
                            d_del_any();
                            break;
                        case 9:
                            d_update_node();
                            break;
                        case 10:
                            d_sort_list();
                            break;
                        case 0:
                            main();


                        }
                        system("cls");
                        d_print_list();
                        d_list_op_menu();
                        cout<<"->";
                        cin>>op;
                        cout<<"\n";
                }

        }
    }
    return 0;
}
