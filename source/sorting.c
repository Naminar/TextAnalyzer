#include <assert.h>
#include <ctype.h>

#include "../include/tools.h"
#include "../include/piramed.h"

static int char_cmp(const char symbol);

void front_sort(struct Inform* inf_buff, unsigned str_number, const char* output_file)
{
    piramid_sort(inf_buff, str_number, 'f');

    file_out(str_number, inf_buff, output_file);
}


void back_sort(struct Inform* inf_buff, unsigned str_number, const char* output_file)
{
    piramid_sort(inf_buff, str_number, 'b');

    file_out(str_number, inf_buff, output_file);
}


int comp_front(const char* f_add, const char* s_add)
{
    int ind  = 0,
        ind1 = 0;

    while (1)
    {
        if (char_cmp(f_add[ind]))
        {ind++; continue;}

        if (char_cmp(s_add[ind1]))
        {ind1++; continue;}

        if (tolower(f_add[ind]) != tolower(s_add[ind1]))
            break;

        if (f_add[ind] == '\0')
            break;

        ind++;
        ind1++;
    }

    if (tolower(s_add[ind1]) < tolower(f_add[ind]))
        return TRUE;

    return FALSE;
}


int comp_back(struct Inform* inf_buff, int daughter, int mother)
{
    char* daughter_symbol = inf_buff[daughter].address +
                            inf_buff[daughter].length  - 1;

    char* mother_symbol =   inf_buff[mother].address +
                            inf_buff[mother].length  - 1;

    while (1)
    {
        if (char_cmp(*mother_symbol))
        {--mother_symbol; continue;}

        if (char_cmp(*daughter_symbol))
        {--daughter_symbol; continue;}

        if (tolower(*mother_symbol) != tolower(*daughter_symbol))
            break;

        if ( *daughter_symbol == '\n' || *daughter_symbol == '\0' )
            break;

        --daughter_symbol;
        --mother_symbol;
    }

    if (tolower(*daughter_symbol) > tolower(*mother_symbol))
        return TRUE;

    return FALSE;
}
///////////////////////////////////////////
static int char_cmp(const char symbol)
{
    if (symbol == ' ' ||
        symbol == '"' ||
        symbol == '.' ||
        symbol == '!' ||
        symbol == ',' ||
        symbol == ']' ||
        symbol == '[' ||
        symbol == '?'  )
    {return 1;}

    return 0;
}
