// used in networking for transmiting data in minimized size
// O(nlogn)
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vc vector<char>
class Node
{
public:
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq)
    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
class compare
{
public:
    bool operator()(Node *left, Node *right)
    {
        return (left->freq > right->freq);
    }
};
void printCodes(Node *root, string code)
{
    if (!root)
    {
        return;
    }
    if (root->data != '$')
    {
        cout << root->data << ":" << code << endl;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}
void arrangeHuffman(char *arr, int freq[], int size)
{
    Node *left, *right, *top;
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
    {
        minHeap.push(new Node(arr[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    arrangeHuffman(arr, freq, size);
}