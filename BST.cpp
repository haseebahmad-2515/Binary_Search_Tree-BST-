#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// it is problem on leetcode convert the sorted linked to balance

/*
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, start, mid - 1);
        node->right = helper(nums, mid + 1, end);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // step 1: convert linked list to vector
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        // step 2: same logic as before
        return helper(nums, 0, nums.size() - 1);
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==nullptr){
            return nullptr;
        }
        if(root->val>p->val&&root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val&&root->val<q->val){
             return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root ;
        }
        
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (root->left == nullptr)
            return right + 1;

        if (root->right == nullptr)
            return left + 1;

        return min(left, right) + 1;
    }
};

      iterative versions
      
int kthSmallest(Node* root, int k) {
    stack<Node*> st;
    Node* curr = root;
    int count = 0;

    while (curr != nullptr || !st.empty()) {
        // go as far left as possible
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // visit node
        curr = st.top();
        st.pop();
        count++;

        if (count == k)
            return curr->data;

        // go right
        curr = curr->right;
    }
    return -1; // not found
}
    int kthLargest(Node* root, int k) {
    stack<Node*> st;
    Node* curr = root;
    int count = 0;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->right;  // right first
        }
        curr = st.top();
        st.pop();
        count++;

        if (count == k)
            return curr->data;

        curr = curr->left;  // then left
    }
    return -1;
}

void printKLevel(node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }

    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}




int countKLevel(node *root, int k)
{
    if (root == NULL)
        return 0;

    if (k == 1)
        return 1;

    return countKLevel(root->left, k - 1)
         + countKLevel(root->right, k - 1);
}


*/

class bstnode
{
    friend class BST;
    int data;
    bstnode *left;
    bstnode *right;

public:
    bstnode(int val = 0)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
private:
    bstnode *root;

    // task 1 lab 11
    int getHeight(bstnode *b)
    {
        if (b == nullptr)
        {
            return 0;
        }
        int left = getHeight(b->left);
        int right = getHeight(b->right);
        // we will consider the max no of height
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
    bstnode *createBalancedTreeHelper(int *arr, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        bstnode *temp = new bstnode(arr[mid]);
        temp->left = createBalancedTreeHelper(arr, start, mid - 1);
        temp->right = createBalancedTreeHelper(arr, mid + 1, end);
        return temp;
    }
    int countnodes(bstnode *curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }

        return 1 + countnodes(curr->left) + countnodes(curr->right);
    }

    void preorder(bstnode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void inorder(bstnode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(bstnode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void preorder1(bstnode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preorder1(node->right);
        preorder1(node->left);
    }
    void inorder1(bstnode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorder1(node->right);
        cout << node->data << " ";
        inorder1(node->left);
    }

    void postorder1(bstnode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        postorder1(node->right);
        postorder1(node->left);
        cout << node->data << " ";
    }

    void destroy(bstnode *node)
    {
        if (node == nullptr)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    bool recusrivesearch(bstnode *curr, int key)
    {

        while (curr != nullptr)
        {
            if (key == curr->data)
            {
                return true;
            }
            else if (key < curr->data)
            {
                return recusrivesearch(curr->left, key);
            }
            else
            {
                return recusrivesearch(curr->right, key);
            }
        }
        return false;
    }

public:
    BST()
    {
        root = nullptr;
    }

    bool insert(int val)
    {

        bstnode *temp = new bstnode;
        bstnode *curr = root;
        bstnode *parent = nullptr;
        temp->data = val;
        temp->left = nullptr;
        temp->right = nullptr;

        if (root == nullptr)
        {
            root = temp;
            return true;
        }
        while (curr != nullptr)
        {
            parent = curr;
            if (val > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        if (val > parent->data)
        {
            parent->right = temp;
        }
        else
        {
            parent->left = temp;
        }
        return true;
    }
    void mirror(bstnode *curr)
    {
        if (curr == nullptr)
            return;

        // swap left and right
        bstnode *temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        // recurse on both sides
        mirror(curr->left);
        mirror(curr->right);
    }

    void mirror()
    {
        mirror(root);
    }

    int getHeight()
    {
        return getHeight(root);
    }

    void createBalancedTree(int *arr, int start, int end)
    {
        root = createBalancedTreeHelper(arr, start, end);
    }
    int countnodes()
    {
        return countnodes(root);
    }

    int findMin()
    {
        if (root == nullptr)
        {
            return 0;
        }
        bstnode *curr = root;
        if (curr->left != nullptr)
        {
            while (curr->left != nullptr)
            {
                curr = curr->left;
            }

            return curr->data;
        }
    }

    int findMax()
    {
        if (root == nullptr)
        {
            return 0;
        }
        bstnode *curr = root;
        if (curr->right != nullptr)
        {
            while (curr->right != nullptr)
            {
                curr = curr->right;
            }

            return curr->data;
        }
    }

    int countevennodes(bstnode *curr)
    {
        int count = 0;
        if (curr == nullptr)
        {
            return 0;
        }
        if (curr->data % 2 == 0)
        {
            count = 1;
        }

        return count + countevennodes(curr->left) + countevennodes(curr->right);
    }
    int countoddnodes(bstnode *curr)
    {
        int count = 0;
        if (curr == nullptr)
        {
            return 0;
        }
        if (curr->data % 2 == 1)
        {
            count = 1;
        }

        return count + countoddnodes(curr->left) + countoddnodes(curr->right);
    }

    int findMaxRec(bstnode *b)
    {
        if (b == NULL)
            return -1; // empty tree

        if (b->right == NULL) // rightmost node reached
            return b->data;

        return findMaxRec(b->right);
    }

    int findMaxRec()
    {
        return findMaxRec(root);
    }

    int findMinRec(bstnode *b)
    {
        if (b == NULL)
            return -1; // empty tree

        if (b->left == NULL) // leftmost node reached
            return b->data;

        return findMinRec(b->left);
    }

    int findMinRec()
    {
        return findMinRec(root);
    }

    void findkthlargest(bstnode *curr, int &count, int kth)
    {
        // it will do the reverse in-order R-N-L
        if (curr == NULL)
            return;
        findkthlargest(curr->right, count, kth);
        count++;

        if (count == kth)
        {
            cout << curr->data << " ";
            return;
        }
        findkthlargest(curr->left, count, kth);
    }
    void findkthlargest(int kth)
    {
        int count = 0;
        findkthlargest(root, count, kth);
    }

    void findkthsmallest(bstnode *curr, int &count, int kth)
    {
        // it will do the  in-order l-N-R
        if (curr == NULL)
            return;
        findkthsmallest(curr->left, count, kth);
        count++;

        if (count == kth)
        {
            cout << curr->data << " ";
            return;
        }
        findkthsmallest(curr->right, count, kth);
    }

    void findkthsmallest(int kth)
    {
        int count = 0;
        findkthsmallest(root, count, kth);
    }


    

    void printInRange(bstnode *curr, int min, int max)
    {
        if (curr == nullptr)
            return;

        if (curr->data > min)
            printInRange(curr->left, min, max);

        if (curr->data >= min && curr->data <= max)
            cout << curr->data << " ";

        if (curr->data < max)
            printInRange(curr->right, min, max);
    }

    void printInRange(int min, int max)
    {
        printInRange(root, min, max);
    }

    void deleteAllLeafs(bstnode *&curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        if (curr->left == nullptr && curr->right == nullptr)
        {

            delete curr;
            curr = nullptr;
            return;
        }
        deleteAllLeafs(curr->left);
        deleteAllLeafs(curr->right);
    }
    void deleteAllLeafs()
    {
        deleteAllLeafs(root);
    }

    // height calculation
    int height(bstnode *curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        // post order
        int left = height(curr->left);
        int right = height(curr->right);

        return max(left, right) + 1;
    }

    int height()
    {
        return height(root);
    }

    void countNodesInRange(bstnode *b, int l, int h, int &count)
    {
        if (b == 0)
        {
            return;
        }
        else if (b->data >= l && b->data <= h)
        {
            countNodesInRange(b->left, l, h, count);
            count++;
            countNodesInRange(b->right, l, h, count);
        }
        else if (b->data > h)
        {
            countNodesInRange(b->left, l, h, count);
        }
        else if (b->data < l)
        {
            countNodesInRange(b->right, l, h, count);
        }
    }

    bool isCheck(bstnode *curr, int minVal, int maxVal) // workhorse function
    {
        if (curr == nullptr)
        {
            return true;
        }
        else if (curr->data >= maxVal || curr->data <= minVal) // current root is compared to its root
        {
            return false;
        }
        else
        {
            // HERE BASICALLY curr->data is everytime the rootnode of each subtree
            // and curr->left and curr->right are it's sides
            return isCheck(curr->left, minVal, curr->data) && isCheck(curr->right, curr->data, maxVal);
        }
    }

    void printAllPathsWithSumK(bstnode *curr, int *arr, int arrlength, int target)
    {
        // we can do this by vector or array

        if (curr == nullptr)
        {
            return;
        }
        arr[arrlength] = curr->data;
        arrlength++;
        if (curr->left == nullptr && curr->right == nullptr)
        {
            int sum = 0;
            for (int i = 0; i < arrlength; i++)
            {
                sum = sum + arr[i];
            }

            if (sum == target)
            {
                for (int i = 0; i < arrlength; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
        printAllPathsWithSumK(curr->left, arr, arrlength, target);
        printAllPathsWithSumK(curr->right, arr, arrlength, target);
    }
    void printAllPathsWithSumK()
    {
        int arr[100];
        int arrlength = 0;
        int target = 174;
        printAllPathsWithSumK(root, arr, arrlength, target);
    }

    void printAllPaths(bstnode *curr, int *arr, int arrlength)
    {
        if (curr == nullptr)
        {
            return;
        }
        arr[arrlength] = curr->data;
        arrlength++;
        if (curr->left == nullptr && curr->right == nullptr)
        {
            for (int i = 0; i < arrlength; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        printAllPaths(curr->left, arr, arrlength);
        printAllPaths(curr->right, arr, arrlength);
    }
    void printAllPaths()
    {
        int arr[100];
        int arrlength = 0;
        printAllPaths(root, arr, arrlength);
    }

    // wrapper function
    bool recusrivesearch(int key)
    {
        return recusrivesearch(root, key);
    }

    bool search(int key)
    {
        bstnode *curr = root;
        while (curr != nullptr)
        {
            if (key == curr->data)
            {
                return true;
            }
            else if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return false;
    }

    bool remove(int val)
    {
        bstnode *curr = root;
        bstnode *parent = nullptr;

        while (curr != nullptr && curr->data != val)
        {
            parent = curr;
            if (val > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (curr == nullptr)
        {
            return false;
        }

        // degree 2

        // successor and predessaor always have the 0 or 1 degree it can have the degree 2
        if (curr->left != nullptr && curr->right != nullptr)
        {
            // find inorder predecessor (max of left subtree)
            bstnode *predParent = curr;
            bstnode *pred = curr->left;
            while (pred->right != nullptr)
            {
                predParent = pred;
                pred = pred->right;
            }
            curr->data = pred->data; // copy predecessor value
            // now delete predecessor (it has 0 or 1 degree)
            curr = pred;
            parent = predParent;
        }

        // degree 1 and 0
        bstnode *ch = nullptr;
        if (curr->left != nullptr)
        {
            ch = curr->left;
        }
        else
        {
            ch = curr->right;
        }
        // if curr is root then (it will handle the degree o)

        if (curr == root)
        {
            root = ch;
        }
        else
        {
            if (curr == parent->left)
            {
                parent->left = ch;
            }
            else
            {
                parent->right = ch;
            }
        }

        delete curr;
        curr = nullptr;
        return true;
    }

    void findSuccessorPredecessor(int val)
    {
        if (root == nullptr)
        {
            cout << " no nodes" << endl;
            return;
        }
        bstnode *curr = root;
        bstnode *parent = nullptr;
        while (curr != nullptr && curr->data != val)
        {
            parent = curr;
            if (val > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        bstnode *pred = curr->left;
        bstnode *succ = curr->right;

        if (curr->left != nullptr)
        {
            while (pred->right != nullptr)
            {
                pred = pred->right;
            }
            cout << pred->data << endl;
        }
        else
        {
            cout << "no pred" << endl;
        }

        if (curr->right != nullptr)
        {
            while (succ->left != nullptr)
            {
                succ = succ->left;
            }
            cout << succ->data << endl;
        }
        else
        {
            cout << "no succ" << endl;
        }
    }

    // pre-order(NODE-LEFT-RIGHT)
    void preorder()
    {
        preorder(root);
    }

    // in-order(LEFT-NODE-RIGHT)
    void inorder()
    {
        inorder(root);
    }
    // postorder(LEFT-RIGHT-NODE)
    void postorder()
    {
        postorder(root);
    }

    // pre-order(NODE-RIGHT-LEFT)
    void preorder1()
    {
        preorder1(root);
    }

    // in-order(RIGHT-NODE-LEFT)
    void inorder1()
    {
        inorder1(root);
    }
    // postorder(RIGHT-LEFT-NODE)
    void postorder1()
    {
        postorder1(root);
    }

    // level and line order can also be  done as same way it was  in binary trees

    bstnode *createcopy(bstnode *tn)
    {
        if (tn == nullptr)
        {
            return nullptr;
        }
        bstnode *newNode = new bstnode;
        newNode->data = tn->data;
        newNode->left = createcopy(tn->left);
        newNode->right = createcopy(tn->right);

        return newNode;
    }

    BST createcopy()
    {
        BST copy;
        copy.root = createcopy(root);
        return copy;
    }

    BST &operator=(const BST &obj)
    {

        if (this == &obj)
        {
            return *this;
        }
        destroy(root);
        root = createcopy(obj.root);
        return *this;
    }

    ~BST()
    {
        destroy(root);
    }
};

int main()
{
    BST bst;
    BST bst1;

    // insertion
    bst.insert(23);
    bst.insert(32);
    bst.insert(43);
    bst.insert(39);
    bst.insert(37);
    bst.insert(44);
    int array[12] = {7, 10, 14, 20, 36, 47, 55, 63, 72, 86, 92};

    // search

    /* if( bst.search(20))
         cout << "Found: "  << endl;
     else
         cout << "Not found" << endl;

     // remove
     bool removed = bst.remove(43);
     if(removed)
         cout << "43 removed successfully" << endl;
     else
         cout << "43 not found" << endl;
 */

    bst1.createBalancedTree(array, 0, 10);
    bst1.inorder();

    cout << bst1.findMaxRec();
    cout << bst1.findMinRec();
    // cout<<bst1.countnodes();

    /* cout<<bst1.findMax();
     cout<<endl;
     cout<<bst1.findMin();
     */

    return 0;
}
