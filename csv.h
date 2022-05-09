#ifndef PARETO_FRONT_CSV_H
#define PARETO_FRONT_CSV_H

char **split_string(const char *string, char separator);
char ***read_cvs_file(const char *filename, char separator);

#endif //PARETO_FRONT_CSV_H
