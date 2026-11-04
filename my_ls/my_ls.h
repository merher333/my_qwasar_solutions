#ifndef MY_LS_H
#define MY_LS_H

void parse_options(int argc, char **argv,
                   int *show_all, int *sort_time,
                   int *first_operand);

void list_entries(char **names, int count,
                  int show_all, int sort_time);

int compare_name(const void *a, const void *b);
int compare_time(const void *a, const void *b);

#endif /* MY_LS_H */
