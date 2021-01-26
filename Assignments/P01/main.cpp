/******************************************************
* Author   :        Sandesh Pathak
* Email    :        spathak0919@my.msutexas.edu
* Label    :        P01
* Title    :        Resizing the stack
* Course   :        CMPS 3013
* Semester :        Spring 2021
*
*    Description : 
*
*        In this program it will read numbers from .dat file. 
*        If the number is even it will use push operation 
*        and if the number is odd it will use pop operation.
*         In the end an output file is created where it     
*        outputs max stack size, end stack size and the times 
*        stacks are resized. 
*
*   Usage:  nums.dat
*           nums_test.dat
*           main.cpp
*
**************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void openfiles(ifstream&, ofstream&);     // ask user for input and output file

class arraystack
{
    private:          // private access modifier
    
    int*a;            // initialize pointer 
    int size;         // initialize size as an integer value
    int top;          // initialize top as an integer value
    int timeresized;  // initialize timeresized as an integer value
    int maxsize;      // initialize max size as an integer value
    
    public:           // public access modifier
    
    arraystack();     // constructor 
    arraystack(int s);

    
    bool full();
    bool empty(); 
    
    int peek();
    int Pop();
    bool Push(int x);

    void print();
    void containergrow();
    void containershrink();
    void checkresize();

    int get_top();
    int get_size();
    int get_timeresized();
    int get_maxsize();
    
};

arraystack::arraystack()
{
    
    size = 10;
    a = new int[size];
    top = -1;
    timeresized = 0;
    maxsize = size;
    
}

arraystack::arraystack(int s)
{
    
    size = 10;
    a = new int[s];
    top = -1;
    timeresized = 0;
    maxsize =size;
    
}

bool arraystack::empty()
{
    return (top <= -1);
}

bool arraystack::full()
{
    return (top >= size -1);
}

int arraystack::peek()
{
    if (!empty())
    {
        return a[top];
    }
    return -99;
}

int arraystack::Pop()
{
    if(!empty())
    {
        checkresize();
        return a[top --];
        
    }
    return -99;
    
}
void arraystack::print()
{
    for (int i =0;i<=top; i++)
    {
        cout <<a[i]<<"" ;
    }
    cout <<endl;
}

bool arraystack::Push(int x)
{
    a[++top]= x;
    checkresize();
    return true;
}

void arraystack::containergrow()
{
    int newsize = size * 1.50;
    int *b =new int[newsize];
    
    for (int i =0; i<size;i++)
    {
    b[i]=a[i];
    }
    delete[] a;

    size = newsize;
    a=b;

    if (maxsize <newsize)
    {

      maxsize=size;
    }
}

void arraystack::containershrink()
{
int newsize = size/2;
if(newsize<10)
{
  newsize=10;
}
int*b= new int[newsize];

for(int i=0;i<=top;i++)
{
  b[i]=a[i];
}
delete[] a;
size =newsize;
a=b;
}

void arraystack::checkresize()
{
  if (full())
  {

    containergrow();
    timeresized++;
  }

  else if(top<(size/2) && size >10)
  {
    containershrink();
    timeresized++;
  }
}

int arraystack::get_size()
{
  return size;
}

int arraystack::get_timeresized()
{
  return timeresized; 
}
int arraystack::get_maxsize()
{
  return maxsize;
}

int arraystack::get_top()
{
  return top;
}

int main()
{
  arraystack stack;
  ifstream infile;
  ofstream outfile;

  openfiles(infile,outfile);

  int num;
  while(!infile.eof())
  {
    infile >>num;
    if(num % 2 ==0)
    {
      stack.Push(num);
    }
    else
    {
      stack.Pop();
    }
  }
  outfile <<"#####################################################"<<"\n";
  outfile <<"\tAssignment 4 - Resizing the Stack"<<"\n";
  outfile <<"\tCMPS 3013"<<"\n";
  outfile <<"\tSandesh Pathak"<<"\n\n";
  outfile <<"\tMax Stack Size: "<<stack.get_maxsize()<<"\n";
  outfile <<"\tEnd Stack Size: "<<stack.get_size()<<"\n";
  outfile <<"\tStack Resized : "<<stack.get_timeresized()<<" Times\n\n";
  outfile <<"#####################################################"<<"\n";


}
void openfiles(ifstream& infile, ofstream& outfile)
{
  char infilename[40];
  char outfilename[40];

  cout <<"Enter file name "<<endl;
  cin>> infilename;

  infile.open(infilename);
  cout <<"Enter outfile name "<<endl;
  cin >>outfilename;

  outfile.open(outfilename);
}

