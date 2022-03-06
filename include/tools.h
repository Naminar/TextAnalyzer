#include <stdlib.h>

struct Inform{
    char* address;
    unsigned length;
};

char* read_text(struct stat*, const char*);
void file_out(int str_n, struct Inform* inf_buff, const char*);
struct Inform* indx_ctch(size_t txt_size, char*, unsigned*);
void print_original_txt(char* output_file, size_t size_orig,
                        char* buffer, unsigned* str_number);

enum {FALSE = 0, TRUE = 1};
