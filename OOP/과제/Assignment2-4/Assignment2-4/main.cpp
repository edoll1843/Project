#include <iostream>
using namespace std;
int my_strlen(char* str);
char* my_strstr(char* str, char* strSearch, char* strChange)
{
	int str_len = 0;//declare
	str_len = my_strlen(str);//get length
	int search_len = 0;//declare
	search_len = my_strlen(strSearch);//get length
	int strChange_len = 0;
	strChange_len = my_strlen(strChange);

	int array[100] = { -1, };//declare
	int array_count = 0;

	char* answer = new char[100];//declare
	for (int set = 0; set < 100; set++)
	{//reset
		answer[set] = NULL;
	}
	for (int a = 0; a < str_len; a++)
	{//find first match char
		int count = 1;
		int count_1 = 0;
		if (str[a] == strSearch[0])
		{//if same
			while (count < search_len)
			{//find string until search length
				if (str[a+count] == strSearch[count])
				{//if same
					count++;
					if (count == search_len)
					{//if count is same with search length
						array[array_count] = a;
						array_count++;
						break;//break
					}
				}
				else
				{//no math
					count_1++;
				}
				if (count_1 == search_len)
					break;
			}

		}
	}
	if (array[0] == -1)
		return 0;//if there is no search string
	else
	{
		int a = 0;
		while (1)
		{//put string in answer

			answer[a] = str[a];//until find sting
			a++;
			if (a == array[0])
				break;
		}
		for (int b =0,c = a; b < strChange_len; b++, c++)
		{//put chnage string
			answer[c] = strChange[b];
			a++;
		}
		int z =array[0] + search_len;
		for (z; z < str_len; z++)
		{//put last string
			answer[a + 1] = str[z];
			a++;
		}
		return answer;
	}



}
int my_strlen(char* str)
{//get lenth of str
	int a = 0;
	for (a = 0; *str; str++, a++);
	return a;
}
int main()
{
	int strlen = 0;//declare
	char* str1 = new char[100];
	char* strChange1 = new char[100];
	char* strSearch1 = new char[100];
	char* result = new char[100];//declare
	for (int a = 0; a < 100; a++)
		str1[a] = NULL;//set to NULL
	for (int a = 0; a < 100; a++)
		strSearch1[a] = NULL;
	for (int a = 0; a < 100; a++)
		strChange1[a] = NULL;
	cout << "원본 문자열을 입력하세요." << endl;
	cin.getline(str1, 100);
	cout << endl;
	cout << "변경 전 문자열을 입력하세요." << endl;
	cin.getline(strSearch1, 100);
	cout << endl;
	cout << "변경 후 문자열을 입력하세요." << endl;
	cin.getline(strChange1, 100);
	cout << endl;
	result = my_strstr(str1, strSearch1, strChange1);//my_strstr func
	cout << "변경 된 결과는 다음과 같습니다." << endl<<endl;
	if (result == 0)
	{//if no search string
		cout << "일치하는 문자열이 없습니다.";
	}
	else
	{//change string output
		cout << "변경된 문자열: " << endl;
		for (int a = 0; a < 100; a++)
		{
			if (result[a] != NULL)
				cout << result[a];
		}
	}
	return 0;
}