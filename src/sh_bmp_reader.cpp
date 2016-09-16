#include "..\headers\sh_bmp_reader.h"
#include "..\headers\sharinit.h"
#include <stdio.h>

sh_bmp_img sh_read_bmp(const char* file){
    sh_bmp_img img = {};

    char *t = shareadfile(file);
    img.orig_file_ptr = t;

    sh_bmpfileheader fhead = {};
    //Note(sharo): read the BMPFILEHEADER struct. 
    fhead.file_type = *(uint16 *)(t); t += sizeof(uint16);
    fhead.file_size = *(uint32 *)(t); t += sizeof(uint32); 
    fhead.r1        = *(uint16 *)(t); t += sizeof(uint16);
    fhead.r2        = *(uint16 *)(t); t += sizeof(uint16);
    fhead.offset    = *(uint32 *)(t); t += sizeof(uint32);

 
    //Note(sharo): read the bmpheader
    sh_bmpheader head =  *(sh_bmpheader *) (t);//bmpheader comes 14 bytes after bmpfileheader
    t += fhead.offset - 14; //we moved 14 bytes, so subtract 14 bytes? dumb

    //Todo(sharo): just a pointer? seems bad.
    img.fhead = fhead;
    img.head = head;
    img.data = (sh_rgb *)(t);
    img.height = head.height; //why would I do this?
    img.width = head.width;

    return img;
}

