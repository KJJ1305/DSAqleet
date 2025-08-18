/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "# ";

        return to_string(root->val)+" "+serialize(root->left)+serialize(root->right);
    }

    TreeNode* build(istringstream &ss){
        string val;
        ss>>val;
        if(val=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=build(ss);
        root->right=build(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return build(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));