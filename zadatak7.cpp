#include <iostream>
#include<list>
#include<functional>

int reduce(const std::list<int>& list1, std::function<int(int,int)> f,const int& start){

  std::list<int>::const_iterator it = list1.begin();
  int rez = 0;
  
  while(it!=list1.end()){
    if(it==list1.begin()){
    rez = f(*it,start);
    it++;
    }else{
    rez = f(*it,rez);
    it++;
    }
  }

  return rez;
  
}

int main(int argc, char *argv[])
{
  std::list<int> list1{11,4,5,12,6,8,9};
  int start = -12;

  auto lam = [&](int a, int b){
    return a+b+1;
  };

  std::cout<<"Output: "<<std::endl;
  std::cout<<reduce(list1,lam,start);

  return 0;
}
