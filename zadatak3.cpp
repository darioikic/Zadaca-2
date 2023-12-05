#include <iostream>
#include <list>
#include <functional>
#include <stdexcept>

typedef std::function<bool(int)> predicate;

std::list<int> parni_neparni(std::list<int>::const_iterator& it1, std::list<int>::const_iterator& it2, predicate f){

  std::list<int> rezultat;
  std::list<int>::const_iterator it3 = it1;

  try{
  while(it1!=it2){
  if(f(*it1)){
    rezultat.push_front(*it1);
  }else{
  rezultat.push_back(*it1);
  }
  it1++;
  }
  return rezultat;
  }catch(...){
  rezultat.clear();
  while(it3!=it2){
  rezultat.push_back(*it3);
  it3++;
  }
  return rezultat;
  }
}

int main(int argc, char *argv[])
{
  
  std::list<int> l1{15,20,25,-10,-75,100,-255,200};
  std::list<int>::const_iterator it1,it2;

  it1 = l1.begin();
  it2 = l1.end();

  auto lam = [&](int a){
    
    if(a>400){
    throw std::out_of_range{"Error"};
    }
  
    return !(a%2);
  };

  std::list<int> l2 = parni_neparni(it1,it2,lam);

  for(auto e : l2){
    std::cout<<e<<" ";
  }




  return 0;
}
