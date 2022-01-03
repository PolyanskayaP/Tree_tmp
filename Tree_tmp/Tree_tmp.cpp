//66 вариант, дерево двоичного поиска, А - обратный, В - симметричный, 
//левый сын, правый брат (таблица, массив)   A=A Uпр B
#include <iostream>
using namespace std;

const int v = 7;

struct node { //таблица организована массивом структур
    int left_child;
    char name;
    int znach;
    int right_sibling;
    int mark;
};

void findNode(int value, int k, node* A, int& size) { 
    if (size == 0) {                     
        A[size].left_child = -1;
        A[size].mark = 1;
        A[size].name = size + 65;
        A[size].right_sibling = -1;
        A[size].znach = value; 

        size++;
        return;
    }

    if (value < A[k].znach) {
        if (A[k].left_child == -1) {
            A[size].left_child = -1;
            A[size].name = size + 65;
            A[size].znach = value;
            A[size].right_sibling = -1;
            A[size].mark = 1;

            A[k].left_child = size;
            size++;
        }
        else
            if (A[A[k].left_child].mark == 1) {
                findNode(value, A[k].left_child, A, size);
        }
        else
            if (A[A[k].left_child].mark == 0) {
                A[A[k].left_child].znach = value;
                A[A[k].left_child].mark = 1;
            }
    }
    else {
        if (A[k].left_child == -1) {
            A[k].left_child = size;

            A[size].left_child = -1;
            A[size].name = size + 65;
            A[size].znach = -1;
            int lsize = size;//
            A[lsize].right_sibling = ++size;
            A[lsize].mark = 0;

            int rig = A[lsize].right_sibling;
            A[rig].left_child = -1;
            A[rig].name = rig + 65;
            A[rig].znach = -1;
            A[rig].right_sibling = -1;
            A[rig].mark = 0;

            size++;
        }
        if (A[A[k].left_child].right_sibling == -1) {
            A[A[k].left_child].right_sibling = size;

            A[size].left_child = -1;
            A[size].name = size + 65;
            A[size].znach = -1;
            A[size].right_sibling = -1;
            A[size].mark = 0;

            size++;
        }

        int indRight = A[A[k].left_child].right_sibling;
        if (A[indRight].mark == 1) {
            findNode(value, indRight, A, size);
        }
        else {
            A[indRight].znach = value;
            A[indRight].mark = 1;
        }
    }
    return;
}

void pram_obh_dob(int i, node* B, node* A, int& sizeA) {
    if (B[i].mark == 1) {
        findNode(B[i].znach, 0, A, sizeA);
    }

    if (B[i].left_child != -1) {
        pram_obh_dob(B[i].left_child, B, A, sizeA);
        if (B[B[i].left_child].right_sibling != -1)
            pram_obh_dob(B[B[i].left_child].right_sibling, B, A, sizeA);
    }
}

void pram_obh(int i, node* A) {
    if (A[i].mark == 1) {
        cout << A[i].name << "=" << A[i].znach << " ";
    }

    if (A[i].left_child != -1) {
        pram_obh(A[i].left_child, A);
        if (A[A[i].left_child].right_sibling != -1)
            pram_obh(A[A[i].left_child].right_sibling, A);
    }
}

void obrat_obh(int i, node* A) {
    if (A[i].left_child != -1) {
        obrat_obh(A[i].left_child, A);
        if (A[A[i].left_child].right_sibling != -1)  
            obrat_obh(A[A[i].left_child].right_sibling, A);
    }

    if (A[i].mark == 1) {
        cout << A[i].name << "=" << A[i].znach << " ";
    }
}

void sim_obh(int i, node* A) {
    if (A[i].left_child == -1 && A[i].mark == 1) {
        cout << A[i].name << "=" << A[i].znach << " ";
    }
    else 
    if (A[i].mark == 1)
    {
        sim_obh(A[i].left_child, A);
        if (A[i].mark == 1) {
            cout << A[i].name << "=" << A[i].znach << " ";
        }
        if (A[A[i].left_child].right_sibling != -1)
            sim_obh(A[A[i].left_child].right_sibling, A);
    }
}

int main()
{
    int i, j;
    int forA[v] = { 50,30,60,70,40,20,10 };
    int forB[v] = { 22,99,88,10,11,0,33 };
    int sizeA = 0; 
    int sizeB = 0;
    node A[(v + v) * 2];
    node B[v * 2];

    for (i = 0; i < v; i++) {  //добавление элементов в дерево А 
        findNode(forA[i], 0, A, sizeA);
    }

    i = 0;  j = 0; 
    cout << "A tree: ";
    while (j < v) {            //вывод дерева А в порядке индексов узлов
        if (A[i].mark == 1) {
            cout << A[i].name << "=" << A[i].znach << " "; 
            j++;
        }
        i++;
    }

    cout << endl;

    for (i = 0; i < v; i++) {  //добавление элементов в дерево B
        findNode(forB[i], 0, B, sizeB);
    }

    i = 0;  j = 0;
    cout << "B tree: ";
    while (j < v) {            //вывод дерева B в порядке индексов узлов
        if (B[i].mark == 1) {
            cout << B[i].name << "=" << B[i].znach << " ";
            j++;
        }
        i++;
    }
    cout << endl;
    cout << endl;

    cout << "A tree, postorder: ";
    obrat_obh(0, A);          //обратный обход дерева А

    cout << endl;

    cout << "B tree, inorder (symmetrical): ";
    sim_obh(0, B);            //симметричный обход дерева B 

    cout << endl;
    cout << endl;

    pram_obh_dob(0, B, A, sizeA); //элементы дерева B добавляются в А в прямом 
    //порядке обхода дерева B
    
    cout << "after adding preorder B in  A (C tree): " << endl; 
    cout << "C tree, preorder: ";
    pram_obh(0, A); 
    cout << endl;

    cout << "C tree, postorder: ";
    obrat_obh(0, A);
    cout << endl;

    cout << "C tree, inorder (symmetrical): ";
    sim_obh(0, A);
    cout << endl;

    return 0; 
}
 
