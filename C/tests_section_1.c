#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "database.h"

int main() {
    vector v1 = create_zero_vector(2);
    vector v2 = create_zero_vector(2);

	v1->content[0] = 1;
	v1->content[1] = 2;
	
	v2->content[0] = 3;
	v2->content[1] = 4;

	database b = create_empty_database(2);
	b->datas[0].vector = v1;

	b->datas[1].vector = v2;
	b->datas[1].class = 1;
	print_data_base(b);

	printf("%f %f\n", distance(v1,v2), distance(v2,v1));
	printf("%f\n", distance(v1,v1));


	delete_database(b);

    return 0;
}
