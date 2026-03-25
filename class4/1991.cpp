#include <bits/stdc++.h>

using namespace std;

int tree[26][2];

void preorder(int cur){
    if (cur == -1) return;
    
    cout << (char)(cur + 'A');
    preorder(tree[cur][0]);
    preorder(tree[cur][1]);
} 
void inorder(int cur){
    if (cur == -1) return;

    inorder(tree[cur][0]);
    cout << (char)(cur + 'A');
    inorder(tree[cur][1]);
} 
void postorder(int cur){
    if (cur == -1) return;

    postorder(tree[cur][0]);
    postorder(tree[cur][1]);
    cout << (char)(cur + 'A');
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i< n; i++){
        char root, left, right;
        cin >> root >> left >> right;

        int root_inx = root - 'A';

        if (left == '.'){
            tree[root_inx][0] = -1;
        } else{
            tree[root_inx][0] = left - 'A';
        }

        if (right == '.'){
            tree[root_inx][1] = -1;
        } else{
            tree[root_inx][1] = right - 'A';
        }
    }

    preorder(0); cout << "\n";
    inorder(0); cout << "\n";
    postorder(0); cout << "\n";

    return 0;
}