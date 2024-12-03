#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 二叉树节点结构
struct TreeNode {
    string name;
    TreeNode* left;  // 左子树: 孩子
    TreeNode* right; // 右子树: 兄弟

    TreeNode(string val) : name(val), left(nullptr), right(nullptr) {}
};

// 1. 构建二叉树：括号表示法
TreeNode* buildTree(const string& str, int& index) {
    if (index >= str.length() || str[index] == ')') return nullptr;

    // 跳过括号
    if (str[index] == '(') {
        index++;
    }

    // 读取节点的名字
    string name;
    while (index < str.length() && isalpha(str[index])) {
        name.push_back(str[index++]);
    }

    TreeNode* node = new TreeNode(name);

    // 构建左子树
    node->left = buildTree(str, index);

    // 构建右子树
    if (index < str.length() && str[index] == '(') {
        node->right = buildTree(str, index);
    }

    // 跳过 ')'
    if (index < str.length() && str[index] == ')') {
        index++;
    }

    return node;
}

// 2. 后序递归遍历（输出家谱）
void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);  // 遍历左子树
    postOrder(root->right); // 遍历右子树
    cout << root->name << " "; // 访问根节点
}

// 3. 先序非递归遍历
void preOrderNonRecursive(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        cout << node->name << " ";

        // 先压右子树，再压左子树
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

// 4. 查找某一成员的所有长辈（所有祖先节点）
bool findAncestors(TreeNode* root, const string& member, stack<string>& ancestors) {
    if (root == nullptr) return false;

    // 当前节点是目标成员
    if (root->name == member) return true;

    // 查找左子树
    ancestors.push(root->name);
    if (findAncestors(root->left, member, ancestors)) return true;
    ancestors.pop();

    // 查找右子树
    ancestors.push(root->name);
    if (findAncestors(root->right, member, ancestors)) return true;
    ancestors.pop();

    return false;
}

//测试用例A(B(D)(E))(C(F)(G))
int main() {
    // 输入家谱的二叉树括号表示法
    string treeStr;
    cout << "请输入家谱的二叉树括号表示法：";
    cin >> treeStr;

    int index = 0;
    TreeNode* root = buildTree(treeStr, index);

    // 后序遍历（递归）
    cout << "后序遍历输出家谱：";
    postOrder(root);
    cout << endl;

    // 先序遍历（非递归）
    cout << "先序遍历输出家谱：";
    preOrderNonRecursive(root);
    cout << endl;

    // 查找某成员的所有长辈
    string member;
    cout << "请输入要查找的成员名字：";
    cin >> member;

    stack<string> ancestors;
    if (findAncestors(root, member, ancestors)) {
        cout << "成员 " << member << " 的所有长辈：";
        while (!ancestors.empty()) {
            cout << ancestors.top() << " ";
            ancestors.pop();
        }
        cout << endl;
    } else {
        cout << "成员 " << member << " 不在家谱中。" << endl;
    }

    return 0;
}
