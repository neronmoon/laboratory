// Даны две последовательности чисел. Построить бинарное дерево,
// содержащее числа первой последовательности. Для каждого числа второй
// последовательности узнать, входит ли оно в дерево. После выполнения
// программы очистить память, занятую древовидной структурой.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bTree {
    int data; //поле данных
    struct bTree* left; //указатель на левого потомка
    struct bTree* right; //указатель на правого потомка
} bTree;

//создание бинарного дерева
void create_tree(bTree** p, int x)
{
    if (!(*p)) //если указатель на корень дерева не равен NULL
    {
        bTree* pnew = (bTree*)
            malloc(sizeof(bTree)); // выделяем память
        pnew->data = x; //заносим значение
        pnew->left = pnew->right = NULL;
        *p = pnew;
    }
    else {
        if ((*p)->data > x)
            create_tree(&((*p)->left), x);
        else
            create_tree(&((*p)->right), x);
    }
}

void print_tree(bTree** p, int l)
{
    int i;
    if (*p != NULL) {
        print_tree(&((*p)->right), l + 1);
        for (i = 0; i < l; i++)
            printf(" ");
        printf("%d\n", (*p)->data);
        print_tree(&((*p)->left), l + 1);
    }
}

//прямой обход бинарного дерева
bool search(bTree* node, int x)
{
    if (node != NULL) {
        if(node->data == x || search(node->left, x) || search(node->right, x)) {
            return true;
        }
    }
    return false;
}

//освобождение памяти, выделенной под бинарное дерево
bTree* drop_tree(bTree* Node)
{
    if (Node != NULL) {
        drop_tree(Node->left);
        drop_tree(Node->right);
        free(Node);
    }
    return NULL;
}
int main()
{
    int i, n, temp, x;
    bTree* root;
    root = NULL;
    printf("Число элементов в первой последовательности: ");
    scanf("%d", &n);
    printf("Первая последовательность: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        create_tree(&root, temp);
    }
    printf("Дерево выглядит так: \n");
    print_tree(&root, 0);

    printf("Число элементов во второй последовательности: ");
    scanf("%d", &n);
    printf("Вторая последовательность: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (search(root, x)) {
            printf("\n%d содержится в дереве\n", x);
        } else {
            printf("\n%d НЕ содержится в дереве\n", x);
        }
    }

    drop_tree(root);
    return 0;
}
