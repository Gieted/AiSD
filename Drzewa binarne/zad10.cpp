struct node_calc
{
    char op;
    int number;
    node_calc *left;
    node_calc *right;
};

int eval(node_calc *tree)
{
    if (tree->op == '+')
        return eval(tree->left) + eval(tree->right);
    else if (tree->op == '-')
        return eval(tree->left) - eval(tree->right);
    else if (tree->op == '*')
        return eval(tree->left) * eval(tree->right);
    else if (tree->op == '/')
        return eval(tree->left) / eval(tree->right);
    else
        return tree->number;
}
