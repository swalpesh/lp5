#include<iostream>
#include<omp.h>
#include<queue>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void bfs(Node *root) {
    if (root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);

    #pragma opm parallel
    #pragma omp single
    while(!q.empty()){
        Node *node = q.front();
        q.pop();

        cout<<"Visited : "<< node->value << endl;

        if(node->left != nullptr){
            #pragma omp task
            q.push(node->left);
        }

        if(node->right != nullptr){
            #pragma omp task
            q.push(node->right);
        }
    }

}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    bfs(root);

    return 0;
}
