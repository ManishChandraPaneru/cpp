#include<bits/stdc++.h>
using namespace std;

struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(int x) : val(x), left(NULL), right(NULL) {}
};

void allTraversals(Treenode* root){
    stack<pair<Treenode*,int>> st;
    vector<int> preOrder,inOrder,postOrder;
    st.push({root,1});
    while(!st.empty()){
        auto p=st.top();
        st.pop();
        if(p.second==1){
            preOrder.push_back(p.first->val);
            p.second++;
            st.push(p);
            if(p.first->left!=NULL)st.push({p.first->left,1});
        }
        else if(p.second==2){
            inOrder.push_back(p.first->val);
            p.second++;
            st.push(p);
            if(p.first->right!=NULL)st.push({p.first->right,1});
        }
        else{
            postOrder.push_back(p.first->val);
        }
    }

    cout << "PreOrder: ";
    for (int val : preOrder)
        cout << val << " ";
    cout << endl;

    cout << "InOrder: ";
    for (int val : inOrder)
        cout << val << " ";
    cout << endl;

    cout << "PostOrder: ";
    for (int val : postOrder)
        cout << val << " ";
    cout << endl;
}

int main(){
    vector<int> preOrder,inOrder,postOrder;
    Treenode *root = new Treenode(1);
    root->left = new Treenode(2);
    root->right = new Treenode(3);
    root->left->left = new Treenode(4);
    root->left->right = new Treenode(5);
    root->right->left = new Treenode(6);
    root->right->right = new Treenode(7);

    allTraversals(root);

    return 0;
}