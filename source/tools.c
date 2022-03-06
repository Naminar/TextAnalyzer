#include <assert.h>
#include <sys\stat.h>
#include <string.h>
#include <stdio.h>

#include "../include/tools.h"

void add_zero_and_address(struct Inform* inf_buff, char* buffer, int address_number,
                          int address_ind, int zero_ind);

struct Inform* indx_ctch(size_t txt_size, char* buffer, unsigned* str_n);


char* read_text(struct stat* file_inf, const char* input_file)
{
    FILE* txt = NULL;

    txt = fopen(input_file, "rb");

    if (!txt)
    {
        printf("No such file exists. Pleas, try again!\n");

        assert(0);
    }

    stat(input_file, file_inf);

    unsigned buff_size = file_inf->st_size;

    char* big_str = NULL;

    big_str = (char*) calloc(buff_size + sizeof(char), sizeof(char));

    assert(big_str != NULL);

    fread(big_str, sizeof(char), buff_size/sizeof(char), txt);

    fclose(txt);

    big_str[buff_size/sizeof(char)] = '\0';

    return big_str;
}


void file_out(int str_n, struct Inform* inf_buff, const char* output_file)
{

    FILE* out_txt = NULL;

    out_txt = fopen(output_file,"a");

    assert(out_txt != NULL);

    for(int i = 0; i < str_n - 1; i++)
        fprintf(out_txt,"%s\n", inf_buff[i].address);

    fprintf(out_txt,"%s \n====================================================="
            "==================================\n", inf_buff[str_n - 1].address);

    printf("process done\n");

    fclose(out_txt);
}


struct Inform* indx_ctch(size_t txt_size, char* buffer, unsigned* str_n)
{
    unsigned n_symb = txt_size / sizeof(char);

    unsigned str_number = 1;

    for(unsigned ind = 0; ind < n_symb; ind++)
    {
        if(buffer[ind] == '\n')
            str_number++;
    }

    *str_n = str_number;

    struct Inform* inf_buff = (struct Inform*)
                              calloc(str_number,sizeof(struct Inform));

    inf_buff[0].address = buffer;

    unsigned numb = 0;

    for (unsigned ind = 0; ind < n_symb; ind++)
    {
        if (buffer[ind] == '\r')
        {
            ++numb;

            add_zero_and_address(inf_buff, buffer, numb, ind + 2, ind);

            ++ind;
        }
        else if (buffer[ind] == '\n')
        {
            ++numb;

            add_zero_and_address(inf_buff, buffer, numb, ind + 1, ind);
        }
    }

    inf_buff[numb].length = strlen(inf_buff[numb].address);

    return inf_buff;
}

//////////////////////////////////////////////////////////////////////

void add_zero_and_address(struct Inform* inf_buff, char* buffer, int address_number, int address_ind, int zero_ind)
{
    inf_buff[address_number].address = &buffer[address_ind];

    buffer[zero_ind] = '\0';

    inf_buff[address_number - 1].length = strlen(inf_buff[address_number - 1].address);
}

void print_original_txt(char* output_file, size_t size_orig, char* buffer,unsigned* str_number)
{
    FILE* out_txt_orig = fopen(output_file,"a");

    struct Inform* inf_buff_orig =  indx_ctch(size_orig, buffer, str_number);

    for(int i = 0; i < *str_number; i++)
    {
        fprintf(out_txt_orig,"%s\n", inf_buff_orig[i].address);
    }

    printf("process done\n");

    fclose(out_txt_orig);
}
