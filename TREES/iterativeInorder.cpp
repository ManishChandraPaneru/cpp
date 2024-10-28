#include<bits/stdc++.h>
using namespace std;

struct Treenode{
    Treenode* left;
    Treenode* right;
    int val;
};

vector<int> iterativeInorder(Treenode *root){
    vector<int> ans;
    stack<Treenode*> st;
    Treenode *node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty())break;
            Treenode* top=st.top();
            st.pop(); 
            ans.push_back(top->val);
            node=node->right;
        }
    }
    return ans;
}

int main(){

}