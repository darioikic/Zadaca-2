#include <iostream>
#include <list>

std::list<int> parni_neparni(std::list<int>::const_iterator& it1, std::list<int>::const_iterator& it2){

  std::list<int> rezultat;

  while(it1!=it2){
  if(*it1%2==0){
    rezultat.push_front(*it1);
  }else{
  rezultat.push_back(*it1);
  }
  it1++;
   }
  return rezultat;
}

int main(int argc, char *argv[])
{
  
  std::list<int> l1{1,3,9,10,2,5,8,6};
  std::list<int>::const_iterator it1,it2;

  it1 = l1.begin();
  it2 = l1.end();

  std::list<int> l2 = parni_neparni(it1,it2);

  for(auto e : l2){
    std::cout<<e<<" ";
  }




  return 0;
}
