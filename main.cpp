#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node *next;
};
class list
{
private:
    node *head, *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void createnode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
            temp=NULL;
        }
    }
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    void insert_start(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }
    void insert_position(int pos, int value)
    {
        node *pre=new node;
        node *cur=new node;
        node *temp=new node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }
    void delete_first()
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    void delete_last()
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }
    void delete_position(int pos)
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
    void delete_repeat()
    {
        node *temp =new node;
        temp=head;
        vector<int> check;
        vector<int>::iterator it;
        int i=1;

        while(temp->next != NULL)
        {

            it=find(check.begin(),check.end(),temp->data);
            if(it !=check.end())
            {
                delete_position(i);
                i--;
            }
            else
            {
                check.push_back(temp->data);
            }

            temp= temp->next;
            if(temp->next ==0)
            {

                it=find(check.begin(),check.end(),temp->data);
                if(it !=check.end())
                {
                    i++;
                    delete_position(i);

                }
            }
            i++;

        }
    }
};
int main()
{
    list *obj= new list;
    obj->createnode(25);
    obj->createnode(50);
    obj->createnode(90);
    obj->createnode(40);
    obj-> createnode(40);
    obj ->createnode(25);
    obj->display();
    cout<<endl;
    obj->delete_repeat();
    obj->display();
    return 0;
}