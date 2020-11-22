#include <stdio.h>

typedef enum endian_type endian_t;

enum endian_type {
    UNDEFINED = -1,
    LITTLE_ENDIAN = 0,
    BIG_ENDIAN
};

static inline endian_t endian_check(unsigned int data);

endian_t endian_check(unsigned int data)
{
    unsigned char *uchar_data = (unsigned char *)&data;
    const unsigned int mask = 0xFF;
    
    if (((data & mask) == uchar_data[0])
            && (((data >> 8) & mask) == uchar_data[1])
            && (((data >> 16) & mask) == uchar_data[2])
            && (((data >> 24) & mask) == uchar_data[3])) {
        
        return LITTLE_ENDIAN;
    
    } else if (((data & mask) == uchar_data[3])
            && (((data >> 8) & mask) == uchar_data[2])
            && (((data >> 16) & mask) == uchar_data[1])
            && (((data >> 24) & mask) == uchar_data[0])) {
        
        return BIG_ENDIAN;
        
    } else {
        return UNDEFINED;    
    }
}

int main()
{
    endian_t endian;
    unsigned int data = 0x11223344;
    
    endian = endian_check(data);
    
    if (endian == LITTLE_ENDIAN) {
        printf("Little endian!\n");
    } else if (endian == BIG_ENDIAN) {
        printf("Big endian!\n");
    } else {
        printf("undefined!\n");
    }
    
    return 0;
}
