
#include <iostream>
#include <iomanip>


using namespace std; 

class DoubleSubscriptedArray{
  friend std::ostream &operator<<( std::ostream &, const DoubleSubscriptedArray & );
  friend std::istream &operator>>( std::istream &, DoubleSubscriptedArray & );


private:
    int size;
    int *ptr;


  public:
DoubleSubscriptedArray(){
  size = 10;
}
DoubleSubscriptedArray(int siz){
 size = (siz>0 ? siz : 10);
  ptr = new int[size];
  for(int i=0;i<size;i++){
    ptr[i] = 0;
  }
}

DoubleSubscriptedArray(const DoubleSubscriptedArray &copyArray):size(copyArray.size){
  ptr = new int[size];
  for(int i=0;i<size;i++){
    ptr[i] = copyArray.ptr[i];
  }
  
}

int getSize()const{return size;}

~DoubleSubscriptedArray(){delete []ptr;}
const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &right){
 if(&right != this){
   delete [] ptr;
   size = right.size;
   ptr = new int[size];
 } 
  for(int i=0;i<size;i++){
    ptr[i] = right.ptr[i];
  }
  return *this;
}

bool operator==(const DoubleSubscriptedArray &right)const{
  if(size != right.size){
    return false;
  }
  for(int i=0;i<size;i++){
    if(ptr[i] != right.ptr[i]){
      return false;
    }
  }
  return true;
}


bool operator!=( const DoubleSubscriptedArray &right ) const{
  return ! ( *this == right );
}

int &operator[](int subs){
  if(subs<0||subs>=size){
    cerr <<endl<<"Error : Subscript "<<subs<<" out of range"<<endl;
    exit(1);
  }
  return ptr[subs];
  
  
}

  
};


istream &operator>>(istream &input, DoubleSubscriptedArray &x){
  for(int i=0;i<x.size;i++){
    input>> x.ptr[i];
  }
  return input;
}

ostream &operator<<(ostream &output, const DoubleSubscriptedArray &x){
  for(int i=0;i<x.size;i++){
    output<<setw(12)<<x.ptr[i];
    if((i+1)%4==0){
      output<<endl;
    }
    if(i%4!=0){
      output<<endl;
    }
  }
  return output;
}

int main(){
  DoubleSubscriptedArray int1(5);
  DoubleSubscriptedArray int2;
  cout<<"The size of the array 1 is : "<<int1.getSize()<<endl<<"Array after its initialization : "<<int1;

  cout<<"The size of the array 1 is : "<<int2.getSize()<<endl<<"Array after its initialization : "<<int2;

  cout<<endl<<"Enter 5 integers : "<<endl;
  cin>>int1;
  cin>>int2;

  cout<<endl<<"Array after the input : "<<endl<<int1<<endl<<int2<<endl;

  cout<<endl<<"Evaluate int1 != int2 : "<<endl;
  if(int1 != int2){
    cout<<"Int1 and int2 are not equal"<<endl;
  }

  DoubleSubscriptedArray int3(int1);
  cout<<endl<<"Size array 3 : "<<int3.getSize()<<endl;
  cout<<"Array after its initialization : "<<int3;

  cout<<"Assigning int2 to int1 : "<<endl;
  int1 = int2;
  cout<<"Int1 : "<<endl<<int1<<endl;
  cout<<"Int2 : "<<endl<<int2<<endl;

  cout<<"Evaluating int1 is the same as int 2 (int1=int2): "<<endl;
  if(int1 ==int2){
    cout<<"Int1 and int2 are equal"<<endl;
    
  }

  cout<<"int1[3] is : "<<int1[3];

  return 0;
}