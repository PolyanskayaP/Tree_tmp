// Tree_tmp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

const int v = 7;

struct node { 
    int index; //mojno ubrat'?
    int left_child;
    char name;
    int znach;
    int right_sibling;
  //  int parent;
    int mark;
};

void findNode(int value, /**/int k, node* A, /*mojet size*/int& size) { //возвр индекс вершины-родителя
    //k = k - 1;
    //k = k + 1;
    if (size == 0) {                     //zapih znachh  addnafi   !!!!!!!
    /*   A = (node*)realloc(A, sizeof(node) * (++size));
        A[k].left_child = -1;
        A[k].mark = 0; //virtual
        A[k].name = size + 65;
        A[k].right_sibling = -1;
        A[k].znach = -1;
        A[k].index = size - 1;   */
   //     return -1; //zanuli!!!!   k - index tekus..?

        A[size].index = size;
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
            A[size].index = size;
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

                A[k].left_child = A[A[k].left_child].index;
            }
    }
    else {
        if (A[k].left_child == -1) {
            A[k].left_child = size;

            A[size].index = size;
            A[size].left_child = -1;
            A[size].name = size + 65;
            A[size].znach = -1;
            int lsize = size;//
            A[lsize].right_sibling = ++size;
            A[lsize].mark = 0;

            int rig = A[lsize].right_sibling;
            A[rig].index = rig;
            A[rig].left_child = -1;
            A[rig].name = rig + 65;
            A[rig].znach = -1;
            A[rig].right_sibling = -1;
            A[rig].mark = 0;

            size++;
        }
        if (A[A[k].left_child].right_sibling == -1) {
            A[A[k].left_child].right_sibling = size;

            A[size].index = size;
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
            /////if A[indRight].mark == 0;
            //A[indRight].index = indRight;
            //A[indRight].name = indRight + 65;
            A[indRight].znach = value;
            A[indRight].mark = 1;
        }
    }
    return;
}

/*void add(int value, node* A, int& size) {  //prover' size!
    int i = size; 
    int indParent = findNode(value, 0, A, size); //a  ecli -1????? to est'[0]   
    if (indParent == -1) {
    //    A = (node*)realloc(A, sizeof(node) * (++size));
        A[i].index = i;  
        A[i].left_child = -1; //cout << "zahsel!"<< size<<i;  
        A[i].mark = 1; //cout << A[i].left_child;
        A[i].name = i + 65;
        A[i].right_sibling = -1;
        A[i].znach = value;
        size++;
        return; 
    }

    if (value < A[indParent].znach) { //ya,rod,brat
        if (A[A[indParent].left_child].mark == 0) { //virt
           // A = (node*)realloc(A, sizeof(node) * (++size)); //доб. в динамический массив
            A[A[indParent].left_child].znach = value;
            A[A[indParent].left_child].name = i + 65; //
            A[A[indParent].left_child].index = i;
            A[A[indParent].left_child].left_child = -1;
            A[A[indParent].left_child].mark = 1; //1 - обычн, 0 - виртуальный

             
        }
        else {
            A = (node*)realloc(A, sizeof(node) * (++size)); //доб. в динамический массив
            A[i].znach = value;
            A[i].name = i + 65; //
            A[i].index = i;
            A[i].left_child = -1;
            A[i].mark = 1; //1 - обычн, 0 - виртуальный

            A[indParent].left_child = i;
        }
    }
    else
    {
        //A[indParent].left_child
        A = (node*)realloc(A, sizeof(node) * (++size)); //доб. в динамический массив
        A[i].znach = value;
        A[i].name = i + 65; //
        A[i].index = i;
        A[i].left_child = -1;
        A[i].mark = 1; //1 - обычн, 0 - виртуальный

        A[A[indParent].left_child].right_sibling = i;

    }
}*/

int main()
{
    int i, j;
    int forA[v] = { 50,30,60,70,40,20,10 };
    int forB[v] = { 22,99,88,10,11,0,33 };
    int sizeA = 0; 
    int sizeB = 0;
    //node* A = (node *) malloc (sizeof(node));
    node A[v*v];//*2
    node B[v * v];

    for (i = 0; i < v; i++) {
        findNode(forA[i], 0, A, sizeA);
        //add(forA[i], A, sizeA); cout <<"size="<< sizeA;
        //cout <<" "<< A[i].znach << " " << sizeA << " ";
    }

    i = 0;  
    j = 0; 
    while (j < v) {
        if (A[i].mark == 1) {
            cout << A[i].znach << " ";
            j++;
        }
        i++;
    }

    cout << endl;
    cout << endl;

    for (i = 0; i < v; i++) {
        findNode(forB[i], 0, B, sizeB);
        //add(forA[i], A, sizeA); cout <<"size="<< sizeA;
        //cout <<" "<< A[i].znach << " " << sizeA << " ";
    }

    i = 0;
    j = 0;
    while (j < v) {
        if (B[i].mark == 1) {
            cout << B[i].znach << " ";
            j++;
        }
        i++;
    }

    //free(A);//
 //   free(B);
    return 0; 
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
/*   A = (node*)realloc(A, sizeof(node) * (++sizeA)); //добавляем одну ячейку
    A = (node*)realloc(A, sizeof(node) * (++sizeA)); //еще одну



    B = (node*)realloc(B, sizeof(node) * (++sizeB)); //добавляем одну ячейку
    B = (node*)realloc(B, sizeof(node) * (++sizeB)); //еще одну



    C = (node*)realloc(C, sizeof(node) * (++sizeC)); //добавляем одну ячейку
    C = (node*)realloc(C, sizeof(node) * (++sizeC)); //еще одну


    delete[] C;
    delete[] B;   */
    //delete[] A;

    //cout << A[k].left_child;   //find
    /*int indLeft = A[k].left_child;
    if (indLeft == -1) {
        A = (node*)realloc(A, sizeof(node) * (++size));
        A[size - 1].left_child = -1;
        A[size - 1].mark = 0; //virtual
        A[size - 1].name = size - 1 + 65;
        A[size - 1].right_sibling = -1;
        A[size - 1].znach = -1;
        A[size - 1].index = size - 1;

        A[k].left_child = A[size - 1].index;

        indLeft = A[k].left_child;
    }
    int indRight = A[indLeft].right_sibling;

    if (value < A[k].znach and A[indLeft].mark == 1 ) {
        findNode(value, indLeft, A, size);
    }
    else
    if (value >= A[k].znach and indRight != -1) {
        //if (indRight != -1) {//left?
            findNode(value, indRight, A, size);
        //}
        //else {
        //    ret
        //}
    }
    else {
        return k; //roditel'
    }
   //}*/
