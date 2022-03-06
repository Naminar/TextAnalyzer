#include <stdio.h>
#include <sys\stat.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


#include "include/tools.h"
#include "include/sorting.h"
#include "include/piramed.h"

int main(void)
{
    //system ("cd & pause");

    unsigned str_number = 0;

    char input_file[20] =  {};
    char output_file[20] = {};

    struct stat file_inf = {};

    printf("Enter input file\n");

    scanf("%s", input_file);

    printf("Enter output file\n");

    scanf("%s", output_file);

    char* buffer = read_text(&file_inf, input_file);

    if (file_inf.st_size == 0)
    {
        FILE* out_txt = NULL;

        out_txt = fopen(output_file,"w");

        assert(out_txt != NULL);

        fprintf(out_txt,"I'll differentiate you now!\n"
                        "Enter not null file!");

        fclose(out_txt);

        return 0;
    }

    struct Inform* inf_buff = indx_ctch(file_inf.st_size, buffer,
                                        &str_number);

    back_sort(inf_buff, str_number, output_file);

    front_sort(inf_buff, str_number, output_file);

    //////////////////////////////////////////////

    print_original_txt(output_file, file_inf.st_size, buffer, &str_number);

    free(buffer);

    printf("====================================\n"
           "All processes completed successfully!\n\n"
           "Your file done!\n");
}










