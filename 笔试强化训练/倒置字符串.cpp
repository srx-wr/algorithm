#include<iostream>
#include<string>
using namespace std;

void reverse_str(string& str,int l,int r)
{
    while(l < r)
    {
        char tmp = str[l];
        str[l] = str[r];
        str[r] = tmp;
        l ++;
        r --;
    }
}

int main()
{
    string s;
    getline(cin,s);
    int size = s.size();
    int i = 0,j = 0;
    while(j < size)
    {
        i = j;
        if(s[j] == ' ')
        {
            reverse_str(s, i, i);
            j ++;
        }
        
        j++;
    }
    for(i = 0; i < size; i ++)
    {
        printf("%c",s[i]);
    }
    return 0;
}
