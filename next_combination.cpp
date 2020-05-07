#include<iostream>
using namespace std;

int counter =0;

// To get the required permutations
void permute(string &s,int idx,string prefix);
//To swap values by reference
void swap(int &pos1,int &pos2);
//To find the lexicographical combinations(required function)
void combine(string s,int idx,string sarray[]);
//To merge the sorted string
void merge(string &s,int low,int mid,int high);
//To perform mergesort on string
void mergesort(string &s,int l,int h);

int main()
{
    string sarray[10000];
    string s;
    cout<<"Enter the string : ";
    getline(cin,s);
    string copy=s;
    mergesort(copy,0,copy.length()-1);
    combine(copy,0,sarray);
    for(int i=0;i<counter;i++)
    {
        if(sarray[i]==s)
        {
            if(i==counter-1)
            {
                cout<<"\nNext Combination doesn't exist";
            }
            else
            {
                while(sarray[i+1]==s)
                    i++;
                cout<<"\nNext Combination : "<<sarray[i+1];
                break;
            }
            
        }
    }
    cout<<"\n";
    cout<<"\n BY : PULKIT AHUJA";
    cout<<"\n ROLL NO : 2019UCO1614";
    cout<<"\n";
}
//This is an auxiliary function to find the permutations for more than 2-lettered string
void permute(string &s,int idx,string prefix,string sarray[])
{
    //base case 
    if(idx==s.length()-1)
    {
        sarray[counter]=prefix+s;
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
        permute(s,idx+1,prefix,sarray);
        
        //backtracking
        temp=s[idx];
        for(int j=idx;j<i;j++)
        {
            s[j]=s[j+1];
        }
        s[i]=temp;
    }
}
//This is the main function to compute all the combinations of the given string and to store them in array
void combine(string s,int idx,string sarray[])
{   
    if(idx==s.length())
        return;
    
    string temp="",prefix="";
    string x(1,s[idx]);
    sarray[counter]=x;
    counter++;
    for(int next=0;next<s.length();next++)
    {
        if(next==idx)
            continue;
        prefix="";
        prefix=prefix+s[idx]+s[next];
        sarray[counter]=prefix;
        counter++;
        for(int i=0;i<s.length();i++)
        {
            if(i!=idx&&i!=next)
            {
                temp+=s[i]; 
                permute(temp,0,prefix,sarray);
            }
            
        }  
        temp=""; 
    }
    combine(s,idx+1,sarray);
}

void swap(int &pos1,int &pos2)
{
    int temp=pos1;
    pos1=pos2;
    pos2=temp;
}
//Definition of mergesort function
void mergesort(string &s,int l,int h)
{
    if(l==h)
        return;
        
    int mid=(l+h)/2;
    mergesort(s,l,mid);
    mergesort(s,mid+1,h);
    merge(s,l,mid,h);
}
//The auxi function for mergesort ,to merge the sorted arrays
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