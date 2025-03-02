#pragma once
#include<vector>
class AllocaInst{};
class DominantTree{};
class Function{};

class AllocaInfo 
{

};

class BlockInfo 
{

};

class PromoteMem2Reg
{
public:
  // 遍历基本块中的指令，将指令进行一个消除 alloca/ store / load指令
    bool isAllocaPromotable(AllocaInst* AI);

    void reName();
    bool promoteMemoryToRegister(DominantTree* tree,Function *func,std::vector<AllocaInst *>& Allocas);
    void RemoveFromAList(unsigned AllocaNum);
     
private:
    // ValUseList& listPtr;
};
