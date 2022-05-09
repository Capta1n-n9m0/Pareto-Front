#include <stdio.h>
#include "csv.h"

int main(){
    char separator = '*';
    char ***lines = read_cvs_file("bikes.csv", separator);
    for(int i = 0; lines[i]; i++){
        for(int j = 0; lines[i][j]; j++){
            puts(lines[i][j]);
        }
    }
}
