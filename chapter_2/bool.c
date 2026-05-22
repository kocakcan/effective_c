#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char *name;
	bool is_engineer;
} Person;

Person *create_person(char *name, bool is_engineer) {
	Person *new_person = malloc(sizeof(*new_person));
	if (new_person == NULL) {
		fprintf(stderr, "malloc: out-of-memory\n");
		return NULL;
	}
	new_person->name = strdup(name);
	if (new_person->name == NULL) {
		fprintf(stderr, "strdup: failed to allocate name\n");
		free(new_person);
		return NULL;
	}
	new_person->is_engineer = is_engineer;
	return new_person;
}

void free_person(Person *p) {
	if (!p)
		return;
	free(p->name);
	free(p);
}

int main(void) {
	Person *me = create_person("Can", false);
	if (me == NULL) {
		fprintf(stderr, "create_person: failed\n");
		return 1;
	}
	printf("Name: %s | Is engineer?: %s\n", me->name,
			me->is_engineer ? "true" : "false");
	free_person(me);
	return 0;
}
