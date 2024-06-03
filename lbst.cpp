#include<iostream>
#define SPACE 10
using namespace std;
class tree
{
public:
    int value;
    tree*left;
    tree*right;
    tree()
    {
       value=0;
       left=NULL;
       right=NULL;
    }
    tree(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

class bst
{
public:
    tree* root;
    bst()
    {
        root=NULL;
    }
    bool isempty()
    {
        if(root==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    tree*insertn(tree*r,tree*nn)
    {
        if(r==NULL)
        {
            r=nn;
            cout<<"inserted"<<endl;
            return r;
        }
        else if(nn->value<r->value)
        {
            r->left=insertn(r->left,nn);
        }
         else if(nn->value>r->value)
        {
            r->right=insertn(r->right,nn);
        }
        else
        {
            cout<<"no duplicate allowed"<<endl;
            return r;
        }
        return r;
    }
    void print(tree*r,int space)
    {
        if (r==NULL)
        {
            return;
        }
        space=space+SPACE;
        print(r->right,space);
        cout<<endl;
        for(int i=SPACE;i<space;i++)
        {
            cout<<" ";
        }
        cout<<r->value<<"\n";
        print(r->left,space);
    }
    tree*searchn(tree*r,int val)
    {
        if(r==NULL || r->value==val)
        {
            return r;
        }
        else if(val<r->value)
        {
            return searchn(r->left,val);
        }
        else
        {
            return searchn(r->right,val);
        }
    }
    tree*minvalue(tree*node)
    {
        tree*current=node;
        while(current->left!=NULL)
        {
            current=current->left;
        }
        return current;
    }
    tree*del(tree*r,int v)
    {
        if(r==NULL)
        {
            return NULL;
        }
        else if(v<r->value)
        {
            r->left=del(r->left,v);

        }
        else if(v>r->value)
        {
            r->right=del(r->right,v);
        }
        else
        {
            if(r->left==NULL)
            {
                tree*temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL)
            {
                tree*temp=r->left;
                delete r;
                return temp;
            }
            else
            {
                tree*temp=minvalue(r->right);
                r->value=temp->value;
                r->right=del(r->right,temp->value);
            }
        }
        return r;
    }
};
int main()
{
    bst obj;
    int val,n;
    cout<<"enter no. of ele"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter ele"<<endl;
        cin>>val;
        tree*nn=new tree();
        nn->value=val;
        obj.root=obj.insertn(obj.root,nn);
        cout<<endl;
    }
    obj.print(obj.root,5);
    int option;
    while(true)
    {
        cout<<endl;
        cout<<"choose 1.search 2.delete 3.exit"<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"enter ele to search"<<endl;
            cin>>val;
            if (obj.searchn(obj.root,val)!=NULL)
            {
                cout<<"found"<<endl;

            }
            else
            {
                cout<<"not found"<<endl;
            }
            break;
        case 2:
            cout<<"enter ele to del"<<endl;
            cin>>val;
            if (obj.searchn(obj.root,val)!=NULL)
            {
                obj.del(obj.root,val);
                cout<<"deleted"<<endl;

            }
            else
            {
                cout<<"not found"<<endl;
            }
            cout<<"current tree"<<endl;
            obj.print(obj.root,5);
            cout<<endl;
            break;
        case 3:
            cout<<"exiting..."<<endl;
            return 0;
        default:
            cout<<"invalid option"<<endl;
            }
    }
    return 0;
}
