
//! @file
//! @mainpage
//!
//! Meow!!!
//!

/**
 Function starts sorting from the beginning

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  str_number

 @note launch piramid_sort
*/
void front_sort(struct Inform*, unsigned);

/**
 Function compare strings

 @param  [in]  f_add        daughter's string

 @param  [in]  s_add        mother's string

 @return should it be changed or not
*/
int comp_front(const char*, const char*);


/**
 Function starts sorting from the end

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  str_number

 @note launch piramid_sort
*/
void back_sort(struct Inform*, unsigned);

/**
 Function compare strings

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  daughter     daughter's string

 @param  [in]  mother       mother's string

 @return should it be changed or not
*/
int comp_back(struct Inform*, int, int);



/**
 Function beginning pyramid sort

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  n

 @param  [in]  lock         lock to open correct
                            heap_creat
 @note beginning pyramid sort
*/
void piramid_sort(struct Inform*, int, char);

/**
 Function build heap

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  n            number of new elements

 @param  [in]  i            mother's index

 @note beginning pyramid sort
*/
void heap_creat_f(struct Inform*, int, int);

/**
 Function build heap

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  n            number of new elements

 @param  [in]  i            mother's index

 @note beginning pyramid sort
*/
void heap_creat_b(struct Inform*, int, int);



/**
 Function reads from a file

 @param  [in]  inf_buff     array of information
                            about each row

 @return big_str - address of one union string

 @note And create a big string
*/
char* read_text(struct stat*);

/**
 Function build heap

 @param  [in]  str_n        number of strings

 @param  [in]  inf_buff     array of information
                            about each row

 @note beginning pyramid sort
*/
void file_out(int, struct Inform*);

/**
 Function

 @param  [in]  inf_buff     array of information
                            about each row

 @param  [in]  buffer       address of one union string

 @param  [out] str_n        number of string

 @return array of information about each row
*/
Inform* indx_ctch(struct stat*, char*, unsigned*);

