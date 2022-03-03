#include <bits/stdc++.h>

using namespace std;

struct LinkedList {
    int val;
    LinkedList *next;

    LinkedList() {
        val = 0;
        next = nullptr;
    }

    LinkedList(int val) {
        this->val = val;
        this->next = nullptr;
    }

    LinkedList(int val, LinkedList *next) {
        this->val = val;
        this->next = next;
    }
};

LinkedList *read() {
    vector<int> a{1, 2, 3, 4, 5};
    LinkedList *root = new LinkedList();
    LinkedList *ret = root;
    if (a.empty()) return nullptr;
    for (int i = 0; i < a.size(); i++) {
        root->val = a[i];
        if (i + 1 < a.size()) {
            root->next = new LinkedList();
            root = root->next;
        }
    }
    return ret;
}

void exec(LinkedList *root) {

}

void print(LinkedList *root) {
    if (root == nullptr) {
        puts("");
        return;
    }
    printf("%d ", root->val);
    print(root->next);
}

int main() {
    if (fopen(R"(D:\Code_Cpp\codeforces\inp.txt)", "r")) freopen(R"(D:\Code_Cpp\codeforces\inp.txt)", "r", stdin);
    LinkedList *temp = read();
    exec(temp);
    print(temp);
}