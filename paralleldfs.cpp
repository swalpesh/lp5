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

void dfs(Node *root) {

    if(root == nullptr){
        return;
    }

    #pragma omp critical
    cout<< "Visited : "<< root->value<<endl;

    #pragma omp task
    dfs(root->left);

    #pragma omp task
    dfs(root->right);

}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    #pragma omp parallel
    {
        #pragma omp single
        dfs(root);
    }

    return 0;

}
