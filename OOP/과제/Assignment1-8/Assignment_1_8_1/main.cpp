#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char line[1500];//declare arr
    char* str[1500];//declare arr
    int num[1500];//declare num arr
    ifstream read;//ifstream
    read.open("ciphertext.txt");//open the text file
    read.getline(line, 1500);// get line size 1500
    cout << "ciphertext: " << line;
    cout << endl;
    char* token = strtok(line, " "); //tok by " "
    int cnt = 0;

    while (token)
    {//while token is not null
        str[cnt] = token; // put token str[cnt] 
        token = strtok(NULL, " ");// token by " " again
        cnt++; //count up
    }
    for (int b = 0; b < cnt; b++)
    {
        num[b] = strtol(str[b], NULL, 16);//print num to hexadecimal
    }
    for (int a = 0; a <= 127; a++)
    {
        cout << "key(" << a << "): ";//print key
        for (int b = 0; b < cnt; b++)
        {
            char temp = NULL;
            if ((num[b] + a) > 127)
            {//if num is lagger than 127
                temp = (num[b] + a )- 128;// make reset and shift a
            }
            else
            {  // else put hex int temp and shift
                temp = num[b] + a;
            }
            cout << temp<<" ";//print
        }
        cout << endl;
    }
}