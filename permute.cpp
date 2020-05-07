#include<bits/stdc++.h>
using namespace std;

int counter =0 ;

// To produce all possible permutations of a given string
void permute(string &s,int idx,string []);
//To swap two values by reference
void swap(int &pos1,int &pos2);
//To merge two strings
void merge(string &s,int low,int mid,int high);
//Sort the string 
void mergesort(string &s,int l,int h);

int main()
{
    string s;
    string sarray[10000];
    cout<<"\nEnter the string : "<<endl;
    getline(cin,s);
    string copy=s;
    mergesort(copy,0,copy.length()-1);
    permute(copy,0,sarray);
    for(int i=0;i<counter;i++)
    {
        if(sarray[i]==s)
        {
            if(i==counter-1)
            {
                cout<<"\nNext permutation doesn't exist";
            }
            else
            {
                while(sarray[i+1]==s)
                    i++;
                cout<<"\nNext permutation is : "<<sarray[i+1];
                break;
            }
            
        }
    }
    cout<<"\n";
    cout<<"\n BY : PULKIT AHUJA";
    cout<<"\n ROLL NO : 2019UCO1614";
    cout<<"\n";
}

void permute(string &s,int idx,string sarray[])
{
    //base case 
    if(idx==s.length()-1)
    {
        sarray[counter]=s;
        counter++;
        return;
    }
    char temp;
    for(int i=idx;i<s.length();i++)
    {
        temp=s[i];
        for(int j=i;j>idx;j--)
        {
            s[j]=s[j-1];
        }
        s[idx]=temp;
        permute(s,idx+1,sarray);
        
        //backtracking
        temp=s[idx];
        for(int j=idx;j<i;j++)
        {
            s[j]=s[j+1];
        }
        s[i]=temp;
    }
}
void swap(int &pos1,int &pos2)
{
    int temp=pos1;
    pos1=pos2;
    pos2=temp;
}

void mergesort(string &s,int l,int h)
{
    if(l==h)
        return;
        
    int mid=(l+h)/2;
    mergesort(s,l,mid);
    mergesort(s,mid+1,h);
    merge(s,l,mid,h);
}

void merge(string &s,int low,int mid,int high)
{

    string temp;
    int l=low,r=mid+1;
    while(l<=mid&&r<=high)
    {
        if(s[l]<s[r])
        {
            temp+=s[l];
            l++;
        }
        else
        {
            temp+=s[r];
            r++;
        }   
    }
    while(l<=mid)
    {
        temp+=s[l];
        l++;
    }
    while(r<=high)
    {
        temp+=s[r];
        r++;
    }
    for(int i=low,k=0;i<=high;i++,k++)
    {
        s[i]=temp[k];
    }
}
