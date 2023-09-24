#include <iostream>
using namespace std;

struct nut
{
    int info;
    nut *left, *right;
};

typedef nut Node;
Node *root;

void khoiTao(Node *&root)
{
    root = NULL;
}

void mocNut(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node;
        root->info = x;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (root->info >= x)
            mocNut(root->left, x);
        else
            mocNut(root->right, x);
    }
}

void taoCay(Node *&root)
{
    int tmp;
    do
    {
        cout << "Nhap so nguyen, 0 de dung: ";
        cin >> tmp;
        if (tmp != 0)
            mocNut(root, tmp);
    } while (tmp != 0);
}

int main()
{
    khoiTao(root);
    taoCay(root);

    return 0;
}
