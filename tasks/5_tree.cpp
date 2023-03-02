#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

struct Trunk {
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    cout << p->str;
}

class BinarySearchTree {
private:
    Node *root;
    vector<int> arr;

    void addHelper(Node *current, int value) {
        if (current->value > value) {
            if (current->left == nullptr) {
                current->left = new Node(value);
            } else {
                addHelper(current->left, value);
            }
        } else {
            if (current->right == nullptr) {
                current->right = new Node(value);
            } else {
                addHelper(current->right, value);
            }
        }
    }

    Node *deleteHelper(Node *current, int value) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->value == value) {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            } else if (current->left == nullptr) {
                Node *tmp = current->right;
                delete current;
                return tmp;
            } else if (current->right == nullptr) {
                Node *tmp = current->left;
                delete current;
                return tmp;
            } else {
                Node *successor = current->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
                current->value = successor->value;
                current->right = deleteHelper(current->right, successor->value);
                return current;
            }
        }
        if (current->value > value) {
            current->left = deleteHelper(current->left, value);
        } else {
            current->right = deleteHelper(current->right, value);
        }
        return current;
    }

    bool searchHelper(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        if (value < node->value) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    void printHelper(Node *root, std::string indent, bool last) {
        if (root != nullptr) {
            std::cout << indent;
            if (last) {
                // std::cout << "     ";
                std::cout << "     (R)";
                // std::cout << "R----";
                indent += "   ";
            } else {
                // std::cout << "L----";
                // std::cout << "     ";
                std::cout << "     (L)";
                indent += "|  ";
            }
            std::cout << root->value << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    void printTree(Node* root, Trunk *prev, bool isLeft) {
        if (root == nullptr) {
            return;
        }
    
        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);
    
        printTree(root->right, trunk, true);
    
        if (!prev) {
            // trunk->str = "———";
            trunk->str = "   ";
        }
        else if (isLeft)
        {
            // trunk->str = " ╭———";
            trunk->str = "     ";
            // prev_str = "   |";
            prev_str = "    ";
        }
        else {
            // trunk->str = " ╰———";
            trunk->str = "     ";
            prev->str = prev_str;
        }
    
        showTrunks(trunk);
        cout << " " << root->value << endl;
    
        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "    ";
        // trunk->str = "   |";
    
        printTree(root->left, trunk, false);
    }

    void destroyHelper(Node *root) {
        if (root == nullptr) {
            return;
        }
        destroyHelper(root->left);
        destroyHelper(root->right);
        delete root;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroyHelper(root);
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            addHelper(root, value);
        }
    }

    void remove(int value) {
        root = deleteHelper(root, value);
    }

    void clear() {
        destroyHelper(root);
        root = nullptr;
    }

    bool search(int value) {
        return searchHelper(root, value);
    }

    void print() {
        printHelper(root, "", true);
    }

    void printArr() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " [" << i+1 << "]\n";
        }
    }

    void print2() {
        printTree(root, nullptr, false);
    }

    void arrPush(int val) {
        arr.push_back(val);
    }
};

void draw() {
    cout << "\n===============================================================\n";
}

void menu() {
    cout << "\n1. Вывести дерево в виде дерева\n" \
        << "2. Вывести дерево в симметричном виде\n" \
        << "3. Удалить все элементы из дерева\n" \
        << "4. Добавить элемент в дерево\n" \
        << "5. Удалить элемент из дерева\n"
        << "6. Вывод последовательности заполнения\n" \
        << "7. Поиск\n" \
        << "0. Выход\n";
}

int main() {
    // setlocale(LC_ALL, "rus");
    int n, numf;
    cout << "Сколько элементов внести в дерево?\n";
    cin >> n;
    BinarySearchTree tree;
    for (int i = 0; i < n; i++) {
        cin >> numf;
        tree.insert(numf);
        tree.arrPush(numf);
    }
    draw();
    bool fl = true;
    while (fl) {
        menu();
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            draw();
            tree.print2();
            break;
        case 2:
            draw();
            tree.print();
            break;
        case 3:
            draw();
            tree.clear();
            break;
        case 4:
            draw();
            cout << "Сколько элементов внести в дерево (дозаполнить)?\n";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> numf;
                tree.insert(numf);
                tree.arrPush(num);
            }
            break;
        case 5:
            draw();
            cout << "Какой элемент удалить?\n";
            cin >> n;
            tree.remove(n);
            break;
        case 6:
            draw();
            tree.printArr();
            break;
        case 7:
            draw();
            cout << "Какой элемент ищем?\n";
            cin >> n;
            if (tree.search(n)) {
                cout << "элемент найден\n";
            } else {
                cout << "элемент не найден\n";
            }
            break;
        case 0:
            fl = false;
            break;
        default:
            break;
        }
    }
}