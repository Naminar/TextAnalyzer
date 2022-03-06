#include <assert.h>

#include "../include/tools.h"
#include "../include/sorting.h"

void move_inf_buffer_case(struct Inform* inf_buff, int index,
                          int mother);


void piramid_sort(struct Inform* inf_buff, int n, char lock)
{


    if (lock == 'f')
    {
        for (int i = n/2-1; i >= 0; --i)
        {
            heap_creat_front(inf_buff, n, i);
        }

        for (int i = n-1; i >= 0; --i)
        {
            move_inf_buffer_case(inf_buff, i, 0);

            heap_creat_front(inf_buff, i, 0);
        }
    }
    else
    {
        for (int i = n/2-1; i >= 0; --i)
        {
            heap_creat_back(inf_buff, n, i);
        }

        for (int i = n-1; i >= 0; --i)
        {
            move_inf_buffer_case(inf_buff, i, 0);

            heap_creat_back(inf_buff, i, 0);
        }
    }


}


void heap_creat_front(struct Inform* inf_buff, int n, int i)
{
    int mother = i;

    int daughter1 = 2*i + 1;
    int daughter2 = 2*i + 2;

    if (daughter1 < n && comp_front(inf_buff[daughter1].address,
                                    inf_buff[mother].address))
        mother = daughter1;

    if (daughter2 < n && comp_front(inf_buff[daughter2].address,
                                    inf_buff[mother].address))
        mother = daughter2;

    if (mother != i)
    {
        move_inf_buffer_case(inf_buff, i, mother);

        heap_creat_front(inf_buff, n, mother);
    }
}


void heap_creat_back(struct Inform* inf_buff, int n, int i)
{
    int mother = i;

    int daughter1 = 2*i + 1;
    int daughter2 = 2*i + 2;

    if (daughter1 < n && comp_back(inf_buff, daughter1, mother))
        mother = daughter1;

    if (daughter2 < n && comp_back(inf_buff, daughter2, mother))
        mother = daughter2;

    if (mother != i)
    {
        move_inf_buffer_case(inf_buff, i, mother);

        heap_creat_back(inf_buff, n, mother);
    }
}

////////////////////////////////////////////////////////////////////////

void move_inf_buffer_case(struct Inform* inf_buff, int index, int mother)
{
    static struct Inform move_stc = {};

    move_stc = inf_buff[index];
    inf_buff[index] = inf_buff[mother];
    inf_buff[mother] = move_stc;
}
