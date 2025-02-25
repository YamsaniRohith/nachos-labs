#ifndef PCBMANAGER_H
#define PCBMANAGER_H

#include "bitmap.h"
#include "pcb.h"
#include "synch.h"

class PCB;
class Lock;

class PCBManager {

    public:
        PCBManager(int maxProcesses);
        ~PCBManager();

        PCB* AllocatePCB();
        int DeallocatePCB(PCB* pcb);
        PCB* GetPCB(int pid);
        int GetLength();

    private:
        BitMap* bitmap;
        PCB** pcbs;
        // Need a lock here
        Lock* pcbManagerLock;

};

#endif // PCBMANAGER_H