from libcpp.vector cimport vector
from life cimport Life

cdef class PyLife:

    cdef Life* thisptr

    def __cinit__(self,int x,int y,world):

        cdef vector[int] vec=world

        self.thisptr=new Life(x,y,vec)
    
    def __dealloc__(self):
        if(self.thisptr):
            del self.thisptr
    
    def generation(self):

        cdef vector[int] res
        res=self.thisptr.generation()

        return list(res)