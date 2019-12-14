//Q Given a string ‘s’ with four different letters in it, write a C program to eliminate any of the two letters so that the string retained is valid and is of maximum possible length. All the of occurrences of the letters to be eliminated should be removed from s. The string retained after removing two letters is said to be valid when for all characters ‘ch’ in the string, either the character on its left or character on its right is same as ‘ch’. For example, aaddaaa is valid but aaaeaa is not valid.

// When there are more than one valid string with the maximum possible length, retain the lexicographically lesser string. A string s1 is said to be lexicographically lesser than s2 when s1 will come first in dictionary. For example, consider the string s, aabbcddc with four different letters a, b, c and d. The valid strings that shall be formed with any two letters are:

// aabb – When letters c and d are removed

// aacc – When letters b and d are removed

// aadd – When letters a and a are removed

// bbcc – When letters a and d are removed

// bbdd – When letters a and c are removed

// cddc – When letters a and b are removed

// The maximum length of the strings that can be formed is four and lexicographically least string is aabb, so print aabb.

// Input Format
//
// First line contains the string s with some four letters of English alphabet
//
// Output Format
//
// Lexicographically least and maximum length valid string retained after removing any two letters

#include <iostream>
#include <sstream>
using namespace std;

int main()
{   int i,j,k,l;
    string s;
    cin>>s;
    string len = "";
    bool flag = false;
    for(i=0;i<s.size();i++)
    {   flag = false;
        for(j=0;j<len.size();j++)
            if(len[j]==s[i])
                flag = true;
        if(!flag)
            len = len + s[i];
    }
    string min="";

    for(j=0;j<4;j++)
    {
        for(k=j+1;k<4;k++)
        {
            string temp = "";

            for(i=0;i<s.size();i++)
                if(s[i]!=len[j]&&s[i]!=len[k])
                    temp = temp + s[i];

            if ((min == "")||(temp.size()>min.size())||(temp<min&&temp.size()==min.size()))
            {
                flag = false;
                int x = temp.size();

                if((x>1)&&(temp[0]!=temp[1]||temp[x-1]!=temp[x-2]))
                    flag = true;

                for(l=1;l<x-1;l++)
                    if(!(temp[l-1]==temp[l]||temp[l]==temp[l+1]))
                        flag = true;

                if(!flag)
                    min = temp;
                    continue;
            }
        }
    }
    cout<<min;
}
