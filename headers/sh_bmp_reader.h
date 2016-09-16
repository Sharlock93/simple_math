#ifndef SH_BMP_READER
#define SH_BMP_READER
#include <stdint.h>

typedef uint8_t uint8;
typedef  int8_t  int8;

typedef uint32_t uint32;
typedef  int32_t  int32;

typedef uint64_t uint64;
typedef uint16_t uint16; 

//Note(sharo): the size of this should be 14 bytes, but the compiler pads it to 16
//Todo(sharo): I'm not gonna fight the compiler to make it 14 again, but it should be possible.
struct sh_bmpfileheader {
    uint16 file_type;
    uint32 file_size;
    uint16 r1;
    uint16 r2;
    uint32 offset;
};


//Note(sharo): used for multi-image BMP files, most likely only on mac?
struct sh_bmparrayheader {
    uint16 ftype;
    uint32 size;
    uint32 next;
    uint16 s_width;
    uint16 s_height;
};

struct sh_bmpheader {
    uint32 size;
    int32 width;
    int32 height;
    uint16 num_bit_plane; //bit per plane.
    uint16 bpp; //bit per plane.
    uint32 compression_scheme;
    uint32 size_of_img_data;
    uint32 x_res;
    uint32 y_res;
    uint32 num_colors;
    uint32 num_important_colors;
    uint16 res_uints;
    uint16 padding;
    uint16 origin;
    uint16 halftoning;
    uint32 halftone_param1;
    uint32 halftone_param2;
    uint32 color_encode;
    uint32 id;
};

//Note(sharo): inverted because of little endian? maybe only windows weirdness
struct sh_rgb {
    uint8 blue; 
    uint8 green; 
    uint8 red; 
    uint8 pad; //pad to 4 byes
};

struct sh_bmp_img {
    sh_bmpfileheader fhead;
    sh_bmpheader head;
    int32 height; //Note(sharo): can be negative if stored top to bottom
    int32 width;
    char* orig_file_ptr;
    sh_rgb* data; //Todo(sharo): let the programmer free?
};

extern "C" __declspec(dllexport) sh_bmp_img sh_read_bmp(const char* file);
#endif /* ifndef SH_BMP_READER */
