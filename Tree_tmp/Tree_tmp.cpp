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

int findNode(int value, int k, node* A, int& size) { //возвр индекс вершины-родителя
    //k = k - 1;
    if (size == 0) {
        
     /*   A = (node*)realloc(A, sizeof(node) * (++size));
        A[k].left_child = -1;
        A[k].mark = 0; //virtual
        A[k].name = size + 65;
        A[k].right_sibling = -1;
        A[k].znach = -1;
        A[k].index = size - 1;   */
        return -1; //zanuli!!!!   k - index tekus..?
    }
    int indLeft = A[k].left_child;
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
   //}
}

void add(int value, node* A, int& size) {  //prover' size!
    int i = size; //-1 
    int indParent = findNode(value, i, A, size); //a  ecli -1????? to est'[0]   
    if (indParent == -1) {
        A = (node*)realloc(A, sizeof(node) * (++size));
        A[i].index = i;
        A[i].left_child = -1;
        A[i].mark = 1;
        A[i].name = i + 65;
        A[i].right_sibling = -1;
        A[i].znach = value;
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
}

int main()
{
    int i;
    int forA[v] = { 5,3,6,7,4,2,1 };
    int forB[v] = { 2,9,8,10,1,0,3 };
    /*std::cout << "Hello World!\n";
    stroka* B = new stroka[10];//how much?
    delete[] B; */

    int sizeA = 0; 
    node* A = 0; 

  /*  int sizeB = 0;
    node* B = 0;

    int sizeC = 0;
    node* C = 0;

    for (i = 0; i < v; i++) {
        A = (node*)realloc(A, sizeof(node) * (++sizeA));  
        A[i].znach = forA[i];
        A[i].name = i+65; //
        A[i].index = i;

        //cout << A[i].znach << " " << A[i].name << " ";
    } //cout << endl;

    for (i = 0; i < v; i++) {
        B = (node*)realloc(B, sizeof(node) * (++sizeB));
        B[i].znach = forB[i];
        B[i].name = i + 65; //
        B[i].index = i;

        //cout << B[i].znach << " " << B[i].name << " ";
    }

    */
    for (i = 0; i < v; i++) {
        
        add(forA[i], A, sizeA);
        //cout << A[i].znach << " ";
    }

    free(A);
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