#ifndef DOG_H
#define DOG_H
#include<stdio.h>
/**
 * struct dog - Structure representing information about a dog.
 * @name: Pointer to the name of the dog.
 * @age: Age of the dog.
 * @owner: Pointer to the name of the owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
#endif
