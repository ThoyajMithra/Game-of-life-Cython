from libcpp.vector cimport vector

cdef extern from "life.h":

    cdef cppclass Life:
        int height;   
        int width;     
        int size;

        vector[vector[int]] overhead;

        vector[int] world;

        Life(int x, int y,vector[int] w) ;

        vector[int] generation() ;