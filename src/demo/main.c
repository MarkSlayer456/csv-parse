#include "csv_parse.h"

int main(void)
{
    csv_data_t a = parse("test.csv");
    printf("%d\n", a.rows);
    printf("%d\n", a.cols);
    int mark = csv_get_line(a, "mark");
    printf("Mark was found on line: %d\n", mark);
    printf("printing info for mark:\n");
    char **info = csv_get_line_data(a, mark);
    for(int i = 0; i < a.cols; i++) {
        if(i + 1 == a.cols) printf("%s", info[i]);
        else printf("%s,", info[i]);
    }
    printf("\n");
    
    // a easier way to do that
    char **info2 = csv_get_line_from_value(a, "mark");
    for(int i = 0; i < a.cols; i++) {
        if(i + 1 == a.cols) printf("%s", info2[i]);
        else printf("%s,", info2[i]);
    }
    printf("\n");
    
    // find a lot of data at a time
    printf("\n");
    printf("\n");
    printf("finding all marks\n");
    int *marks = csv_find_all(a, "mark");
    for(int j = 0; marks[j] != 0; j++) {
        char **info = csv_get_line_data(a, marks[j]);
        for(int i = 0; i < a.cols; i++) {
            if(i + 1 == a.cols) printf("%s", info[i]);
            else printf("%s,", info[i]);
        }
        printf("\n");
    }
	return 0;
}
