#include <iostream>

using namespace std;

int main()
{
    int two_d_array[2][3] = {//make array
       {1,2,3},//input
       {4,5,6}
    };
    int* a = 0, * b = 0, * c = 0, * d = 0, * e, * f, (*g)[3], * h, * i, * j;//declare
    a = &two_d_array[0][0];//address of [0][0]==1
    b = &two_d_array[1][0];//address of [1][0]==4
    c = &two_d_array[0][1];//address of [0][1]==2
    d = &two_d_array[0][2];//address of [0][2]==3
    h = a;//h->a->1
    i = a;//i->a->1
    j = c;//j->c->2
    e = two_d_array[0];//e->1,2,3
    f = two_d_array[1];//f->4,5,6
    g = two_d_array;//g->1,2,3,4,5,6
    cout << "First Condition" << endl;
    cout << "a:" << *a << endl;//print
    cout << "b:" << *b << endl;
    cout << "c:" << *c << endl;
    cout << "d:" << *d << endl;
    cout << "h:" << *h << endl;
    cout << "i:" << *i << endl;
    cout << "j:" << *j << endl << endl;

    cout << "Second Condition" << endl;
    cout << "1-a:" << a << endl;//print
    cout << "1-h:" << h << endl;
    cout << "1-i:" << i << endl;
    cout << "2-c:" << c << endl;
    cout << "2-j:" << j << endl;
    cout << "3-d:" << d << endl;
    cout << "4-b:" << b << endl;
    cout << "5-?:" << b + 1 << endl;//shift 4bit
    cout << "6-?:" << b + 2 << endl << endl;//shift 8 bit

    cout << "Third Condition" << endl;
    cout << "e:" << e[0] <<" "<<e[1] << " " <<e[2]<<endl;
    cout << "f:" << f[0] << " " <<f[1] << " " <<f[2]<<endl;
    cout << "g:";
    for(int z =0; z<2;z++)
        for (int x = 0; x < 3; x++)
        {
            cout << g[z][x]<< " ";
        }
    cout << endl;
}