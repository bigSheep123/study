#include"head.hpp"

bool PromoteMem2Reg::promoteMemoryToRegister(DominantTree* tree,Function *func,std::vector<AllocaInst *>& Allocas)
{
    // 移除没有users 的 alloca指令
    for(unsigned AllocaNum = 0; AllocaNum != Allocas.size(); ++AllocaNum){
        AllocaInst* AI = Allocas[AllocaNum];
        if(!AI->isUsed()){
            delete AI;
            
        }
    }

    return true;
}
