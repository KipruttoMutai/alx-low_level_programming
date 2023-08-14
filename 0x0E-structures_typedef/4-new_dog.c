#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1 = 0, len2 = 0, i = 0;

	while (name[len1])
		len1++;
	while (owner[len2])
		len2++;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len1 + 1));
	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->name == NULL || dog->owner == NULL)
	{
		free(dog->name);
		free(dog->owner);
		free(dog);
		return (NULL);
	}
	while (i <= len1)
	{
		dog->name[i] = name[i];
		i++;
	}

	i = 0;
	while (i <= len2)
	{
		dog->owner[i] = owner[i];
		i++;
	}

	dog->age = age;

	return (dog);
}

