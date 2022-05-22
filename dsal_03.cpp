#include<bits/stdc++.h>
using namespace std;

struct node
{
    char label[60];
    int chcount;
    node *child[50];
}*root;

class general
{
    public:
        void insert();
        void display();
        general()
        {
            root == NULL;
        }
};

void general::insert()
{
    int secount;
    root = new node();
    cout<<"Enter the name of book : ";
    cin>>root->label;
    cout<<"Enter the total number of chapters in book : ";
    cin>>root->chcount;
    for(int i=0;i<root->chcount;i++)
    {
        root->child[i] = new node();
        cout<<"Enter the name of chapters : ";
        cin>>root->child[i]->label;
        
        cout<<"Enter the number of sections : ";
        cin>>root->child[i]->chcount;
        for(int j=0;j<root->child[i]->chcount;j++)
        {
            root->child[i]->child[j] = new node();
            cout<<"Enter the name of section : ";
            cin>>root->child[i]->child[j]->label;
        
            cout<<"Enter the number of sub sections : ";
            cin>>root->child[i]->child[j]->chcount;
            for(int k=0; k<root->child[i]->child[j]->chcount; k++)
            {
                root->child[i]->child[j]->child[k] = new node();
                cout<<"Enter the name of sub section : ";
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void general::display()
{
    if(root != NULL)
    {
        cout<<"********** Hierarchy of Book **********"<<endl;
        cout<<"Book Name is : "<<root->label<<endl;
        for(int i=0; i<root->chcount; i++)
        {
            cout<<"-- "<<root->child[i]->label<<endl;
            for(int j=0; j<root->child[i]->chcount; j++)
            {
                cout<<"---- "<<root->child[i]->child[j]->label<<endl;
                for(int k=0; k<root->child[i]->child[j]->chcount; k++)
                {
                    cout<<"------ "<<root->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }
    }
}

int main()
{
    general tree;
    int ch;
    do
    {
        cout<<"Press 1 to Insert."<<endl
            <<"Press 2 to Display."<<endl
            <<"Press 3 to exit."<<endl
            <<"Enter the choice:"<<endl;
        cin>>ch;
        
        switch(ch)
        {
            case 1: 
                tree.insert();
                break;
            case 2: 
                tree.display();
                break;
            case 3:
                return 0;
        }
    }while(ch<4);
    return 0;
}
